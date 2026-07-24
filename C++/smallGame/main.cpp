/* COMILE THIS CODE WITH "ncurses" -> g++ main.cpp -lncurses -o main */
#include <iostream>
#include "myFuncs.h"
funcs f;
using namespace std;

int main(){
    int ch;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    clear();
    //Display the map
    char (*map)[40] = f.spawnEnemiesAndPlayer();
    int currentRow=1; //Players current position on rows (y on y-axis)
    int currentColumn=1;//Players current position or columns (x on x-axis)
    int enemies=10; //Number of enemies, if it goes down another 1 enemy appears randomly to keep them 10 always.
    bool lost = false; // IF enemy kills player turns to true and stops the while loop.
    f.displayMap(map);

    printw("Press Q to exit.\n");
    printw("Press w/a/s/d to shoot.\n");
    printw("Press Arrow Keys to move.\n");
    while (!lost && (ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP: // Move Up
            map = f.moveUp(map,currentRow,currentColumn, lost);
            if(!lost) map = f.enemiesMovingRandomly(map, lost);
            break;

            case KEY_DOWN: // Move Down
            map = f.moveDown(map,currentRow, currentColumn, lost);
            if(!lost) map = f.enemiesMovingRandomly(map, lost);
            break;

            case KEY_RIGHT: // Move Right
            map = f.moveRight(map,currentRow, currentColumn, lost);
            if(!lost) map = f.enemiesMovingRandomly(map, lost);
            break;

            case KEY_LEFT: // Move Left
            map = f.moveLeft(map,currentRow, currentColumn, lost);
            if(!lost) map = f.enemiesMovingRandomly(map, lost);
            break;

            case 'd':
            map = f.shootRight(map, currentRow, currentColumn, enemies);
            break;

            case 'a':
            map = f.shootLeft(map, currentRow, currentColumn, enemies);
            break;

            case 'w':
            map = f.shootUp(map, currentRow, currentColumn, enemies);
            break;
            
            case 's':
            map = f.shootDown(map, currentRow, currentColumn, enemies);
            break;
        }
        if(enemies<10) map=f.spawnOneEnemy(map, enemies);
    }
    return 0;
}