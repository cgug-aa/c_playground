#include<iostream>    //c에서 stdio.h 가 iostream으로 바뀜
using namespace std;  //std를 사용하지 않겠다

int sum(int a, int b) //함수를 선언해줌 메인으로 들어가기 전에 (메인 함수보다
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

double biggest(double *a,int n)
{
   double max = 0;
   for (int i = 0; i < 5; i++)
      if (max < a[i])
         max = a[i];
   return(max);
}
void Ex0904_prac1_03()
{
   double a[5];
   cout << "5개의 실수를 입력하라>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "제일 큰 수 = " << biggest(a,5) << endl;
}

int main()
{
   Ex0904_prac1_01();
   Ex0904_prac1_02();
   Ex0904_prac1_03();
   return 0;
}