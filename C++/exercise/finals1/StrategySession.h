#ifndef STRATEGYSESSION_H 
#define STRATEGYSESSION_H 

#include "GameSession.h"

class StrategySession : public GameSession{
private:
  int unitsKilled;
  int buildingsDestroyed;
  int resourcesGathered;
public:
  ~StrategySession() = default;
  StrategySession() = default;
  StrategySession(string playerID, string gameName, int duration, int score, double accuracy, long timeStamp, int unitsKilled, int buildingsDestroyed, int resourcesGathered) : GameSession(playerID,gameName,duration,score,accuracy,timeStamp){
    this->unitsKilled=unitsKilled;
    this->buildingsDestroyed=buildingsDestroyed;
    this->resourcesGathered=resourcesGathered;
  }
  void display(ostream& o) const override;
  void read(istream& i) override;
  double calculateRating() const override;
  string getGameType() const override { return "STRATEGY"; }
};


#endif
