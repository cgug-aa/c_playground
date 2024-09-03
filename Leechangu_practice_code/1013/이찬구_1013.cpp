/*
5.2 분할 컴파일
헤더 파일과 cpp파일을 분리해서 저장
#include "Circle.h" 라고 선언하고,
-파일에 중복 선언하면 에러발생
-sol) #ifndef CIRCLE_H  #define CIRCLE_H (클래스) #endif
 헤더파일을 만들 때 습관적으로 #ifndef를 적는게 좋음

Circle.h파일

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
cout << "donut 면적은 " << area << endl;
Circle pizza;
pizza.SetRadis(30);

area = pizza.getArea();
cout << "pizza 면적은 " << area << endl; 
}
