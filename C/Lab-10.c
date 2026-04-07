// Given names of function prototypes were matching with functions of "string.h" library so I had to modify the names.
// From this code, given on the link below, I learnt about 'memset()' which fills array with specific value.
// https://www.dropbox.com/scl/fi/f0qfi0figuhlpskpn08z9/donut_deobfuscated.c?rlkey=n5xig3ndm4kvjgh4zx0tv6qi3&e=4&dl=0 
#include <stdio.h>
#include <string.h>

int lab_strlen(char* s); // Given a string, return the number of characters in the string, NOT INCLUDING the null at the end.
char* lab_strcpy(char* dest, const char* src); // The function will copy the string src into the string dest. Note the function returns the address of the string dest.
char* lab_strcat(char* dest, const char* src); // The function concatenates the string src into the end of string dest.  If dest is "Hello " and src is "World" before, after calling strcat, dest will be "Hello World"

int main(void){

    char name[30], lastName[30], ID[11], dest1[30]="random sentence 1", dest2[50];
    memset(dest2, '\0', 50); // Initialize dest2 with null characters to ensure it starts empty.
    printf("Enter your first name: ");
    fgets(name, 30, stdin);
    printf("\nEnter your lastname: ");
    fgets(lastName, 30, stdin);
    printf("\nEnter your ID: ");
    fgets(ID, 11, stdin);
    
    int name_Length=0, lastName_Length=0;
    name_Length=lab_strlen(name);
    lastName_Length=lab_strlen(lastName);
    // 2 Examples:
    printf("\nSize of '%s' is %d characters\n", name, name_Length);
    printf("Size of '%s' is %d characters\n", lastName, lastName_Length);

    // Example of strcpy, copying lastName to dest1.
    // First showing dest1 before copying, then copying lastName to dest1, and finally showing dest1 after copying.
    printf("Before strcpy, string dest1 = %s\n", dest1);
    lab_strcpy(dest1, lastName);
    printf("After strcpy copying lastname to dest1, string dest1 =%s\n", dest1);

    // Example of strcat, concatenating name, lastName and ID to dest2.
    lab_strcat(dest2, name);
    lab_strcat(dest2, lastName);
    lab_strcat(dest2, ID);
    printf("strcat:\n Hi %s\n", dest2);

    return 0;
}

int lab_strlen(char* s){
    int number_Of_Characters=0;
    for(int i=0;i<30;i++){
        // '\n' Messed up the output so I had to remove the newline - '\n' character.
        if(s[i]=='\n'){
            s[i]='\0';
            break;
        }
        number_Of_Characters++;
    }
    return number_Of_Characters;
}

char* lab_strcpy(char* dest, const char* src){
// 'memset()' will help me copy one string to another.
// With this 'memset()' given below I assinged '\0' to every position in array. So, array is filled with - '\0'.
    memset(dest, '\0', 30);
    for(int i=0;i<30;i++){
        dest[i]=src[i];
    }
    return dest;

}

char* lab_strcat(char* dest, const char* src){
    // To concatenate src to dest, I need to find the length of dest first, so that I can start concatenating from the end of dest and not overwrite existing characters in 'dest'.
    int dest_Length=strlen(dest);
    int j=0; // j is used to keep track of the index of 'src' while concatenating.
    for(int i=dest_Length;i<49; i++){  // dest2 is 50 chars, so i<49 to leave room for \0
        dest[i]=src[j];
        j++;
    }
    return dest;
}