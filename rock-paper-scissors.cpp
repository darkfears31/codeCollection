#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    cout << "This is a simple Tic-Tac-Toe game!" << endl;
    cout << "Press Enter to continue!" << endl;
    cin.get(); //wait for user input to continue
    cout << "In this game you will be playing against the computer." << endl;
    cin.get(); //wait for user input to continue
    char PlayAgainOrNot;
    bool Playing = true;
    while (Playing){
//Must learn from here
    // Seed the random number generator
    srand(time(0));
    // Generate a number between 1 and 3
    int randomNumber = 1 + (rand() % 3);
//To here
    cout << "Choose what you will play, with number 1, 2 or 3" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl; 
    cout << "3. Scissors" << endl;  
    int UserChoice;
    cin >> UserChoice; 
// Game logic
    if (UserChoice == 1 && randomNumber == 2){
        cout << "low lvl!" << endl;
        system("mpg123 /home/kaikaci/Downloads/pt-nWord.mp3");
    }
    else if (UserChoice == 2 && randomNumber == 3){
        cout << "BrokeAhh!" << endl;
        system("mpg123 /home/kaikaci/Downloads/pt-nWord.mp3");
    }
    else if (UserChoice == 3 && randomNumber == 1){
        cout << "dumbahh you lost!" << endl;
        system("mpg123 /home/kaikaci/Downloads/pt-nWord.mp3");
    }
    else if (UserChoice == randomNumber){
        cout << "It's a tie!" << endl;
    }
    else{
        cout << "You win!" << endl;
    }
//Game ends
    cout << "Do you want to play again? (Y/N)" << endl;
    cin >> PlayAgainOrNot;
    if (PlayAgainOrNot == 'Y' || PlayAgainOrNot == 'y'){
        Playing = true;
    }
    else {
        Playing = false;
        system("mpg123 /home/kaikaci/Downloads/trombone.mp3");
    }
 }
    return 0;
}