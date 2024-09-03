#include<iostream>
#include<string.h>
#include<string>      //문자열 비교(strcmp), 복사(strcpy), 수정 가능
#include<vector>      //vector포함
//#include "cal.h"      //헤더파일 포함
using namespace std;


//0901 실습

//<iostream> 헤더파일을 컴파일 전에 소스에 확장하도록 지시
//<iostream> 헤더 파일: 입출력을 위한 클래스와 객체, 변수 등이 선언됨
//using namespace std; 를 쓰면 std따로 안 적어도 됨

void Ex0901_1()
{
    std::cout << "My name is changu.\n\n"; //C++에의 출력객체인 cout 이용
    //cout<< 값 형식으로 출력
    //<<연산자 다음에 기본형의 변수를 지정하면 자동으로 데이터 형에 맞추어 출력
}
void Ex0901_2()
{
    std::cout << "정보통신공학부\n23세\n통신 엔지니어\n\n";
}
void Ex0901_3()
{
	int sum = 0;
	for (int n = 0; n < 11; n++)
		sum += n;
	std::cout << "1에서 10까지 더한 결과는" << sum << "입니다.\n\n";
	
    //변수, 문자열 출력

	//char c='#';
	//std::cout<<c<<5.5<<'-'<<"Hi";
	//변수(c), 숫자(5.5), 문자(-), 문자열(Hi) 출력
}
void Ex0901_4()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= i; j++) std:: cout << "*";
		std::cout << "\n";
	}
}
int Ex0901_main(){
	Ex0901_1();
	Ex0901_2();
	Ex0901_3();
	Ex0901_4();
	return 0;
}

//0904 실습

//함수를 선언해줌 메인으로 들어가기 전에 메인 함수보다
//앞에 함수를 작성하면 굳이 선언 안 해도 됨
int sum(int a, int b) //처음 숫자 a, 끝 숫자 b
{                    
   int k;
   int res = 0;   //결과
   for (k = a; k <= b; k++)
      res += k;

   return (res);
}
int Ex0904_1()    //1부터 입력값까지 합을 나타내는 함수
{
   int n = 0;
   cout << "끝수를 입력하세요>>"<<endl;
   cin >>n ;
    if (n <= 0){
        cout << "양수를 입력하세요!\n";
        return 0;
        }
    cout << "1에서 " << n << "까지의 합은 " << sum(1, n) <<"입니다\n" << endl;
    return 0;
}
void Ex0904_2()
{
   int r=0;
   for (int i = 1; i < 10; i++)
   {
      for (int n = 1; n < 10; n++)
      {
         r = n * i;
         cout << i << "*" << n << "=" << r<<"  ";
      }
      cout << endl;
   }
}
double biggest(double *a,int n)
{
   double max = 0;
   for (int i = 0; i < 5; i++)
      if (max < a[i])
         max = a[i];
   return(max);
}
void Ex0904_3()
{
   double a[5];
   cout << "5개의 실수를 입력하라>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "제일 큰 수 = " << biggest(a,5) << endl;  //배열은 인덱스에 배열이름으로
}
int Ex0904_main()
{
   Ex0904_1();
   Ex0904_2();
   Ex0904_3();
   return 0;
}

//0908 실습

//cin.ignore(최대확인글자수, ‘문자’ ) : 입력 버퍼 지우기
//최대 수만큼 버퍼에 있는 문자를 지우고, 혹시 ‘문자’가 나타나면 ‘문자’까지 지우고 스톱
//cin >> val;
//if (cin.fail() == 1) {      // 입출력 오류가 발생하면
//cin.clear();                // 모든 오류비트 clear
//cin.ignore(256, ‘\n’);      // 최대 256개의 문자 무시가능, 개행문자를 만나면 추출을 멈춤
//}
int Ex0908_1()
{
    char c[100];
    int count=0;
    cout<<"문자들을 입력하라(100개 미만)."<<endl;

    cin.getline(c, 100);//문자열을 입력 받는데 띄어쓰기를 포함해서 입력된다.
    //cout<<c<<endl;      문자열 끝나면 엔터치기
    for(int i=0; i<100;i++)
   {
      if(c[i]=='\n') break;   // \0은 줄바꿈
      if(c[i]=='x') count++;
   }
    cout <<'x'<< "의 개수는" <<count<<endl; //큰 따옴표는 문자나 문자열,
    return 0;                              //작은 따옴표는 변수를 불러온다.
}
int Ex0908_2()
{
    return 0;
}
int Ex0908_3()
{
   char name[100];
   char address[100];
   int age=0;
   cout<<"이름은?";
   cin.getline(name, 100);  //getline을 써야지 띄어쓰기가 포함돼. name을 100까지
   cout<<"나이는?";
   cin>>age;
   cin.ignore(100, '\n');   //앞선 입력(cin)에서 개행이 남기 때문에 
                            //개행을 지워줘야 다음 입력값이 잘 들어온다
   cout<<"주소는?";
   cin.getline(address, 100);
   cout<<"--------------------------------------"<<endl;
   cout<<name<<". "<<address<<". "<<age<<"세"<<endl;
   return 0;
}

//포인터
int Ex0908_4()
{
    char a[5]={'a', 'b', 'c', 'd', 'e'};
//&a[1], &a[2] 등으로 배열의 주소를 알 수 있다.
//a[2]는 *(a+2)와 같은 값으로 동일하다.
//a+2는 주소 *(a+2)는 값
    char * p;
    p=a;  //a는 배열이니까 주소가 들어가
    printf("vla =0x%x %c %c 0x%x \n", a+1, *(a+1), a[1], &a[1]);//주소, 값, 값, 주소
    char *p1;
    p1=&a[3];
    printf("%c", *p1);
//p1이 들어있는 자리의 값이 나온다.
//printf("%c", *(p1+1))를 하면 a[4]의 값이 나온다.
//a[3]와 *(a+3)가 같기 때문에 p1[-1]은 a[2]의 값이 나온다.
    return 0;
}

//0911 실습

//포인터 [*b와 &a를 구분할 수 있어야 돼]
//포인터는 변수의 주소를 나타냄

//int a;    에서
//cout<<a;  는 값
//cout<<&a; 는 주소
//주소를 복사해서 사용하고 싶을 때 b=&a 는 실수형이지만
//b는 주소를 저장하는 변수이므로, *를 붙여서 int *b;
//(포인터 변수 int랑 큰 관련없는 새로운 변수락 생각하면 됨)로 선언한다.
//*b; 는 b의 값(내용)이 나옴.
//포인터 변수에 *을 붙이면 내용이 됨.

//float M[10];  배열에서
//cout<<M;      은 주소
//cout<<&M[0];  은 내용
//cout<<*M;     은 내용
//cout<<M+1;    은 주소
//cout<<*(M+1)  은 내용
//cout<<M[1];   은 내용
int Ex0911_0()
{
   int n=10, m;
   char c = 'A';
   double d;
   int *p;
   p=&n;
   cout<<n<<endl; //10이 출력
   *p=25;         //p를 통해 n의 주소로 가서
//*p로 값을 바꿔줌(포인터를 통해 값을 바꿈)
   cout<<n<<endl; //25가 출력된다.
   return 0;
}
void func(int* pointer)    //주소를 받아야 하니까 포인터를 써준다.
{
   cout<<pointer<<endl;    //주소를 받아
   cout<<*pointer<<endl;   //값을 받아
}
int Ex0911_1()
{
   int arr[6]={1,2, 3, 4, 5, 6};
   int* chr_ptr=arr;
//포인터 변수를 선언하고, 주소(배열)를 넣어준다.
   chr_ptr++;           //포인터 주소 하나 추가 arr[1]
   cout<<chr_ptr<<endl; //arr[1]의 주소
   cout<<*chr_ptr<<endl;//arr[1]의 값
   cout<<arr<<endl;     //arr[0]의 주소
   cout<<arr+4<<endl;   //arr[5]의 주소
   cout<<&arr[3]<<endl; //arr[3]의 주소
   cout<<arr[4]<<endl;  //arr[4]의 값
   cout<<*(chr_ptr+2)<<endl; //arr[3]의 값
   func(arr);
   return 0;
}
int Ex0911_2()  //이중포인터 변수일 때
{
   int a=10, b=20, c=30, d=40, e=50;
   int* a_ptr =&a;    //그냥 변수니까 주소를 넣을 때 &를 붙여서 넣어줘
   int* b_ptr =&b; 
   int* c_ptr =&c;
   int* d_ptr =&d;
   int* e_ptr =&e;

   int* ptr[5];       //포인터 변수를 5개 잡음
   ptr[0]=&a;
   ptr[1]=&b;
   ptr[2]=&c;
   ptr[3]=&d;
   ptr[4]=&e;
   for(int i=0;i<5;i++)
      cout<<*ptr[i]<<endl;
   //ptr로 하면 주소가 출력   *ptr으로 하면 값이 출력
   //cout << *a_ptr<<endl;
   return 0;
}
int En0911_3()   //이중포인터 배열일 때
{
   int arr_0_[3]={1,2,3};
   int arr_1_[4]={11, 12, 13, 14};
   int arr_2_[5]={21, 22, 23, 24, 25};
   int* ptr[3];
   ptr[0]=arr_0_;      //ptr[0] 자체가 변수야 
   ptr[1]=arr_1_;
   ptr[2]=arr_2_;
//int* ptr[3]={arr_0_,arr_1_,arr_2_};
   cout<<*ptr[0]<<endl;  //*중요*  *ptr[0]은 출력 1 
   cout<<*(ptr[0]+1)<<ptr[0][1]<<endl;  //*(ptr[0]+1)은 ptr[0][1]이므로 둘 다 2를 출력
//int** ptr2 =ptr;  //참고) ptr의 주소를 구하고 싶으면 포인터를 한번 더 써주면 돼
   return 0;
}

//0915 실습

//포인터 복습

void Func(int a)
{
   a=200;
   cout<<"Func: "<<a<<endl;
   cout<<"Func:& "<<&a<<endl;
}
void Funcptr(int *a)
{
   *a=200;
   cout<<"Func: "<<*a<<endl;
   cout<<"Func:& "<<&a<<endl;
}
int Ex0915_1()
{
   int a =100;
   int *p=&a;
   cout<<&a<<endl;  //a의 주소
   cout<<p<<endl;   //a의 주소
   cout<<*p<<endl;  //100
   //Func(a);         //값이 바뀌지않음
   Funcptr(&a);       //a의 값이 바뀜
   cout<<&a<<endl;
   cout<<a<<endl;
   return 0;
}
void FuncArray(int* ptr)   //배열을 받기 위해 주소를 넘겨준다.
{
   cout<<"Func"<<ptr<<endl;   //주소
   cout<<"Func"<<*ptr<<endl;  //ptr[0]값
   cout<<"Func"<<ptr[0]<<endl;//ptr[0]값
   for(int i=0;i<5;i++)
      cout<<ptr[i]<<endl;  //ptr 값이 출력 돼
}
int Ex0915_2()
{
   int c[5]={10, 20, 30, 40 ,50};
   cout<<c<<endl;      //배열의 이름은 주소를 반환
   cout<<*c<<endl;     //c[0]
   cout<<c+1<<endl;    //주의)배열의 이름이므로 주소를 반환한다.
   cout<<*(c+1)<<endl; //포인터를 사용하여 값을 반환. 20
   FuncArray(c);
   int* p;
   p=c;
   cout<<p<<endl;
   cout<<*p<<endl;
   cout<<p+1<<endl;
   cout<<*(p+1)<<endl;
   return 0;
}
//c와 다르게 레퍼런스 존재
//레퍼런스 선언 >>> 배열 주소와 전혀 상관없음
//이미존재하는 변수에 대한 다른 이름 선언 >>>별명
//int target=20;
//int& ref=target;
//ref=3;
void FuncRef(int& ttt)
{
   cout<<"Ref: "<<ttt<<endl;
   ttt=500;
}
int Ex0915_3()
{
   int target = 20;
	int& nickname = target;   //주의) int& nickname은 초기화를 무조건 해줘야 한다.
	nickname = -10;           //레퍼런스 nickname 선언하고, target처럼 쓰겠다.

	cout << target << endl;
	FuncRef(target);
	cout << target << endl;   //값이 바뀌게 된다. 배열이 아니라 변수 자체로 쓰이기 때문에
	return 0;
}
void swap(int& a, int& b)    //레퍼런스 변수로 넣어주면 값이 바뀐다.
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void adder(int a, int b, int& c)  //&를 사용하지 않으면 이 함수에 a,b,c와 메인 함수의 a,b,c가 다른 변수가 된다.
{
	c = a + b;
}
void adder(int a, int b, int* c)  //레퍼런스 말고 포인터로 값을 호출할라면?
{
	*c = a + b;    //변수의 값을 바꿔줘야하니까 *를 써줘
}
void addsub(int a, int b, int& sum, int& diff)   //a와 b는 함수에서 불러오는데만 사용되므로 &를 안 붙여도 됨
{                   //sum이랑 diff는 메인 함수로 보내줘야하므로 &나 *를 써야한다.
	sum = a + b;
	diff = a - b;
}
int Ex0915_4()
{
	int a = 10, b = 20;
	swap(a, b);
	cout << "a = "  << a << '\t' <<"b = " << b << endl;
	int c = 0;
	adder(a, b, c);
	cout << "adderref: c = " << c << endl;
	adder(a, b, &c);
	cout << "adderptr: c = " << c << endl;
	c = 0;
	int d = 0;
	addsub(a, b, c, d);
	cout << "sum = " << c << '\t' << "diff = " << d << endl;
	return 0;
}
bool average(int *a, int size, int& avg)  //int a[]라고 써도 돼
{
	int sum = 0;
	if (size < 0)
		return (false);

	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = (sum/size);
	return (true);
}
int Ex0915_5()
{
	int x[] = { 0,1,2,3,4,5};
	int avg;
	if (average(x,6,avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -1, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류 " << endl;

	return 0;
}

//0918 실습

//

bool bigger(int a, int b, int& big)
{//big은 메인함수로 다시 보내줘야 하니까 레퍼런스를 사용했다.
	if (a == b)return true;
	else if (a > b){
		big = a;
		return false;
	}
	else{
		big = b;
		return false;
	}
}
int Ex0918_1()         //정수의 크기를 비교하는 실습
{
	int x, y, big;
	bool b;
	cout << "두 정수를 입력하세요>>";
	cin >> x >> y;
	b = bigger(x, y, big);
	//cout << b << endl;
	if (b)
		cout << "same" << endl;
	else
		cout << "큰 수는" << big << endl;
	return 0;
}
char& find(char a[], char c, bool& success)  //문장 속 글자를 찾아주고
{
	success = false;              //최초에 false라 초기값을 주고
	for (int i = 0;; i++)         //;;으로 나중값을 공백으로 두면 계속 반복
	{
		if (a[i]=='\0')
			return a[i];            //찾는 문자가 없으면 줄바꿈을 출력
		else if (a[i] == c)        //찾는 문자 찾으면 그 공간을 보내줘
		{
			success = true;
			return a[i];
		}
	}
}
int Ex0918_2()        //문장속 대문자를 소문자로 바꾸는 예제
{
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);    //a[i]의 공간을 받았으니까 값을 가져오기 위해
   // & 참고를 넣어줘 돼
	if (b == false){
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';          // a[i]의 값인 'M' 위치에 'm' 기록
	cout << s << endl;  // "mike"가 출력됨
}
int Sum(int a=-20, int b=-10, int c=10)   //int c=10이라 해도 총합은 60이 된다.
{//하지만 메인함수에서 c값을 전달해주지 않으면,
//c값을 디폴트로 10이 된다.
	return (a + b + c);//디폴트 값을 설정할 땐 끝에서부터 설정해야한다.
}
int Ex0918_3()
{
	int a = 10, b = 20, c = 30;
	int d, e, f, g;

	d=Sum(a, b,c);
	e = Sum(a, b);
	f = Sum(a);
	g = Sum();    //매개변수가 없으면 함수에 있는 디폴트 값으로 들어감
	cout << d << '\n' << e << '\n' << f << '\n' << g;
	return 0;
}
int diff(int a, int b){
	return (a - b);
}
double diff(double a, double b)  
//인덱스와 출력 타입이 다르면 함수 이름이 같아도 다른 함수로 취급
//c언어에서는 안된다.
{
	return (a - b);
}
int Ex0918_4()
{
	int A = 10, B = 20, C;
	C = diff(A, B);
	cout << C<<endl;

	double dA = 1.0, dB = 2.0, dC;
	dC = diff(dA, dB);
	cout << dC;
	return 0;
}
//'unsigned int'를 UINT선언해서 쓴다;
typedef unsigned int UINT;
void f(char c= ' ', int line = 1)
{
	for (int i = 0; i < line; i++)
	{
		for (int n = 0; n < 10; n++)
			cout << c;
		cout << '\n';
	}
}
int Ex0918_5()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}

//0922 실습

//클래스와 객체
//c에서 구조체처럼 class를 적고 '멤버변수'와 '멤버함수'를 넣는다
//string 자체가 변수 타입
//string name; 빈 문자열 가진 스트링 객체
//string address("서울시 성북구 삼선동 389") 문자열 리터럴로 초기화
//string copyAddress(address) address를 복사한 copyAddress 생성

int Ex0922_1()      //string의 기능 실습
{
   char cname[]="Lee";
   string sname(cname);   //문자열 cname에 있던 게 sname으로 복사가 된다.
   cout<<sname[0]<<endl;  //배열처럼 접근할 수도 있다.
   //string name ="Lee chan gu";
   string name("Lee chan gu");
   string address("chengju CBNU");
   string str=name+address;  //문자열 두개를 합쳐
   cout<<str<<endl;
   
   string str_copy=str;
   cout<<str_copy<<endl;
   cout<<str.size()<<endl;  //.size()는 문자열의 길이를 알려준다.

   int pos=str.find("gu");  //.find()는 목표 문자의 인덱스 위치를 알려준다
   cout<<pos<<endl;
   return 0;
}
//벡터 실습
int Ex0922_2()
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
//클래스
//접근 지정자 private, protected, public
class Circle_0922{
public:              //public을 사용하지 않으면 private이 디폴트이므로 
   int radius;       //외부에서 사용할 수 없다.
   double getArea(); //변수, 함수 선언
};
//클래스 소속을 나타내기 위해 ::를 써준다.
double Circle_0922::getArea(){
   return (3.14*radius*radius);
}
//클래스는 변수형을 만든다는 느낌
int Ex0922_3()
{
   Circle_0922 donut;     //클래스 객체(변수형) 이름
   donut.radius = 1;      //donut 객체의 반지름을 1로 설정
   double area = donut.getArea(); // donut 객체의 면적 알아내기
   cout << "donut 면적은 " << area << endl;

   Circle_0922 pizza;
   pizza.radius = 30;      // pizza 객체의 반지름을 30으로 설정
   area = pizza.getArea(); // pizza 객체의 면적 알아내기
   cout << "pizza 면적은 " << area << endl;

   Circle_0922 *ptr;
   ptr = &pizza;                //포인터가 클래스 pizza를 가르킴
   cout<<ptr->radius<<endl;     //포인터의 내용을 보기 위해 ->를 사용한다
                                //ptr->radius을 (*ptr).radius로 쓸 수도 있다.
   cout<<ptr->getArea()<<endl;  //(*ptr).getArea()로 바꿀 수 있다.
   return 0;
}
class Rectangle_0922{
public:
    int width;
    int height;
    int getArea(){
        return (width*height);
    }
};
int Ex0922_4()  //실습 4-3
{
   Rectangle_0922 rect;
   rect.width = 3;              //클래스 안의 변수에 값을 넣어줌
   rect.height = 5;
   cout << "사각형의 면적은 " << rect.getArea() << endl;
   return 0;
}

//0925 실습

//생성자:-객체가 생성되는 시점에서 자동으로 호출되는 멤버 함수
//       -객체가 생성될 때 객체가 필요한 초기화를 위해
//소멸자:-객체가 소멸되는 시점에서 자동으로 호출되는 멤버 함수
//       -객체가 소멸될 때 객체의 정리를 위해
//       -메인함수가 끝나면 소멸됨.
class CirCle_0925{
public:
   int radius;
   //int* MEM;
   CirCle_0925();       //생성자
   CirCle_0925(int r);  //생성자 
   ~CirCle_0925();      //소멸자
   double getArea();   //함수를 클래스에 정의하고
};
CirCle_0925::CirCle_0925(){   //함수를 밖에 적어준다.
   //MEM= new int [10000*10000]; //이렇게 메모리를 늘려주면 pc의 메모리를 많이 잡아먹게 됨
                                 //따라서 소멸자가 필요함.
   radius = 1;
   cout<<"반지름 "<<radius<<"인 원 생성"<<endl;
}
CirCle_0925::CirCle_0925(int r){  //파라미터가 달라서 다른 함수로 취급한다.
   //MEM= new int [10000*10000];
   radius = r;
   cout<<"반지름 "<<radius<<"인 원 생성"<<endl;
}
double CirCle_0925::getArea(){
   return (3.14*radius*radius);
}
CirCle_0925::~CirCle_0925(){
   //delete[] MEM;
   cout<<"반지름 "<<radius<<"인 원 소멸"<<endl;   //소멸할 때 출력될 문장
}
int Ex0925_1()
{
   //CirCle_0925 A(); 파라미터가 없으므로 디폴트 값인 1이 반지름으로
   CirCle_0925 A(100); 
   CirCle_0925 B(200); //int r에 200을 파라미터로 전해줌
   return 0;
}  //생성과 소멸은 역순
class Rectangle_0925{
public:
   double width, height;
   Rectangle_0925(){
      width=0;
      height=0;
   }
   Rectangle_0925(int w_in, int h_in=3){
      width=w_in;
      height=h_in;
   }
   bool isSquare(){
      if(width==height)return true;
      else return false;
   }
   ~Rectangle_0925(){      //rect1,2,3이 다 소멸되므로 3번 출력된다.
      cout<<"클래스 소멸"<<endl;
   }
};
int Ex0925_2()
{
   Rectangle_0925 rect1;
   Rectangle_0925 rect2(3,5);
   Rectangle_0925 rect3(3);
   if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
   if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
   if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
   return 0;
}

//1013 실습

//분할 컴파일
//클래스를 헤더 파일과 cpp파일로 분리하여 작성
//클래스 선언(클래스 이름.h)
//클래스 구현(멤버함수의 구현)&클래스가 선언된 헤더파일 include
//main.cpp 선언된 헤더파일 포함

//헤더파일을 중복해서 선언하면, 문제가됨
//1st) 헤더파일의 이름을 따서 심볼을 만든다. 클래스이름_H
//2nd) 헤더파일 앞에 #ifndef 심볼, #define 심볼
//3rd) 헤더파일의 제일 끝에 #endlif를 추가한다.
class Adder_1013{
    int op1,op2;
public:
    Adder_1013(int a, int b); //생성자
    int process();       //포함 함수
};

class Calculator_1013{
public:
   void run();     //포함 함수
};
Adder_1013::Adder_1013(int a, int b){
   op1=a;
   op2=b;
}
int Adder_1013::process(){
   return op1+op2;
}

void Calculator_1013::run(){
   cout<<"두 개의 수를 입력하세요."<<endl;
   int a, b;
   cin>>a>>b;
   Adder_1013 adder(a,b);
   cout<<adder.process()<<endl;
}
void cal(){
   Calculator_1013 calc;  //class 변수 선언
   calc.run();       //class 실행
   //메인에서 실행하기 위한 함수
   //cal 안에서 Calculator 실행 안에서 adder process를 실행
}
void cal();

int Ex1013()
{
   cal();
   return 0;
}

//1016 실습

//접근지정자
//private: 해당 클래스의 멤버함수에서의 접근까지 허용
//protected: 파생클래스의 멤버함수에서의 접근까지
//public: 클래스 밖에서의 접근까지
//생성자를 프라이빗으로 만들면, 호출할 때(함수, 변수 다) 오류발생
//접근자 함수는 get이나 set으로 접근한다.

class Ram{
   char mem[100*1024];     // 100kb 메모리
   int size;
public:
   Ram();     //mem을 0으로 초기화 하고 size를 100*1024로 초기화
   ~Ram();    //"메모리 제거됨" 문자열 출력
   char read(int address); //address주소의 메모리를 읽어 리턴
   void write(int address, char value);
   //address 주소에 value 저장
   //주소가 범위를 벗어나는 오류 발생하면 에러 메시지 출력함,
};
Ram::Ram()
{
   size=100*1024;
   for(int i=0;i<size;i++)
      mem[i]=0;
//memset(mem,0,size); mem이 char가 아니라 int면 bit단위를 4로 해야됨 
}
Ram::~Ram(){
   cout<<"메모리 제거됨"<<endl;
}
char Ram::read(int address){
   return mem[address];
}
void Ram::write(int address, char value){
   mem[address]=value;
}
int Ex1016_1(){
   Ram ram;
   ram.write(100, 20);//100번지에 20저장
   cout<<"100번지의 값="<<(int)ram.read(100)<<endl;

   ram.write(101, 30);//101번지에 30저장
   cout<<"101번지의 값="<<(int)ram.read(101)<<endl;

   char res=ram.read(100)+ram.read(101);//20+30=50
   ram.write(102, res);//102번지에 50저장
   cout<<"102번지의 값="<<(int)ram.read(102)<<endl;
   //102번지 메모리 값 출력
   return 0;
}

//static

//class로 묶어서 합치면 프로그램을 각각의 개체로 볼수 있음
//class A와 class B를 합치다 보면 공유되는 변수가 있을 수 있는데
//이를 static으로 선언할 수 있다.

class Person_1016{
public:
   double money;
   void addMoney(int money_in){
      money+=money_in;
   }
   static int sharedMoney_1;//공금
   static void addShared(int n){
      sharedMoney_1+=n;
   }
};
int Person_1016::sharedMoney_1=10;
//이렇게 static변수를 선언해놔야함. 글로벌 변수처럼
int Ex1016_2(){
   Person_1016 A, B;  //서로 다른 class
   //공금은 합치고 싶다~ 이건 static으로 써야겠네
   //A.sharedMoney=B.sharedMoney
   A.sharedMoney_1=100;
   B.sharedMoney_1=200;
   //실제로 sharedMoney는 공유 변수라서 출력해보면
   //cout<<A.sharedMoney<<endl; //200으로 출력됨
   cout<<Person_1016::sharedMoney_1<<endl;
   //Person::sharedMoney로 접근할 수 있음 덜 헷갈림
}
class Math{
public:
   static int cg_abs(int a){
      return a>0?a:-a;
   }
   static int cg_max(int a, int b){
      return (a>b)?a:b;
   }
   static int cg_min(int a, int b){
      return (a>b)?b:a;
   }
};
int Ex1016_3(){
   cout<<Math::cg_abs(-5)<<endl;
   cout<<Math::cg_max(10, 8)<<endl;
   cout<<Math::cg_max(-3, -8)<<endl;
   return 0;
}
class Person_1016_2{
public:
   double money;   //개인소유 돈
   void addMoney(int money_in){
      money+=money_in;
   }
   static int sharedMoney;  //공금
   static void addShared(int n){
      sharedMoney+=n;
   }
   string name; //객체이름
   Person_1016_2(){money=0;}
   Person_1016_2(string name_in){
      money=0;
      name=name_in;
   }
   ~Person_1016_2(){
      cout<<name<<"'s mmoney = "<<money<<endl;
   } //만들어진 객체가 2개니까 소멸이 두 개가 되고
     //따라서 KANG이랑 KIM이 다 나옴
};
int Person_1016_2::sharedMoney=0;  //전역변수처럼 초기화 해줘야돼
int EX1016_4(){
   Person_1016_2 A("KANG"), B("KIM");
   //3월
   A.addMoney(100);
   A.addShared(5);
   B.addMoney(200);
   B.addShared(5);

   //4월
   A.addMoney(100);
   A.addShared(5);
   B.addMoney(200);
   B.addShared(5);

   cout<<"공금 = "<<Person_1016_2::sharedMoney<<endl;
   Person_1016_2::addShared(100);
   cout<<"공금 = "<<Person_1016_2::sharedMoney<<endl;
   return 0;
}

//1020 실습

//여러가지 객체의 생성방법
//객체를 배열처럼 여러개 생성할 수 있다.
//객체이름에 인덱스가 들어갔다고 생각할 수 있다. 객체이름[i]=하나의 객체

class Circle1020{
   int radius;
public:
   Circle1020(){radius=1;}
   Circle1020(int r){radius=r;}
   int getRadius(){return radius;}
   void setRadius(int r){radius=r;}
   double getArea();
   ~Circle1020();
};
double Circle1020::getArea(){
   return 3.14*radius*radius;
}
Circle1020::~Circle1020(){}
int Ex1020_1(){
   Circle1020 cir[3]={Circle1020(10), Circle1020(20), Circle1020(30)};

   cir[0].setRadius(100);
   cir[1].setRadius(200);
   cir[2].setRadius(300);

//   for(int i=0;i<3;i++){
//      cout<<"면적"<<cir[i].getArea()<<endl;
//   }

   Circle1020* p; //선언문 *p와 * p와 다르다
   p=cir;         //객체의 주소를 포인터로 가르킴
   //(*p).setRadius(-100); //*p는 내용 cir[0]이므로 내용 cir[0]이 바뀐다.
   p->setRadius(-100); //위 문장과 내용이 바뀜

   p=&(cir[1]);  //p는 주소 변수이므로 &를 통해 주소를 넣어줘야 한다.
   p->setRadius(-100); //cir[1]의 내용이 바뀜
   
   p++;
   p->setRadius(-100); //cir[2]의 내용이 바뀜
   (*p).setRadius(-500); //cir[2]의 값이 -500이 됨.
//   for(int i=0;i<3;i++){
//      cout<<"면적"<<cir[i].getArea()<<endl;
//   }
   p[0].setRadius(-400);  //cir대신 p를 쓸 수 있다.
   p[1].setRadius(-400);
   p[2].setRadius(-400);

//   for(int i=0;i<3;i++){
//      cout<<"면적"<<cir[i].getArea()<<endl;
//   }
   return 0;
}
class Color{
   int red, green, blue;
public:
   Color(){red=green=blue=0;}
   Color(int r, int g, int b){
      red=r;
      green=g;
      blue=b;
   }
   void setColor(int r, int g, int b){
      red=r;
      green=g;
      blue=b;
   }
   void showColor(){
      cout<<"(r, g, b) = "<<red<<" "<<green<<" "<<blue<<" "<<endl;
   }
};
int Ex1020_2(){
   Color screenColor(255, 0, 0); //빨간색의 screenColor 객체 생성
   Color* p;
   p=&screenColor;   //p가 screebColor의 주소를 가지도록
   p->showColor();   //p와 show()를 이용하여 screen 색 출력
   Color colors[3];  //Color의 일차원 배열 colors 선언. 원소는 3개
   p=colors;         //p가 colors 배열을 가리키도록 코드 작성

   p[0].setColor(255, 0, 0);
   p[1].setColor(0, 255, 0);
   p[2].setColor(0, 0, 255);

   for(int i=0;i<3;i++){
      p[i].showColor();
      // (*(p+1))->showColor; 로도 가능
      // (p+1)->showColor; 도 가능
   }

   return 0;
}

//1023 실습

//객체의 동적 생성 및 반환
//데이터타입 *포인터변수 = new 데이터타입 ;
//delete[] 포인터변수;
class allocTEST{
public:
   int* data;
   int size;
   allocTEST(){
      data=NULL;
   }
   allocTEST(int size_in){
      data= new int[size_in];
      size=size_in;
   }
   ~allocTEST(){
      delete[] data; //이러면 자동으로 해제해주면서 끝남
   }
};
int Ex1023_1(){
   allocTEST E(100);
   for(int i=0; i<E.size;i++)
      E.data[i];
   int A[3]={100, 200, 300};
   int* B=(int*)malloc(3*sizeof(int)); //3칸 짜리 논을 만듦
   B[0]=100; B[1]=200; B[2]=300;
   free(B);    //할당된 메모리 제거

   //교수님 sol
   float* C=new float[3];  //3칸짜리 float논 만듦
   C[0]=100; C[1]=200; C[2]=300;
   delete[] C;  //할당된 메모리 제거

   int n=100;
   int* p;
   p=&n;

   //int D[n] //배열의 인덱스는 무조건 실수 값이여야한다.
   int* D=new int[n];  //이렇게는 쓸수있어
   delete[] D;

   return 0;
}
class Member{
public:
   string name;
   Member(){name=" ";}
   Member(string name_in){name=name_in;}
   string getName(){ return name;}//이름 출력
   void setName(string name_in){name=name_in;}
};
class Family{
   string family_name;
   Member* p;  //클래스Member의 포인터를 가진다. p[3];
   int size;   //Member 배열의 크기. 가족구성원 수
public:
   Family(){}
   Family(string family_name_in, int size_in){
      size=size_in;
      family_name=family_name_in;
      p=new Member[size_in];     //포인터변수=new 변수형(클래스명)[변수]
      if(p==NULL)
         cout<<"메모리 할당 실패"<<endl;
   }
   string getName(){ return family_name;}
   void setName(int index, string name_in){
       p[index].setName(name_in);
   }
   void show(){
      for(int i=0;i<size;i++)
         cout<<p[i].getName()<<endl;
   }
   ~Family(){
      delete[] p;
   }
};
int Ex1023_2(){
   Family simpson; //기존 3명으로 구성된 가족
   simpson.setName(0, "Mr. simpson");
   simpson.setName(1, "Mrs. simpson");
   simpson.setName(2, "Bart simpson");
   simpson.show();

   Family *LEE=new Family("LEE", 4); // (*LEE).setName(0, "Mr.LEE");
   LEE->setName(0, "Mr. LEE");
   LEE->setName(1, "Mrs. LEE");
   LEE->setName(2, "LEE's son");
   LEE->setName(3, "LEE's daughter");
   LEE->show();

   return 0;
}

//***********************************************************
//기말고사 범위

//1030 실습

//복사 생성자
//값에 의한 호출시 매개 변수 객체의 생성자가 실행되지 않는 이유?
//호출되는 순간의 실인자 객체 상태를 매개 변수 객체에 그대로 전달하기 위함

//따라서 주소에 의한 호출로 해줘야 돼

//여긴 객체 전달 및 참조 코드
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
   //클래스 변수로 옮겨 담아ㅏ
    _Circle_ tmp;  //A와 B를 값에 의한 호출을 하면 다른 객체가 만들어지므로 값이 바뀌지 않음
    tmp = A;       //참조(&)에 의한 호출을 해야됨 (_Circle_& A, _Circle_& B)
    A = B;
    B = tmp;
}
void SwapCircle(_Circle_* A, _Circle_* B) {
    _Circle_ tmp;   
    tmp = *A;  //여기서는 주소이니까 포인터를 붙여줘야돼
    *A = *B;
    *B = tmp;
}
void SwapCircle(_Circle_& A, _Circle_* B) {
    _Circle_ tmp;   //섞어서도 쓸 수 있다.
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
    obj.setRadius(R);  //참조일 때랑 주소일 때 차이 확인
}
void readRadius(_Circle_* obj) {  //포인터로 해볼게요
    cout << "[2] 정수 값으로 반지름을 입력하시오>>" << endl;
    int R;
    cin >> R;
    //(* obj).setRadius(R);  //변수니까 *을 만들어줘
    obj->setRadius(R);       //obj가 객체 포인터니까 이렇게 쓸 수 있어.
}
int Ex1030_1()
{
    _Circle_ donut;         //클래스 객체 하나로 두번 출력
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
    Accumulator& add(int n);// value에 n을 더해 값을 누적한다.
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
int Ex1030_2() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7);      // acc의 value 멤버가 28이 된다.
    cout << acc.getValue() << endl; // 28 출력

    return 0;
}
class _Accumulator_ {
    int value;     //private니까 외부에서 호출 안됨,
public:
    _Accumulator_(int value); // 매개변수 value로 멤버 value를 초기화한다.
    _Accumulator_ add(int n);// value에 n을 더해 값을 누적한다.
    int get(); // 누적된 값 value를 리턴한다.
};
_Accumulator_::_Accumulator_(int value) {this->value = value;}
int _Accumulator_::get() { return value; }
_Accumulator_ _Accumulator_::add(int n){
   value+=n;
   return *this;
}
int Ex1030_2_1() {         //Accumulator& add(int n) -> Accumulator add(int n) 일 때
    _Accumulator_ acc(10);
    acc.add(5).add(6).add(7);  // acc의 value 멤버가 28이 된다.
    cout << acc.get() << endl; // 28 출력
    return 0;
}
//****PDF [참고]에 출력값은 28이 아니라 15이다.
//그 이유는?
//Q1

//여긴 복사생성자 
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
    _Student_(){ strcpy(name, ""); }    //strcpy는 첫번째 인덱스로 그릇, 두번째 인덱스에 source를 넣는다
    _Student_(char* name) {
        strcpy(this->name, name);    
    }
    ~_Student_(){}
    void showName() { cout << "이름이 " << name << endl; }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};
int Ex1030_4() {
//Q2
    _Student_ A((char*)"KANG"), B((char*)"KIM");   //(char*)를 통해 변수형을 지정
    B.showName();
    B = A;   //얕은 복사-동적 할당이 없으니까 괜찮아
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
    ~Student() {
        delete[] name;
    }
    void showName() {
        cout << "이름이 " << name << endl;
    }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};
int Ex1030_5(){          //Ex1030_4랑 비교해보기

    Student A((char*)"KANG"), B;
    B = A;           //얕은 복사를 하면
    B.showName();
    B.setName((char*)"PARK");
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
int Ex1127_04() {

    Adder_1127 adder;
    Subtractor_1127 subtractor;
    adder.run();
    subtractor.run();

    return 0;
}

// 1204 실습

// 템플릿
// p10까지 잘 알아두기.
// template 선언해도 클래스나 함수 앞에 다시 써줘야 돼

//stack과 queue의 차이점  stack은 제일 최근에 쌓은거부터 나온다.
//queue는 fifo

template <class T> 
class Stack {
protected:
    int m_size;   //stack의 용량
    int m_top;    //stack에 들어있는 데이터의 개수
    T *m_buffer;  //stack 메모리
public:
    Stack(int size){
        this->m_buffer=new T[size];
        this->m_size=size;
        this->m_top=0;
    }
    ~Stack(){
        delete[] this->m_buffer;
        this->m_size=0;
        this->m_top=0;
    }
    void Push(T value);
    T Pop();
};
template <class T>
void Stack<T>::Push(T value) {   // <>사이에 타입이 들어간다.
    m_buffer[m_top]=value;
    m_top++;
}
template <class T> 
T Stack<T> ::Pop() {
    m_top--;
    return m_buffer[m_top];  //리턴값은 m_top-1이니까 미리 윗줄에서 -1을 해줌
}
int Ex1204_0(){
    Stack<int> iStack(10);   //int 타입을 다루는 스택 객체 생성
    Stack<double> dStack(10); //double 타입을 다루는 스택 객체 생성
    
    for(int i=0;i<10;i++)
        iStack.Push(i);
    for(int i=0;i<10;i++)
        int n = iStack.Pop();

    dStack.Push(3.5); 
    double d = dStack.Pop();

    return 0;
}

//C=A-B;
// 벤다이어그램을 생각하면서 이해하면 좋을 듯
template <class T>
bool CheckItem(T item, T* minus, int sizeMinus){
    for(int i=0;i<sizeMinus;i++){
        if(minus[i]==item)//같은 원소가 있음
            return true;
    }
    return false; //같은 원소가 없음
}
template <class T>
T* remove(T* src, int sizeSrc, T minus[], int sizeMinus, int& retSize)
{   //주소를 리턴해줘
    T* C=new T[sizeSrc];  //배열의 사이즈엔 숫자가 들어가야돼 따라서 동적할당 해버리자.
    int count=0;

    for(int i=0;i<sizeSrc;i++){
        if(false==CheckItem(src[i],minus, sizeMinus)){
            C[count]=src[i];
            count++;
        }
    }
    retSize=count;   //c배열의 원소의 개수를 알려줘
    return C;
};
int Ex1204_1() {
    // remove() 함수를 int로 구체화하는 경우

    cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2}을 뺍니다" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2};
    int retSize;
    
    int* p = remove<int>(x, 4, y, 5, retSize);  //remove함수가 주소를 반환하므로 p의 변수형도 주소로한다.
    
    if(retSize == 0) {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c 배열의 모든 원소 출력
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // 할당받은 배열 반환
    }
// remove() 함수를 double로 구체화하는 경우
// 이곳에 작성
}
int main() {
    // remove() 함수를 int로 구체화하는 경우

    cout << "실수 배열 {1,2,3,4}에서 실수 배열 {-3,5,10,1,2}을 뺍니다" << endl;
    double x[]={1.0,2.0,3.0,4.0};
    double y[]={-3.0,5.0,10.0,1.0,2.0};
    int retSize;
    
    double* p = remove<double>(x, 4, y, 5, retSize);  //remove함수가 주소를 반환하므로 p의 변수형도 주소로한다.
    
    if(retSize == 0) {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c 배열의 모든 원소 출력
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // 할당받은 배열 반환
    }
    return 0;
}
//실습 12-2는 안해도 될듯?