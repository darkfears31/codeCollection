// Main partially isn't written by me.
#include "kingdom.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "=== LOADING KINGDOMS ===\n";
  readFromFile();

  // Add these kingdoms if they aren't already loaded.
  Kingdom* redvale=getOrCreateKingdom("Redvale", 1400, 500, 0);
  Kingdom* goldcrest=getOrCreateKingdom("Goldcrest", 1100, 450, 1);
  Kingdom* ironmere=getOrCreateKingdom("Ironmere", 1600, 600, 2);
  Kingdom* helga=getOrCreateKingdom("Helga", 1200, 700, 1);

  // after the first run the file already contains the merged kingdom.
  const string mergedName = "Kolxeti&Tusheti";
  bool alreadyMerged = (findKingdom(mergedName) != nullptr);
  if(!alreadyMerged){
    getOrCreateKingdom("Kolxeti", 1750, 750, 2);
    getOrCreateKingdom("Tusheti", 1350, 450, 0);
  }

  cout << "\n=== KINGDOMS BEFORE BATTLES ===\n";
  displayAllKingdoms();

  cout << "\n=== BATTLE 1: REDVALE VS GOLDCREST ===\n";
  redvale->fight(*goldcrest);

  cout << "\n=== BATTLE 2: IRONMERE VS REDVALE ===\n";
  ironmere->fight(*redvale);

  cout << "\n=== BATTLE 3: IRONMERE VS GOLDCREST ===\n";
  ironmere->fight(*goldcrest);

  cout << "\n=== Merging Kolxeti and Tusheti ===\n";
  if(alreadyMerged){
    cout << mergedName << " already exists, skipping merge.\n";
  }
  else{
    Kingdom* kolxeti = findKingdom("Kolxeti");
    Kingdom* tusheti = findKingdom("Tusheti");
    if(kolxeti!=nullptr && tusheti!=nullptr){
      try{
        Kingdom* merged = *kolxeti + *tusheti;
        kolxeti = nullptr;   // operator+ deleted both originals
        tusheti = nullptr;
        cout << "Created " << merged->getKingdomName() << ".\n";
      }
      catch(const runtime_error& error){
        cout << error.what();
      }
    }
  }

  Kingdom* conquered = nullptr;
  for(Node* n = Kingdom::getHead(); n != nullptr; n = n->getNext()){
    if(n->getKingdom()->getIsConquered()){ conquered = n->getKingdom(); break; }
  }

  cout << "\n=== ADD POPULATION: HELGA +600 ===\n";
  cout << "Before:\n" << *helga;
  helga->addPopulation(600);
  cout << "After:\n" << *helga;

  cout << "\n=== RENAMING: HELGA -> HELGALAND -> HELGA ===\n";
  try{
    helga->changeName("Helgaland");
    cout << "Renamed to: " << helga->getKingdomName() << "\n";
    helga->changeName("Helga");
    cout << "Renamed back to: " << helga->getKingdomName() << "\n";
  }
  catch(const runtime_error& error){
    cout << error.what();
  }

  // changeName on a conquered kingdom must be blocked.
  cout << "\n=== RENAMING A CONQUERED KINGDOM ===\n";
  if(conquered != nullptr){
    cout << "Trying to rename " << conquered->getKingdomName() << ": ";
    conquered->changeName("Renamed Kingdom");   // prints the "can't change name" message
  }
  else{
    cout << "No kingdom was conquered this run.\n";
  }

  cout << "\n=== EXCEPTION HANDLING ===\n";
  try{
    cout << "Creating a second 'Redvale'...\n";
    Kingdom::createKingdom("Redvale", 100, 100, 1);
  }
  catch(const runtime_error& error){
    cout << "Caught: " << error.what();
  }
  try{
    cout << "Renaming Helga to 'Redvale'...\n";
    helga->changeName("Redvale");
  }
  catch(const runtime_error& error){
    cout << "Caught: " << error.what();
  }
  if(conquered != nullptr){
    try{
      cout << "Merging conquered " << conquered->getKingdomName() << " with Helga...\n";
      Kingdom* bad = *conquered + *helga;   // throws before anything is deleted
      cout << "Unexpectedly created " << bad->getKingdomName() << ".\n";
    }
    catch(const runtime_error& error){
      cout << "Caught: " << error.what();
    }
  }

  cout << "\n=== COMPARISON (operator==) ===\n";
  cout << "Redvale == Ironmere: " << ((*redvale == *ironmere) ? "equal" : "not equal") << "\n";
  cout << "Redvale == Redvale: " << ((*redvale == *redvale) ? "equal" : "not equal") << "\n";

  cout << "\n=== FINAL KINGDOM STATUS ===\n";
  displayAllKingdoms();

  saveToFile();

  cout << "Kingdom simulation completed.\n";

  return 0;
}
