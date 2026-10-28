#include "kingdom.h"
#include "Node.h"

void saveToFile(){
  ofstream inFile("kingdoms.txt");
  if(!inFile.is_open()){
    cout<<"File not opened.\n";
    return;
  }
  // Leet code experience coming in handy
  Node* curr = Kingdom::getHead();
  while(curr!=nullptr){
    //Using Node-s getKingdom() to access kingdom that is stored in node.
    Kingdom* currKingdom = curr->getKingdom();
    // Used static_cast<int> to save which kind of strategy kingdom uses.
    // OFC I used help for casting.
    inFile<<currKingdom->getKingdomName()<<' '<<currKingdom->getPopulation()<<' '
      <<currKingdom->getResources()<<' '<<currKingdom->getArmyStrength()<<' '
      <<currKingdom->getLevel()<<' '<<currKingdom->getIsConquered()<<' '
      <<static_cast<int>(currKingdom->getRulerStrategy())<<' '; 
    for(const string& name :  currKingdom->getConqueredKingdoms()){
      inFile<<name<<' ';
    }
    inFile<<'\n';
    curr=curr->getNext();
  }
  inFile.close();
}

void readFromFile(){
  ifstream readFile("kingdoms.txt");
  if(!readFile.is_open()){
    cout<<"File doesn't exist or couldn't open file.\n";
    return;
  }
  string name;
  int population;
  double resources;
  int armyStrength;
  int level;
  bool isConquered;
  int strategyVal;

  while(readFile>>name>>population>>resources>>armyStrength>>level>>isConquered>>strategyVal){
    if(strategyVal<0||strategyVal>2){
      cout<<"Not a valid integer for strategy.\n";
      cout<<"Don't tamper with the file.\n";
      return;
    }
    if(population<0||resources<0){
      cout<<"Not a valid integer for population or resources.\n";
      cout<<"Don't tamper with the file.\n";
      return;
    }
    // because in file variables are written next to each other (except conqueredKingdoms) we gotta take whole line and dissect it to read it properly.
    string line;
    getline(readFile, line);
    vector<string> conqueredKingdoms;
    string conqueredKingdom;
    istringstream iss(line);
    
    // Read conquered kingdoms.
    while(iss>>conqueredKingdom){
      conqueredKingdoms.push_back(conqueredKingdom);
    }
    // take strategy from file.
    try{
      //After reading everything for one object from file, we got to create it.
      Kingdom* k = Kingdom::createKingdom(name, population, resources, strategyVal); 
      k->setLevel(level);
      k->setArmyStrength(armyStrength);
      k->setIsConquered(isConquered);
      k->setConqueredKingdoms(conqueredKingdoms);
    }
    catch(const runtime_error& error){
      cout<<error.what();
      continue;
    }
  }
  readFile.close();
  cout<<"Read success.\n";
}

ostream& operator<<(ostream& o, const Kingdom& other){
  other.display(o);
  return o;
}

// Find a kingdom in the linked list by name.
Kingdom* findKingdom(const string& name) {
  Node* current = Kingdom::getHead();
  while (current != nullptr) {
    Kingdom* kingdom = current->getKingdom();
    if (kingdom->getKingdomName() == name) return kingdom;
    current = current->getNext();
  }
  return nullptr;
}

// Create a kingdom only if it doesn't already exist.
Kingdom* getOrCreateKingdom(const string& name,int population,double resources,int strategy){
  Kingdom* kingdom = findKingdom(name);
  if (kingdom != nullptr) {
    return kingdom;
  }
  return Kingdom::createKingdom(name, population, resources, strategy);
}

void displayAllKingdoms() {
  Node* current = Kingdom::getHead();
  while (current != nullptr) {
    current->getKingdom()->display(cout);
    cout << '\n';
    current = current->getNext();
  }
}
