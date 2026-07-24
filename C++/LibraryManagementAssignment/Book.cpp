#include "Book.h"

void Book::display(ostream& o) const{
  o<<'['<<type<<']'<<endl;
  o<<"ID: "<<get_ID()<<endl;
  o<<"Title: "<<get_Title()<<endl;
  o<<"Author: "<<get_Author_OR_Creator()<<endl;
  o<<"Year: "<<get_Publication_Year()<<endl;
  o<<"Pages: "<<pages<<endl;
  o<<"Genre: "<<genre<<endl;
  o<<"Status: "<<(get_Availability() ? "Available" : "Not Available")<<endl;
  o<<"Late Fee Per Day: "<<lateFee<<" Gel"<<endl;
}

string Book::get_Type() const{
  return type;
}

double Book::calculateLateFee(int overdueDays){
  return overdueDays * lateFee;
}

void Book::saveToFile(ofstream& out) const{
  out<<type<<'|'<<get_ID()<<'|'<<get_Title()<<'|'<<get_Author_OR_Creator()<<'|'<<
    get_Publication_Year()<<'|'<<pages<<'|'<<genre<<'|'<<
      get_Availability()<<'|'<<lateFee<<endl;
}

unique_ptr<Book> Book::loadFromLine(istringstream& iss){
  // As we know 'iss' is a whole line 
  // IF title is bigger than one word typical iss>>TITLE>>AUTHOR won't work so we
  // have to use delimeter, in this example '|', and getline, read line until '|'
  // getline reads everything as string so we have to convert that string to integer or double 
  // for that I found - stoi() - pretty usable
  string ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABILITY, PAGES, GENRE, LATE_FEE;
  getline(iss, ID,'|');
  getline(iss, TITLE,'|');
  getline(iss, AUTHOR,'|');
  getline(iss, PUBLICATION_YEAR,'|');
  getline(iss, PAGES,'|');
  getline(iss, GENRE,'|');
  getline(iss, AVAILABILITY,'|');
  getline(iss, LATE_FEE);
  return make_unique<Book>(stoi(ID), TITLE, AUTHOR, stoi(PUBLICATION_YEAR), stoi(AVAILABILITY), stoi(PAGES), GENRE, stod(LATE_FEE)); 
}
