#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SpaceCraft{
private:
  string name;
  int launchYear;
  double maxSpeed;
public:
  virtual ~SpaceCraft()=default;
  SpaceCraft() = default;
  SpaceCraft(string n, int l, double m){
    name=n;
    launchYear=l;
    maxSpeed=m;
  }
  virtual void mission() const =0;
  virtual void display(ostream& o) const;
  virtual void read(istream& i);
  double getMaxSpeed();
  bool operator<(SpaceCraft& other);
  bool operator>(SpaceCraft& other);
};

ostream& operator<<(ostream& out, const SpaceCraft& s);
istream& operator>>(istream& i, SpaceCraft& s);
#endif
