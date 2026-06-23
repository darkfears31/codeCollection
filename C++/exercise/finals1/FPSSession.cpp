#include "FPSSession.h"

void FPSSession::display(ostream& o) const {
  GameSession::display(o);
  o<<"Head Shot Count: "<<headShotCount<<"\nAccuracy Headshots: "<<accuracyHeadshots<<"\nWeapon: "<<weapon<<endl;
}
void FPSSession::read(istream& i) {
  GameSession::read(i);
  i>>headShotCount>>accuracyHeadshots>>weapon;
}
double FPSSession::calculateRating() const {
  return (getScore() * 1.5) + (headShotCount * 10) + (accuracyHeadshots * 0.5);
}
