// Adapter - dog eating cats food example.
#include <iostream>

using namespace std;


class Cat{
public:
  virtual void eatQuietely(string foodname){
    cout<<"I cat, am eating "<<foodname<<endl;
  }
};

class Dog{
public:
  void eatQuietely(string foodname){
    cout<<"I Dog, am eating "<<foodname<<endl;
  }
};

class Zoo{
public:
  void feedCatFoodTo(Cat cat){
    cout<<"Starting to feed cat...\n";
    cat.eatQuietely("Delicious cat food.");
    cout<<"Done feeding cat.\n";
  }
};

class CatAdapter : public Cat{
private:
  Dog& dog;
public:
  CatAdapter(Dog& dog) : dog(dog) {}
  void eatQuietely(string foodName) override {
    dog.eatQuietely(foodName);
  }
};


int main(){
  Zoo* zoo = new Zoo();
  Dog* dog = new Dog();
  Cat* cat = new Cat();
  CatAdapter adapter(*dog);
  zoo->feedCatFoodTo(*cat);
  zoo->feedCatFoodTo(adapter);

  delete zoo;
  delete dog;
  delete cat;
  return 0;
}
