// To do this task I needed to remove non-alphabetic characters from sentence given by user.
// As we know every character has its unique code in ASCII table.
// For example character 'a' in decimal will be equal to 97.
// Character 'b' in decimal will be equal to 98.
// And so on. 
// According to this ASCII table given in this site: https://www.ascii-code.com/
// I implemented that logic into my code.
#include <stdio.h>

void RemoveNonAlpha(char userString[]);

int main(void){

    char sentence[50];
    printf("Enter a sentence:\n");
    fgets(sentence, 50, stdin);
    printf("After removing non alphabet characters: \n");
    RemoveNonAlpha(sentence);
    return 0;
}

// In the for loop given below, I converted every character of userString[] to decimal
// And wrote 'if' statement which checks:
// If characters ASCII value into decimal goes out of range.
// From the site we know that A-Z in decimals will be -> 65-90 and a-z -> 97-122.
// So I assign char_In_ASCII_Code character from the array, convert it to decimal and compare to given numbers.
// If decimal is out of the bounds program doesn't print, it skips the character.
// But if it is in the range, program shows the character.
void RemoveNonAlpha(char userString[]){
    int char_In_ASCII_Code=0;
    for(int i=0;i<50;i++){
        char_In_ASCII_Code=userString[i];
        if(char_In_ASCII_Code<65 || (char_In_ASCII_Code>90 && char_In_ASCII_Code<97) || char_In_ASCII_Code>122){
            continue;
        }
        else{
            printf("%c", userString[i]);
        }
    }
}
// I removed userStringAlphaOnly[] character array because, I didn't understood what it was used for.