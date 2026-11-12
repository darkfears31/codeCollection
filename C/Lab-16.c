#include <stdio.h>
#include <string.h>

static int permCount=0;

void RemoveFromIndex(char* origString, int remLoc); 
void InsertAtIndex(char* origString, char* addChar, int addLoc);   
void PermuteString(char* remainLetters, char* permutedLetters) {    
  char tmpString[2];   
  int i; 
  tmpString[1] = '\0';  
  if (strlen(remainLetters) == 0) {            // Base case: All letters used
    permCount++;
    printf("%d: %s\n", permCount, permutedLetters);
  }
  else{
    // Reversed For loop as told
    for(i = strlen(remainLetters)-1; i >= 0; --i){
        tmpString[0] = remainLetters[i];
        strcat(permutedLetters, tmpString);
        RemoveFromIndex(remainLetters, i);
        PermuteString(remainLetters, permutedLetters);
        // Put letter back in remaining letters
        permutedLetters[strlen(permutedLetters) - 1] = '\0';
        InsertAtIndex(remainLetters, tmpString, i);
    }
  }
}

int main(void) {
  char wordToPermute[50]; // User defined word to permute. 
  char finishPermute[50]; // Temp string already permuted. 
  
  printf("Enter a word to permute: ");
  scanf("%s", wordToPermute);
  finishPermute[0] = '\0';
  // Recursively output all the permutations
  PermuteString(wordToPermute, finishPermute);
  // Output total permutations
  printf("\nTotal permutations: %d\n", permCount);
  
  return 0;
}

// Remove letter at location remLoc from string origString
void RemoveFromIndex(char* origString, int remLoc) {

  for(int i=remLoc;i<strlen(origString)-1;i++){
    origString[i] = origString[i+1];
  }
  origString[strlen(origString)-1] = '\0';

}

// Add letter addChar to location addLoc of string origString
void InsertAtIndex(char* origString, char* addChar, int addLoc) {

  for(int i=strlen(origString);i>addLoc;i--){
    origString[i]=origString[i-1];
  }
  origString[addLoc] = addChar[0];
  origString[strlen(origString)+1] = '\0';

}

