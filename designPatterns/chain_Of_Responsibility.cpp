#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

template <class T>
class Handle{
public:
  virtual ~Handle()=default;
  virtual T handle(T text)=0;
  virtual void setNext(Handle<T>* next)=0;
};

template <class T>
class baseHandler : public Handle<T>{
protected:
  Handle<T>* next=nullptr;
public:

  void setNext(Handle<T>* n) override{
    next=n;
  }

  T handle(T request) override{
    if(next!=nullptr){
      return next->handle(request);
    }
    return request;
  }
};
class EncryptHandler : public baseHandler<string> {
private:
  int move;
public:
  EncryptHandler(int move=0){
    this->move=move;
  }
  string handle(string text) override{
    string tmp="";
    for(char c : text){
      int charInInt = c +3;
      tmp+=to_string(static_cast<char>(c))+ ' ';
    }
    text=tmp;
    return baseHandler<string>::handle(text);
  }
};


class toASCII_Handler : public baseHandler<string>{
protected:
public:
  string handle(string text) override{
    string ASCIItext = "";
    for(char c:text){
      ASCIItext+=to_string(static_cast<char>(c))+ ' ';
    }
    return baseHandler<string>::handle(ASCIItext);
  }
};

class WrappingHandler : public baseHandler<string> {
private:
  string prefix;
  string suffix;
public:
  WrappingHandler(string prefix="", string suffix=""){
    this->prefix=prefix;
    this->suffix=suffix;
  }
  string handle(string text) override{
    text = prefix+text+suffix;
    return baseHandler<string>::handle(text);
  }
};


int main(){

  string someString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
  Handle<string>* h1=new EncryptHandler(3);
  Handle<string>* h2=new toASCII_Handler();
  Handle<string>* h3=new WrappingHandler("[", "}");

  h1->setNext(h2);
  h2->setNext(h3);
  string response=h1->handle(someString);
  cout<<"response: "<<response<<endl;
  delete h1;
  delete h2;
  return 0;
}
