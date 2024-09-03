#include <iostream>
using namespace std;

/*
생성자
-객체가 생성되는 시점에서 자동으로 호출되는 멤버 함수
-객체가 생성될 때 객체가 필요한 초기화를 위해
소멸자
-객체를 소멸되는 시점에서 자동으로 호출되는 멤버 함수
-객체가 소멸될 때 객체의 정리를 위해
*/
class CirCle0925{
public:
    int radius;
    //int* MEM;
    CirCle0925();       //생성자
    CirCle0925(int r);  //생성자 
    ~CirCle0925();      //소멸자
    double getArea();   //함수를 클래스에 정의하고
};
/*
출력화면:
반지름 1인 원 생성
반지름 100인 원 생성
반지름 100인 원 소멸
반지름 1인 원 소멸

-메인함수가 끝나면서 소멸시키는 것
생성이 AB순서면,
소멸은 BA순서
*/

CirCle0925::~CirCle0925()
{
    //delete[] MEM;
    cout<<"반지름 "<<radius<<"인 원 소멸"<<endl;   //소멸할 때 출력될 문장
}
CirCle0925::CirCle0925()   //함수를 밖에 적어준다.
{
    //MEM= new int [10000*10000]; //이렇게 메모리를 늘려주면 pc의 메모리를 많이 잡아먹게 됨
                                     //따라서 소멸자가 필요함.
    radius = 1;
    cout<<"반지름 "<<radius<<"인 원 생성"<<endl;
}
CirCle0925::CirCle0925(int r)  //파라미터가 달라서 다른 함수로 취급한다.
{
    //MEM= new int [10000*10000];

    radius = r;
    cout<<"반지름 "<<radius<<"인 원 생성"<<endl;
}
double CirCle0925::getArea()
{
    return (3.14*radius*radius);
}

int FFF()
{
    //CirCle0925 A(); 파라미터가 없으므로 디폴트 값인 1이 반지름으로
    CirCle0925 A(100); 
    CirCle0925 B(100); //int r에 100을 파라미터로 전해줌
    
    return 0;
}
//CirCle0925이 포함된 함수를 벗어나면 소멸된다.
//CirCle0925 gA(1000);
//CirCle0925 gB(2000);    //글로벌 변수가 제일 먼저 실행됨
int Ex0925_01()
{
    CirCle0925 A;
    CirCle0925 B(30);
    FFF();

    return 0;
}
/*
출력화면:
반지름 1000인 원 생성
반지름 2000인 원 생성
반지름 1인 원 생성
반지름 30인 원 생성
반지름 100인 원 생성
반지름 100인 원 생성
반지름 100인 원 소멸
반지름 100인 원 소멸
반지름 30인 원 소멸
반지름 1인 원 소멸
반지름 2000인 원 소멸
반지름 1000인 원 소멸

-생성과 소멸은 역순
*/

class Rectangle{
public:
    double width, height;
    /*bool isSquare;
    Rectangle(int width=2, int height=2){
        if(width == height)
            isSquare='True';
    }           내가 실습했던 코드
    */
    Rectangle();       //for rect1 생성자 선언 클래스와 동일한 이름
    Rectangle(int w_in, int h_in=3){ //생성자 for rect2,3  <**디폴트값은 뒤에서 부터!!>
      width=w_in;
      height=h_in;
    }
    bool isSquare(){
        if(width==height)
            return true;
        else
            return false;
    }
};
Rectangle::Rectangle(){
    width=0;
    height=0;
}

int main()
{
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
    
    
    
    return 0;
}