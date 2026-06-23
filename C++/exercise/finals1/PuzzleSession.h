#ifndef PUZZLESESSION_H
#define PUZZLESESSION_H

#include "GameSession.h"

class PuzzleSession : public GameSession{
private:
  int levelsCompleted;
  int hintsUsed;
public:
  ~PuzzleSession() = default;
  PuzzleSession() = default;
  PuzzleSession(string playerID, string gameName, int duration, int score, double accuracy, long timeStamp, int levelsCompleted, int hintsUsed) : GameSession(playerID,gameName,duration,score,accuracy,timeStamp){
    this->levelsCompleted=levelsCompleted;
    this->hintsUsed=hintsUsed;
  }
  void display(ostream& o) const override;
  void read(istream& i) override;
  double calculateRating() const override;
  string getGameType() const override { return "PUZZLE"; }
};

#endif
