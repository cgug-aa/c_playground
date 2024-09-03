#include <iostream>
#include <string> //string
#include <vector> //vector

using namespace std;

/*
-클래스와 객체!

c에서 구조체처럼
class를 적고
멤버변수와
멤버함수를 넣는다

-string 클래스 와 vector 클래스
#include<string>
문자열 복사, 비교, 길이등을 활용할 수 있다

string자체가 변수 타입이다.
string name; // 빈 문자열을 가진 스트링 객체
string address("서울시 성북구 삼선동 389“); // 문자열 리터럴로 초기화
string copyAddress(address); // address를 복사한 copyAddress 생성
*/

int Ex0922_01()
{
    char cname[]="Lee";
    string sname(cname);   //문자열 cname에 있던 게 sname으로 복사가 된다.

    cout<<sname[0]<<endl;  //배열처럼 접근할 수도 있다.

    //string name ="Lee chan gu";
    string name("Lee chan gu");
    string address("chengju CBNU");

    string str=name+address;

    cout<<str<<endl;

    string str_copy=str;

    cout<<str_copy<<endl;

    cout<<str.size()<<endl;  //문자열의 길이를 알려준다.

    int pos=str.find("gu");  //문자열에서 문자의 인덱스 찾아 위치를 알려준다

    cout<<pos<<endl;


    return 0;
}

//string은 기능이 많아서 여기까지!

/*
벡터

*/
int Ex0922_02()
{
    vector<int> A; //vector는 배열로 <>안에 그 형식을 넣는다.

    cout<<A.size()<<endl;

    A.push_back(10);   //벡터에 값을 푸쉬해서 넣는다.
    A.push_back(20);
    A.push_back(30);
    A.push_back(40);

    for(int i=0;i<A.size();i++)
    cout<<A[i]<<endl;

    A.clear();       //를 통해 벡터를 초기화할 수 있다.

    return 0;
}

/*
접근 지정자 private, protected, public
롤 나눠서 코드를 접근 권한을 인가할 수 있다.

*/
class Circle{         //변수형을 만든다는 느낌     
public:  //public을 사용하지 않으면 private이 default이므로
         //외부에서 사용할 수 없다.
   int radius;        //변수 선언
   double getArea();   //함수 선언

};
//class안에 함수가 길어질 때 함수를 class밖에 선언할 수 있다.
//이 때 클래수 소속임을 밝히기 위해 ::를 사용한다
double Circle::getArea()
   {
    return (3.14*radius*radius);
   }


/*
class Circle{         //변수형을 만든다는 느낌     
private:  //public을 사용하지 않으면 private이 default이므로
         //외부에서 사용할 수 없다.
   int radius;        //변수 선언
public:
   double getArea()   //함수 선언
   {
    return (3.14*radius*radius);
   }
   void setRadius(int r)
   {
    radius=r;         //이런 식으로 선언하면 위 클래스와 동일하게 사용할 수 있다.
   }
};
*/
int Ex0922_03()
{
    Circle donut;     //클래스 객체 이름
    donut.radius = 1; // donut 객체의 반지름을 1로 설정

    double area = donut.getArea(); // donut 객체의 면적 알아내기
    cout << "donut 면적은 " << area << endl;

    Circle pizza;

    pizza.radius = 30; // pizza 객체의 반지름을 30으로 설정
    area = pizza.getArea(); // pizza 객체의 면적 알아내기
    cout << "pizza 면적은 " << area << endl;

    Circle *ptr;
    ptr = &pizza;

    cout<<ptr->radius<<endl;     //포인터의 내용을 보기 위해 ->를 사용한다
                                 //ptr->radius을 (*ptr).radius로 쓸 수도 있다.
    cout<<ptr->getArea()<<endl;  //(*ptr).getArea()로 바꿀 수 있다.
    return 0;
}

class Rectangle{
public:
    int width;
    int height;
    int getArea()
    {
        return (width*height);
    }
};
int main()
{
   Rectangle rect;
   rect.width = 3;
   rect.height = 5;
   cout << "사각형의 면적은 " << rect.getArea() << endl;
   
   return 0;
}