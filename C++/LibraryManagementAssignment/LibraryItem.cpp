#include "LibraryItem.h"

int LibraryItem::get_ID() const {
  return id;
}

string LibraryItem::get_Title() const {
  return title;
}

string LibraryItem::get_Author_OR_Creator() const {
  return creator;
}

int LibraryItem::get_Publication_Year() const {
  return publicationYear;
}

bool LibraryItem::get_Availability() const {
  return available;
}

void LibraryItem::borrowItem(const string& name){
  borrowInfo.borrowerName = name;
  borrowInfo.borrowDate = std::chrono::system_clock::now();
  available = false;
}

int LibraryItem::calculateOverdueDays(){
  // Calculates how many hours book was borrowed and convers it to days.
  // if it was borrowed for 47 hour, function returns 1day and so on.
  // it basically uses floor.
  auto duration = std::chrono::system_clock::now() - borrowInfo.borrowDate;
  auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
  return hours.count() / 24;
}

void LibraryItem::returnedItem(){
  borrowInfo.borrowerName = "";
  available = true;
}

bool LibraryItem::operator<(const LibraryItem& other) const {
    return this->available > other.available;
}

bool LibraryItem::operator==(const LibraryItem& other) const {
  return this->id == other.id;
}

ostream& operator<<(ostream& out, const LibraryItem& item){
  item.display(out);
  return out;
}
