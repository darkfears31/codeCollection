#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "LibraryItem.h"
#include "DVD.h"
#include "Magazine.h"
#include "ResearchPaper.h"
#include "Book.h"

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <memory>
#include <chrono> // For real date marking
#include <ctime> // For real date marking

using namespace std;

class LibrarySystem{
private:
  map<int, unique_ptr<LibraryItem>> items;
public:
  LibrarySystem() = default;
  ~LibrarySystem() = default;
  // Creating New Objects and Adding it to vector.
  int displayForAdd();// Done
  unique_ptr<Book> createBook();// Done
  unique_ptr<DVD> createDVD();// Done
  unique_ptr<Magazine> createMagazine();// Done
  unique_ptr<ResearchPaper> create_Research_Paper();// Done
  int create_New_Objects_ID(int& ID); // Done
  void add(); // Done
  
  //Display
  void Display() const; // Done
  
  // Search and Display
  int choice_SearchWith() const ; // Done
  void searchWith_ID(int& ID) const; // Done   
  void searchWith_Title() const; // Done
  void searchWith_Author_Or_Creator() const; // Done
  void searchWith_Publication_Year() const; // Done
  void searchWith_Item_Type() const; // Done
  void search() const; // Done

  // Borrow - Return
  void borrow(); // Done
  LibraryItem* findItemByID(int ID) const;  // Done | Find item with ID, then return address of it.
  void returnItem(); // Done
  
  // Delete Item
  // first display it, if found delete.
  // function searchWith_ID() -- will be used.
  void removeByID(int targetID); // I will be for real, I didn't write this as I dont have full understanding of lambda functions, but we already went over lamba functions.
  void deleteItem(); // Done

  void sortVector(); // Done
  void saveToFile(); // Done
  void loadFromFile(); // Done
};

#endif 
