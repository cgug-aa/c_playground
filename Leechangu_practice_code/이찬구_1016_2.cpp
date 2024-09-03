#include <iostream>
using namespace std;
/*
class로 묶어서 합치면 프로그램을 각각의 개체로 볼 수 있음
class A와 class B를 합치다 보면 공유되는 변수가 있을 수 있는데
이를 static 으러 선언할 수 있다. 

예제)
*/
class Person_1 {
public:
    double money;       // 개인 소유의 돈
    void addMoney(int money_in) {
        money += money_in;
    }
    static int sharedMoney_1; // 공금
    static void addShared(int n) {
        sharedMoney_1 += n;
    }
};
int Exprac()
{
    Person_1 A, B;   //서로다른 class
    //공금은 합치고 싶다~ 이건 static으로 써야겠네
    //A.sharedMoney =B.sharedMoney  
    A.sharedMoney_1=100;
    B.sharedMoney_1=200;
    //실제로 sharedMoney는 공유 변수라서 출력해보면
    //cout<<A.sharedMoney<<endl; //200이 출력됨
    cout<<Person_1::sharedMoney_1<<endl;
    //Person::sharedMoney로 접근할 수 있음 덜 헷갈림
}

int Person_1::sharedMoney_1=10; //sharedMoney를 10으로 초기화
//이렇게 static변수를 선언해놔야함. 글로벌 변수처럼
/*
---------------------------------------------------
*/

class Math{
public:
    static int cg_abs(int a){
         return a>0?a:-a; }
    static int cg_max(int a, int b) {
         return (a>b)?a:b; }
    static int cg_min(int a, int b) {
         return (a>b)?b:a; }
};

int Exprac2() {
cout << Math::cg_abs(-5) << endl;
cout << Math::cg_max(10, 8) << endl;
cout << Math::cg_min(-3, -8) << endl;
}

//밖에 함수를 작성해도 되지만, 기능에 따라 
//함수를 구분하는게 식별하기 편리하므로 사용한다.
/*
----------------------------------------------
*/
class Person{
public:
    double money;       // 개인 소유의 돈
    void addMoney(int money_in) {
        money += money_in;
    }
    static int sharedMoney; // 공금
    static void addShared(int n) {
        sharedMoney += n;
    }
    string name;    //객체이름
    Person(){money=0;}
    Person(string name_in){
        money=0;
        name=name_in;
    };
    ~Person(){
      cout<<name<<"'s money = "<<money<<endl;  
    }
};
int Person::sharedMoney=0;

int main() {
Person A("KANG"), B("KIM");
// 3월
A.addMoney(100);
A.addShared(5);
B.addMoney(200);
B.addShared(5);
// 4월
A.addMoney(100);
A.addShared(5);
B.addMoney(200);
B.addShared(5);
cout << "공금 = " << Person::sharedMoney << endl;
Person::addShared(100);
cout << "공금 = " << Person::sharedMoney << endl;
}