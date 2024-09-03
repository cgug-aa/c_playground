#include <iostream>
using namespace std;

//클래스 선언
class Circle {
private:
    int radius;
public:
    void SetRadis(int r);
    int GetRadius();
    double getArea(); 
    Circle(){
        radius=0;
    };
    ~Circle(){
        cout<<"반경 = "<<radius<<endl;    }
}; 