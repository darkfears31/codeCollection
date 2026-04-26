#include <stdio.h>
// Function Prototypes
void fillPlayerArray(int* jerseyNums, int* ratingNums, int size);
void addJerseyNums(int* jerseyNums, int position, int playerJersey);
void addRatingNums(int* ratingNums, int position, int playerRating);
void displayPlayers(int* jerseyNums, int* ratingNums, int size);
void displayPlayer(int* jerseyNums, int* ratingNums, int position);
void displayMenu();
char chooseMenuOption();
void updatePlayerRating(int* jerseyNums, int* ratingNums, int size);
void outputPlayersAboveRating(int* jerseyNums, int* ratingNums, int size);
void replacePlayer(int* jerseyNums, int* ratingNums, int size);

int main(void){
  // Moved playerJersy and playerRating into functions.
  const int NUM_PLAYERS=5;
  int jerseyNums[NUM_PLAYERS];
  int ratingNums[NUM_PLAYERS];
  // Call fillPlayerArray to create players
  fillPlayerArray(jerseyNums, ratingNums, NUM_PLAYERS);
  // Call displayPlayers to display players info
  displayPlayers(jerseyNums, ratingNums, NUM_PLAYERS);
  printf("\n");
  // Displaying menu, for which I used do while loop. 
  // Loop continues until menuOp becomes 'q'. 
  char menuOp;
  do {
    //Display menu 
      displayMenu();
    // Choose menu option 
      menuOp = chooseMenuOption();
      switch(menuOp){
          case 'u':
              // As name suggests it updates player rating based on their jersey number.
              updatePlayerRating(jerseyNums, ratingNums, NUM_PLAYERS);
              break;
          case 'a':
              // Outputs player if their rating is above certaing number, which is provided by user.
              outputPlayersAboveRating(jerseyNums, ratingNums, NUM_PLAYERS);
              break;
          case 'r':
              // Replaces player.
              replacePlayer(jerseyNums, ratingNums, NUM_PLAYERS);
              break;
          case 'o':
              // Displays all the players
              displayPlayers(jerseyNums, ratingNums, NUM_PLAYERS);
              break;
      }
  } while(menuOp != 'q');
  return 0;
}

// uses for loop to fill the arrays. 
// Function calls addJerseyNums() and addRatingNums(), which populate arrays.
void fillPlayerArray(int* jerseyNums, int* ratingNums, int size){
  for(int i=0;i<size;i++){
    int playerJersey=0, playerRating=0;
    printf("\nEnter Player %d's Jersey Number:\n", i+1);
    scanf("%d", &playerJersey);

    printf("Enter Player %d's Rating:\n", i+1);
    scanf("%d", &playerRating);
    
    addJerseyNums(jerseyNums, i, playerJersey);
    addRatingNums(ratingNums, i, playerRating);
  }
}

// Uses position to determine where jersey number of player should be put.
void addJerseyNums(int* jerseyNums, int position, int playerJersey){
  jerseyNums[position]=playerJersey;
}
// Uses position to determine where rating of a player should be put.
void addRatingNums(int* ratingNums, int position, int playerRating){
  ratingNums[position]=playerRating;
}
// Displays all the players using for loop.
// Calls displayPlayer() to display each player.
void displayPlayers(int* jerseyNums, int* ratingNums, int size){
  for(int i=0;i<size;i++){
    displayPlayer(jerseyNums, ratingNums, i);
  }
}

// Takes position from the caller function and uses it to determine which player info to show.
void displayPlayer(int* jerseyNums, int* ratingNums, int position){
  printf("Player %d -- Jersey Number: %d, Rating: %d\n", position+1, jerseyNums[position], ratingNums[position]);
}

// Displays menu.
void displayMenu(){
  printf("u - Update player rating\n");
  printf("a - Output players above a rating\n");
  printf("r - Replace player\n");
  printf("o - Output roster\n");
  printf("q - Quit\n");
}

// User chooses which menu option to choose, by inputting character, and function returns that character.
char chooseMenuOption(){
  char option;
  printf("Choose an Option: ");
  scanf(" %c", &option);
  return option;
}

// Takes number given by user and searches matching jersey number in jerseyNums array.
// If matching jersey number is found, user is told to provide new rating for the player.
// which is then inputted to corresponding place in the ratingNums array.
// If player is found for loop is stopped to avoid extra runtime.
void updatePlayerRating(int* jerseyNums, int* ratingNums, int size){
  int jerseyNumberOfPlayer;
  printf("Enter a Jersey Number:\n");
  scanf("%d", &jerseyNumberOfPlayer);
  for(int i=0;i<size;i++){
    if(jerseyNumberOfPlayer==jerseyNums[i]){
      int newRating;
      printf("Enter New Rating For Player:\n");
      scanf("%d", &newRating);
      ratingNums[i]=newRating;
      break;
    }
  }
}

// Takes rating from the user and uses for loop to compare all the rating to it.
// If rating from ratingNums array is greater than user given rating it displays the player.
void outputPlayersAboveRating(int* jerseyNums, int* ratingNums, int size){
  int rating;
  printf("Enter Rating:\n");
  scanf("%d", &rating);
  for(int i=0;i<size;i++){
    if(ratingNums[i]>rating){
      displayPlayer(jerseyNums, ratingNums, i);
    }
  }
  printf("\n");
}

// Searches player with jersey number given by user,
// If found it tells user to provide new jersey number and rating for player and overwrites all the values in the arrays.
// If player is found for loop is stopped to avoid extra runtime.
void replacePlayer(int* jerseyNums, int* ratingNums, int size){
  int jerseyNumberOfPlayer;
  printf("Enter a Jersey Number:\n");
  scanf("%d", &jerseyNumberOfPlayer);
  for(int i=0;i<size;i++){
    if(jerseyNumberOfPlayer==jerseyNums[i]){
      int newJerseyNumber, newRating;
      printf("Enter New Jersey Number:\n");
      scanf("%d", &newJerseyNumber);
      jerseyNums[i]=newJerseyNumber;
      printf("Enter New Rating For Player:\n");
      scanf("%d", &newRating);
      ratingNums[i]=newRating;
      break;
    }
  }
}
