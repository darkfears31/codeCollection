#ifndef RESEARCHPAPER_H 
#define RESEARCHPAPER_H 
#include "LibraryItem.h"

class ResearchPaper : public LibraryItem{
private:
  string type = "Research Paper";
  string journalOrConference;
  string DOI;
  double lateFee=0.2;
public:
  ResearchPaper(int ID, string TITLE, string AUTHOR, int PUBLICATION_YEAR, bool AVAILABILITY,string JOURNAL_OR_CONFERENCE, string DO_I, double LATE_FEE) 
   : LibraryItem(ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABILITY), journalOrConference(JOURNAL_OR_CONFERENCE), DOI(DO_I), lateFee(LATE_FEE) {}
  void display(ostream& o) const override;
  string get_Type() const override;
  double calculateLateFee(int overdueDays);
  void saveToFile(ofstream& out) const override;
  static unique_ptr<ResearchPaper> loadFromLine(istringstream& iss);
};
#endif
