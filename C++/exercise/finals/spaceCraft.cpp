#include "spaceCraft.h"

void SpaceCraft::display(ostream& o) const{
  o<<"Name: "<<name<<"\nLaunch Year: "<<launchYear<<"\nMax Speed: "<<maxSpeed<<endl;
}

void SpaceCraft::read(istream& i){
  i>>name>>launchYear>>maxSpeed;
}

double SpaceCraft::getMaxSpeed(){
  return maxSpeed;
}

bool SpaceCraft::operator<(SpaceCraft& other){
  return maxSpeed < other.maxSpeed;
}
bool SpaceCraft::operator>(SpaceCraft& other){
  return maxSpeed > other.maxSpeed;
}
ostream& operator<<(ostream& out, const SpaceCraft& s){
  s.display(out);
  return out;
}
istream& operator>>(istream& i, SpaceCraft& s){
  s.read(i);
  return i;
}
