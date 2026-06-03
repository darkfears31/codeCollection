#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"

class DVD : public LibraryItem{
private:
  string type = "DVD";
  int duration;
  string ageRating;
  double lateFee=1.0;
public:
  DVD(int ID, string TITLE, string DIRECTOR, int PUBLICATION_YEAR, bool AVAILABILITY,int DURATION, string AGE_RATING, double LATE_FEE) 
   : LibraryItem(ID, TITLE, DIRECTOR, PUBLICATION_YEAR, AVAILABILITY), duration(DURATION), ageRating(AGE_RATING), lateFee(LATE_FEE) {}
  void display(ostream& o) const override;
  string get_Type() const override;
  double calculateLateFee(int overdueDays);
  void saveToFile(ofstream& out) const override;
  static unique_ptr<DVD> loadFromLine(istringstream& iss);
};
#endif
