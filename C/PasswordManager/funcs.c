#include "funcs.h"

// just a helper to advance the LFSR state by one step and spit out a key byte
// taps at bits 0,1,2,4 -- picked these because they make a maximal-length sequence
// for a 64-bit register meaning it cycles through all 2^64-1 states before repeating
static unsigned char lfsr_step(unsigned long long* state){
  unsigned long long bit = ((*state >> 0) ^ (*state >> 1) ^ (*state >> 2) ^ (*state >> 4)) & 1;
  *state = (*state >> 1) | (bit << 63);
  return (unsigned char)((*state ^ (*state >> 32) ^ (*state >> 16)) & 0xFF);
}

// XOR each byte of data with a key byte from the LFSR
// the cool thing about XOR is that doing it twice gives you back the original
// so this same function works for both encrypting and decrypting
void encrypt_decrypt(char* password, char* data, size_t len){
  unsigned long long state = password_In_Number(password);
  for(size_t i = 0; i < len; i++)
      data[i] ^= lfsr_step(&state);
}

// pack the password string into a single 64-bit number so the LFSR has a seed
// just shifts each character into the number 8 bits at a time
// stops early if the password is shorter than PASS_SIZE
unsigned long long password_In_Number(char* password){
  unsigned long long pass = 0;
  for(int i = 0; i < PASS_SIZE; i++){
      if(password[i] == '\0') break;
      pass <<= 8;
      pass |= (unsigned char)password[i];
  }
  return pass;
}

// just tries to open the file, if it works the file exists, close it and return true
bool check_If_File_Exists(const char* filename){
  FILE* f = fopen(filename, "rb");
  if(f){ fclose(f); return true; }
  return false;
}

// we don't know how big of a string the user wants to enter so I found this code online
// which acts like some kind of vector, bigger the input string becomes,
// bigger the char array becomes also
// I found it here:
//     https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
char* inputString(FILE* fp, size_t size){
  char* str = malloc(size);
  if(!str) return NULL;
  size_t len = 0;
  int ch;
  while((ch = fgetc(fp)) != EOF && ch != '\n'){
      str[len++] = (char)ch;
      if(len >= size){
          size += 16;
          char* tmp = realloc(str, size);
          if(!tmp){ free(str); return NULL; }
          str = tmp;
      }
  }
  str[len] = '\0';
  return str;
}

// first time the program runs there's no password.txt yet
// so we ask the user to pick a password, make them type it twice to avoid typos
// then encrypt the password with itself and save the ciphertext to password.txt
// we also copy the plaintext into the password buffer so main can use it right away
void first_Time_Using(char* password){
  printf("Hello,\nThis is a password manager.\nPlease choose a password (up to %d characters):\n", PASS_SIZE);
  char p1[PASS_SIZE + 1];
  char p2[PASS_SIZE + 1];

  while(true){
      printf("Password: ");
      fgets(p1, sizeof(p1), stdin);
      p1[strcspn(p1, "\n")] = '\0';

      printf("Confirm password: ");
      fgets(p2, sizeof(p2), stdin);
      p2[strcspn(p2, "\n")] = '\0';

      if(strcmp(p1, p2) == 0) break;
      printf("Passwords do not match. Try again.\n");
  }

  strncpy(password, p1, PASS_SIZE);
  password[PASS_SIZE] = '\0';

  // encrypt the password with itself as the key, store ciphertext not plaintext
  // so even if someone opens password.txt they just see garbage bytes
  char cipher[PASS_SIZE] = {0};
  strncpy(cipher, p1, PASS_SIZE);
  encrypt_decrypt(p1, cipher, PASS_SIZE);

  FILE* f = fopen("password.txt", "wb");
  if(!f){ fprintf(stderr, "Error: could not create password.txt\n"); return; }
  fwrite(cipher, 1, PASS_SIZE, f);
  fclose(f);

  printf("Password set successfully.\n");
}

// password.txt exists so we need to verify the user knows the password
// we read the stored ciphertext, encrypt whatever they type with itself,
// and check if it matches -- same trick as first_Time_Using
// give them 3 tries before giving up
bool login(char* password){
  FILE* f = fopen("password.txt", "rb");
  if(!f){
    fprintf(stderr, "Error: password.txt not found.\n");
    return false; 
  }

  char stored[PASS_SIZE] = {0};
  if(fread(stored, 1, PASS_SIZE, f) != PASS_SIZE){
      fprintf(stderr, "Error: password.txt is corrupt.\n");
      fclose(f);
      return false;
  }
  fclose(f);

  int tries = 3;
  while(tries-- > 0){
      char attempt[PASS_SIZE + 1] = {0};
      printf("Enter password: ");
      fgets(attempt, sizeof(attempt), stdin);
      attempt[strcspn(attempt, "\n")] = '\0';

      char cipher[PASS_SIZE] = {0};
      strncpy(cipher, attempt, PASS_SIZE);
      encrypt_decrypt(attempt, cipher, PASS_SIZE);

      if(memcmp(cipher, stored, PASS_SIZE) == 0){
          strncpy(password, attempt, PASS_SIZE);
          password[PASS_SIZE] = '\0';
          printf("Access granted.\n");
          return true;
      }
      printf("Wrong password. %d attempt(s) left.\n", tries);
  }

  printf("Too many failed attempts.\n");
  return false;
}

// open encrypted.txt, read each line, decrypt it, print it
// the newline at the end of each line was never encrypted so we strip it first
// otherwise encrypt_decrypt would mangle the last character
void read_encrypted(char* pass){
  FILE* f = fopen("encrypted.txt", "rb");
  if(!f){ printf("(no entries yet)\n"); return; }

  char buf[256];
  int line = 1;
  while(fgets(buf, sizeof(buf), f)){
      size_t len = strlen(buf);
      if(len > 0 && buf[len - 1] == '\n'){
          buf[len - 1] = '\0';
          len--;
      }
      if(len == 0){ line++; continue; }

      encrypt_decrypt(pass, buf, len);
      printf("%d: %s\n", line++, buf);
  }
  fclose(f);
}

// ask how many strings, read them one by one, encrypt and append to encrypted.txt
// also print the hex so you can see it actually encrypted something
// then decrypt and print so you can verify it round-trips correctly
void write_encrypted(char* pass){
  int count = 0;
  printf("How many strings do you want to encrypt? ");
  scanf("%d", &count);
  getchar(); // scanf leaves a newline in the buffer, eat it before fgets runs

  for(int n = 0; n < count; n++){
      printf("input string %d: ", n + 1);
      char* string = inputString(stdin, 16);
      size_t len = strlen(string);

      encrypt_decrypt(pass, string, len);

      // write ciphertext first, then decrypt to show the user -- not the other way around
      FILE* f = fopen("encrypted.txt", "ab");
      fwrite(string, 1, len, f);
      fwrite("\n", 1, 1, f); // newline as a separator, not encrypted on purpose
      fclose(f);

      printf("encrypted (hex): ");
      for(size_t i = 0; i < len; i++)
          printf("%02x ", (unsigned char)string[i]);
      printf("\n");

      encrypt_decrypt(pass, string, len);
      printf("decrypted: %s\n", string);

      free(string);
  }
}
