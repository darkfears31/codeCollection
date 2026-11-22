#include <iostream>
#include <deque>
using namespace std;

template <typename T>
struct Memento {
  T state;
};

class Calculator {
public:
  int value = 0;
  Memento<int> save() {
    return Memento<int>{value};
  }
  void restore(Memento<int> memento) {
    value = memento.state;
  }
};

class App {
public:
  Calculator calculator;
  deque<Memento<int>> history;
  void add(int number) {
    history.push_back(calculator.save());
    if (history.size() > 5) {
      history.pop_front();
    }
    calculator.value += number;
  }

  void undo() {
    if (history.empty()) {
        cout << "Nothing to undo." << endl;
        return;
    }
    Memento<int> memento = history.back();
    history.pop_back();
    calculator.restore(memento);
  }

  void print() {
    cout << calculator.value << endl;
  }
};

int main() {
  App app;
  app.add(5);
  app.add(10);
  app.print();

  app.add(1);
  app.add(2);
  app.add(3);
  app.print();

  for (int i = 0; i < 7; i++) {
    app.undo();
    app.print();
  }
}
