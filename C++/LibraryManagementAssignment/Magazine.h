#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem{
private: 
  string type = "Magazine";
  int issueNumber;
  string publishMonth;
  double lateFee=0.3;
public:
  Magazine(int ID, string TITLE, string PUBLISHER, int PUBLICATION_YEAR, bool AVAILABILITY,int ISSUE_NUMBER, string PUBLISH_MONTH, double LATE_FEE) 
   : LibraryItem(ID, TITLE, PUBLISHER, PUBLICATION_YEAR, AVAILABILITY), issueNumber(ISSUE_NUMBER), publishMonth(PUBLISH_MONTH), lateFee(LATE_FEE) {}
  void display(ostream& o) const override;
  string get_Type() const override;
  double calculateLateFee(int overdueDays);
  void saveToFile(ofstream& out) const override;
  static unique_ptr<Magazine> loadFromLine(istringstream& iss);

};
#endif
