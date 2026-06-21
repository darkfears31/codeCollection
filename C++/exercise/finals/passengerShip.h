#ifndef PASSENGERSHIP_H 
#define PASSENGERSHIP_H 

#include "spaceCraft.h"

class PassengerShip : public SpaceCraft{
private:
  int passengerCount;
public:
  ~PassengerShip() override = default;
  PassengerShip()=default;
  PassengerShip(string name, int launchYear, double maxSpeed, int passCount) : SpaceCraft(name,launchYear,maxSpeed){
    passengerCount=passCount;
  }
  void mission() const override;
  void display(ostream& o) const override;
  void read(istream& i) override;
};

#endif 
