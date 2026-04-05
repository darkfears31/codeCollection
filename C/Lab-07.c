// Used ASCII table to find uppercase letters and then print it.
// Removed userAcronym[] character array as I don't understand what I should do with it.
#include <stdio.h>

void CreateAcronym(char userPhrase[]);

int main(void){

    char name[50];
    printf("Enter name to create acronym:\n");
    fgets(name, 50, stdin);
    printf("Acronym: \n");
    CreateAcronym(name);
    return 0;
}

void CreateAcronym(char userPhrase[]){
    for(int i=0;i<50;i++){
        if(userPhrase[i]>=65 && userPhrase[i]<=90){
            printf("%c", userPhrase[i]);
        }
    }
}