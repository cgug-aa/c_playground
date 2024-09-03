#include <iostream>
#include<string.h>
using namespace std;

/*
�������� ��ü�� �������
��ü�� �迭ó�� ������ ������ �� �ִ�.
��ü�̸��� �ε����� ���ٰ� ������ �� �ִ�. ��ü�̸�[i]=�ϳ��� ��ü

*/

class Circle1020 {
    int radius;
public:
    Circle1020() { radius = 1; }   //�����ڴ� ��ȯ���� ����.
    Circle1020(int r) { radius = r; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    double getArea();
    ~Circle1020() { radius = 0; }
};

double Circle1020::getArea() {
    return 3.14 * radius * radius;
}

int Ex1020_01() {
    Circle1020 cir[3] = { Circle1020(10), Circle1020(20), Circle1020(30) };

    cir[0].setRadius(100);
    cir[1].setRadius(200);
    cir[2].setRadius(300);

    for (int i = 0; i < 3; i++) {
        cout << "����" << cir[i].getArea() << endl;
    }

    Circle1020* p;      //���� *p�� * p�� �ٸ���
    p = cir;         //cir�� cir[0]�� �ּҸ� ������ �ִ�
    //(*p).setRadius(-100);    //*p�� ���� cir[0]�̹Ƿ� ���� cir[0]�� �ٲ��. 
    p->setRadius(-100);   //�� ����� �����ϴ�

    p = &(cir[1]);   //p�� �ּ� ���� �̹Ƿ� &�� ���� �ּҸ� �־���� �Ѵ�. ������ ������ �ȵ�
    p->setRadius(-100); //cir[1]�� ������ �ٲ�

    p++; //cir[1]���� cir[2]�� �ּҷ� �ٲ���   (*p)�� p->�� ���� �ǹ�
    p->setRadius(-100); //cir[2]�� ������ �ٲ�

    (*p).setRadius(-500); //cir[2]�� ���� -500�� ��

    /////////////////////////////////////////////////////////////////
    p = cir;

    p[0].setRadius(-400);   //cir��� p�� �� �� �ִ�.
    p[1].setRadius(-400);
    p[2].setRadius(-400);

    return 0;
}

class Color {
    int red, green, blue;
public:
    Color() { red = green = blue = 0; }
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
    void setColor(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }

    void showColor() {
        cout << "(r, g, b)= " << red << " " << green << " " << blue << endl;
    }

};

int Ex1020_2() {
    Color screenColor(255, 0, 0); // �������� screenColor ��ü ����
    Color* p;                     // Color Ÿ���� ������ ���� p ����
    p = &screenColor; // (1) p�� screenColor(��ü)�� �ּҸ� �������� �ڵ� �ۼ� ���� &�� �ٲ������
    p->showColor();               // (2) p�� show()�� �̿��Ͽ� screenColor �� ���
    Color colors[3];              // (3) Color�� ������ �迭 colors ����. ���Ҵ� 3��
    p = colors;                   // (4) p�� colors �迭�� ����Ű���� �ڵ� �ۼ�

    // (5) p�� setColor()�� �̿��Ͽ� colors[0], colors[1], colors[2]��
    // ���� ����, �ʷ�, �Ķ����� �������� �ڵ� �ۼ�
    p[0].setColor(255, 0, 0);
    p[1].setColor(0, 255, 0);
    p[2].setColor(0, 0, 255);

    // (6) p�� show()�� �̿��Ͽ� colors �迭�� ��� ��ü�� �� ���. for �� �̿�
    for (int i = 0; i < 3; i++) {
        p[i].showColor();   //(p+1)->showColor; �ε� �����ϴ�
        //(*(p+1))->showColor; �ε� ����
    }
    return 0;
}
class allocTEST {
public:
    int* data;
    int size;
    allocTEST() {
        data = NULL;
    }
    allocTEST(int size_in) {
        data = new int[size_in];
        size = size_in;
    }
    ~allocTEST() {
        delete[] data;        //�̷��� �ڵ����� �������ָ鼭 ����
    }

};
int Ex1023_1()
{
    allocTEST E(100);
    for (int i = 0; i < E.size; i++) {
        E.data[i];
    }

    int A[3];
    A[0] = 100;    A[1] = 200;    A[2] = 300;

    printf(" %ld", A);
    //A = 100, �Ұ�

    int* B = (int*)malloc(3 * sizeof(int));   //3ĭ ¥�� ���� ����
    B[0] = 100;   B[1] = 200;   B[2] = 300;

    free(B);

    //������ ��õ ���   ��� �Ҵ��ϰ� �����Ҷ� ��� �� �� ����(malloc�̶� free����, new�� delete������ ����)
    float* C = new float[3];                    //�̷��Ե� �� �� �־�
    C[0] = 100;   C[1] = 200;   C[2] = 300;
    delete[] C;

    int n = 100;
    int* p;
    p = &n;

    //int D[n];       //�迭�� �ε����� ������ �Ǽ� ���̿����Ѵ�.(���� �Ұ���)
    int* D = new int[n];  //�̷��Դ� �� �� �־�

    delete[] D;

    return 0;

}

class Member {
    string name;
public:
    Member() { name = ""; }      //����Ʈ ������
    //Member(string name_in) { this->name = name_in; }   //������ //this�� Ŭ������ �ҷ����� ���
    Member(string name_in) { name = name_in; }
    string getName() { return name; }         //�̸� ���
    void setName(string name_in) { name = name_in; }
};
class Family {
    string family_name;
    Member* p;// Member p[3]; // Member �迭 ������
    int size; // Member �迭�� ũ��. ���� ������ ��
public:
    Family() {};
    Family(string family_name_in, int size_in); // size ������ŭ Member �迭 ���� ����
    void setName(int index, string name_in);
    void show(); // ��� ���� ������ ���
    ~Family();
};

Family::Family(string family_name_in, int size_in) {
    size = size_in;
    family_name = family_name_in;        //�߿�
    p = new Member[size_in];

    if (p == NULL) {
        cout << "�޸� �Ҵ� ����" << endl;
    }
};

void Family::setName(int index, string name_in) {
    p[index].setName(name_in);
};
void Family::show() {
    for (int i = 0; i < size; i++)
        cout << p[i].getName() << endl;
}
Family::~Family()
{
    delete[] p;
}

int Ex1023_2() {

    Family simpson; //Family simpson("Simpson", 3); // 3������ ������ Simpson ����
    simpson.setName(0, "Mr. Simpson");
    simpson.setName(1, "Mrs. Simpson");
    simpson.setName(2, "Bart Simpson");
    simpson.show();
    //���Ʒ��� �Ȱ��� ����� �Ѵ�.
    Family* LEE = new Family("LEE", 4);
    LEE->setName(0, "Mr. LEE"); // (*LEE).setName(0, "Mr.LEE");
    LEE->setName(1, "Mrs. LEE");
    LEE->setName(2, "LEE's son");
    LEE->setName(3, "LEE's daughter");
    LEE->show();

    return 0;

}

//���� ������
//���� ���� ȣ��� �Ű� ���� ��ü�� �����ڰ� ������� �ʴ� ����?
//ȣ��Ǵ� ������ ������ ��ü ���¸� �Ű� ���� ��ü�� �״�� �����ϱ� ����

//���� �ּҿ� ���� ȣ��� ����� ��

class _Circle_ {
private:
    int radius;
public:
    _Circle_() {this-> radius = 1; }       //this�� �����ص� ����
    _Circle_(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

void SwapCircle(_Circle_& A, _Circle_& B) {
    _Circle_ tmp;     //A�� B�� ���� ���� ȣ���� �ϸ� �ٸ� ��ü�� ��������Ƿ� ���� �ٲ��� ����
    tmp = A;          //����(&)�� ���� ȣ���� �ؾߵ� (_Circle_& A, _Circle_& B)
    A = B;
    B = tmp;
}
void SwapCircle(_Circle_* A, _Circle_* B) {
    _Circle_ tmp;     //���⼭�� �ּ��̴ϱ� �����͸� �ٿ���ߵ�
    tmp = *A;  
    *A = *B;
    *B = tmp;
}
void SwapCircle(_Circle_& A, _Circle_* B) {
    _Circle_ tmp;     //����� �� �� �ִ�.
    tmp = A;
    A = *B;
    *B = tmp;

}

int Ex1030_0() {      //swap�ϴ� �Լ��� ������ ���� ȣ���� �ǵ��� �ۼ�
    _Circle_ A(10), B(20);

    cout << "A ���� = " << A.getArea() << endl;
    cout << "B ���� = " << B.getArea() << endl;

    //_Circle_ tmp;    �̰Ÿ� ���� ������ �ڵ带 �ۼ��ؾ� ��
    //tmp = A;
    //A = B;
    //B = tmp;

    SwapCircle(A,B);          //������ ���� ȣ��
    //�Ʒ� � �ڵ� �� ��� �����ϱ�
    SwapCircle(&A, &B);       //������ ���
    SwapCircle(A, &B);

    cout << "A ���� =" << A.getArea() << endl;
    cout << "B ���� =" << B.getArea() << endl;

    return 0;
}
void readRadius(_Circle_& obj) {  //�׳� ��ΰ� �������� &���� �ϳ��� ���� ��
    cout << "[1]���� ������ �������� �Է��Ͻÿ�>>" << endl;
    int R;
    cin >> R;

    obj.setRadius(R);

}
void readRadius(_Circle_* obj) {  //�����ͷ� �غ��Կ�
    cout << "[2] ���� ������ �������� �Է��Ͻÿ�>>" << endl;
    int R;
    cin >> R;

    //(* obj).setRadius(R);  //�����ϱ� *�� ���巯��
    obj->setRadius(R);       //���İ� ����

}

int Ex1030_1()
{
    _Circle_ donut;
    readRadius(donut);      //���� �Ѱ��ָ� ������
    cout << "donut�� ���� = " << donut.getArea() << endl;
    readRadius(&donut);     //�ּҷ� �Ѱ��ָ� �����ͷ�
    cout << "donut�� ���� = " << donut.getArea() << endl;

    return 0;
}

class Accumulator {
    int value;     //private�ϱ� �ܺο��� ȣ�� �ȵ�,
public:
    Accumulator(int value); // �Ű����� value�� ��� value�� �ʱ�ȭ�Ѵ�.
    Accumulator& add(int n); // value�� n�� ���� ���� �����Ѵ�.
    int getValue(); // ������ �� value�� �����Ѵ�.
};
Accumulator::Accumulator(int value) {this->value = value;}
int Accumulator::getValue() { return value; }
Accumulator& Accumulator::add(int n)
{
    value += n;
    return *this;       //Accumulator�� ��ü�� ����
    //this �� �ּҴϱ� ���� ��Ÿ������ 
    
    //Accumulator tmp = *this;
    //return tmp;    !�̷� ��쿣 ��� �ɱ�!

//���ι� ó�� ������ acc.add(5)�� �ѹ��� ����
// this�� �ż� this-> add(6).add(7)�� �ǰ�
// this�� �ż� this->.add(7)�� �ȴ�.
}

//****PDF [����]�� ��°��� 28�� �ƴ϶� 15�̴�.

int Ex1030_2() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
    cout << acc.getValue() << endl; // 28 ���

    return 0;
}

//���� ������
//���� ����
//���� ����

int Ex1030_3()
{
    int data[5] = {1,2,3,4,5};
    int* ptr;      //�̰Ŵ� ���� ��ä�ε� �ּҸ� ������
                   //int ptr[5]�� �Ҷ��� ���� ��ä�� ���� ��´�=��������

    ptr = data;

    cout << *(ptr+1) << endl;     //ptr[1]

    return 0;
}

class _Student_ {
    char name[100];
public:
    _Student_() { strcpy(name, ""); }    //strcpy�� ù��° �ε����� �׸�, �ι�° �ε����� source�� �ִ´�
    _Student_(char* name) {
        strcpy(this->name, name);    
    }
    ~_Student_() {}
    void showName() { cout << "�̸��� " << name << endl; }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};

int Ex1030_4() {
    _Student_ A((char*)"KANG"), B((char*)"KIM");   //(char*)�� ���� �������� ����
    B = A;
    B.showName();
    B.setName((char*)"PARK");
    B.showName();
    A.showName();

    return 0;
}

class Student {
    char* name;
public:
    Student() {name=NULL; }    //
    Student(char* name) {
        int length = strlen(name);
        this->name = new char[length + 1];  //������ �齽������ �����༭ +1
        strcpy(this->name, name);
    }
    Student(Student& inputObj){   //���� ���������
        int length=strlen(inputObj.name);
        this->name=new char[length+1];
        strcpy(this->name,inputObj.name);
    }
    ~Student() {
        delete[] name;   //name�� �Ҵ��ؼ� ���� ������ ������ߵ�
    }
    void showName() {
        cout << "�̸��� " << name << endl;

    }
    void setName(char* name) {  //�����Ϸ��� ���� ����(�̸��� ����)�� �޶����� 
        //������ �߹Ƿ� �����ߴٰ� �ٽ� �������ش�.
        int length=strlen(name);
        delete[] this-> name;
        this->name=new char[length+1]; 

        strcpy(this->name, name);
    }
    Student clone(){

    }
};

int Ex1030_5()   //Ex1030_4�� ���غ���
{
    Student A((char*)"KANG");
    Student B = A;  
    B.showName();
    B.setName((char*)"PARKPARK");
    B.showName();
    A.showName();

    return 0;
}

//1103 �ǽ�

class Test{
public:
    int* data;
    int size;
    Test(){
        data=NULL;
        size=0;
    }
    void MemAlloc(int size){
        data=new int[size];
        this->size=size;
    }
    //���������:(1)�޸� �Ҵ� (2)�Ҵ�� �޸𸮿� ������ ����
    //��������ڵ� �������̹Ƿ�, ��ü�� ������ �� �ڵ� �����
    Test(Test& rightObj){
        this->data=new int[rightObj.size];
        for(int i=0;i<rightObj.size;i++){
            this->data[i]=rightObj.data[i];
        }
    }
    ~Test(){ delete[] data;}
};
int Ex1103_0()
{

/*    Test A, B;
    A.MemAlloc(5);
    for(int i=0;i<5;i++){
        A.data[i]=100*i;
    }

    //B=A;   //operator overriding
    // ���� ����� ���ǻ����� ����
    //A�� B �ȿ� data ������ ����
    //A.MemAlloc(5)�� ���� a�� data=2000�� ��
    //B=A�� ���� b�� data=2000�� ��.
    //�Ҵ��� a�� �߰�, �ּҸ� �����ؼ� b�� ��
    //(�ּҰ� ������ �׷��� ���� ����)

    //���� ���縦 ����ϴ°� ������ ������ ����
    //���� ����� A.MemAlloc���� A�� �Ҵ���� ��
    //B.MemAlloc�� ���� �ٸ� �ּҿ� �Ҵ�ް�
    //�ּҴ� �ٸ����� ���� ���� �����ؿ�
    //A�� 2000������ B�� 4000������

    //Person(const Person& person); // �������� ������
//class Person {
//...
//Person(const Person& person); // ���� ������
//};
//Person::Person(const Person& person) { // ���� ������
//this��id = person.id; // id �� ����
//int len = strlen(person.name);// name�� ���� ����
//this��name = new char [len+1]; // name�� ���� ���� �Ҵ�
//strcpy(this��name, person.name); // name�� ���ڿ� ����
//}
*/
    Test A;
    A.MemAlloc(5);
    for(int i=0;i<5;i++){
     A.data[i]=100*i;
    }
    Test B=A;// ���� ����

    return 0;
}
class Book {
    char *title; // ���� ���ڿ�
    int price; // ����
public:
    Book(char* title, int price){
        int length=strlen(title);
        this->title=new char[length+1];
        strcpy(this->title, title);
        this->price=price;
    }
    ~Book(){
        delete[] title, price;
    }
    void set(char* title, int price){
                //������ �߹Ƿ� �����ߴٰ� �ٽ� �������ش�.
        int length=strlen(title);
        delete[] this-> title;
        this->title=new char[length+1]; 
        strcpy(this->title, title);
        this->price=price;
    }
    void show() { cout << title << ' ' << price << "��" << endl; }
};
int main() {
    Book cpp("��ǰC++", 10000);
    Book java = cpp;
    java.set("��ǰ�ڹ�", 12000);
    cpp.show();
    java.show();
}