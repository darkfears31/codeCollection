#ifndef KINGDOM_H
#define KINGDOM_H

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <random>

using namespace std;

// Global Functions --> see definition in global_functions.cpp
// as I found out, without keyword `extern` everyfile will get its own copy of `globalKingdomNames`, so I needed to write it.
extern set<string> globalKingdomNames;

//Predefining class because Kingdom uses it.
class Node;

class Kingdom{
private:
  string kingdomName;
  int population;
  double resources;
  // Depended on population and level, so won't be in constructor.
  int armyStrength=0;
  // because level is given by population, it will not be included in constructor.
  int level;
  bool isConquered=false;
  vector<string> conqueredKingdoms;
  //For first node next node doesn't exist, it will be changed after creating other nodes.
  // Thought making 'head' global but it will be accessible by every function which kind of rejects rule of encapsulation.
  // making it 'static' will do the same thing.
  // only one 'head' will exist.
  static Node* head;
  enum class rulerStrategy{
    AGGRESSIVE,
    DIPLOMATIC,
    ECONOMIC
  };
  rulerStrategy strategy;
  // Moved this functions in private as I want only member functions to access it.
  void calculateLevel();
  void addResources();
  void armyStrengthIncrement();
  // because only constructor needs it, moved it to private. 
  // because it's template function function definition should be written here to avoid any bugs.
  template <class T>
  void checkIfValid(T& variable);


public:
  // I like to keep Constructors and Destructors implementation here.
  Kingdom(const string kingdomName="", int population=0, double resources=0, rulerStrategy strategy = rulerStrategy::DIPLOMATIC){
    checkIfValid(population);
    this->population=population;
    calculateLevel();
    checkIfValid(resources);
    this->resources=resources;
    setRulerStrategyInput(strategy);
    armyStrengthIncrement();
    // changeName changes names but still can set name, because of checking if it exists and stuff.
    // also changeName() is last because if any other functions threw exception it would've not be added to globalKingdomNames and
    // this function adds kingdom name to that.
    changeName(kingdomName);
  }
  // copying would run the destructor on the copy, which erases the real kingdom's name from the set.
  Kingdom(const Kingdom&) = delete;
  Kingdom& operator=(const Kingdom&) = delete;

  // because head is static createKingdom should be static too.
  static Kingdom* createKingdom(string kingdomName, int population, double resources, int strategyInt);
  static Kingdom* createKingdom(string kingdomName="", int population=0, double resources=0, rulerStrategy strategy = rulerStrategy::DIPLOMATIC);
  ~Kingdom(){
    globalKingdomNames.erase(kingdomName);
  }
  void fight(Kingdom& enemy);
  void afterWar();
  void changeName(const string& kingdomName);
  void setRulerStrategyInput(rulerStrategy strategy);
  void addPopulation(int amount);
  bool operator==(const Kingdom& other) const;
  Kingdom* operator+(Kingdom& other);
  void display(ostream& o) const;
  void removeFromList(Kingdom* k);


  /* ---------------- getters ---------------- */
  static Node* getHead();
  string getKingdomName() const;
  int getPopulation() const;
  double getResources() const;
  int getArmyStrength() const;
  int getLevel() const;
  bool getIsConquered() const;
  rulerStrategy getRulerStrategy() const;
  vector<string> getConqueredKingdoms() const;
  double getStrategyBonus() const;
  double getAdjustedArmyStrength() const;

/* ---------------- setters ---------------- */
  void setKingdomName(string kingdomName);
  void setPopulation(int population);
  void setResources(double resources);
  void setArmyStrength(int armyStrength);
  void setLevel(int level);
  void setIsConquered(bool isConquered);
  void setRulerStrategy(rulerStrategy strategy);
  void setConqueredKingdoms(vector<string> conqueredKingdoms);
};

template <class T>
void Kingdom::checkIfValid(T& variable){
  while(true){
    if(variable>=0){
      break;
    }
    cout<<"Enter correct variable: ";
    T input;
    if(cin>>input) {variable=input;}
    else{
      cout<<"Enter valid value: ";
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
}
ostream& operator<<(ostream& o,const Kingdom& other);
void saveToFile();
void readFromFile();
Kingdom* findKingdom(const string& name);
Kingdom* getOrCreateKingdom(const string& name, int population, double resources, int strategy);
void displayAllKingdoms();
#endif
