#include <iostream>
using namespace std;

//Ŭ���� ����
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
        cout<<"�ݰ� = "<<radius<<endl;    }
}; 