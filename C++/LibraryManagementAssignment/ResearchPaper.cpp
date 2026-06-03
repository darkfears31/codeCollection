#include "ResearchPaper.h"

void ResearchPaper::display(ostream& o) const{
  o<<'['<<type<<']'<<endl;
  o<<"ID: "<<get_ID()<<endl;
  o<<"Title: "<<get_Title()<<endl;
  o<<"Author: "<<get_Author_OR_Creator()<<endl;
  o<<"Year: "<<get_Publication_Year()<<endl;
  o<<"Journal or Conference: "<<journalOrConference<<endl;
  o<<"DOI: "<<DOI<<endl;
  o<<"Status: "<<(get_Availability() ? "Available" : "Not Available")<<endl;
  o<<"Late Fee Per Day: "<<lateFee<<" Gel"<<endl;
}

string ResearchPaper::get_Type() const{
  return type;
}

double ResearchPaper::calculateLateFee(int overdueDays){
  return overdueDays * lateFee;
}

void ResearchPaper::saveToFile(ofstream& out) const{
  out<<type<<'|'<<get_ID()<<'|'<<get_Title()<<'|'<<get_Author_OR_Creator()<<'|'<<
    get_Publication_Year()<<'|'<<journalOrConference<<'|'<<DOI<<'|'<<
      get_Availability()<<'|'<<lateFee<<endl;
}

unique_ptr<ResearchPaper> ResearchPaper::loadFromLine(istringstream& iss){
  // As we know 'iss' is a whole line 
  // IF title is bigger than one word typical iss>>TITLE>>AUTHOR won't work so we
  // have to use delimeter, in this example '|', and getline, read line until '|'
  // getline reads everything as string so we have to convert that string to integer or double 
  // for that I found - stoi() - pretty usable
  string ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABILITY, JOURNAL_OR_CONFERENCE, DO_I, LATE_FEE;
  getline(iss, ID,'|');
  getline(iss, TITLE,'|');
  getline(iss, AUTHOR,'|');
  getline(iss, PUBLICATION_YEAR,'|');
  getline(iss, JOURNAL_OR_CONFERENCE,'|');
  getline(iss, DO_I,'|');
  getline(iss, AVAILABILITY,'|');
  getline(iss, LATE_FEE);
  return make_unique<ResearchPaper>(stoi(ID), TITLE, AUTHOR, stoi(PUBLICATION_YEAR), stoi(AVAILABILITY), JOURNAL_OR_CONFERENCE, DO_I, stod(LATE_FEE)); 
}
