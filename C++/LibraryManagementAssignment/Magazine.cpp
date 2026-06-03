#include "Magazine.h"

void Magazine::display(ostream& o) const{
  o<<'['<<type<<']'<<endl;
  o<<"ID: "<<get_ID()<<endl;
  o<<"Title: "<<get_Title()<<endl;
  o<<"Publisher: "<<get_Author_OR_Creator()<<endl;
  o<<"Year: "<<get_Publication_Year()<<endl;
  o<<"Publish Month: "<<publishMonth<<endl;
  o<<"Issue Number: "<<issueNumber<<endl;
  o<<"Status: "<<(get_Availability() ? "Available" : "Not Available")<<endl;
  o<<"Late Fee Per Day: "<<lateFee<<" Gel"<<endl;
}

string Magazine::get_Type() const{
  return type;
}

double Magazine::calculateLateFee(int overdueDays){
  return overdueDays * lateFee;
}

void Magazine::saveToFile(ofstream& out) const{
  out<<type<<'|'<<get_ID()<<'|'<<get_Title()<<'|'<<get_Author_OR_Creator()<<'|'<<
    get_Publication_Year()<<'|'<<publishMonth<<'|'<<issueNumber<<'|'<<
      get_Availability()<<'|'<<lateFee<<endl;
}

unique_ptr<Magazine> Magazine::loadFromLine(istringstream& iss){
  // As we know 'iss' is a whole line 
  // IF title is bigger than one word typical iss>>TITLE>>AUTHOR won't work so we
  // have to use delimeter, in this example '|', and getline, read line until '|'
  // getline reads everything as string so we have to convert that string to integer or double 
  // for that I found - stoi() - pretty usable
  string ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABILITY, PUBLISH_MONTH, ISSUE_NUMBER, LATE_FEE;
  getline(iss, ID,'|');
  getline(iss, TITLE,'|');
  getline(iss, AUTHOR,'|');
  getline(iss, PUBLICATION_YEAR,'|');
  getline(iss, PUBLISH_MONTH,'|');
  getline(iss, ISSUE_NUMBER,'|');
  getline(iss, AVAILABILITY,'|');
  getline(iss, LATE_FEE);
  return make_unique<Magazine>(stoi(ID), TITLE, AUTHOR, stoi(PUBLICATION_YEAR), stoi(AVAILABILITY), stoi(ISSUE_NUMBER), PUBLISH_MONTH, stod(LATE_FEE)); 
}
