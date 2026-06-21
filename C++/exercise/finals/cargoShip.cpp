#include "cargoShip.h"

void CargoShip::mission() const{
  cout<<"Delivering "<<cargoCapacity<<" tons of Cargo.\n";
}

void CargoShip::display(ostream& o) const{
  SpaceCraft::display(o);
  o<<cargoCapacity<<endl;
}

void CargoShip::read(istream& i){
  SpaceCraft::read(i);
  i>>cargoCapacity;
}
