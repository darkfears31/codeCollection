#include "PuzzleSession.h"

void PuzzleSession::display(ostream& o) const {
  GameSession::display(o);
  o<<"Levels Completed: "<<levelsCompleted<<"\nHints Used: "<<hintsUsed<<endl;
}
void PuzzleSession::read(istream& i) {
  GameSession::read(i);
  i>>levelsCompleted>>hintsUsed;
}
double PuzzleSession::calculateRating() const {
  return (getScore() * 0.8) - (hintsUsed * 5) + (levelsCompleted * 20);
}
