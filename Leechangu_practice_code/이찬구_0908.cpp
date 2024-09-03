#include<iostream>    //c에서 stdio.h 가 iostream으로 바뀜
using namespace std;  //std를 사용하지 않겠다

int sum(int a, int b) //함수를 선언해줌 메인으로 들어가기 전에 메인 함수보다
{                     //앞에 함수를 작성하면 굳이 선언 안 해도 됨
   int k;
   int res = 0;
   for (k = a; k <= b; k++)
      res += k;

   return (res);
}
int Ex0904_prac1_01()
{
   int n = 0;
   cout << "끝수를 입력하세요>>"<<endl;
   cin >>n ;
      if (n <= 0)
      {
         cout << "양수를 입력하세요!\n";
         return 0;
      }
      cout << "1에서 " << n << "까지의 합은 " << sum(1, n) <<"입니다\n" << endl;
      return 0;
}
void Ex0904_prac1_02()
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

double biggest(double a[],int n)  //배열의 값을 호출한다. 배열안에 인덱스를 안써도 된다. 배열의 대괄호를 안 쓴다면, 포인터를 써줘야됨.
{
   double max = 0;               //max라는 값을 선언하고, 그 값을 배열의 값과 비교한다.
   for (int i = 0; i < 5; i++)
      if (max < a[i])
         max = a[i];
   return(max);
}
/* 교수님 sol

double FindMaxvalue(double a, double b)
{
   double maxvalue;

   if(a>b)maxvalue=a;
   else maxvalue=b;

   return(maxvalue);
}
void biggest()
{
   double a[5]={1.0,2.0,3.0,-1.0,-100.0}
   double maxvalue =a[0];
   for(int i=1; i<5;i++)
      maxvalue-FindMaxvalue(maxvalue, a[i]);
   return (maxvalue);
}
int EX0904_prac1_3()
{
   double a[5];
   cout<<"5개의 실수를 입력하라>>";

}

*/

void Ex0904_prac1_03()
{
   double a[5];
   cout << "5개의 실수를 입력하라>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "제일 큰 수 = " << biggest(a,5) << endl;
}

int Ex0908_prac1_04()
{
   char c[100];
   int count=0;
   cout<<"문자들을 입력하라(100개 미만)."<<endl;

   cin.getline(c, 100);    //문자열을 입력 받는데 띄어쓰기를 포함해서 입력된다. 문자열 끝나면 엔터치기
   //cout << c <<endl;
   
   for(int i=0; i<100;i++)
   {
      // if(c[i]=='\n') break;   // \0은 줄바꿈
      if(c[i]=='x') count++;

   }
   cout <<'x'<< "의 개수는" <<count<<endl;  //큰 따옴표는 문자나 문자열, 작은 따옴표는 변수를 불러온다.

   return 0;
}
int Ex0908_prac1_05()
{
   return 0;
}

int Ex0908_prac1_06()
{
   char name[100];
   char address[100];
   int age=0;

   cout<<"이름은?"; 
   cin.getline(name,100);
   cout<<"나이는?";
   cin>>age;
   cin.ignore(100, '\n');        //주의! 개념 알기

/*cin.ignore(최대확인글자수, ‘문자’ ) : 입력 버퍼 지우기
최대 수만큼 버퍼에 있는 문자를 지우고, 혹시 ‘문자’가 나타나면 ‘문자’까지 지우고 스톱
_______________________________________________________
cin >> val;
if (cin.fail() == 1) { // I/O 오류가 발생하면
cin.clear(); // 모든 오류비트 clear
cin.ignore(256, ‘\n’); // 최대 256개의 문자 무시가능, 개행문자를 만나면 추출을 멈춤
}
________________________________________________________
*/

   cout<<"주소는?";
   cin.getline(address, 100);
   
   cout<<"--------------------------------------"<<endl;
   cout<<name<<". "<<address<<". "<<age<<"세"<<endl;

   return 0;
}

int main()                       //메인함수는 사용되는 함수의 모듈만 포함
{
   //Ex0904_prac1_01();
   //Ex0904_prac1_02();
   //Ex0904_prac1_03();
   //Ex0908_prac1_04();
   //Ex0908_prac1_05();
   Ex0908_prac1_06();
   return 0;
}