#include "StrategySession.h"

void StrategySession::display(ostream& o) const {
  GameSession::display(o);
  o<<"Units Killed: "<<unitsKilled<<"\nBuildings Destroyed: "<<buildingsDestroyed<<"\nResources Gathered: "<<resourcesGathered<<endl;
}
void StrategySession::read(istream& i) {
  GameSession::read(i);
  i>>unitsKilled>>buildingsDestroyed>>resourcesGathered;
}
double StrategySession::calculateRating() const {
  return (getScore() * 1.2) + (buildingsDestroyed * 25) + (resourcesGathered * 0.1);
}
