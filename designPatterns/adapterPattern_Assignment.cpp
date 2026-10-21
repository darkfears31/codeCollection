#include <iostream>
#include <vector>
using namespace std;

class Triangle{
private:
  double sideA;
  double sideB;
  double sideC;
public:
  Triangle(double sideA,double sideB,double sideC){
    this->sideA = sideA;
    this->sideB=sideB;
    this->sideC=sideC;
  }
  virtual double getPerimeter(){
    return sideA+sideB+sideC;
  }
};

class Rectangle{
private:
  double sideA;
  double sideB;
  double sideC;
  double sideD;
public:
  Rectangle(double sideA, double sideB, double sideC, double sideD) : sideA(sideA), sideB(sideB), sideC(sideC), sideD(sideD) {}
  double getPerimeter(){
    return sideA+sideB+sideC+sideD;
  }
};

class SuperMath{
public:
  void sumOfTrianglesPerimeters(vector<Triangle*> triangles, int size){
    double sum=0;
    for(int i=0;i<size;i++){
      sum+=triangles[i]->getPerimeter();
    }
    cout<<"Sum is: "<<sum<<endl;
  }
};

class TriangleAdapter : public Triangle{
private:
  Rectangle& rectangle;
public:
  TriangleAdapter(Rectangle& rectangle) : Triangle(0,0,0), rectangle(rectangle) {}
  double getPerimeter() override{
    return rectangle.getPerimeter();
  }
};

int main(){
  SuperMath superMath;
  Triangle t1(3, 6, 4);
  Triangle t2(9, 4, 5);
  Triangle t3(12,15,17);
  Rectangle rectangle(5,6,7,8);
  TriangleAdapter adapter(rectangle);
  vector<Triangle*> triangles = {&t1, &t2, &t3, &adapter};
  int size = triangles.size();
  superMath.sumOfTrianglesPerimeters(triangles,size);

  return 0;
}
