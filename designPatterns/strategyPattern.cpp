#include <iostream>
#include <string>

using namespace std;

class SwordMaterial{
public:
  virtual double getDamage() const = 0;
  virtual double getDurability() const = 0;
  virtual ~SwordMaterial() = default;
};

class WoodSword : public SwordMaterial{
public:
  double getDamage() const override{
    return 10.5;
  }
  double getDurability() const override{
    return 20.2;
  }
};

class DiamondSword : public SwordMaterial{
public:
  double getDamage() const override{
    return 50.8;
  }
  double getDurability() const override{
    return 80.6;
  }
};

class GoldSword : public SwordMaterial{
public:
  double getDamage() const override{
    return 35.8;
  }
  double getDurability() const override{
    return 30.9;
  }
};

class Sword{
private:
  SwordMaterial* material;
public:
  Sword(SwordMaterial* material){
    this->material = material;
  }
  void showStats(){
    cout << "Damage: "<< material->getDamage()<<endl;
    cout<<"Durabillity: "<< material->getDurability()<<endl;
  }
  void changeSword(SwordMaterial* otherMaterial){
    material = otherMaterial;
  }
};

class Player{
private:
  double hp;
  Sword sword;
public:
  Player(double hp, Sword sword) : hp(hp), sword(sword) {}
  void showPlayerStats(){
    cout<<"HP: "<< hp <<endl;
    sword.showStats();
  }
  void changeSword(SwordMaterial* material){
    sword.changeSword(material);
  }
};

int main(){
  WoodSword wood;
  GoldSword gold;
  DiamondSword diamond;
  
  Sword sword(&wood);

  Player player(100, sword);
  player.showPlayerStats();

  player.changeSword(&gold);
  player.showPlayerStats();

  player.changeSword(&diamond);
  player.showPlayerStats();
  return 0;
}
