#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <memory>
#include <chrono> // For real date marking
#include <ctime> // For real date marking
using namespace std;

// Saves borrower info.
struct BorrowInfo{
  string borrowerName;
  std::chrono::system_clock::time_point borrowDate; // Saves borrow date.
};

class LibraryItem {
private:
  BorrowInfo borrowInfo;
  int id;
  string title;
  string creator;
  int publicationYear;
  // IF we create object or add object it automatically means that it is available
  // borrowed object cannot be added in library (In Real Life)
  bool available=true;

public:
  LibraryItem(int ID, string TITLE, string CREATOR, int PUBLICATION_YEAR, bool AVAILABILITY){
    id=ID;
    title=TITLE;
    creator=CREATOR;
    publicationYear=PUBLICATION_YEAR;
    available = AVAILABILITY;
  }
  virtual ~LibraryItem() = default;

  // Getters

  // I decided not to make some functions pure virtual as
  // some functions do the same for different derived classes.
  // And I'm lazy to copy code into other classes.
  virtual int get_ID() const; // Done
  virtual string get_Title() const; // Done
  virtual string get_Author_OR_Creator() const; // Done
  virtual int get_Publication_Year() const; // Done
  virtual bool get_Availability() const; // Done

  // These functions will remain pure virtual
  virtual string get_Type() const = 0;
  virtual void display(ostream& o) const = 0;

  // Borrow - Return
  // Because for every item this function acts the same, it won't be pure virtual
  void borrowItem(const string& name); // Done
  int calculateOverdueDays(); // Done
  virtual double calculateLateFee(int overdueDays) = 0;
  void returnedItem(); // Done
  
  // Save To File
  virtual void saveToFile(ofstream& out) const = 0;
  

  // Done
  bool operator<(const LibraryItem& other) const;   // I decided to compare items by availability, as reader only wants to see what books are available.
  bool operator==(const LibraryItem& other) const;  // compare by ID
};

ostream& operator<<(ostream& out, const LibraryItem& item); // Done

#endif
