/*
5.2 ���� ������
��� ���ϰ� cpp������ �и��ؼ� ����
#include "Circle.h" ��� �����ϰ�,
-���Ͽ� �ߺ� �����ϸ� �����߻�
-sol) #ifndef CIRCLE_H  #define CIRCLE_H (Ŭ����) #endif
 ��������� ���� �� ���������� #ifndef�� ���°� ����

Circle.h����

class Circle {
private:
int radius;
public:
void SetRadis();
int GetRadius();
double getArea();
};
 
*/

#include <iostream>
using namespace std;
#include "circle.h"

#ifndef CIRCLE_H
#define CIRCLE_H

#endif

int main(){
Circle donut;
donut.SetRadis(1);

double area = donut.getArea();
cout << "donut ������ " << area << endl;
Circle pizza;
pizza.SetRadis(30);

area = pizza.getArea();
cout << "pizza ������ " << area << endl; 
}
