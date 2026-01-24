#ifndef MYFUNCS_H
#define MYFUNCS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <random>
#include <time.h>
#include <ncurses.h> 
using namespace std;

class funcs{
    static char array[20][40]; //Array where everything starts.
    public:

    /* --------------MAP-----------------------------------------------------------------*/
    char (*map())[40]{ // i - row , j - column
        static char array[20][40];
        for(int i=0; i<20;i++){
            for(int j=0;j<40;j++){
                if(i==0 || i==19) array[i][j]='_';
                else if (j==0 || j==39) array[i][j]='|';
                else array[i][j] = ' ';
            }
        }
        return array;
    }
    void displayMap(char (*mapToDisplay)[40]){
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                printw("%c", mapToDisplay[i][j]);
            }
            printw("\n");
        }
        refresh();
        
    }
    /* --------------MAP----------------------------------------------------------------------*/

    /* --------------ENEMIES------------------------------------------------------------------*/
    char (*spawnEnemiesAndPlayer())[40]{
        srand(time(0));
        char (*arrayButWithEnemiesAndPlayer)[40] = map();
        for(int i=1;i<=10;i++){ // number of enemies to spawn.
            arrayButWithEnemiesAndPlayer[rand()%18+1][rand()%38+1] = 'O'; //O - enemy
        }
        arrayButWithEnemiesAndPlayer[1][1] = 'X'; //Spawn Player
        return arrayButWithEnemiesAndPlayer;
    }
    char (*spawnOneEnemy(char (*mapWithRestoredEnemies)[40], int& enemies))[40]{
        srand(time(0));
        //Spawn new enemy after one is killed.
        //New enemy mustn't spawn on top of another enemy or player.
        bool enemySpawned=false;
        int randomRow;
        int randomColumn;
        while(enemySpawned!=true){
            randomRow=rand()%18+1;
            randomColumn=rand()%38+1;
            if(mapWithRestoredEnemies[randomRow][randomColumn]!='O' && mapWithRestoredEnemies[randomRow][randomColumn]!='X'){
                enemySpawned=true;
                enemies++;
            }
        }
        mapWithRestoredEnemies[randomRow][randomColumn] = 'O'; //O - enemy, spawn one enemy.
        return mapWithRestoredEnemies;
    }
    char (*enemiesMovingRandomly(char (*mapAfterEnemiesMoving)[40], bool& lost))[40]{
        srand(time(0));
        for(int i=0;i<20;i++){
            for(int j=0;j<40;j++){
                if(mapAfterEnemiesMoving[i][j]=='O'){ //Detect if there is enemy
                    int row = i;
                    int column = j;
                    int randomMovingDirection; // Move in random direction.
                    bool enemyMoved=false; //Decide if enemy moved or not.
                    while(enemyMoved!=true){
                        randomMovingDirection = rand()%4+1;
                            switch(randomMovingDirection){
                                case 1:
                                if(row-1!=0){ //Can't go inside wall.
                                    swap(mapAfterEnemiesMoving[row][column], mapAfterEnemiesMoving[row-1][column]);
                                    enemyMoved = true; //To stop while loop.
                                }
                                break;

                                case 2:
                                if(row+1!=19){ //Can't go inside wall.
                                    swap(mapAfterEnemiesMoving[row][column], mapAfterEnemiesMoving[row+1][column]);
                                    enemyMoved = true; //To stop while loop.
                                }
                                break;
                                
                                case 3:
                                if(column-1!=0){ //Can't go inside wall.
                                    swap(mapAfterEnemiesMoving[row][column], mapAfterEnemiesMoving[row][column-1]);
                                    enemyMoved = true; //To stop while loop.
                                }
                                break;
                                
                                case 4:
                                if(column+1!=39){ //Can't go inside wall.
                                    swap(mapAfterEnemiesMoving[row][column], mapAfterEnemiesMoving[row][column+1]);
                                    enemyMoved = true; //To stop while loop.
                                }
                                break;
                                
                        }
                    }
                    clear();
                    displayMap(mapAfterEnemiesMoving);
                }
            }
        }
        return mapAfterEnemiesMoving;
    }
    /* --------------ENEMIES-------------------------------------------------------------------*/
    
    /* --------------MOVING---------------------------------------------------------------------*/
    char (*moveUp(char (*mapAfterMovingUp)[40],int& currentRow, int& currentColumn, bool& lost))[40]{
        if(currentRow-1==0) printw("Can't go there.\n"); //end of map or player.
        else if(mapAfterMovingUp[currentRow-1][currentColumn]=='O'){
            currentRow--;
            mapAfterMovingUp[currentRow][currentColumn] = 'O'; //Player got devoured by enemy.
            mapAfterMovingUp[currentRow+1][currentColumn]=' '; // To indicate that player moved.
            clear();
            displayMap(mapAfterMovingUp);
            printw("You've been devoured by an enemy!\n");
            lost = true;
        }
        else{
            currentRow--; 
            swap(mapAfterMovingUp[currentRow+1][currentColumn], mapAfterMovingUp[currentRow][currentColumn]);
            clear();
            displayMap(mapAfterMovingUp);
            printw("\nUp Arrow\n");
        }
        return mapAfterMovingUp;
    }
    char (*moveDown(char (*mapAfterMovingDown)[40],int& currentRow, int& currentColumn, bool& lost))[40]{
        if(currentRow+1==19) printw("Can't go there.\n"); //end of map or player.
        else if(mapAfterMovingDown[currentRow+1][currentColumn]=='O'){
            currentRow++;
            mapAfterMovingDown[currentRow][currentColumn] = 'O'; //Player got devoured by enemy.
            mapAfterMovingDown[currentRow-1][currentColumn]=' '; // To indicate that player moved.
            clear();
            displayMap(mapAfterMovingDown);
            printw("You've been devoured by an enemy!\n");
            lost = true;
        }
        else{   
            currentRow++; 
            swap(mapAfterMovingDown[currentRow-1][currentColumn], mapAfterMovingDown[currentRow][currentColumn]);
            clear();
            displayMap(mapAfterMovingDown);
            printw("\nUp Arrow\n");
        }
        return mapAfterMovingDown;
    }
    char (*moveRight(char (*mapAfterMovingRight)[40],int& currentRow, int& currentColumn, bool& lost))[40]{
        if(currentColumn+1==39) printw("Can't go there.\n"); //end of map or player.
        else if(mapAfterMovingRight[currentRow][currentColumn+1]=='O'){
            currentColumn++;
            mapAfterMovingRight[currentRow][currentColumn] = 'O'; //Player got devoured by enemy.
            mapAfterMovingRight[currentRow][currentColumn-1]=' '; // To indicate that player moved.
            clear();
            displayMap(mapAfterMovingRight);
            printw("You've been devoured by an enemy!\n");
            lost = true;
        }
        else{
            currentColumn++; 
            swap(mapAfterMovingRight[currentRow][currentColumn-1], mapAfterMovingRight[currentRow][currentColumn]);
            clear();
            displayMap(mapAfterMovingRight);
            printw("\nUp Arrow\n");
        }
        return mapAfterMovingRight;
    }
    char (*moveLeft(char (*mapAfterMovingLeft)[40],int& currentRow, int& currentColumn, bool& lost))[40]{
        if(currentColumn-1==0) printw("Can't go there.\n"); //end of map or player.
        else if(mapAfterMovingLeft[currentRow][currentColumn-1]=='O'){
            currentColumn--;
            mapAfterMovingLeft[currentRow][currentColumn] = 'O'; //Player got devoured by enemy.
            mapAfterMovingLeft[currentRow][currentColumn+1]=' '; // To indicate that player moved.
            clear();
            displayMap(mapAfterMovingLeft);
            printw("You've been devoured by an enemy!\n");
            lost = true;
        }
        else{
            currentColumn--; 
            swap(mapAfterMovingLeft[currentRow][currentColumn+1], mapAfterMovingLeft[currentRow][currentColumn]);
            clear();
            displayMap(mapAfterMovingLeft);
            printw("\nUp Arrow\n");
        }
        return mapAfterMovingLeft;
    }
    /* --------------MOVING----------------------------------------------------------------------*/

    /*---------------SHOOTING---------------------------------------------------------------------*/
    char (*shootRight(char (*shootRightMap)[40], int currentRow, int currentColumn, int& enemies))[40]{
        if(currentColumn==38) printw("Can't shoot a wall.\n");
        else{
            bool hitSomething = false; //IF bullet hits something it turns to true and loop is stopped.
            while(hitSomething!=true){
                currentColumn++;
                shootRightMap[currentRow][currentColumn]='-'; //Shoots from player position+1.
                if(currentColumn+1==39){
                    shootRightMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    hitSomething=true;
                }
                else if (shootRightMap[currentRow][currentColumn+1]=='O'){
                    shootRightMap[currentRow][currentColumn+1] = ' '; //bullet hits enemy it should dissapear
                    shootRightMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    enemies--;
                    hitSomething = true;
                }
                else{
                    swap(shootRightMap[currentRow][currentColumn], shootRightMap[currentRow][currentColumn+1]);
                }
                clear();
                displayMap(shootRightMap);
            }
        }
        return shootRightMap;
    }
    char (*shootLeft(char (*shootLeftMap)[40], int currentRow, int currentColumn, int& enemies))[40]{
        if(currentColumn==1) printw("Can't shoot a wall.\n");
        else{
            bool hitSomething = false; //IF bullet hits something it turns to true and loop is stopped.
            while(hitSomething!=true){
                currentColumn--;
                shootLeftMap[currentRow][currentColumn]='-'; //Shoots from player position+1.
                if(currentColumn-1==0){
                    shootLeftMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    hitSomething=true;
                }
                else if (shootLeftMap[currentRow][currentColumn-1]=='O'){
                    shootLeftMap[currentRow][currentColumn-1] = ' '; //bullet hits enemy it should dissapear
                    shootLeftMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    enemies--;
                    hitSomething = true;
                }
                else{
                    swap(shootLeftMap[currentRow][currentColumn], shootLeftMap[currentRow][currentColumn-1]);
                }
                clear();
                displayMap(shootLeftMap);
            }
        }
        return shootLeftMap;
    }
    char (*shootUp(char (*shootUpMap)[40], int currentRow, int currentColumn, int& enemies))[40]{
        if(currentRow==1) printw("Can't shoot a wall.\n");
        else{
            bool hitSomething = false; //IF bullet hits something it turns to true and loop is stopped.
            while(hitSomething!=true){
                currentRow--;
                shootUpMap[currentRow][currentColumn]='|'; //Shoots from player position+1.
                if(currentRow-1==0){
                    shootUpMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    hitSomething=true;
                }
                else if (shootUpMap[currentRow-1][currentColumn]=='O'){
                    shootUpMap[currentRow-1][currentColumn] = ' '; //bullet hits enemy it should dissapear
                    shootUpMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    enemies--;
                    hitSomething = true;
                }
                else{
                    swap(shootUpMap[currentRow][currentColumn], shootUpMap[currentRow-1][currentColumn]);
                }
                clear();
                displayMap(shootUpMap);
            }
        }
        return shootUpMap;
    }
    char (*shootDown(char (*shootDownMap)[40], int currentRow, int currentColumn, int& enemies))[40]{
        if(currentRow==19) printw("Can't shoot a wall.\n");
        else{
            bool hitSomething = false; //IF bullet hits something it turns to true and loop is stopped.
            while(hitSomething!=true){
                currentRow++;
                shootDownMap[currentRow][currentColumn]='|'; //Shoots from player position+1.
                if(currentRow+1==19){
                    shootDownMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    hitSomething=true;
                }
                else if (shootDownMap[currentRow+1][currentColumn]=='O'){
                    shootDownMap[currentRow+1][currentColumn] = ' '; //bullet hits enemy it should dissapear
                    shootDownMap[currentRow][currentColumn] = ' '; //bullet hits something it should dissapear
                    enemies--;
                    hitSomething = true;
                }
                else{
                    swap(shootDownMap[currentRow][currentColumn], shootDownMap[currentRow+1][currentColumn]);
                }
                clear();
                displayMap(shootDownMap);
            }
        }
        return shootDownMap;
    }
};



#endif