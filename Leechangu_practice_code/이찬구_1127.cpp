#include <iostream>
#include <string.h>
#include <vector>
#pragma warning(disable:4996)
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
int Ex1103() {
    //Book cpp("��ǰC++", 10000);
    //Book java = cpp;
    //java.set("��ǰ�ڹ�", 12000);
    //cpp.show();
    //java.show();
    return 0;
}

//1110 �ǽ�

//friend �Լ�
//friend ���� 3����
//1. �ܺ� �Լ� equals()�� Rect Ŭ������ friend�� ����
//2. RectManager Ŭ������ equals() ��� �Լ��� Rect Ŭ������ friend�� ����
//3. RectManager Ŭ������ ��� ��� �Լ��� Rect Ŭ������ friend�� ����

class Rect { // Rect Ŭ���� ����
    int width, height;
public:
    Rect(int width, int height) { this->width = width; this->height = height; }
    friend bool equals(Rect r, Rect s);
};
bool equals(Rect r, Rect s) { // �ܺ� �Լ�
    if (r.width == s.width && r.height == s.height) return true; 
//friend�� ����ż� class�� private ������ width�� height�� ���� ����
    else return false;
}
int Ex1110_1() {
    Rect a(3,4), b(4,5);
    if (equals(a, b)) cout << "equal" << endl;
    else cout << "not equal" << endl;
    return 0;
}
class Power { // �������� ǥ���ϴ� �Ŀ� Ŭ����
    int kick; // �߷� ���� ��
    int punch; // �ָ����� ġ�� ��
public: 
    Power(){kick=punch=0;}
    Power(int kick_in, int punch_in) { 
      this->kick = kick_in;
      this->punch = punch_in;
    }
    friend Power AddPower(Power A, Power B);
};
Power AddPower(Power A, Power B){
    Power tmp;
    tmp.kick=A.kick+B.kick;
    tmp.punch=A.punch+B.punch;
    return tmp;
}
int Ex1110_2(){
    Power A(20, 10), B(30, 20);

    Power C=AddPower(A, B);
    return 0;
}

class _Power_ { // �������� ǥ���ϴ� �Ŀ� Ŭ����
    int kick; // �߷� ���� ��
    int punch; // �ָ����� ġ�� ��
public: 
    _Power_(){kick=punch=0;}
    _Power_(int kick_in, int punch_in) { 
      this->kick = kick_in;
      this->punch = punch_in;
    }
    _Power_ operator+(_Power_ B){
        _Power_ tmp;
        tmp.kick=this->kick+B.kick;
        tmp.punch=this->punch+B.punch;
        return tmp;
    }
    _Power_ operator-(_Power_ B){
        _Power_ tmp;
        tmp.kick=this->kick+B.kick;
        tmp.punch=this->punch+B.punch;
        return tmp;
    }
};
class Point2D{
public:
    int x, y;
    Point2D(){x=y=0;}
    Point2D(int x, int y){
    this->x=x;
    this->y=y;
    }
    Point2D operator+(Point2D Q){
        Point2D tmp;
        tmp.x=this->x+Q.x;
        tmp.y=this->y+Q.y;
    }
};

class Complex {
    float re, im;
public:
    Complex() { re = im = 0; }
    Complex(float re, float im) { this->re = re; this->im = im; }
    Complex operator+(Complex in) {
       Complex tmp;
       tmp.re = this->re + in.re;
       tmp.im = this->im + in.im;
       return tmp;
    }
    Complex operator-(Complex in) {
       Complex tmp;
       tmp.re = this->re - in.re;
       tmp.im = this->im - in.im;
       return tmp;
    }
    Complex operator*(Complex in) {
       Complex tmp;
       tmp.re = this->re * in.re - this->im*in.im;
       tmp.im = this->re * in.im + this->im*in.re;
       return tmp;
    }
    Complex operator/(Complex in) {
       Complex tmp;
       Complex s,m;
       s.re = this->re * in.re - this->im*in.im;
       s.im = this->re * in.im + this->im*in.re;
       m.re = this->re * in.re + this->im*in.im;
       tmp.re=s.re/m.re;
       tmp.im=s.im/m.re;
       return tmp;
    }
    void show(){
        cout.precision(5);
        if(im>=0)
            cout << re << " + j" << im << endl;
        else
            cout << re << " - j" << -im << endl;
    }
};
int Ex1110_3(){
    _Power_ A(20, 10), B(30, 20);
    _Power_ C=A+B;  //A.operator+(B)
    _Power_ D=C-B;  

    Point2D P(4, 5), Q(7, 8);
    Point2D R=P+Q;

    Complex X(2,3), Y(3, 4), Z;
    Z = X + Y;
    Z.show();
    Z = X - Y;
    Z.show();
    Z = X * Y;
    Z.show();
    Z = X / Y;
    Z.show();

    return 0;
}
class Cpx {
    float re, im;
public:
    Cpx() { re = im = 0; }
    Cpx(float re, float im) { this->re = re; this->im = im; }
    
    friend Cpx operator+(Cpx A, Cpx B);
    friend Cpx AddCpx(Cpx A, Cpx B);
    
    void show(){
        cout.precision(5);
        if(im>=0)
            cout << re << " + j" << im << endl;
        else
            cout << re << " - j" << -im << endl;
    }
};
Cpx AddCpx(Cpx A, Cpx B){
    Cpx tmp;
    tmp.re=A.re+B.re;   
    tmp.im=A.im+B.im;
    return tmp;
}
Cpx operator+(Cpx A, Cpx B) {
    Cpx tmp;
    tmp.re = A.re + B.re;
    tmp.im = A.im + B.im;
    return tmp;
}
int Ex1110_4(){
    Cpx X(2,3), Y(3, 4), Z;

    Z=AddCpx(X, Y);   //Z=X+Y

    return 0;
}

//1113 ����

class _Book_ {
    string title;
    int price;
    int pages;
public:
    _Book_(string title="", int price=0, int pages=0) {
    this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << ' ' << price << "�� " <<pages << " ������" << endl;
    }
    string getTitle() { 
        return title; 
    }
    void operator+=(int increment){
        this->price+=increment;
    }
    void operator-=(int decrement){
        this->price-=decrement;
    }
    bool operator==(int price){  //�ǽ� 9-3�� �̿��� ���� �ۼ�
        bool k=false;
        if(this->price==price){
            k=true;
            return k;
        }
        else
            return k;
    }
    bool operator==(string b){
        bool k=false;
        if(this->title==b){
            k=true;
            return k;
        }
        else
            return k;
    }
    bool operator==(_Book_ b){
        if(this->price==price&&this->title==b.title&&this->pages==b.pages){
            return true;
        }
        else return false;
    }

};
int EX1113_1(){   //�ǽ�9-1
    _Book_ a("û��", 20000, 300), b("�̷�", 30000, 500);
    a+=500;  // a.operator+=(500)
    b-=500;  //
    a.show();
    b.show();

    return 0;
}

class BOOK {
    string title;
    int price;
    int pages;
public:
    BOOK(string title="", int price=0, int pages=0) {
    this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << ' ' << price << "�� " <<pages << " ������" << endl;
    }
    string getTitle() { 
        return title; 
    }
    friend void operator+=(BOOK& book, int increment);
    friend void operator-=(BOOK& book, int decrement);
    bool operator!(){   //�ǽ� 9-5 ����  �Ű����� ����
        if(price==0) return true;
        else return false;
    }
};
void operator+=(BOOK& book, int increment){
    book.price+=increment;
}
void operator-=(BOOK& book, int decrement){
    book.price-=decrement;
}
int Ex1113_2(){
    BOOK a("û��", 20000, 300), b("�̷�", 30000, 500);
    int inc=500;
    a+=inc;  // operator+=(a,500) �Ű������� �� ��
    b-=inc;  //
    a.show();
    b.show();

    return 0;
}

int Ex1113_3(){
    _Book_ a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
    // price ��
    if(a == 30000) cout << "���� 30000��" << endl; 
    // å title ��
    if(a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl;
    // title, price, pages ��� ��
    if(a == b) cout << "�� å�� ���� å�Դϴ�." << endl; 
    return 0;
}

int Ex1113_4(){
    BOOK book("�������", 0, 50); // ������ 0
    if(!book) cout << "��¥��" << endl;
    return 0;
}

void Vec2DTest(){
    int m=2, n=5; 
    vector<vector<int>> vec(m, vector<int>(n,0));
    //m by n ����� �ʱⰪ 0���� �����.
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            vec[i][j]=100;
    }

}
void Vec1DTest(){
    int size=5;
    vector<int> vec1d(size, 0);   //���� �迭�� [size]��ŭ �� int�� ����.
    for(int i=0;i<vec1d.size();i++){
        vec1d[i]=100;
    }
}
int Ex1113_5(){
    //Vec1DTest();
    //Vec2DTest();
    int m=2, n=3; 
    vector<vector<int>> A(m, vector<int>(n,1)); //���ͼ����ϴ°� �ϱ��ؾ� ��
    int y=3, x=2; 
    vector<vector<int>> B(y, vector<int>(x,2));
    vector<vector<int>> C;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<x;j++){
            C[i][j]=0;
            for(int k=0;k<n;k++){
                C[i][j]+=A[i][j]*B[k][j];
            }        
        }
    }

//    C=A*B;
//    C=A+B;
//    C=A-B;
//    C=A/B; //AB^{-1}
//    C+=A;
//    C-=B;
//    C=A*2;
//    C=A+1;
//    C=A-1;
//    C=A/3;

    return 0;
}

//1117 �ǽ�

class Matrix2D{
    
};
int Ex1117_0(){
    int m=2, n=3;
    vector<vector<int>>A;
    A.reserve(m);           //m��ŭ �޸� �Ҵ�

    for(int i=0;i<A.size();i++){
        A[i].resize(n);
    }

    A[1][2]=100;

    return 0;
}

// �� �� 
// ��Ȱ�뼺�� ���̱� ���� ���
// ��ӿ��� �ݷ��� �ϳ� �ٴ´�.
// Ŭ���� �ȿ� �ڽ� Ŭ����
// **11p ����
// 2���� �ڽ� Ŭ������ �����ϸ� ������ �ٸ� �θ� Ŭ������ ������
// �����ϴ°� x
// �θ� ����->�ڽ� ����->�ڽ� �Ҹ�->�θ� �Ҹ�
// �ڽ�Ŭ������ ȣ���Ҷ� �θ�Ŭ������ ����Ʈ�����ڰ� ������, �������� �ʴ´�.
// **26p ����   B����A�� ȣ���� �� �Ķ���ʹ� �ڷ����� ���� �ʾƵ� ��(�Լ� ȣ���ϵ��� �ϸ� ��)

// 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
class Point {
    int x, y; //�� �� (x,y) ��ǥ��
public:
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
class ColorPoint : public Point { // 2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ���� ColorPoint. Point�� ��ӹ���
    string color;// ���� �� ǥ��
public:
    void setColor(string color) { 
        this->color = color;
    }
    void showColorPoint();
};
    void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint(); // Point�� showPoint() ȣ��
}
int Ex1117_1() {
    Point p; // �⺻ Ŭ������ ��ü ����
    ColorPoint cp; // �Ļ� Ŭ����(�ڽ� Ŭ����)�� ��ü ����
    //�θ� Ŭ������ private����� �� �� �� �־�

    cp.set(3,4); // �⺻ Ŭ������ ��� ȣ��
    cp.setColor("Red"); // �Ļ� Ŭ������ ��� ȣ��
    cp.showColorPoint(); // �Ļ� Ŭ������ ��� ȣ��
}

class A {
    int y;
public:
    A() { cout << "������ A" << endl; }
    A(int y) {
        this->y=y;
        cout << "������ A*" << endl;
    }
    ~A(){ cout << "�Ҹ��� A" << endl;}
};
class B : public A {
    int x;
public:
    B() { // A() ȣ���ϵ��� �����ϵ�
    cout << "������ B" << endl;
    }
    //B(int x):A(x+3){       //����) �θ� Ŭ������ A �Ķ���͸� ���� ��, x(or y)�� ������� �ۼ��ؾߵ�
    B(int x, int y) :A(y){   //�ε� �� �� ����.   
        this->x=x;
        cout << "������ B*" << endl;
    }
    ~B(){ cout << "�Ҹ��� B" << endl;}
};
class C:public B{
public:
    C(){ cout << "������ C" << endl;}
    ~C(){ cout << "�Ҹ��� C" << endl;}
};
int Ex1117_2(){
    B father(100, 200);   //class�� ����� ���� �����ڰ� �������.
    return 0;
}

class Circle_1117 {
private:
    int radius;
public:
    Circle_1117() { radius = 1; }
    Circle_1117(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
    int SetRadius(){return radius;}  //�� Ǯ��
    //void setRadius(int r){radius=r;}  //������ Ǯ��
    //int getRadius(){return radius;}
};
class NamedCircle: public Circle_1117{
    string name;
public:
    NamedCircle(int r, string name): Circle_1117(r){
        //this->setRadius(r);        //������ sol
        this->name=name;
    };
    void show(){
        cout<<"�������� "<< SetRadius() <<" �� "<<name<<endl;
        //cout<<"�������� "<< getRadius() <<"�� "<<name<<endl;
    }

};
int Ex1117_3(){
    NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
    waffle.show();
    return 0;
}

//1120 �ǽ�

//                            <����>                         
/*
class Matrix {
public:
	vector<vector<int>> mat;
	Matrix(){}
	Matirx(int m,int n){	vector::resize() �̿��ؼ� �޸� �Ҵ�	}
	~Matrix() {	vector.clear()�̿��ؼ� �޸� ����	}
	//�������ߺ� �Լ� ����
};
*/

class Circle1117 {
private:
	int radius;
public:
	Circle1117() { radius = 1; }
	Circle1117(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) { radius = r; }
	int getRadius() {
		return radius;
	}
};
class NamedCircle1120 : public Circle1117 {
	string name;
public:
	NamedCircle1120() {
		this->setRadius(0);
		this->name = "";
	}
	NamedCircle1120(int r, string name) 
	{
		this->setRadius(r);
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void show() {
		cout << "�������� " << getRadius() << "�� " << name << endl;
	}
};


int EX1120_0() {
	
	NamedCircle1120 pizza[5];

	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i <= 5; i++)
	{
		cout << i+1 << ">> ";
		//cin >> pizza[i].radius >> pizza[i].name;
		int r;
		string name;
		cin >> r >> name;
		pizza[i].setRadius(r);
		pizza[i].setName(name);

	}
	
	int save_index = 0;
	int r_max = pizza[0].getRadius();

	for (int index = 1; index < 5; index++)
	{
		if (pizza[index].getRadius() > r_max)
		{
			save_index = index;
		}
		r_max = pizza[save_index].getRadius();
	}

	cout << "���� ������ ū ���ڴ� " << pizza[save_index].getName() << "�Դϴ�." << endl;

	/*
	// [0] , [1] ��
	if (pizza[1].getRadius() > r_max)
	{
		save_index = 1;
	}
	else
	{
		save_index = 0;
	}
	r_max = pizza[save_index].getRadius();

	// [2], {[1], [0] �� ū ��} ��

	if (pizza[2].getRadius() > r_max) {
		save_index = 2;
	}
	r_max = pizza[save_index].getRadius();
	*/

	return 0;
}

//1124 �ǽ�

class BaseArray {
private:
	int capacity; 
	int* mem; 
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; 
		mem = new int[capacity]; 
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; } //�ε����� ���� �ش��ϴ� �濡�� �� ���
	int getCapacity() { return capacity; }
};

class MyQueue :public BaseArray{
	int size;
public:
	MyQueue() { size = 0;}
	MyQueue(int capacity) : BaseArray(capacity) { //cap�� Ÿ���� ���� �ʴ´�.
		size = 0;
	}
    void enqueue(int input) {
		put(size, input); 
		size++;
	}
    int capacity() {return getCapacity();}
	int length(){return size;} //�� ���ִ� queue�� ��(size)

	int dequeue() {  
//size�� 5�� �� 4�� �Ű��ָ� ��
//m[1]�� m[0]��
//m[2]�� m[1]��
//m[3]�� m[2]��
//m[4]�� m[3]��
        int tmp=get(0);
        size--;
		for (int i = 0; i < size ; i++){
            //int tmp=get(i+1);
            //put(i,tmp);
			put(i, get(i + 1));  //�� �� ���� �� �ٷ�
		}
		return tmp;
	}
};
int Ex1124_1() {
   MyQueue mQ(100);  //size�� 100���� ����
   int n;
   cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
   for (int i = 0; i < 5; i++) {
      cin >> n;
      mQ.enqueue(n); // ť�� ����
   }
   cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;
   cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
   while (mQ.length() != 0) {
      cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
   }
   cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;

   return 0;
}



class MyStack: public BaseArray{
    int size;
public:
	MyStack() { size = 0;}
	MyStack(int capacity) : BaseArray(capacity) { //cap�� Ÿ���� ���� �ʴ´�.
		size = 0;
	}
    void push(int input) {
		put(size, input); 
		size++;
	}
    int capacity() {return getCapacity();}
	int length(){return size;} //�� ���ִ� queue�� ��(size)

    int pop() {  
        size--;	
		return get(size);
	}
};
int Ex1124_2() {

   MyStack mS(100);  //size�� 100���� ����
   int n;
   cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
   for (int i = 0; i < 5; i++) {
      cin >> n;
      mS.push(n);
   }
   cout << "������ �뷮 : " << mS.capacity() << ", ������ ũ�� : " << mS.length() << endl;
   cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
   while (mS.length() != 0) {
      cout << mS.pop() << ' '; // ť���� �����Ͽ� ���
   }
   cout << endl << "������ ���� ũ�� : " << mS.length() << endl;

   return 0;
}

//c++���� ����� �θ��� Ŭ������ �ڽĵ��� �Ȱ��� ����.

//�� ĳ����**
//�θ��� ù��° ������ �ּҸ� �޴´�.

// 200 capacity(4bytes)  �θ�Ŭ����
// 204 mem(8bytes)
//----------------------
// 212 size(4bytes)     �ڽ�Ŭ����

//MyQueue mQ;;
//MyQueue *pDer = &mQ;     //200�� ����
//BaseArray* pBase = pDer; //�ּҸ� ������ �� �ִ� ����
//           (200)  (200)

//BaseArray ba;
//BaseArray *pBase=&ba;
//mYQueue* pDer=pBase;
//pDer=(MyQueue*)pBase;
//�ڽ�Ŭ������ ���� ��ü�� �� ��ü�� �θ�Ŭ���� �ּҴ� ����.
// �� �����͸� �ڽ�Ŭ������ �����ϳ� �θ� Ŭ������ �����ϳĿ� ����
//������ �Ҽ� �ִ� ������ �޶�����.

//���� ������
//pdf 9p�� ���� ���� �ߴ� �ڵ� Ȯ��!!

//���� ��� ����

//1127 �ǽ�

//���� �Լ�

//virtual �� ���� �����Լ��� �����
//virtual �� ������ �θ�� �������� �ʰ� �ڽĸ� �����Ѵ�.

class Base {
public:
    virtual void f() { cout << "Base::f() called" << endl; } //�θ�Ŭ����
};
class Derived : public Base {
public:
    void f() { cout << "Derived::f() called" << endl; }
    //�ڽ�Ŭ������ virtual�� �ϵ� ���ϵ� �Ȱ��� ����.
};
int Ex1127_0() {
    Derived d, *pDer;
    pDer = &d;
    pDer->f(); // Derived::f() ȣ��
    
    Base* pBase;
    pBase = pDer; // ��ĳ����
    pBase->f(); // Base::f() ȣ��

    return 0;
}
//�ǽ�11-1
//������ �����ͷ� �̷��� ������ �� ����. �ǽ�11-1 ����
//   int* A= new int;
//    //������ ������ �ϳ� ���� A�� �־���.
//    *A=100;
//    delete A;

class Shape_1127{
    string name;
public:
    //virtual float getArea() { return 0.0; }
    virtual float getArea()=0;  //���� ���� �Լ�.
    //�����̶� ã���� �ʾ�
    //�׷��� �ڵ� ����ߵ� ��?
    void setName(string name){this->name=name;}
    string getName(){return name;}
    //�ڽĿ� �����ϸ� �����ϱ� �����Ƿ�

};
class Oval_1127 : public Shape_1127{
    float a,b;
public:
    Oval_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //�����̺��̱� ������ �ڽ��� �ٲ��ַ���...
                        //�θ�Ŭ������ �ٸ� �Լ��� �ҷ��ͼ� �Ѵ�.
    }
    virtual float getArea() { return 3.14*a*b; }//Ÿ���� ����
};
class Rect_1127 : public Shape_1127{
    float a,b;
public:
    Rect_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //�����̺��̱� ������ �ڽ��� �ٲ��ַ���...
                        //�θ�Ŭ������ �ٸ� �Լ��� �ҷ��ͼ� �Ѵ�.
    }
    virtual float getArea() { return a*b; }//���簢���� ����
};
class Triangular_1127 : public Shape_1127{
    float a,b;
public:
    Triangular_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //�����̺��̱� ������ �ڽ��� �ٲ��ַ���...
                        //�θ�Ŭ������ �ٸ� �Լ��� �ҷ��ͼ� �Ѵ�.
    }
    virtual float getArea() { return 0.5*a*b; }//Ÿ���� ����
};
int Ex1127_1() {
    Oval_1127* p0;
    Rect_1127* p1;
    Triangular_1127* p2;

    Shape_1127 *p[3];  //������ �θ�Ŭ������ �Ǿ� ����.

    p0 = new Oval_1127("��붱", 10, 20); 
    p1 = new Rect_1127("����", 30, 40); 
    p2 = new Triangular_1127("�佺Ʈ", 30, 40);
    
    cout << p0->getName() << " ���̴� " << p0->getArea() << endl;
    cout << p1->getName() << " ���̴� " << p1->getArea() << endl;
    cout << p2->getName() << " ���̴� " << p2->getArea() << endl;

    delete p0;    delete p1;    delete p2;
    return 0;
}

int Ex1127_2() { //�� �Լ����� Ȯ���� ��������.
   
    Shape_1127 *ptr[3];  //������ �θ�Ŭ������ �Ǿ� ����.

    ptr[0]=new Oval_1127("��붱", 10, 20);   //��ĳ����
    ptr[1]=new Rect_1127("����", 30, 40); 
    ptr[2]=new Triangular_1127("�佺Ʈ", 30, 40);
    
    for(int i=0;i<3;i++)
        cout << ptr[i]->getName() << " ���̴� " << ptr[i]->getArea() << endl;
    
    for(int i=0;i<3;i++)
        delete ptr[i];
    return 0;
}

class Calculator {
public:
    //virtual�� �����ϱ� ������ �� ���൵ ��.
    virtual int add(int a, int b) = 0; // �� ������ �� ����
    virtual int subtract(int a, int b) = 0; // �� ������ �� ����
    virtual double average(int a [], int size) = 0; // �迭 a�� ��� ����. size�� �迭�� ũ��
};
class GoodCalc : public Calculator{
    int sum=0;
public:
    int add(int a, int b){return a+b;}
    int subtract(int a, int b){return a-b;}
    double average(int a [], int size){
        for(int i=0;i<size;i++){
            sum+=a[i];
        }
        return (double)sum/size; 
        //int ���� ����� ���̱� ������ �̻��� ��(3.33->3)�� ���� �� ����.
        //(double)(sum/size); ���غ���.
    }
};
int Ex1127_3() {
    int a[] = {1,2,3,4,5};
    Calculator *p = new GoodCalc();
    cout << p->add(2, 3) << endl;
    cout << p->subtract(2, 3) << endl;
    cout << (*p).average(a, 5) << endl;  //(*p). �̷��Էε� �� �� �ִ�.
    delete p;

    return 0;
}

class Calculator_1127 {
    void input() {
        cout << "���� 2 ���� �Է��ϼ���>> ";
        cin >> a >> b;
    }
protected:  //�ڽĸ� �＼�� �� �� �ִ�. �� 3�ڴ� �＼�� �Ұ�(private�� ����)
    int a, b;
    virtual int calc(int a, int b) = 0; // �� ������ �� ����
public:
    void run() {
    input();
    cout << "���� ���� " << calc(a, b) << endl;
    }
};
class Adder_1127 : public Calculator_1127{
public:
    int calc(int a, int b){return a+b;}
};
class Subtractor_1127 : public Calculator_1127{
public:
    int calc(int a, int b){return a-b;} // �� ������ �� ����
};
int main() {

    Adder_1127 adder;
    Subtractor_1127 subtractor;
    adder.run();
    subtractor.run();

    return 0;
}