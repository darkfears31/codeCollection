#include "kingdom.h"
#include "Node.h"
// As it's my first time having interaction with this random generator, I used help.
namespace{
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<double> bonus(0.8, 1.2);
  uniform_real_distribution<double> lossPercent(0.15, 0.30);
}
Node* Kingdom::head=nullptr;
set<string> globalKingdomNames;

// User inputs strategy as integer, and after that we cast it to rulerStrategy value, as it was giving errors for readFromFile().
Kingdom* Kingdom::createKingdom(string kingdomName, int population, double resources, int strategyInt){
  if(strategyInt<0 || strategyInt>2){
    throw runtime_error("Invalid strategy value.\n");
  }
  return createKingdom(kingdomName, population, resources, static_cast<rulerStrategy>(strategyInt));
}

// Above createKingdom() calls this createKingdom(), they are different, because they take different variables.
Kingdom* Kingdom::createKingdom(string kingdomName, int population, double resources, rulerStrategy strategy){
  Kingdom* kingdom = new Kingdom(kingdomName, population, resources, strategy);
  Node* node = new Node(kingdom, head);
  // Head now points to Node which has kingdom.
  head=node;
  return kingdom;
}


void Kingdom::changeName(const string& newName){
  if(!isConquered){
    for(const string& name : globalKingdomNames){
      if(name==newName){
        throw runtime_error("Kingdom with that name already exists.\n");
      }
    }
  }
  else {
    cout<<"Kingdom is conquered, can't change name.\n";
    return;
  }
  globalKingdomNames.erase(kingdomName);
  this->kingdomName=newName;
  globalKingdomNames.insert(kingdomName);
}

void Kingdom::setRulerStrategyInput(rulerStrategy strategy){
  while(true){
    switch (strategy) {
      case rulerStrategy::AGGRESSIVE:
      case rulerStrategy::DIPLOMATIC:
      case rulerStrategy::ECONOMIC:
        this->strategy=strategy;
        return;
      default:
        int choice;
        cout<<"Invalid strategy. choose again.\n 1. Aggresive\n 2. Diplomatic\n 3. Economic\n (choose by nubmer): ";
        if(!(cin>>choice)){
          cin.clear();
          cin.ignore(1000, '\n');
          continue;
        }
        switch(choice){
          case 1:
            strategy=rulerStrategy::AGGRESSIVE;
            break;
          case 2:
            strategy=rulerStrategy::DIPLOMATIC;
            break;
          case 3:
            strategy=rulerStrategy::ECONOMIC;
            break;
          default:
            cout<<"Invalid choice, choose again: ";
            break;
        }
    }
  }
}

void Kingdom::addPopulation(int amount){
  // Population can decrease too.
  this->population+=amount;
  if(this->population<0) this->population=0;
  Kingdom::calculateLevel();
  Kingdom::addResources();
  Kingdom::armyStrengthIncrement();
}

void Kingdom::calculateLevel(){
    // level start from 1.
    // after every 500 added population level increases.
    this->level=1+population/500;
}

void Kingdom::addResources(){
  // Give base resources 50.
  this->resources = 50+level*50;
}

void Kingdom::armyStrengthIncrement(){
  this->armyStrength = level*level + population/100;
}

bool Kingdom::operator==(const Kingdom& other) const{
  return armyStrength==other.armyStrength && level==other.level;
}

Kingdom* Kingdom::operator+(Kingdom& other){
  // if any of them are conquered, given kingdoms can't merge.
  if(isConquered || other.isConquered || this==&other ) throw runtime_error("Can't merge kingdoms if any of them is conquered.\nCan't merge kingdom to itself.\n");

  // rulerStrategy will be first kingdoms strategy ( because it was not stated what should be done to that.)
  Kingdom* mergedKingdom= createKingdom(kingdomName+'&'+other.kingdomName, population+other.population, resources+other.resources,  strategy);
  Kingdom* second = &other;
  // With this new kingdom is created and old ones still exist
  // As it was not specified what happens to kingdoms which were used to merge, I decided to delete them as it's only logical explanation.
  removeFromList(second);
  delete second;
  removeFromList(this);
  delete this;
  return mergedKingdom;
}


void Kingdom::display(ostream& o) const{
  o<<"Name: "<<kingdomName<<" Population: "<<population<<" Resources: "<<resources
    <<" Army Strength: "<<armyStrength<<" Level: "<<level<<" Conquered: " << (isConquered ? "Yes\n" : "No\n");
  for(const string& names : conqueredKingdoms){
    o<<names<<endl;
  }
}

void Kingdom::removeFromList(Kingdom* k){
  Node* prev = nullptr;
  Node* curr = head;
  // Find where is given kingdom in Linked List.
  while(curr!=nullptr && curr->getKingdom()!=k){
    prev=curr;
    curr=curr->getNext();
  }
  if(curr==nullptr) return;
  if(prev==nullptr) head=curr->getNext();
  else {prev->setNext(curr->getNext());}
  curr->setNext(nullptr);
  delete curr;
}

void Kingdom::fight(Kingdom& enemy){
  if(isConquered || enemy.isConquered){
    cout<<"If kingdom is conquered they can't have war.\n";
    return;
  }
  else if(this==&enemy) {
    cout<<"Kingdom can't fight itself.\n";
    return;
  }
  double k1 = getAdjustedArmyStrength();
  double k2 = enemy.getAdjustedArmyStrength();
  if(k1 > k2){
    cout<<kingdomName<<" Won.\n";
    conqueredKingdoms.push_back(enemy.kingdomName);
    this->level+=enemy.level;
    armyStrengthIncrement();
    afterWar();
    enemy.isConquered=true;
    enemy.armyStrength=0;
    enemy.population=50;
    enemy.resources=50;
  }
  else if(k1 < k2){
    cout<<kingdomName<<" Lost.\n";
    enemy.conqueredKingdoms.push_back(kingdomName);
    enemy.level+=level;
    enemy.armyStrengthIncrement();
    enemy.afterWar();
    isConquered=true;
    armyStrength=0;
    population=50;
    resources=50;
  }
  else{
    // Chance of this happening is very low but not 0, so had to write it.
    cout<<"Neither won.\n";
    // because neither won both of their population and resources will be reduced to minimum.
    afterWar();
    population=50;
    resources=50;
    enemy.afterWar();
    enemy.population=50;
    enemy.resources=50;
  }
}

void Kingdom::afterWar(){
  // population - 15-30% of it
  population*=(1-lossPercent(gen));
  // resources - 15-30% of it
  resources*=(1-lossPercent(gen));
}

/* ---------------- getters ---------------- */
Node* Kingdom::getHead(){
  return head;
}
string Kingdom::getKingdomName() const{
  return kingdomName;
}
int Kingdom::getPopulation() const{
  return population;
}
double Kingdom::getResources() const{
  return resources;
}
int Kingdom::getArmyStrength() const{
  return armyStrength;
}
int Kingdom::getLevel() const{
  return level;
}
bool Kingdom::getIsConquered() const{
  return isConquered;
}
Kingdom::rulerStrategy Kingdom::getRulerStrategy() const{
  return strategy;
}
vector<string> Kingdom::getConqueredKingdoms() const{
  return conqueredKingdoms;
}
double Kingdom::getStrategyBonus() const{
  switch(strategy){
    case rulerStrategy::AGGRESSIVE:
      return 1.3;
      break;
    case rulerStrategy::DIPLOMATIC:
      return 1.0;
      break;
    case rulerStrategy::ECONOMIC:
      return 0.8;
      break;
    default:
      throw runtime_error("Invalid ruler strategy.\n");
  }
}
double Kingdom::getAdjustedArmyStrength() const{
  double random = bonus(gen);
  return armyStrength + (level * random) * getStrategyBonus();
}

/* ---------------- setters ---------------- */
void Kingdom::setKingdomName(string kingdomName){Kingdom::changeName(kingdomName);}
void Kingdom::setPopulation(int population){this->population=population;}
void Kingdom::setResources(double resources){this->resources=resources;}
void Kingdom::setArmyStrength(int armyStrength){this->armyStrength=armyStrength;}
void Kingdom::setLevel(int level){this->level=level;}
void Kingdom::setIsConquered(bool isConquered){this->isConquered=isConquered;}
void Kingdom::setRulerStrategy(rulerStrategy strategy ){
  this->strategy=strategy;
}
void Kingdom::setConqueredKingdoms(vector<string> conqueredKingdoms){this->conqueredKingdoms=conqueredKingdoms;}
