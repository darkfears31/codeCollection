#include "LibrarySystem.h"
#include <iostream>
using namespace std;

int main() {
  LibrarySystem library;
  int choice;
  do {

    cout << "\n=== Library System ===\n";
    cout << "1. Add Item\n";
    cout << "2. Display All\n";
    cout << "3. Search\n";
    cout << "4. Borrow Item\n";
    cout << "5. Return Item\n";
    cout << "6. Delete Item\n";
    cout << "7. Save\n";
    cout << "8. Load From File\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
    cin >> choice;
    if(cin.fail()){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Invalid Choice.\n";
      continue;
    }
    cin.ignore();
    cout<<'\n';
    switch (choice) {
      case 1: 
        library.add();
        break;
      case 2:
        library.Display();
        break;
      case 3:
        library.search();
        break;
      case 4:
        library.borrow();
        break;
      case 5:
        library.returnItem();
        break;
      case 6:
        library.deleteItem();
        break;
      case 7:
        library.saveToFile();
        break;
      case 8:
        library.loadFromFile();
        break;
      case 0:
        cout << "Exiting...\n";
        break;
      default: cout << "Invalid choice.\n";
    }
  } while (choice != 0);
  return 0;
}
