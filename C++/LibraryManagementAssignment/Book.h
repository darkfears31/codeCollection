#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem{
private:
  string type = "Book";
  int pages;
  string genre;
  double lateFee=0.5;
public:
  Book(int ID, string TITLE, string AUTHOR, int PUBLICATION_YEAR, bool AVAILABILITY, int PAGES, string GENRE, double LATE_FEE) 
   : LibraryItem(ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABILITY), pages(PAGES), genre(GENRE), lateFee(LATE_FEE) {}
  void display(ostream& o) const override; // Done
  string get_Type() const override; // Done
  double calculateLateFee(int overdueDays); // Done
  void saveToFile(ofstream& out) const override;
  static unique_ptr<Book> loadFromLine(istringstream& iss);
};
#endif
