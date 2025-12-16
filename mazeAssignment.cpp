#include <iostream>
#include <vector> // To save Movements
#include <cstdlib>
#include <ctime>
using namespace std;

int menu(int &choice);
void changeMazeSize(int &height, int &width);
void pathHistory(vector<char> movements);

int main(){
    int height = 5, width = 5, choice; // rows = height, cols = width
    vector<char> movements; // To save Movements
    
    // shared maze grid so other functions can inspect current position
    vector<vector<char>> arr(height, vector<char>(width, '.')); //After consultation with AI

    do{
        menu(choice);
        cout<<endl;
        switch(choice){
            case 1: { // generate maze  (Ajapsandalia, mapatiet)
                
                // make every cell of array '.')
                arr.assign(height, vector<char>(width, '.'));

                // Maze generation using a simple division-like pattern
                srand(time(NULL));
                if(height>=5 && width>=5){ //Had much greater algortihm for maze but gave errors.
                    // Draw horizontal walls on every other inner row
                    for(int i=0;i<height;i+=2){
                        for(int j=0;j<width;j++){
                            int randomHole = rand() % (width-2) + 1; // Random hole position
                            arr[i][j]='1'; // Wall
                            arr[i][randomHole]='.'; // Hole
                        }

                    }
                }

                // Start and End
                if (height>2 && width>2) {
                    arr[1][1]='X';
                    arr[height-2][width-2]='E';
                }

                //Outer walls
                for (int i=0;i<height; i++){
                    for (int j=0;j<width;j++){
                        if (i==0 || i==height-1 || j==0 || j==width-1) arr[i][j] = '1';
                    }
                }
                
                // Print the generated maze    
                for (auto& row : arr) {
                        for (auto& col : row) {
                        cout << col<<" ";
                    }
                    cout << endl;
                    }
//--------------------------------------------------------------------------------------------------------------             
                //Moving part
                char move;
                int currentRow = 1; // position of player at the start
                int currentCol = 1; // position of player at the start
                cout<<"Enter move direction (W/A/S/D) or 'Q' to go back to Menu: ";
                do{
                    while(!(cin>>move) || (move!='W' && move!='A' && move!='S' && move!='D' && move!='Q' && move!='w' && move!='a' && move!='s' && move!='d' && move!='q')){
                        cout<<"Invalid input, Please enter W/A/S/D or Q."<<endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        }
                    if(move=='w' || move=='W'){
                        if(arr[currentRow-1][currentCol]=='.'){ // Check for wall
                            swap(arr[currentRow][currentCol], arr[currentRow-1][currentCol]);
                            currentRow--;
                            movements.push_back(move); // Save movement
                        }
                        else if(arr[currentRow-1][currentCol]=='E'){ // Check for end
                            //swap(arr[currentRow][currentCol], arr[currentRow-1][currentCol]);
                            currentRow--;
                            movements.push_back(move); // Save movement
                            cout<<"Congratulations! You've reached the end of the maze!"<<endl;
                            break; // Exit the loop upon reaching 'E'
                        }
                        else{
                            cout<<"You've hit a wall. Try a different direction."<<endl;
                        }
                    }
                    else if(move=='a' || move=='A'){
                        if(arr[currentRow][currentCol-1]=='.'){ // Check for wall
                            swap(arr[currentRow][currentCol], arr[currentRow][currentCol-1]);
                            currentCol--;
                            movements.push_back(move); // Save movement
                        }
                        else if(arr[currentRow][currentCol-1]=='E'){ // Check for end
                            //swap(arr[currentRow][currentCol], arr[currentRow][currentCol-1]);
                            currentCol--;
                            movements.push_back(move); // Save movement
                            cout<<"Congratulations! You've reached the end of the maze!"<<endl;
                            break; // Exit the loop upon reaching 'E'
                        }
                        else{
                            cout<<"You've hit a wall. Try a different direction."<<endl;
                        }
                    }
                    else if(move=='s' || move=='S'){
                        if(arr[currentRow+1][currentCol]=='.'){ // Check for wall
                            swap(arr[currentRow][currentCol], arr[currentRow+1][currentCol]);
                            currentRow++;
                            movements.push_back(move); // Save movement
                        }
                        else if(arr[currentRow+1][currentCol]=='E'){ // Check for end
                            //swap(arr[currentRow][currentCol], arr[currentRow+1][currentCol]);
                            currentRow++;
                            movements.push_back(move); // Save movement
                            cout<<"Congratulations! You've reached the end of the maze!"<<endl;
                            break; // Exit the loop upon reaching 'E'
                        }
                        else{
                            cout<<"You've hit a wall. Try a different direction."<<endl;
                        }
                    }
                    else if(move=='d' || move=='D'){
                        if(arr[currentRow][currentCol+1]=='.'){ // Check for wall
                            swap(arr[currentRow][currentCol], arr[currentRow][currentCol+1]);
                            currentCol++;
                            movements.push_back(move); // Save movement
                        }
                        else if(arr[currentRow][currentCol+1]=='E'){ // Check for end
                            //swap(arr[currentRow][currentCol], arr[currentRow][currentCol+1]);
                            currentCol++;
                            movements.push_back(move); // Save movement
                            cout<<"Congratulations! You've reached the end of the maze!"<<endl;
                            break; // Exit the loop upon reaching 'E'
                        }
                        else{
                            cout<<"You've hit a wall. Try a different direction."<<endl;
                        }
                    }
                // Print after player move    
                for (auto& row : arr) {
                        for (auto& col : row) {
                        cout << col<<" ";
                    }
                    cout << endl;
                    }
                }while(move!='Q' && move!='q'); // If Q is pressed, exit to menu
                cout<<endl;


                break;
            }
            case 2:
                changeMazeSize(height, width);
                // resize shared grid to match new dimensions (rows x cols)
                arr.assign(height, vector<char>(width, '.'));
                break;
            case 3: {
                bool found = false;
                for(int i=0;i<height && !found; i++){ // go over whole array to find 'X'
                    for(int j=0; j<width; j++){
                        if(arr[i][j]=='X'){
                            cout<<"Current Position: ("<<i<<","<<j<<")"<<endl;
                            found = true; // when found break both loops
                            break;
                        }
                    }
                }
                if(!found) cout << "Current Position: (not placed)" << endl;
                break;
            }
            case 4:
                pathHistory(movements);
                break;
            case 5:
                break;
        }
    } while(choice != 5);

    return 0;
}



int menu(int &choice){
    cout<<"1. Generate New Maze."<<endl;
    cout<<"2. Change Maze Size."<<endl;
    cout<<"3. Show Current Position."<<endl;
    cout<<"4. Show Path History."<<endl;
    cout<<"5. Quit."<<endl;
    while(!(cin>>choice) || choice<1 || choice>5){
        cout<<"Invalid input, Please enter number from 1 to 5."<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return choice;
}

void changeMazeSize(int &height, int &width){
    //Validation
    cout<<"Height (1-20): ";
    while(!(cin>>height) || height<1 || height>20){
        cout<<"Invalid input, Please enter number from 1 to 20."<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    //Validation
    cout<<"Width (1-20): ";
    while(!(cin>>width) || width<1 || width>20){
        cout<<"Invalid input, Please enter number from 1 to 20."<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void pathHistory(vector<char> movements){
    cout<<"Path History: ";
    for(char move : movements){
        cout<<move<<" ";
    }
    cout<<endl;
}