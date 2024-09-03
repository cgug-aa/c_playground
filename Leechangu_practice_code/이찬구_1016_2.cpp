#include <iostream>
using namespace std;
/*
class�� ��� ��ġ�� ���α׷��� ������ ��ü�� �� �� ����
class A�� class B�� ��ġ�� ���� �����Ǵ� ������ ���� �� �ִµ�
�̸� static ���� ������ �� �ִ�. 

����)
*/
class Person_1 {
public:
    double money;       // ���� ������ ��
    void addMoney(int money_in) {
        money += money_in;
    }
    static int sharedMoney_1; // ����
    static void addShared(int n) {
        sharedMoney_1 += n;
    }
};
int Exprac()
{
    Person_1 A, B;   //���δٸ� class
    //������ ��ġ�� �ʹ�~ �̰� static���� ��߰ڳ�
    //A.sharedMoney =B.sharedMoney  
    A.sharedMoney_1=100;
    B.sharedMoney_1=200;
    //������ sharedMoney�� ���� ������ ����غ���
    //cout<<A.sharedMoney<<endl; //200�� ��µ�
    cout<<Person_1::sharedMoney_1<<endl;
    //Person::sharedMoney�� ������ �� ���� �� �򰥸�
}

int Person_1::sharedMoney_1=10; //sharedMoney�� 10���� �ʱ�ȭ
//�̷��� static������ �����س�����. �۷ι� ����ó��
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

//�ۿ� �Լ��� �ۼ��ص� ������, ��ɿ� ���� 
//�Լ��� �����ϴ°� �ĺ��ϱ� ���ϹǷ� ����Ѵ�.
/*
----------------------------------------------
*/
class Person{
public:
    double money;       // ���� ������ ��
    void addMoney(int money_in) {
        money += money_in;
    }
    static int sharedMoney; // ����
    static void addShared(int n) {
        sharedMoney += n;
    }
    string name;    //��ü�̸�
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
// 3��
A.addMoney(100);
A.addShared(5);
B.addMoney(200);
B.addShared(5);
// 4��
A.addMoney(100);
A.addShared(5);
B.addMoney(200);
B.addShared(5);
cout << "���� = " << Person::sharedMoney << endl;
Person::addShared(100);
cout << "���� = " << Person::sharedMoney << endl;
}