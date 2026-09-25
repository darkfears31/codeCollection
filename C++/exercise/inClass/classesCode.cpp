#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    double grade;

public:
  Student()=default;
  Student(int id, string firstName, string lastName, double grade) {
    this->id=id;
    this->firstName=firstName;
    this->lastName=lastName;
    this->grade=grade;  
  }
  int getId() const{
    return this->id;
  }
  string getFirstName() const{
    return this->firstName;
  }
  string getLastName() const{
    return this->lastName;
  }
  double getGrade() const{
    return this->grade;
  }

  void setGrade(double grade);
  void display(ostream& o) const;
  bool operator<(Student s){
    return this->grade<s.grade;
  }
  void read(istream& i);
};

void Student::display(ostream& o) const{
  o<<id<<' '<<firstName<<' '<<lastName<<' '<<grade<<endl;
}

void Student::read(istream& i){
  i>>id>>firstName>>lastName>>grade;
}

ostream& operator<<(ostream& o, const Student& s){
  s.display(o);
  return o;
}
istream& operator>>(istream& i, Student& s){
  s.read(i);
  return i;
}

bool isDuplicateId(const vector<Student>& students, int id) {
  // TODO: Use find_if to search for a student with the given ID.
  auto it = find_if(students.cbegin(), students.cend(), [id](const Student& s){return s.getId()==id;});
  if(it!= students.end()) return true;
  else {return false;}
}

bool loadStudentsFromFile(vector<Student>& students, const string& filename) {
  ifstream f(filename);
  if(!f.is_open()){
    cout<<"Error Opening File\n";
    return false;
  }
  int id;
  string fn, ln;
  double grade;
  while(f>>id>>fn>>ln>>grade){
    if(grade<0 || grade>100) continue;
    if(isDuplicateId(students, id)) continue;
    Student s(id, fn, ln, grade);
    students.push_back(s);
  }
  f.close();
  return true;
}

void addStudent(vector<Student>& students) {
  int id;
  string fn, ln;
  double grade;
  cout<<"Enter ID: ";
  cin>>id;
  if(isDuplicateId(students, id)) return; 
  cout<<"Enter First Name: ";
  cin>>fn;
  cout<<"Enter Last Name: ";
  cin>>ln;
  cout<<"Enter Grade: ";
  cin>>grade;
  if(grade<0 || grade>100) return;
  Student s(id, fn, ln, grade);
  students.push_back(s);
  cout<<'\n';
}

void displayAllStudents(const vector<Student>& students) {
  // TODO: Use an iterator-based loop to display all students.
  for(auto s:students){
    cout<<s<<endl;
  }
}

void sortStudentsByGrade(vector<Student>& students) {
  // TODO: Use sort to arrange students by grade in descending order.
  sort(students.begin(), students.end());
}

void sortStudentsByLastName(vector<Student>& students) {
  // TODO: Use sort to arrange students alphabetically by last name.
  sort(students.begin(), students.end(), [](Student& s1, Student& s2){return s1.getLastName()<s2.getLastName();});
}

void searchStudentById(const vector<Student>& students) {
    // TODO: Read the ID to search for, use find_if to search for the student.
    // TODO: Display the student if found, otherwise display an error message.
  int studID;
  cout<<"ID to search for: ";
  cin>>studID;
  auto it = find_if(students.cbegin(), students.cend(), [studID](const Student& s){return s.getId()==studID;});
  if(it!= students.end()){
    cout<<*it;
  }
  else {cout<<"Error\n";}
}

void countPassedStudents(const vector<Student>& students) {
    // TODO: Use count_if to count students with grade >= 51 and display the number of passed students.
  int gradesAbove = count_if(students.cbegin(), students.cend(), [](const Student& s){ return s.getGrade()>=51;});
  cout<<"Grades above or equal to 51: "<<gradesAbove<<endl;
}

void displayStudentsAboveGrade(const vector<Student>& students) {
    // TODO: Ask the user to enter the minimum grade.
    // TODO: Create a vector for filtered students.
    // TODO: Use copy_if to copy students with grade above the given value.
    // TODO: Use for_each to display the filtered students.
  double minGrade;
  cout<<"Enter Minimum grade: ";
  cin>>minGrade;
  vector<Student> studsAboveGrade;
  studsAboveGrade.resize(students.size());
  copy_if(students.begin(), students.end(), back_inserter(studsAboveGrade), [minGrade](const Student& s) {return s.getGrade()>=minGrade;});
  for_each(studsAboveGrade.begin(), studsAboveGrade.end(), [](Student& s){cout<<s;});

}

void displayHighestGradeStudent(const vector<Student>& students) {
    // TODO: Check if the vector is empty. Use max_element to find the student with the highest grade.
    // TODO: Display the result.
  if(!students.empty()){
   auto it = max_element(students.begin(), students.end(), [](const Student& s1, const Student& s2){return s1.getGrade()<s2.getGrade();});
   cout<<*it;
  }
  else{cout<<"Empty.\n";}
}

void calculateAverageGrade(const vector<Student>& students) {
    // TODO: Check if the vector is empty and use accumulate to calculate the total grade.
    // TODO: Calculate and display the average.

  if(!students.empty()){
   double sum = accumulate(students.begin(), students.end(), 0.0, [](double i, const Student& s){return i+s.getGrade();});
   cout<<"Average Grade: "<< sum/students.size()<<'\n';
  }
  else{cout<<"Empty.\n";}
}

void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    // do not forget to check if the file opened successfully.
  ofstream f(filename);
  if(f.is_open()){
    for(auto s:students){
      f<<s;
    }
  }
  else {cout<<"Empty.\n";}
}

void displayMenu() {
    cout << "\n===== Student Grade Management System =====\n";
    cout << "1. Add a student\n";
    cout << "2. Display all students\n";
    cout << "3. Sort students by grade\n";
    cout << "4. Sort students by last name\n";
    cout << "5. Search student by ID\n";
    cout << "6. Count students who passed\n";
    cout << "7. Display students above a given grade\n";
    cout << "8. Display student with highest grade\n";
    cout << "9. Calculate average grade\n";
    cout << "10. Save and exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Student> students;
    int choice;

    loadStudentsFromFile(students, "students.txt");

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students);
            break;

        case 2:
            displayAllStudents(students);
            break;

        case 3:
            sortStudentsByGrade(students);
            break;

        case 4:
            sortStudentsByLastName(students);
            break;

        case 5:
            searchStudentById(students);
            break;

        case 6:
            countPassedStudents(students);
            break;

        case 7:
            displayStudentsAboveGrade(students);
            break;

        case 8:
            displayHighestGradeStudent(students);
            break;

        case 9:
            calculateAverageGrade(students);
            break;

        case 10:
            saveStudentsToFile(students, "students.txt");
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 10);

    return 0;
}
