#include <iostream>
using namespace std;

#include "circle.h"

void Circle::SetRadis(int r) {
radius = r;
}
int Circle::GetRadius() {
return radius;
}
double Circle::Circle::getArea(){
return 3.14*radius*radius;
}