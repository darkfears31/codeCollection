#include <iostream>
#include <fstream>
#include <string>
#include "spaceCraft.h"
#include "cargoShip.h"
#include "passengerShip.h"
#include "fleet.h"

using namespace std;

int main() {
  Fleet<SpaceCraft*> fleet;

  ifstream fin("fleet.txt");
  if (!fin) {
      cout << "Could not open fleet.txt" << endl;
      return 1;
  }

  string type;
  while (fin >> type) {
      SpaceCraft* s = nullptr;
      if (type == "cargo")
          s = new CargoShip();
      else if (type == "passenger")
          s = new PassengerShip();
      else
          continue;

      fin >> *s;          // polymorphic read()
      fleet.insert(s);
  }
  fin.close();

  cout << "=== Fleet before sorting ===" << endl;
  for (int i = 0; i < fleet.size(); i++) {
      cout << *fleet[i];
      fleet[i]->mission();
  }

  sortFleet(fleet);

  cout << "\n=== Fleet after sorting by speed ===" << endl;
  for (int i = 0; i < fleet.size(); i++) {
      cout << *fleet[i];
  }

  // demonstrate operator[] bounds checking
  try {
      cout << *fleet[100];
  } catch (const out_of_range& e) {
      cout << "\nCaught exception: " << e.what() << endl;
  }

  // cleanup
  for (int i = 0; i < fleet.size(); i++) {
      delete fleet[i];
  }

  return 0;
}
