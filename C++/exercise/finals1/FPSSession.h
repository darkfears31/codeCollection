#ifndef FPSSESSION_H
#define FPSSESSION_H

#include "GameSession.h"

class FPSSession : public GameSession{
private:
  int headShotCount;
  int accuracyHeadshots;
  string weapon;
public:
  ~FPSSession() = default;
  FPSSession() = default;
  FPSSession(string playerID, string gameName, int duration, int score, double accuracy, long timeStamp, int headShotCount, int accuracyHeadshots, string weapon) : GameSession(playerID,gameName,duration,score,accuracy,timeStamp){
    this->headShotCount = headShotCount;
    this->accuracyHeadshots = accuracyHeadshots;
    this->weapon = weapon;
  }
  void display(ostream& o) const override;
  void read(istream& i) override;
  double calculateRating() const override;
  string getGameType() const override { return "FPS"; }
};


#endif

