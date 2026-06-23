#include "GameSession.h"

string GameSession::getPlayerID() const{
  return playerID;
}
int GameSession::getScore() const{
  return score;
}

void GameSession::display(ostream& o) const{
  o<<"Player ID: "<<playerID<<"\nGame Name: "<<gameName<<"\nDuration: "<<duration<<"\nScore: "<<score<<"\nAccuracy: "<<accuracy<<"\nTime Stamp: "<<timeStamp<<endl;
}

void GameSession::read(istream& i){
  i>>playerID>>gameName>>duration>>score>>accuracy>>timeStamp;
}

bool GameSession::operator<(const GameSession& other){
  return score<other.score;
}
bool GameSession::operator>(const GameSession& other){
  return score>other.score;
}
bool GameSession::operator==(const GameSession& other) const {
  return playerID == other.playerID && timeStamp == other.timeStamp;
}

ostream& operator<<(ostream& o, const GameSession& a){
  a.display(o);
  return o;
}
istream& operator>>(istream& i, GameSession& a){
  a.read(i);
  return i;
}

