#include <stdio.h>
#include <string.h>
// Function prototypes
int GetNumOfCharacters(const char usrStr[]);
void OutputWithoutWhitespace(char usrStr[]);

int main(void){

    char sentence[50];
    printf("Enter a sentence or phrase:\n");
    // As I found out gets() function is deprecated, unsafe to use and compiler won't compile it, I will be using fgets() instead.
    fgets(sentence, 50, stdin);
    printf("You entered: %s", sentence);
    int numberOfCharacters=GetNumOfCharacters(sentence);
    printf("Number of characters: %d\n", numberOfCharacters);
    OutputWithoutWhitespace(sentence);
    return 0;
}   


int GetNumOfCharacters(const char usrStr[]){
    int numberOfCharacters=0;
    // Loop through the string until the null terminator-'\0' is reached and return numberOfCharacters.
    for(int i=0;i<50;i++){
        if(usrStr[i]=='\0') break;
        numberOfCharacters++;
    }
    // Return numberOfCharacters-1 because the last character is the null terminator which is not counted as a character in the sentence.
    return numberOfCharacters-1;
}

void OutputWithoutWhitespace(char usrStr[]){
    // If the character is a whitespace, tab or newline, skip it and jump to next character. If not matched, print the character.
    for(int i=0;i<50;i++){
        if(usrStr[i]==' ' || usrStr[i]=='\t' || usrStr[i]=='\n') continue;
        printf("%c", usrStr[i]);
    }
}