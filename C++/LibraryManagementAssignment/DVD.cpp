#include "DVD.h"

void DVD::display(ostream& o) const{
  o<<'['<<type<<']'<<endl;
  o<<"ID: "<<get_ID()<<endl;
  o<<"Title: "<<get_Title()<<endl;
  o<<"Director: "<<get_Author_OR_Creator()<<endl;
  o<<"Year: "<<get_Publication_Year()<<endl;
  o<<"Duration: "<<duration<<endl;
  o<<"Age Rating: "<<ageRating<<endl;
  o<<"Status: "<<(get_Availability() ? "Available" : "Not Available")<<endl;
  o<<"Late Fee Per Day: "<<lateFee<<" Gel"<<endl;
}

string DVD::get_Type() const{
  return type;
}

double DVD::calculateLateFee(int overdueDays){
  return overdueDays * lateFee;
}

void DVD::saveToFile(ofstream& out) const{
  out<<type<<'|'<<get_ID()<<'|'<<get_Title()<<'|'<<get_Author_OR_Creator()<<'|'<<
    get_Publication_Year()<<'|'<<duration<<'|'<<ageRating<<'|'<<
      get_Availability()<<'|'<<lateFee<<endl;
}

unique_ptr<DVD> DVD::loadFromLine(istringstream& iss){
  // As we know 'iss' is a whole line 
  // IF title is bigger than one word typical iss>>TITLE>>AUTHOR won't work so we
  // have to use delimeter, in this example '|', and getline, read line until '|'
  // getline reads everything as string so we have to convert that string to integer or double 
  // for that I found - stoi() - pretty usable
  string ID, TITLE, DIRECTOR, PUBLICATION_YEAR, AVAILABILITY, DURATION, AGE_RATING, LATE_FEE;
    getline(iss, ID,'|');
    getline(iss, TITLE,'|');
    getline(iss, DIRECTOR,'|');
    getline(iss, PUBLICATION_YEAR,'|');
    getline(iss, DURATION,'|');
    getline(iss, AGE_RATING,'|');
    getline(iss, AVAILABILITY,'|');
    getline(iss, LATE_FEE);
  return make_unique<DVD>(stoi(ID), TITLE, DIRECTOR, stoi(PUBLICATION_YEAR), stoi(AVAILABILITY), stoi(DURATION), AGE_RATING, stod(LATE_FEE)); 
}
