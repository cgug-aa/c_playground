#include<iostream>
#include<string>
#include "cal.h"
using namespace std;

Adder::Adder(int a, int b){
    op1=a;
    op2=b;
}
int Adder::process(){
    return op1+op2;
}

void Calculator::run(){
    cout<<"두 개의 수를 입력하세요."<<endl;
    int a, b;
    cin>>a>>b;
    Adder adder(a,b);
    cout<<adder.process()<<endl;
}
void cal(){
    Calculator calc;  //class 변수 선언
    calc.run();       //class 실행
    //메인에서 실행하기 위한 함수
    //cal 안에서 Calculator 실행 안에서 adder process를 실행
}