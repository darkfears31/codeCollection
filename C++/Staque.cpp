#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Staque {
private:
  struct Node {
      int value;
      Node* next;
      Node* previous;
  };
  Node* front;
  Node* back;
  // Counters 
  int size;
  int numberOfOddInStaque;
  int numberOfEvenInStaque;
  // If Staque is reversed, removing and adding should work correctly,
  // for which 'isReversed' will help.
  bool isReversed;
public:

  Staque(){
    size=0;
    numberOfEvenInStaque=numberOfOddInStaque=0;
    front=back=nullptr;
    isReversed=false;
  }
  // Copy constructor
  // If other staque is reversed, newly created one will also be reversed.
  Staque(const Staque& other){
    if(!other.empty()){
      size=other.size;
      numberOfEvenInStaque=other.numberOfEvenInStaque;
      numberOfOddInStaque=other.numberOfOddInStaque;
      isReversed=other.isReversed;
      Node* it=other.front;
      Node* added = new Node{it->value,nullptr,nullptr};
      front=back=added;
      it=other.front->next;
      Node* it2=added;
      while(it!=nullptr){
        it2->next=new Node{it->value, nullptr, it2};
        it2=it2->next;
        it=it->next;
      }
      back=it2;
    }
    else{
      size=0;
      numberOfEvenInStaque=numberOfOddInStaque=0;
      front=back=nullptr;
      isReversed=false;
    }
  }
  
  // Destructor
  ~Staque(){
    this->clear();
  }

  // Assignment operator
  // If other staque is reversed, assigned staque will also be reversed.
  Staque& operator=(const Staque& other){
    if(!other.empty() && this!=&other){
      this->clear();
      size=other.size;
      numberOfEvenInStaque=other.numberOfEvenInStaque;
      numberOfOddInStaque=other.numberOfOddInStaque;
      isReversed=other.isReversed;
      Node* it=other.front;
      Node* added = new Node{it->value,nullptr,nullptr};
      front=back=added;
      it=other.front->next;
      Node* it2=added;
      while(it!=nullptr){
        it2->next=new Node{it->value, nullptr, it2};
        it2=it2->next;
        it=it->next;
      }
      back=it2;
    }
    else if(other.empty()){this->clear();}
    return *this;
  }
  
  // Checks whether staque is reversed and decides where to add new value,
  // if it's reversed even numbers will be added at the back and odds will be added to front.
  void insert(int value){
    if(empty()){
      Node* added = new Node{value,nullptr,nullptr};
      front=back=added;
    }
    else{
      if(value%2==0 && !isReversed){
        Node* added = new Node{value, front, nullptr};
        front->previous=added;
        front=added;
      }
      else if(value%2==0 && isReversed){
        Node* added = new Node{value, nullptr, back};
        back->next=added;
        back=added;
      }
      else if(value%2!=0 && !isReversed){
        Node* added = new Node{value, nullptr, back};
        back->next=added;
        back=added;
      }
      else if(value%2!=0 && isReversed){
        Node* added = new Node{value, front, nullptr};
        front->previous=added;
        front=added;
      }
    }
    if(value%2==0) numberOfEvenInStaque++;
    else{numberOfOddInStaque++;}
    size++;
  }

  void remove(){
    int removedValue;
    // Was written that remove() should remove from back, so if staque is reversed it will remove even number
    // if not it will remove odd number
    // and subtract from corresponding counter.
    if(!empty()){
      Node* tmp=back;
      removedValue=back->value;
      back=back->previous;
      if(back==nullptr){front=nullptr; isReversed=false;}
      else{back->next=nullptr;}
      delete tmp;
      if(removedValue%2==0) numberOfEvenInStaque--;
      else{numberOfOddInStaque--;}
      size--;
    }
    else{
      throw runtime_error("Empty, can't remove.\n");
    }
  }

  // If staque is reversed, logic will be reversed too. Kinda straightforward.
  void remove(bool removeEven){
    if(empty()){
      throw runtime_error("Staque is empty, can not remove anything.\n");
    }
    if(!isReversed){ // staque is not reversed.
      if(removeEven){ 
        if(numberOfEvenInStaque==0){
          throw runtime_error("No even values in Staque.\n");
        }
        Node* tmp=front;
        front=front->next;
        if(front!=nullptr) front->previous=nullptr;
        else{back=nullptr;}
        delete tmp;
        numberOfEvenInStaque--;
        size--;
      }
      else{
        if(numberOfOddInStaque==0){
          throw runtime_error("No odd values in Staque.\n");
        }
        remove();
      }
    }
    else{ // Staque is reversed.
      if(removeEven){ 
        if(numberOfEvenInStaque==0){
          throw runtime_error("No even values in Staque.\n");
        }
        Node* tmp=back;
        back=back->previous;
        if(back!=nullptr) back->next=nullptr;
        else{front=nullptr;}
        delete tmp;
        numberOfEvenInStaque--;
        size--;
      }
      else{
        if(numberOfOddInStaque==0) throw runtime_error("No odd values in Staque.\n");
        Node* tmp=front;
        front=front->next;
        if(front!=nullptr) front->previous=nullptr;
        else{back=nullptr;}
        delete tmp;
        numberOfOddInStaque--;
        size--;
      }
    }
  }

  // Calls remove(bool removeEven) and deletes how many numbers it was told.  
  void remove(int numberOfEven, int numberOfOdd){
    if(!empty() &&  numberOfOdd<=numberOfOddInStaque && numberOfEven<=numberOfEvenInStaque && numberOfOdd>=0 && numberOfEven>=0){
      for(int i=0;i<numberOfEven;i++){
        remove(true);
      }
      for(int i=0;i<numberOfOdd;i++){
        remove(false);
      }
    }
    else{
      throw runtime_error("Can't remove.\n");
    }
  }

  bool empty() const{
    return size==0;
  }

  int getSize() const{
    return size;
  }

  // Deletes every node. This is called in Destructor.
  void clear(){
    Node* tmp = nullptr;
    while(front!=nullptr){
      tmp=front;
      front=front->next;
      delete tmp;
    } 
    size=numberOfOddInStaque=numberOfEvenInStaque=0;
    front=back=nullptr;
    isReversed=false;
  }

  // Goes over the whole staque, and on first occurrence it returns true
  bool contains(int value) const{
    Node* it=front;
    while(it!=nullptr){
      if(it->value==value) return true;
      it=it->next;
    }
    return false;
  }

  // Counts how many matching values it found.
  void count(int value) const{
    int counted=0;
    Node* it=front;
    while(it!=nullptr){
      if(it->value==value) counted+=1;
      it=it->next;
    }
    cout<<"Number "<<value<< " was found "<<counted<<" in staque.\n";
  }

  // Almost every state of staque is written here with relevant code.
  void removeValue(int value){ // 
    if(empty()) throw runtime_error("Staque is empty, cannot remove anything.\n");
    if(front->value==value && size>1){
      if(front->value%2==0) numberOfEvenInStaque--;
      else{numberOfOddInStaque--;}
      size--;
      front=front->next;
      delete front->previous;
      front->previous=nullptr; 
    }
    else if(back->value==value && size>1){
      if(back->value%2==0) numberOfEvenInStaque--;
      else{numberOfOddInStaque--;}
      size--;
      back=back->previous;
      delete back->next;
      back->next=nullptr;
    }
    else if(front->value==value && size==1){
      delete front;
      front=back=nullptr;
      size=numberOfEvenInStaque=numberOfOddInStaque=0;
      isReversed=false;
    }
    else{
      Node* it=front->next;
      while(it!=nullptr){
        if(it->value==value){
          if(it->value%2==0) numberOfEvenInStaque--;
          else{numberOfOddInStaque--;}
          size--;
          it->previous->next=it->next;
          if(it->next==nullptr) back=it->previous;
          else{
            it->next->previous=it->previous;
          }
          delete it;
          break;
        }
        it=it->next;
      }
    }
  }

  // Reverses staque.
  void reverse(){
    if(empty()) throw runtime_error("Staque is empty, can't reverse.\n");
    Node* it=front;
    while(it!=nullptr){
      // same as swap(it->next, it->previous) Didn't want to include <algorithms>
      Node* tmp=it->next;
      it->next=it->previous;
      it->previous=tmp;
      it=tmp;
    }
    // Same swap logic here.
    Node* tmp=front;
    front=back;
    back=tmp;
    // Setting isReversed to opposite.
    isReversed=!isReversed;
  }

  void display(ostream& o) const{ // Changed this to work with operator overloading.
    Node* it=front;
    if(!empty()){
      o<<"(front) ";
      while(it!=nullptr){
        o<<it->value<<' ';
        it=it->next;
      }
      o<<"(back)";
      o<<endl;
    }
    else {o<<"Staque is empty.\n";}
  }

  bool validateIntegrity() const{
    if(empty()){
      return front==nullptr && back==nullptr && numberOfEvenInStaque==0 && numberOfOddInStaque==0;
    }
    else if(front==nullptr || back==nullptr) return false;
    else if(size==1 && front->next==nullptr && front->previous==nullptr && back->next==nullptr && back->previous==nullptr){
      if(front->value%2==0){
        return front==back && numberOfEvenInStaque==1 && numberOfOddInStaque==0;
      }
      else{
        return front==back && numberOfEvenInStaque==0 && numberOfOddInStaque==1;
      }
    }
    else if(size>1){
      // Counts number of nodes from front and back, even numbers, odd numbers, checks linker errors
      int evenCounter{0}, oddCounter{0}, frontNodeCounter{0}, backNodeCounter{0};
      Node* it=front;
      Node* lastNode=nullptr;
      Node* firstNode=nullptr;
      if(it->previous!=nullptr) return false;
      // Forward traversal check.
      while(it!=nullptr){
        if(it->value%2==0) evenCounter++;
        else{oddCounter++;}
        if(it->next!=nullptr && it->next->previous!=it) return false;
        lastNode=it;
        it=it->next;
        frontNodeCounter++;
        if(frontNodeCounter>size) return false; // This prevents while loop from running forever. If nodes point to eachother, this will catch it. 
      }
      // Backward traversal check.
      it=back;
      if(it->next!=nullptr) return false;
      while(it!=nullptr){
        if(it->previous!=nullptr && it->previous->next!=it) return false;
        firstNode=it;
        it=it->previous;
        backNodeCounter++;
        if(backNodeCounter>size) return false; // This prevents while loop from running forever. If nodes point to eachother, this will catch it. 
      }
      return frontNodeCounter==size && backNodeCounter==size && evenCounter==numberOfEvenInStaque && oddCounter==numberOfOddInStaque && lastNode==back && firstNode==front;
    }
    return false;
  }
  
  // Decided that it doesn't maeter if staque is reversed, if values and order of that values match staques are same.
  // if staque is 2 4 3 1 and other is 1 3 4 2 they are the same.
  bool operator==(const Staque& other) const{
    if(size==other.size && size>0 && isReversed==other.isReversed){ // If both staque are in same condition reversed or not reversed.
      Node* it1=front;
      Node* it2=other.front;
      while(it1!=nullptr){
        if(it1->value!=it2->value) return false;
        it1=it1->next;
        it2=it2->next;
      }
    }
    else if(size==other.size && size>0 && isReversed && !other.isReversed){// if first stque is reversed, second not.
      Node* it1=back;
      Node* it2=other.front;
      while(it1!=nullptr){
        if(it1->value!=it2->value) return false;
        it1=it1->previous;
        it2=it2->next;
      }
    }
    else if(size==other.size && size>0 && !isReversed && other.isReversed){// if second stque is reversed, first not.
      Node* it1=front;
      Node* it2=other.back;
      while(it1!=nullptr){
        if(it1->value!=it2->value) return false;
        it1=it1->next;
        it2=it2->previous;
      }
    }
    else if(size!=other.size) return false;
    return true;
  }
};

ostream& operator<<(ostream& o, const Staque& s){
  s.display(o);
  return o;
}

void interface(){
  // Too lazy to write multiple `cout`-s.
  cout<<"\t MENU \t\n";
  cout<<"1)Insert a number.\n2)Remove one element.\n3)Remove an even or odd element.\n4)Remove multiple even and odd elements.\n5)Remove a value.\n6)Display the Staque.\n7)Search for a value and count its occurrences.\n8)Reverse the Staque.\n9)Create and display a deep copy.\n10)Compare two Staques.\n11)Clear the Staque.\n12)Exit.\n";
}

int choice(){
  int choose;
  cout<<"Choose menu option: ";
  while(!(cin>>choose) || choose<1 || choose>12){
    cout<<"Enter valid menu option.\n";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  return choose;
}
 
// If user inputs 'ODD' or 'odD' it should be converted to lowercase to match the statement I gave.
void toLowerCase(string& s){
  for(char &c : s){
    if(c>='A' && c<='Z'){
      c+=32; // Converts to lowercase using ASCII values.
    }
  }
}

// Didn't really know what to do, so I made function which creates new staque solely for comparing purposes.
Staque createStaqueForComparing(){
  cout<<"To compare one staque to another, you need to create second stauqe.\n";
  int numberOfValuesInNewStaque;
  cout<<"How many numbers you want to add in staque? : ";
  while(!(cin>>numberOfValuesInNewStaque)){
    cout<<"Enter valid number.\n";
    cin.clear();
    cin.ignore(1000, '\n');
  }
  Staque newStaque;
  for(int i=1;i<=numberOfValuesInNewStaque;i++){
    int newNumberInStaque;
    cout<<"Enter number: ";
    while(!(cin>>newNumberInStaque)){
      cout<<"Enter valid number.\n";
      cin.clear();
      cin.ignore(1000, '\n');
    }
    newStaque.insert(newNumberInStaque);
    cout<<"You have left "<<numberOfValuesInNewStaque-i<<" numbers to add in new stauqe.\n";
  }
  return newStaque;
}

int main(){
  Staque st1;
  int ch;
  do{
    interface();
    ch=choice();
    try{
      switch (ch){
        case 1:
          int number;
          cout<<"Enter number to add to staque: ";
          while(!(cin>>number)){
            cout<<"Enter valid number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          st1.insert(number);
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 2:
          st1.remove();
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 3:
          {
          string oddOrEven;
          cout<<"Remove even or odd? (enter in word): ";
          while(!(cin>>oddOrEven)){
            cout<<"Enter valid word.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          toLowerCase(oddOrEven);
          if(oddOrEven=="even") st1.remove(true);
          else if(oddOrEven=="odd"){st1.remove(false);}
          else{cout<<"Enter valid word.\n";}
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
          }
        case 4:
          int evens, odds;
          cout<<"Enter how many even numbers you want to remove from staque: ";
          while(!(cin>>evens)){
            cout<<"Enter valid number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          cout<<"Enter how many odd numbers you want to remove from staque: ";
          while(!(cin>>odds)){
            cout<<"Enter valid number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          st1.remove(evens, odds);
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 5:
          int numberToRemove;
          cout<<"Enter number to remove from staque: ";
          while(!(cin>>numberToRemove)){
            cout<<"Enter valid number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          st1.removeValue(numberToRemove);
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 6:
          cout<<st1;
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 7:
          int numberToSearch;
          cout<<"Enter number to search in staque: ";
          while(!(cin>>numberToSearch)){
            cout<<"Enter valid number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
          }
          st1.count(numberToSearch);
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
        case 8:
          {
          st1.reverse();
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
          }
        case 9:
          {
          Staque st2(st1);
          cout<<"Before\n";
          cout<<"Staque 1:\n"<<st1;
          cout<<"Staque 2 (copied):\n"<<st2;
          cout<<"Removed value from Staque 2 to show that it's deep copy.\n";
          st2.remove();
          if(!st2.validateIntegrity()) cout<<"Something is wrong with newly created staque.\n";
          cout<<"After\n";
          cout<<"Staque 1:\n"<<st1;
          cout<<"Staque 2 (copied):\n"<<st2;
          st2.clear();
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
          }
        case 10:
          {
          Staque st3=createStaqueForComparing();
          cout<<"Staque 1:\n"<<st1;
          cout<<"Staque 2 (created for comparing):\n"<<st3;
          cout << ((st1 == st3) ? "Equal\n" : "Not equal\n");
          st3.clear();
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
          }
        case 11:
          {
          st1.clear();
          if(!st1.validateIntegrity()) cout<<"Something is wrong with main staque.\n";
          break;
          }
      }
    }
    catch(const exception& e){cout<<e.what();}
  }while(ch!=12);
}
