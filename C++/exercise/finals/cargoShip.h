#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "spaceCraft.h"

class CargoShip : public SpaceCraft{
private:
  double cargoCapacity;
public:
  ~CargoShip() override = default;
  CargoShip() = default;
  CargoShip(string name, int launchYear, double maxSpeed, double cargoCap) : SpaceCraft(name,launchYear,maxSpeed){
    cargoCapacity=cargoCap;
  }
  void mission() const override;
  void display(ostream& o) const override;
  void read(istream& i) override;
};

#endif 
