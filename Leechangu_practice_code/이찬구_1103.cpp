#include <iostream>
#include<string.h>
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
int main() {
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();
}