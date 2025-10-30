//NOTICE: tasks.txt must be create beforehand, becacuse 'ifstream' can't create it and im too lazy to change the code.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;
void menu(int &firstChoice);
void readLineFromFile();
void addTasksToFile();
void delete_line();

int main(){
    int firstChoice1;
    menu(firstChoice1);
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    switch(firstChoice1){
        case 1:
        readLineFromFile();
        break;
        case 2:
        addTasksToFile();
        break;
        case 3:
        delete_line();
        break;
    }

    return 0;
}

void menu(int &firstChoice){ //'&' is a reference so its possible to use int in given function in main fucntion.
    cout<<"********MENU********"<<endl;
    cout<<"1. Read to-do task list."<<endl;
    cout<<"2. Add to-do task."<<endl;
    cout<<"3. Remove to-do task."<<endl;
    cin>>firstChoice;
}
void readLineFromFile(){
    ifstream toDoList("tasks.txt");
    if(toDoList.is_open()){
        string tasks;
        vector<string> taskList;

        while(getline(toDoList, tasks)){
            taskList.push_back(tasks);
        }
        toDoList.close();
        cout<<"Total Tasks: "<<taskList.size()<<endl;
        if(taskList.size()==0){
            char addTaskQuestion;
            cout<<"There are no tasks. Wish to add? (y/n): ";
            cin>>addTaskQuestion;
            if(addTaskQuestion=='y'||addTaskQuestion=='Y'){
                addTasksToFile();
            }
        }
        else{
        for (size_t index{ }; index<taskList.size(); index++ ){
            cout<<"Task#"<<index+1<<"-->"<<taskList[index]<<endl;
            }
        }
    }
    else{
        cout<<"couldn't open file."<<endl;
    }
}

void addTasksToFile(){
    char repeat;
    do{
    ofstream toDoList("tasks.txt", ios::app);
    string addTask;
    if(!toDoList){
        cout<<"Error.";
    }
    cout<<"Enter new Task:"<<endl;
    // Clear leftover newline from input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, addTask);
    toDoList<<addTask<<endl;
    cout<<"Text added."<<endl;
    toDoList.close();
    cout<<"Wish to add another task (y/n): ";
    cin>>repeat;
    }while(repeat=='y'||repeat=='Y');      
}

void delete_line()
{
    char repeat;
    do{
    // open file in read mode or in mode
    ifstream toDoList("tasks.txt");
    // open file in write mode or out mode
    ofstream listSwap("temp.txt", ofstream::out);
    int n;
    readLineFromFile();
    cout<<"\n\n\n";
    cout<<"Which line you want to delete? ";
    if (!(cin >> n) || n < 1) {
        cerr << "Invalid line number\n";
        return;
    }

    string line;
    int line_no = 1;
    bool wrote_any = false;
    while (getline(toDoList, line)) {
        if (line_no != n) {
            listSwap << line;
            // write newline for all but possibly the last line:
            if (!toDoList.eof()) listSwap << '\n';
            wrote_any = true;
        }
        line_no++;
    }
    
    listSwap.close();
    toDoList.close();

    // remove the original file
    remove("tasks.txt");

    // rename the file
    rename("temp.txt", "tasks.txt");
    cout<<"Wish to remove another task (y/n): ";
    cin>>repeat;
    }while(repeat=='y'||repeat=='Y');
}