#ifndef CAL_H
#define CAL_H

class Adder{
    int op1,op2;
public:
    Adder(int a, int b); //생성자
    int process();       //포함 함수
};

class Calculator{
public:
    void run();     //포함 함수
};
#endif