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
    cout<<"�� ���� ���� �Է��ϼ���."<<endl;
    int a, b;
    cin>>a>>b;
    Adder adder(a,b);
    cout<<adder.process()<<endl;
}
void cal(){
    Calculator calc;  //class ���� ����
    calc.run();       //class ����
    //���ο��� �����ϱ� ���� �Լ�
    //cal �ȿ��� Calculator ���� �ȿ��� adder process�� ����
}