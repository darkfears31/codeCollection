#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
using namespace std;

class GameSession{
private:
  string playerID;
  string gameName;
  int duration;
  int score; // Seconds
  double accuracy; // 0-100
  long timeStamp;
public:
  virtual ~GameSession() = default;
  GameSession() = default;
  GameSession(string playerID, string gameName, int duration, int score, double accuracy, long timeStamp){
    this->playerID=playerID;
    this->gameName=gameName;
    this->duration=duration;
    this->score=score;
    this->accuracy=accuracy;
    this->timeStamp=timeStamp;
  }
  int getScore() const;
  string getPlayerID() const;
  virtual double calculateRating() const =0;
  virtual string getGameType() const =0;
  virtual void display(ostream& o) const;
  virtual void read(istream& i);
  bool operator<(const GameSession& other);
  bool operator>(const GameSession& other);
  bool operator==(const GameSession& other) const;
};

ostream& operator<<(ostream& o, const GameSession& a);
istream& operator>>(istream& i, GameSession& a);


#endif
