#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int randomWord = rand() % 505+1;
    char word[9], userInput[9];
    FILE *fptr;
    if((fptr=fopen("words.txt","r"))==NULL){
        printf("Can't open file.");
        return -1;
    }
    for(int i=0;i<randomWord;i++){
        fgets(word, sizeof(word), fptr);
    }
    int len = strlen(word);
    fclose(fptr);
    word[strcspn(word, "\n")] = '\0';
    printf("Enter Word: ");
    scanf("%8s", userInput);
    while(strcmp(userInput, word)!=0){
        char matching[9];
        for(int i=0;i<len;i++){
            if(userInput[i]==word[i]){
                matching[i]=userInput[i];
            }
            else{
                matching[i]='_';
            }
        }
        matching[len]='\0';
        printf("\n\nMatched: \n%s\n", matching);
        printf("Enter Another Word: ");
        scanf("%s", &userInput);
    }
    printf("\nCorrect word: %s\n", word);
    return 0;
}