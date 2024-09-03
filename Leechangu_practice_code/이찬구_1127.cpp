#include <iostream>
#include <string.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

/*
여러가지 객체의 생성방법
객체를 배열처럼 여러개 생성할 수 있다.
객체이름에 인덱스가 들어갔다고 생각할 수 있다. 객체이름[i]=하나의 객체

*/

class Circle1020 {
    int radius;
public:
    Circle1020() { radius = 1; }   //생성자는 반환형이 없다.
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
        cout << "면적" << cir[i].getArea() << endl;
    }

    Circle1020* p;      //선언문 *p와 * p와 다르다
    p = cir;         //cir는 cir[0]의 주소를 가지고 있다
    //(*p).setRadius(-100);    //*p는 내용 cir[0]이므로 내용 cir[0]이 바뀐다. 
    p->setRadius(-100);   //위 문장과 동일하다

    p = &(cir[1]);   //p는 주소 변수 이므로 &를 통해 주소를 넣어줘야 한다. 내용을 넣으면 안됨
    p->setRadius(-100); //cir[1]의 내용이 바뀜

    p++; //cir[1]에서 cir[2]의 주소로 바꿔줌   (*p)는 p->와 같은 의미
    p->setRadius(-100); //cir[2]의 내용이 바뀜

    (*p).setRadius(-500); //cir[2]의 값이 -500이 됨

    /////////////////////////////////////////////////////////////////
    p = cir;

    p[0].setRadius(-400);   //cir대신 p를 쓸 수 있다.
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
    Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
    Color* p;                     // Color 타입의 포인터 변수 p 선언
    p = &screenColor; // (1) p가 screenColor(객체)의 주소를 가지도록 코드 작성 따라서 &로 바꿔줘야함
    p->showColor();               // (2) p와 show()를 이용하여 screenColor 색 출력
    Color colors[3];              // (3) Color의 일차원 배열 colors 선언. 원소는 3개
    p = colors;                   // (4) p가 colors 배열을 가리키도록 코드 작성

    // (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
    // 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
    p[0].setColor(255, 0, 0);
    p[1].setColor(0, 255, 0);
    p[2].setColor(0, 0, 255);

    // (6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
    for (int i = 0; i < 3; i++) {
        p[i].showColor();   //(p+1)->showColor; 로도 가능하다
        //(*(p+1))->showColor; 로도 가능
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
        delete[] data;        //이러면 자동으로 해제해주면서 끝남
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
    //A = 100, 불가

    int* B = (int*)malloc(3 * sizeof(int));   //3칸 짜리 논을 만듦
    B[0] = 100;   B[1] = 200;   B[2] = 300;

    free(B);

    //교수님 추천 방식   대신 할당하고 제거할때 섞어서 쓸 수 없다(malloc이랑 free끼리, new랑 delete끼리만 가능)
    float* C = new float[3];                    //이렇게도 쓸 수 있어
    C[0] = 100;   C[1] = 200;   C[2] = 300;
    delete[] C;

    int n = 100;
    int* p;
    p = &n;

    //int D[n];       //배열의 인덱스는 무조건 실수 값이여야한다.(변수 불가능)
    int* D = new int[n];  //이렇게는 쓸 수 있어

    delete[] D;

    return 0;

}

class Member {
    string name;
public:
    Member() { name = ""; }      //디폴트 생성자
    //Member(string name_in) { this->name = name_in; }   //생성자 //this는 클래스를 불러오는 기능
    Member(string name_in) { name = name_in; }
    string getName() { return name; }         //이름 출력
    void setName(string name_in) { name = name_in; }
};
class Family {
    string family_name;
    Member* p;// Member p[3]; // Member 배열 포인터
    int size; // Member 배열의 크기. 가족 구성원 수
public:
    Family() {};
    Family(string family_name_in, int size_in); // size 개수만큼 Member 배열 동적 생성
    void setName(int index, string name_in);
    void show(); // 모든 가족 구성원 출력
    ~Family();
};

Family::Family(string family_name_in, int size_in) {
    size = size_in;
    family_name = family_name_in;        //중요
    p = new Member[size_in];

    if (p == NULL) {
        cout << "메모리 할당 실패" << endl;
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

    Family simpson; //Family simpson("Simpson", 3); // 3명으로 구성된 Simpson 가족
    simpson.setName(0, "Mr. Simpson");
    simpson.setName(1, "Mrs. Simpson");
    simpson.setName(2, "Bart Simpson");
    simpson.show();
    //위아래는 똑같은 기능을 한다.
    Family* LEE = new Family("LEE", 4);
    LEE->setName(0, "Mr. LEE"); // (*LEE).setName(0, "Mr.LEE");
    LEE->setName(1, "Mrs. LEE");
    LEE->setName(2, "LEE's son");
    LEE->setName(3, "LEE's daughter");
    LEE->show();

    return 0;

}

//복사 생성자
//값에 의한 호출시 매개 변수 객체의 생성자가 실행되지 않는 이유?
//호출되는 순간의 실인자 객체 상태를 매개 변수 객체에 그대로 전달하기 위함

//따라서 주소에 의한 호출로 해줘야 돼

class _Circle_ {
private:
    int radius;
public:
    _Circle_() {this-> radius = 1; }       //this는 생략해도 무방
    _Circle_(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

void SwapCircle(_Circle_& A, _Circle_& B) {
    _Circle_ tmp;     //A와 B를 값에 의한 호출을 하면 다른 객체가 만들어지므로 값이 바뀌지 않음
    tmp = A;          //참조(&)에 의한 호출을 해야됨 (_Circle_& A, _Circle_& B)
    A = B;
    B = tmp;
}
void SwapCircle(_Circle_* A, _Circle_* B) {
    _Circle_ tmp;     //여기서는 주소이니까 포인터를 붙여줘야돼
    tmp = *A;  
    *A = *B;
    *B = tmp;
}
void SwapCircle(_Circle_& A, _Circle_* B) {
    _Circle_ tmp;     //섞어서도 쓸 수 있다.
    tmp = A;
    A = *B;
    *B = tmp;

}

int Ex1030_0() {      //swap하는 함수를 참조에 의한 호출이 되도록 작성
    _Circle_ A(10), B(20);

    cout << "A 면적 = " << A.getArea() << endl;
    cout << "B 면적 = " << B.getArea() << endl;

    //_Circle_ tmp;    이거를 참조 변수로 코드를 작성해야 돼
    //tmp = A;
    //A = B;
    //B = tmp;

    SwapCircle(A,B);          //참조에 의한 호출
    //아래 어떤 코드 중 모두 가능하기
    SwapCircle(&A, &B);       //포인터 사용
    SwapCircle(A, &B);

    cout << "A 면적 =" << A.getArea() << endl;
    cout << "B 면적 =" << B.getArea() << endl;

    return 0;
}
void readRadius(_Circle_& obj) {  //그냥 써두고 마지막에 &참조 하나만 쓰면 돼
    cout << "[1]정수 값으로 반지름을 입력하시오>>" << endl;
    int R;
    cin >> R;

    obj.setRadius(R);

}
void readRadius(_Circle_* obj) {  //포인터로 해볼게요
    cout << "[2] 정수 값으로 반지름을 입력하시오>>" << endl;
    int R;
    cin >> R;

    //(* obj).setRadius(R);  //변수니까 *을 만드러줘
    obj->setRadius(R);       //위식과 동일

}

int Ex1030_1()
{
    _Circle_ donut;
    readRadius(donut);      //값을 넘겨주면 참조로
    cout << "donut의 면적 = " << donut.getArea() << endl;
    readRadius(&donut);     //주소로 넘겨주면 포인터로
    cout << "donut의 면적 = " << donut.getArea() << endl;

    return 0;
}

class Accumulator {
    int value;     //private니까 외부에서 호출 안됨,
public:
    Accumulator(int value); // 매개변수 value로 멤버 value를 초기화한다.
    Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
    int getValue(); // 누적된 값 value를 리턴한다.
};
Accumulator::Accumulator(int value) {this->value = value;}
int Accumulator::getValue() { return value; }
Accumulator& Accumulator::add(int n)
{
    value += n;
    return *this;       //Accumulator의 객체가 리턴
    //this 는 주소니까 값을 나타내려면 
    
    //Accumulator tmp = *this;
    //return tmp;    !이런 경우엔 어떻게 될까!

//메인문 처음 돌리면 acc.add(5)가 한바퀴 돌고
// this가 돼서 this-> add(6).add(7)이 되고
// this가 돼서 this->.add(7)이 된다.
}

//****PDF [참고]에 출력값은 28이 아니라 15이다.

int Ex1030_2() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
    cout << acc.getValue() << endl; // 28 출력

    return 0;
}

//복사 생성자
//얕은 복사
//깊은 복사

int Ex1030_3()
{
    int data[5] = {1,2,3,4,5};
    int* ptr;      //이거는 집이 한채인데 주소를 공유해
                   //int ptr[5]로 할때는 집을 두채를 만들어서 담는다=깊은복사

    ptr = data;

    cout << *(ptr+1) << endl;     //ptr[1]

    return 0;
}

class _Student_ {
    char name[100];
public:
    _Student_() { strcpy(name, ""); }    //strcpy는 첫번째 인덱스로 그릇, 두번째 인덱스에 source를 넣는다
    _Student_(char* name) {
        strcpy(this->name, name);    
    }
    ~_Student_() {}
    void showName() { cout << "이름이 " << name << endl; }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};

int Ex1030_4() {
    _Student_ A((char*)"KANG"), B((char*)"KIM");   //(char*)를 통해 변수형을 지정
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
        this->name = new char[length + 1];  //마지막 백슬래쉬를 더해줘서 +1
        strcpy(this->name, name);
    }
    Student(Student& inputObj){   //깊은 복사생성자
        int length=strlen(inputObj.name);
        this->name=new char[length+1];
        strcpy(this->name,inputObj.name);
    }
    ~Student() {
        delete[] name;   //name을 할당해서 쓰기 때문에 지워줘야돼
    }
    void showName() {
        cout << "이름이 " << name << endl;

    }
    void setName(char* name) {  //복사하려는 값의 길이(이름의 길이)가 달라지면 
        //오류가 뜨므로 삭제했다가 다시 선언해준다.
        int length=strlen(name);
        delete[] this-> name;
        this->name=new char[length+1]; 

        strcpy(this->name, name);
    }
    Student clone(){

    }
};

int Ex1030_5()   //Ex1030_4랑 비교해보기
{
    Student A((char*)"KANG");
    Student B = A;  
    B.showName();
    B.setName((char*)"PARKPARK");
    B.showName();
    A.showName();

    return 0;
}

//1103 실습

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
    //복사생성자:(1)메모리 할당 (2)할당된 메모리에 데이터 복사
    //복사생성자도 생성자이므로, 객체를 선언할 때 자동 실행됨
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
    // 얕은 복사는 주의사항이 있음
    //A와 B 안에 data 변수가 존재
    //A.MemAlloc(5)를 통해 a의 data=2000이 됨
    //B=A를 통해 b의 data=2000이 됨.
    //할당은 a가 했고, 주소를 공유해서 b가 씀
    //(주소가 같아짐 그래서 값이 같음)

    //깊은 복사를 사용하는게 주의할 사항이 적음
    //깊은 복사는 A.MemAlloc으로 A가 할당받은 걸
    //B.MemAlloc을 통해 다른 주소에 할당받고
    //주소는 다르지만 값은 같게 복사해옴
    //A는 2000번지에 B는 4000번지에

    //Person(const Person& person); // 깊은복사 생성자
//class Person {
//...
//Person(const Person& person); // 복사 생성자
//};
//Person::Person(const Person& person) { // 복사 생성자
//this→id = person.id; // id 값 복사
//int len = strlen(person.name);// name의 문자 개수
//this→name = new char [len+1]; // name을 위한 공간 할당
//strcpy(this→name, person.name); // name의 문자열 복사
//}
*/
    Test A;
    A.MemAlloc(5);
    for(int i=0;i<5;i++){
     A.data[i]=100*i;
    }
    Test B=A;// 깊은 복사

    return 0;
}
class Book {
    char *title; // 제목 문자열
    int price; // 가격
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
                //오류가 뜨므로 삭제했다가 다시 선언해준다.
        int length=strlen(title);
        delete[] this-> title;
        this->title=new char[length+1]; 
        strcpy(this->title, title);
        this->price=price;
    }
    void show() { cout << title << ' ' << price << "원" << endl; }
};
int Ex1103() {
    //Book cpp("명품C++", 10000);
    //Book java = cpp;
    //java.set("명품자바", 12000);
    //cpp.show();
    //java.show();
    return 0;
}

//1110 실습

//friend 함수
//friend 선언 3종류
//1. 외부 함수 equals()를 Rect 클래스에 friend로 선언
//2. RectManager 클래스의 equals() 멤버 함수를 Rect 클래스에 friend로 선언
//3. RectManager 클래스의 모든 멤버 함수를 Rect 클래스에 friend로 선언

class Rect { // Rect 클래스 선언
    int width, height;
public:
    Rect(int width, int height) { this->width = width; this->height = height; }
    friend bool equals(Rect r, Rect s);
};
bool equals(Rect r, Rect s) { // 외부 함수
    if (r.width == s.width && r.height == s.height) return true; 
//friend로 선언돼서 class에 private 변수인 width와 height에 접근 가능
    else return false;
}
int Ex1110_1() {
    Rect a(3,4), b(4,5);
    if (equals(a, b)) cout << "equal" << endl;
    else cout << "not equal" << endl;
    return 0;
}
class Power { // 에너지를 표현하는 파워 클래스
    int kick; // 발로 차는 힘
    int punch; // 주먹으로 치는 힘
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

class _Power_ { // 에너지를 표현하는 파워 클래스
    int kick; // 발로 차는 힘
    int punch; // 주먹으로 치는 힘
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

//1113 수업

class _Book_ {
    string title;
    int price;
    int pages;
public:
    _Book_(string title="", int price=0, int pages=0) {
    this->title = title; this->price = price; this->pages = pages;
    }
    void show() {
        cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
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
    bool operator==(int price){  //실습 9-3번 이용을 위해 작성
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
int EX1113_1(){   //실습9-1
    _Book_ a("청춘", 20000, 300), b("미래", 30000, 500);
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
        cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
    }
    string getTitle() { 
        return title; 
    }
    friend void operator+=(BOOK& book, int increment);
    friend void operator-=(BOOK& book, int decrement);
    bool operator!(){   //실습 9-5 위해  매개변수 주의
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
    BOOK a("청춘", 20000, 300), b("미래", 30000, 500);
    int inc=500;
    a+=inc;  // operator+=(a,500) 매개변수가 두 개
    b-=inc;  //
    a.show();
    b.show();

    return 0;
}

int Ex1113_3(){
    _Book_ a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    // price 비교
    if(a == 30000) cout << "정가 30000원" << endl; 
    // 책 title 비교
    if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
    // title, price, pages 모두 비교
    if(a == b) cout << "두 책이 같은 책입니다." << endl; 
    return 0;
}

int Ex1113_4(){
    BOOK book("벼룩시장", 0, 50); // 가격은 0
    if(!book) cout << "공짜다" << endl;
    return 0;
}

void Vec2DTest(){
    int m=2, n=5; 
    vector<vector<int>> vec(m, vector<int>(n,0));
    //m by n 행렬을 초기값 0으로 만든다.
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            vec[i][j]=100;
    }

}
void Vec1DTest(){
    int size=5;
    vector<int> vec1d(size, 0);   //벡터 배열을 [size]만큼 다 int로 선언.
    for(int i=0;i<vec1d.size();i++){
        vec1d[i]=100;
    }
}
int Ex1113_5(){
    //Vec1DTest();
    //Vec2DTest();
    int m=2, n=3; 
    vector<vector<int>> A(m, vector<int>(n,1)); //벡터선언하는건 암기해야 돼
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

//1117 실습

class Matrix2D{
    
};
int Ex1117_0(){
    int m=2, n=3;
    vector<vector<int>>A;
    A.reserve(m);           //m만큼 메모리 할당

    for(int i=0;i<A.size();i++){
        A[i].resize(n);
    }

    A[1][2]=100;

    return 0;
}

// 상 속 
// 재활용성을 높이기 위한 방식
// 상속에는 콜론이 하나 붙는다.
// 클래스 안에 자식 클래스
// **11p 참고
// 2개의 자식 클래스를 선언하면 각각의 다른 부모 클래스가 생성됨
// 공유하는건 x
// 부모 생성->자식 생성->자식 소멸->부모 소멸
// 자식클래스를 호출할때 부모클래스의 디폴트생성자가 없으면, 생성되지 않는다.
// **26p 주의   B에서A를 호출할 때 파라미터는 자료형을 넣지 않아도 됨(함수 호출하듯이 하면 됨)

// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
    int x, y; //한 점 (x,y) 좌표값
public:
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};
class ColorPoint : public Point { // 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint. Point를 상속받음
    string color;// 점의 색 표현
public:
    void setColor(string color) { 
        this->color = color;
    }
    void showColorPoint();
};
    void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint(); // Point의 showPoint() 호출
}
int Ex1117_1() {
    Point p; // 기본 클래스의 객체 생성
    ColorPoint cp; // 파생 클래스(자식 클래스)의 객체 생성
    //부모 클래스의 private말고는 다 쓸 수 있어

    cp.set(3,4); // 기본 클래스의 멤버 호출
    cp.setColor("Red"); // 파생 클래스의 멤버 호출
    cp.showColorPoint(); // 파생 클래스의 멤버 호출
}

class A {
    int y;
public:
    A() { cout << "생성자 A" << endl; }
    A(int y) {
        this->y=y;
        cout << "생성자 A*" << endl;
    }
    ~A(){ cout << "소멸자 A" << endl;}
};
class B : public A {
    int x;
public:
    B() { // A() 호출하도록 컴파일됨
    cout << "생성자 B" << endl;
    }
    //B(int x):A(x+3){       //주의) 부모 클래스의 A 파라미터를 넣을 땐, x(or y)를 관련지어서 작성해야됨
    B(int x, int y) :A(y){   //로도 쓸 수 있음.   
        this->x=x;
        cout << "생성자 B*" << endl;
    }
    ~B(){ cout << "소멸자 B" << endl;}
};
class C:public B{
public:
    C(){ cout << "생성자 C" << endl;}
    ~C(){ cout << "소멸자 C" << endl;}
};
int Ex1117_2(){
    B father(100, 200);   //class를 만드는 순간 생성자가 만들어짐.
    return 0;
}

class Circle_1117 {
private:
    int radius;
public:
    Circle_1117() { radius = 1; }
    Circle_1117(int radius) { this->radius = radius; }
    double getArea() { return 3.14*radius*radius; }
    int SetRadius(){return radius;}  //내 풀이
    //void setRadius(int r){radius=r;}  //교수님 풀이
    //int getRadius(){return radius;}
};
class NamedCircle: public Circle_1117{
    string name;
public:
    NamedCircle(int r, string name): Circle_1117(r){
        //this->setRadius(r);        //교수님 sol
        this->name=name;
    };
    void show(){
        cout<<"반지름이 "<< SetRadius() <<" 인 "<<name<<endl;
        //cout<<"반지름이 "<< getRadius() <<"인 "<<name<<endl;
    }

};
int Ex1117_3(){
    NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
    return 0;
}

//1120 실습

//                            <과제>                         
/*
class Matrix {
public:
	vector<vector<int>> mat;
	Matrix(){}
	Matirx(int m,int n){	vector::resize() 이용해서 메모리 할당	}
	~Matrix() {	vector.clear()이용해서 메모리 해제	}
	//연산자중복 함수 나열
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
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};


int EX1120_0() {
	
	NamedCircle1120 pizza[5];

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
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

	cout << "가장 면적이 큰 피자는 " << pizza[save_index].getName() << "입니다." << endl;

	/*
	// [0] , [1] 비교
	if (pizza[1].getRadius() > r_max)
	{
		save_index = 1;
	}
	else
	{
		save_index = 0;
	}
	r_max = pizza[save_index].getRadius();

	// [2], {[1], [0] 중 큰 것} 비교

	if (pizza[2].getRadius() > r_max) {
		save_index = 2;
	}
	r_max = pizza[save_index].getRadius();
	*/

	return 0;
}

//1124 실습

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
	int get(int index) { return mem[index]; } //인덱스의 값에 해당하는 방에서 값 출력
	int getCapacity() { return capacity; }
};

class MyQueue :public BaseArray{
	int size;
public:
	MyQueue() { size = 0;}
	MyQueue(int capacity) : BaseArray(capacity) { //cap의 타입은 적지 않는다.
		size = 0;
	}
    void enqueue(int input) {
		put(size, input); 
		size++;
	}
    int capacity() {return getCapacity();}
	int length(){return size;} //줄 서있는 queue의 수(size)

	int dequeue() {  
//size가 5일 때 4번 옮겨주면 돼
//m[1]을 m[0]로
//m[2]를 m[1]로
//m[3]를 m[2]로
//m[4]을 m[3]로
        int tmp=get(0);
        size--;
		for (int i = 0; i < size ; i++){
            //int tmp=get(i+1);
            //put(i,tmp);
			put(i, get(i + 1));  //위 두 줄을 한 줄로
		}
		return tmp;
	}
};
int Ex1124_1() {
   MyQueue mQ(100);  //size가 100으로 생성
   int n;
   cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
   for (int i = 0; i < 5; i++) {
      cin >> n;
      mQ.enqueue(n); // 큐에 삽입
   }
   cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
   cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
   while (mQ.length() != 0) {
      cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
   }
   cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

   return 0;
}



class MyStack: public BaseArray{
    int size;
public:
	MyStack() { size = 0;}
	MyStack(int capacity) : BaseArray(capacity) { //cap의 타입은 적지 않는다.
		size = 0;
	}
    void push(int input) {
		put(size, input); 
		size++;
	}
    int capacity() {return getCapacity();}
	int length(){return size;} //줄 서있는 queue의 수(size)

    int pop() {  
        size--;	
		return get(size);
	}
};
int Ex1124_2() {

   MyStack mS(100);  //size가 100으로 생성
   int n;
   cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
   for (int i = 0; i < 5; i++) {
      cin >> n;
      mS.push(n);
   }
   cout << "스택의 용량 : " << mS.capacity() << ", 스택의 크기 : " << mS.length() << endl;
   cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
   while (mS.length() != 0) {
      cout << mS.pop() << ' '; // 큐에서 제거하여 출력
   }
   cout << endl << "스택의 현재 크기 : " << mS.length() << endl;

   return 0;
}

//c++에서 상속은 부모의 클래스를 자식들이 똑같이 받음.

//업 캐스팅**
//부모의 첫번째 인자의 주소를 받는다.

// 200 capacity(4bytes)  부모클래스
// 204 mem(8bytes)
//----------------------
// 212 size(4bytes)     자식클래스

//MyQueue mQ;;
//MyQueue *pDer = &mQ;     //200을 가짐
//BaseArray* pBase = pDer; //주소를 저장할 수 있는 변수
//           (200)  (200)

//BaseArray ba;
//BaseArray *pBase=&ba;
//mYQueue* pDer=pBase;
//pDer=(MyQueue*)pBase;
//자식클래스로 만든 객체랑 그 객체의 부모클래스 주소는 같다.
// 그 포인터를 자식클래스로 선언하냐 부모 클래스로 선언하냐에 따라
//엑세스 할수 있는 범위가 달라진다.

//접근 지정자
//pdf 9p에 접속 오류 뜨는 코드 확인!!

//다중 상속 선언

//1127 실습

//가상 함수

//virtual 을 통해 가상함수를 만든다
//virtual 이 있으면 부모는 실행하지 않고 자식만 실행한다.

class Base {
public:
    virtual void f() { cout << "Base::f() called" << endl; } //부모클래스
};
class Derived : public Base {
public:
    void f() { cout << "Derived::f() called" << endl; }
    //자식클래스는 virtual을 하든 안하든 똑같이 나옴.
};
int Ex1127_0() {
    Derived d, *pDer;
    pDer = &d;
    pDer->f(); // Derived::f() 호출
    
    Base* pBase;
    pBase = pDer; // 업캐스팅
    pBase->f(); // Base::f() 호출

    return 0;
}
//실습11-1
//변수를 포인터로 이렇게 선언할 수 있음. 실습11-1 참고
//   int* A= new int;
//    //정수형 변수를 하나 만들어서 A에 넣어줌.
//    *A=100;
//    delete A;

class Shape_1127{
    string name;
public:
    //virtual float getArea() { return 0.0; }
    virtual float getArea()=0;  //순수 가상 함수.
    //가상이라 찾지는 않아
    //그래도 코드 써줘야돼 왜?
    void setName(string name){this->name=name;}
    string getName(){return name;}
    //자식에 선언하면 리턴하기 어려우므로

};
class Oval_1127 : public Shape_1127{
    float a,b;
public:
    Oval_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //프라이빗이기 때문에 자식이 바꿔주려면...
                        //부모클래스에 다른 함수를 불러와서 한다.
    }
    virtual float getArea() { return 3.14*a*b; }//타원의 면적
};
class Rect_1127 : public Shape_1127{
    float a,b;
public:
    Rect_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //프라이빗이기 때문에 자식이 바꿔주려면...
                        //부모클래스에 다른 함수를 불러와서 한다.
    }
    virtual float getArea() { return a*b; }//직사각형의 면적
};
class Triangular_1127 : public Shape_1127{
    float a,b;
public:
    Triangular_1127(string name, float a, float b){
        this->a=a;
        this->b=b;
        setName(name);  //프라이빗이기 때문에 자식이 바꿔주려면...
                        //부모클래스에 다른 함수를 불러와서 한다.
    }
    virtual float getArea() { return 0.5*a*b; }//타원의 면적
};
int Ex1127_1() {
    Oval_1127* p0;
    Rect_1127* p1;
    Triangular_1127* p2;

    Shape_1127 *p[3];  //선언이 부모클래스로 되어 있음.

    p0 = new Oval_1127("빈대떡", 10, 20); 
    p1 = new Rect_1127("찰떡", 30, 40); 
    p2 = new Triangular_1127("토스트", 30, 40);
    
    cout << p0->getName() << " 넓이는 " << p0->getArea() << endl;
    cout << p1->getName() << " 넓이는 " << p1->getArea() << endl;
    cout << p2->getName() << " 넓이는 " << p2->getArea() << endl;

    delete p0;    delete p1;    delete p2;
    return 0;
}

int Ex1127_2() { //위 함수보다 확실히 간단해짐.
   
    Shape_1127 *ptr[3];  //선언이 부모클래스로 되어 있음.

    ptr[0]=new Oval_1127("빈대떡", 10, 20);   //업캐스팅
    ptr[1]=new Rect_1127("찰떡", 30, 40); 
    ptr[2]=new Triangular_1127("토스트", 30, 40);
    
    for(int i=0;i<3;i++)
        cout << ptr[i]->getName() << " 넓이는 " << ptr[i]->getArea() << endl;
    
    for(int i=0;i<3;i++)
        delete ptr[i];
    return 0;
}

class Calculator {
public:
    //virtual로 했으니까 내용은 안 써줘도 돼.
    virtual int add(int a, int b) = 0; // 두 정수의 합 리턴
    virtual int subtract(int a, int b) = 0; // 두 정수의 차 리턴
    virtual double average(int a [], int size) = 0; // 배열 a의 평균 리턴. size는 배열의 크기
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
        //int 형을 계산한 값이기 때문에 이상한 값(3.33->3)이 나올 수 있음.
        //(double)(sum/size); 비교해보기.
    }
};
int Ex1127_3() {
    int a[] = {1,2,3,4,5};
    Calculator *p = new GoodCalc();
    cout << p->add(2, 3) << endl;
    cout << p->subtract(2, 3) << endl;
    cout << (*p).average(a, 5) << endl;  //(*p). 이렇게로도 쓸 수 있다.
    delete p;

    return 0;
}

class Calculator_1127 {
    void input() {
        cout << "정수 2 개를 입력하세요>> ";
        cin >> a >> b;
    }
protected:  //자식만 억세스 할 수 있다. 제 3자는 억세스 불가(private과 동일)
    int a, b;
    virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
public:
    void run() {
    input();
    cout << "계산된 값은 " << calc(a, b) << endl;
    }
};
class Adder_1127 : public Calculator_1127{
public:
    int calc(int a, int b){return a+b;}
};
class Subtractor_1127 : public Calculator_1127{
public:
    int calc(int a, int b){return a-b;} // 두 정수의 차 리턴
};
int main() {

    Adder_1127 adder;
    Subtractor_1127 subtractor;
    adder.run();
    subtractor.run();

    return 0;
}