#include "passengerShip.h"

void PassengerShip::mission() const{
  cout<<"Transporting "<<passengerCount<<" Passengers.\n";
}

void PassengerShip::display(ostream& o) const{
  SpaceCraft::display(o);
  o<<passengerCount<<endl;
}

void PassengerShip::read(istream& i){
  SpaceCraft::read(i);
  i>>passengerCount;
}
