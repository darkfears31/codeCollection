// Observer Strategy

#include <iostream>
#include <vector>

using namespace std;
class Subscriber;

class AmazonItem{
private:
  string name;
  double price;
  bool Available;
  vector<Subscriber*> subscribers;
public:
  AmazonItem(string name, double price, bool Available){
    this->name=name;
    this->price = price;
    this->Available = Available;
  }
  void printItem(){
    cout<<name<<", Price "<<price<<", Available: "<<(Available ? "yes " : "no ")<<endl;
  }

  void subscribe(Subscriber* a){
    subscribers.push_back(a);
  }

  void unsubscribe(Subscriber* a);

  void notify();
  void setPrice(double price){
    this->price=price;
    notify();
  }
  void setAvailability(bool Available){
    this->Available=Available;
    notify();
  }

  string getName() const{
    return name;
  }

};


class Subscriber{
  string name;
public:
  Subscriber(string name){
    this->name=name;
  }
  ~Subscriber()=default;
  void update(AmazonItem& item){
    cout<<name<<" got notified that details changed in item:\n"; 
    item.printItem();
  }
  string getName() const{
    return name;
  }
};

void AmazonItem::notify(){
  for(auto a : subscribers){
    a->update(*this);
  }
}

void AmazonItem::unsubscribe(Subscriber* a){
  for(int i=0;i<subscribers.size();i++){
    if(subscribers[i] == a){
      subscribers.erase(subscribers.begin()+i);
      cout<<a->getName()<<" unsubscribed - "<<name<<endl;
      break;
    }
  }
}

int main(){

  AmazonItem Ball("Ball", 45, true);
  AmazonItem Headphone("Headphone", 120, true);

  Subscriber bob("Bob");
  Subscriber tom("Tom");
  Subscriber john("John");
  Subscriber kate("Kate");
  
  // Subscribing to Ball
  Ball.subscribe(&bob);
  Ball.subscribe(&kate);
  Ball.subscribe(&tom);

  cout<<"First change\n\n";
  Ball.setPrice(15.2);
  cout<<"\nFirst change\n";

  //Subscribing and unsubscribing to Ball
  Ball.subscribe(&john);
  Ball.unsubscribe(&tom);

  cout<<"\nSecond change\n\n";
  Ball.setPrice(25.2);
  cout<<"\nSecond change\n";

  Ball.unsubscribe(&bob);
  
  cout<<"\nThird change\n\n";
  Ball.setAvailability(false);
  cout<<"\nThird change\n";

  // Subscribing to Headphone.
  Headphone.subscribe(&bob);
  Headphone.subscribe(&kate);
  Headphone.subscribe(&tom);

  cout<<"\nFirst change\n\n";
  Headphone.setPrice(15.2);
  cout<<"\nFirst change\n";

  //Subscribing and unsubscribing to Ball
  Headphone.subscribe(&john);
  Headphone.unsubscribe(&tom);

  cout<<"\nSecond change\n\n";
  Headphone.setPrice(25.2);
  cout<<"\nSecond change\n";
  
  Headphone.unsubscribe(&kate);

  cout<<"\nThird change\n\n";
  Headphone.setAvailability(false);
  cout<<"\nThird change\n";

}
