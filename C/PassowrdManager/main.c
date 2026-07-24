// Encryption/Decryption using 64bit LFSR.
#include <stdio.h>

int main(){
  char s[] = "labalaba";
  char en[] = "Im here. HAHAHAHA get me.";
  char de[20];
  unsigned long long num = 0, num1=0, num2=0;
  // seed
  for (int i = 0; i < 8; i++){
      num = (num << 8) | s[i];
  }

  printf("encrypted:\n");
  // ENCRYPT
  for (int i = 0; en[i] != '\0'; i++){
      unsigned long long bit = ((num >> 0) ^ (num >> 1) ^ (num >> 2) ^ (num >> 4)) & 1;
      num = (num >> 1) | (bit << 63);

      if (i % 2 == 0) num2 = num;
      else num1 = num;
      unsigned long long key = (num1 + num2) & 0xFF;
      char encrypted = en[i] ^ key;
      printf("%c", encrypted);
      de[i] = encrypted;
  }

  printf("decrypted:\n");
  // RESET STATE
  num = 0;
  for (int i = 0; i < 8; i++){
      num = (num << 8) | s[i];
  }
  num1 = num2 = 0;

  // DECRYPT
  for (int i = 0; de[i] != '\0'; i++){
      unsigned long long bit = ((num >> 0) ^ (num >> 1) ^ (num >> 2) ^ (num >> 4)) & 1;
      num = (num >> 1) | (bit << 63);
      if (i % 2 == 0) num2 = num;
      else num1 = num;

      unsigned long long key = (num1 + num2) & 0xFF;
      char decrypted = de[i] ^ key;
      printf("%c", decrypted);
  }
  return 0;
}
