#include "LibrarySystem.h"


// Adding ------------------------------------------------------------------------------------------------
int LibrarySystem::displayForAdd(){
  int choice;
  cout<<"Which item do you want to add? (choose by number)\n";
  cout<<"1. Book\n";
  cout<<"2. DVD\n";
  cout<<"3. Magazine\n";
  cout<<"4. Research Paper\n";
  // Validate input
  while(true){
    cin>>choice;
    if(cin.fail()){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Enter Valid Number: ";
    }
    else if(choice<1 || choice>4){
      cin.ignore(1000, '\n');
      cout<<"Enter number between 1 and 4: "; 
    }
    else{
      cin.ignore(1000, '\n');
      return choice;
    }
  }
}

unique_ptr<Book> LibrarySystem::createBook(){
  int ID, PAGES, PUBLICATION_YEAR;
  string TITLE, AUTHOR, GENRE;
  double LATE_FEE=0.5;
  bool AVAILABLE = true;
  
  cout<<"ID: ";
  create_New_Objects_ID(ID);

  cout<<"Title: ";
  getline(cin, TITLE);
  
  cout<<"Author: ";
  getline(cin,AUTHOR);
 
  cout<<"Publication year: ";
  cin>>PUBLICATION_YEAR;
  cin.ignore();
  
  cout<<"Number of pages: ";
  cin>>PAGES;
  cin.ignore();
  
  cout<<"Genre: ";
  getline(cin, GENRE);
 
  return make_unique<Book>(ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABLE,PAGES, GENRE, LATE_FEE);
}

unique_ptr<DVD> LibrarySystem::createDVD(){
  int ID, PUBLICATION_YEAR, DURATION;
  string TITLE, DIRECTOR, AGE_RATING;
  double LATE_FEE=0.5;
  bool AVAILABLE = true;
  
  cout<<"ID: ";
  create_New_Objects_ID(ID);

  cout<<"Title: ";
  getline(cin,TITLE);
  
  cout<<"Director: ";
  getline(cin, DIRECTOR);
  
  cout<<"Publication year: ";
  cin>>PUBLICATION_YEAR;
  cin.ignore();
  
  cout<<"Duration: ";
  cin>>DURATION;
  cin.ignore();
  
  cout<<"Age Rating: ";
  getline(cin,AGE_RATING);
  
  return make_unique<DVD>(ID, TITLE, DIRECTOR, PUBLICATION_YEAR, AVAILABLE, DURATION, AGE_RATING, LATE_FEE);
}

unique_ptr<Magazine> LibrarySystem::createMagazine(){
  int ID, PUBLICATION_YEAR, ISSUE_NUMBER;
  string TITLE, PUBLISHER, PUBLISH_MONTH;
  double LATE_FEE=0.3;
  bool AVAILABLE = true;
  
  cout<<"ID: ";
  create_New_Objects_ID(ID);

  cout<<"Title: ";
  getline(cin,TITLE);
  
  cout<<"Publisher: ";
  getline(cin, PUBLISHER);
  
  cout<<"Publication year: ";
  cin>>PUBLICATION_YEAR;
  cin.ignore();
  
  cout<<"Issue Number: ";
  cin>>ISSUE_NUMBER;
  cin.ignore();
  
  cout<<"Publish Month: ";
  cin>>PUBLISH_MONTH;
  cin.ignore();
  
  return make_unique<Magazine>(ID, TITLE, PUBLISHER, PUBLICATION_YEAR, AVAILABLE, ISSUE_NUMBER, PUBLISH_MONTH, LATE_FEE);
}

unique_ptr<ResearchPaper> LibrarySystem::create_Research_Paper(){
  int ID, PUBLICATION_YEAR;
  string TITLE, AUTHOR, JOURNAL_OR_CONFERENCE, DO_I;
  double LATE_FEE=0.5;
  bool AVAILABLE = true;

  cout<<"ID: ";
  create_New_Objects_ID(ID);

  cout<<"Title: ";
  getline(cin,TITLE);
  
  cout<<"Author: ";
  getline(cin,AUTHOR);
 
  cout<<"Publication year: ";
  cin>>PUBLICATION_YEAR;
  cin.ignore();
  
  cout<<"Which Journal or Conference did it appear: ";
  getline(cin,JOURNAL_OR_CONFERENCE);
  
  cout<<"DOI: ";
  getline(cin,DO_I);
 
  return make_unique<ResearchPaper>(ID, TITLE, AUTHOR, PUBLICATION_YEAR, AVAILABLE, JOURNAL_OR_CONFERENCE, DO_I, LATE_FEE);
}

int LibrarySystem::create_New_Objects_ID(int& ID){
  while(true){
    cin>>ID;
    cin.ignore();
    if(items.count(ID)) cout<<"This ID is already occupied.\n";
    else {return ID;}
  }
  return ID;
}

void LibrarySystem::add(){
  int choice = displayForAdd();
  unique_ptr<LibraryItem> item;
  switch (choice){
    case 1:
      item = createBook();
      break;
    case 2:
      item = createDVD();
      break;
    case 3:
      item = createMagazine();
      break;
    case 4:
      item = create_Research_Paper();
      break;
  }
  int ID = item->get_ID();
  items[ID] = move(item);
}
// Adding ------------------------------------------------------------------------------------------------

// Display -------------------------------------------------------------------------------------------
void LibrarySystem::Display() const {
  for(const auto& [id,item] : items){
    item->display(std::cout);
    cout<<'\n';
  }
}
// Display -------------------------------------------------------------------------------------------

// Search and Display ------------------------------------------------------------------------------------------------------

auto compare_With_LowerCase = [](const string& a, const string& b) {
  return std::equal(a.begin(), a.end(), b.begin(), b.end(),
    [](char c1, char c2) {
      return tolower(c1) == tolower(c2);
    });
};

void LibrarySystem::searchWith_ID(int& ID) const {
  auto iterator = items.find(ID);
  if(iterator != items.end()){
    iterator->second->display(cout);
    cout<<'\n';
  }
  else{
    cout<<"No item found with matching ID-s.\n";
    ID=-1;
  }
}

void LibrarySystem::searchWith_Title() const {
  string title;
  int count_found{0};
  cout<<"Enter Title to Search With: ";
  getline(cin, title);
  for(const auto& [id,item] : items){
    if(compare_With_LowerCase(item->get_Title(), title)) {
      item->display(std::cout);
      count_found++;
      cout<<'\n';
    }
  }
  if(count_found==0) cout<<"None Found.\n";
}

void LibrarySystem::searchWith_Author_Or_Creator() const {
  string Author_OR_Creator;
  int count_found{0};
  cout<<"Enter Author Or Creator to Search With: ";
  getline(cin, Author_OR_Creator);
  for(const auto& [id,item] : items){
    if(compare_With_LowerCase(item->get_Author_OR_Creator(), Author_OR_Creator)){
      item->display(std::cout);
      count_found++;
      cout<<'\n';
    }
  }
  if(count_found==0) cout<<"None Found.\n"; 
}

void LibrarySystem::searchWith_Publication_Year() const{
  int publication_Year;
  int count_found{0};
  cout<<"Enter Publication Year to Search With: ";
  cin>>publication_Year;
  for(const auto& [id,item] : items){
    if(item->get_Publication_Year() == publication_Year){
      item->display(std::cout);
      count_found++;
      cout<<'\n';
    }
  }
  if(count_found==0) cout<<"None Found.\n";
}

void LibrarySystem::searchWith_Item_Type() const {
  string Item_Type;
  int count_found{0};
  cout<<"Enter Item Type to Search With: ";
  getline(cin, Item_Type);
  for(const auto& [id,item] : items){
    if(item->get_Type() == Item_Type){
      item->display(std::cout);
      count_found++;
      cout<<'\n';
    }
  }
  if(count_found==0) cout<<"None Found.\n";
}

int LibrarySystem::choice_SearchWith() const {
  int choice;
  cout<<"What do you want to search with? (Chose with number)\n";
  cout<<"1. ID\n";
  cout<<"2. Title\n";
  cout<<"3. Author Or Creator\n";
  cout<<"4. Publication Year\n";
  cout<<"5. Item Type\n";
  // Validate input
  while(true){
    cin>>choice;
    if(cin.fail()){
      cin.clear();
      cin.ignore(1000, '\n');
      cout<<"Enter Valid Number: ";
    }
    else if(choice<1 || choice>5){
      cin.ignore(1000, '\n');
      cout<<"Enter number between 1 and 5: "; 
    }
    else{
      cin.ignore(1000, '\n');
      return choice;
    }
  }
  cout<<'\n';
}

void LibrarySystem::search() const {
  int choice= choice_SearchWith();
  switch (choice){
    case 1:{
      int ID=0;
      cout<<"Enter ID to search with: ";
      cin>>ID;
      cin.ignore();
      searchWith_ID(ID);
      break;
    }
    case 2:
      searchWith_Title();
      break;
    case 3:
      searchWith_Author_Or_Creator();
      break;
    case 4:
      searchWith_Publication_Year();
      break;
    case 5:
      searchWith_Item_Type();
      break;
  }
}
// Search and Display ------------------------------------------------------------------------------------------------------

// Borrow - Return -------------------------------------------------------------------------------------------------

// Find item with ID, then return address of it.
LibraryItem* LibrarySystem::findItemByID(int ID) const{
  auto iterator = items.find(ID);
  if(iterator != items.end()) return iterator->second.get();
  else {return nullptr;}
}

void LibrarySystem::borrow(){
  int ID;
  cout<<"Enter ID of Library Item You want to borrow: ";
  cin>>ID;
  LibraryItem* item = findItemByID(ID);
  if(item != nullptr){
    if(item->get_Availability()==true){
      cin.ignore();
      string full_Name;
      cout<<"Tell me your full name: ";
      getline(cin, full_Name);
      item->borrowItem(full_Name);
    }
    else {cout<<"Item isn't available.\n";}
  }
  else {cout<<"Item not found.\n";}
}

void LibrarySystem::returnItem(){
  int ID;
  cout<<"Enter ID of item you are returning: ";
  cin>>ID;
  LibraryItem* item = findItemByID(ID);
  if(item!=nullptr && item->get_Availability()==false){
    double lateFee = item->calculateLateFee(item->calculateOverdueDays());
    cout<<"Your fee is: "<<lateFee<<endl;
    item->returnedItem();
  }
  else {cout<<"Item not found or is not borrowed.\n";}
}

// Borrow - Return -------------------------------------------------------------------------------------------------

// Delete Item ----------------------------------------------------------------------------------------------- 

// Finds item with matching ID and removes it from Map.
void LibrarySystem::removeByID(int targetID){
  items.erase(targetID);
}

void LibrarySystem::deleteItem(){
  int ID=0;
  cout<<"Enter ID of item to delete: ";
  cin>>ID;
  cin.ignore();
  searchWith_ID(ID); // searchWith_ID() returns ID = -1 if no item is found.
  if(ID!=-1){
    removeByID(ID);
    cout<<"Deleted Succesfully.\n";
  }
}

// Delete Item ----------------------------------------------------------------------------------------------- 

// Save and Load from file ----------------------------------------------------------------------------------------------- 

void LibrarySystem::saveToFile(){
  ofstream f("records.txt");
  if(!f){
    cout<<"Error.\n";
    return;
  }
  for(const auto& [id,item] : items){
    item->saveToFile(f);
  }
  f.close();
}

void LibrarySystem::loadFromFile(){
  ifstream f("records.txt");
  if(!f){
    cout<<"Error.\n";
    return;
  }
  string line;
  while(getline(f, line)){
    istringstream iss(line);
    string type;
    getline(iss, type, '|'); // type gets first word and based on it we create objects
    unique_ptr<LibraryItem> item = nullptr; // create pointer which will hold object
    if(type == "Book") item = Book::loadFromLine(iss);
    else if(type == "DVD") item = DVD::loadFromLine(iss);
    else if(type == "Magazine") item = Magazine::loadFromLine(iss);
    else if(type == "Research Paper") item = ResearchPaper::loadFromLine(iss);
    else {
      // If unknown type is found skip.
      cout<<"Unknown Type.\n";
      continue;
    }
    // if item doesn't point to NULL we add it to vector.
    if(item != nullptr) items[item->get_ID()] = move(item);
  }
  f.close();
}

// Save and Load from file ----------------------------------------------------------------------------------------------- 
