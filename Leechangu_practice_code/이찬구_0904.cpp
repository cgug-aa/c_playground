#include<iostream>    //c���� stdio.h �� iostream���� �ٲ�
using namespace std;  //std�� ������� �ʰڴ�

int sum(int a, int b) //�Լ��� �������� �������� ���� ���� (���� �Լ�����
{                     //�տ� �Լ��� �ۼ��ϸ� ���� ���� �� �ص� ��
   int k;
   int res = 0;
   for (k = a; k <= b; k++)
      res += k;

   return (res);
}
int Ex0904_prac1_01()
{
   int n = 0;
   cout << "������ �Է��ϼ���>>"<<endl;
   cin >>n ;
      if (n <= 0)
      {
         cout << "����� �Է��ϼ���!\n";
         return 0;
      }
      cout << "1���� " << n << "������ ���� " << sum(1, n) <<"�Դϴ�\n" << endl;
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
   cout << "5���� �Ǽ��� �Է��϶�>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "���� ū �� = " << biggest(a,5) << endl;
}

int main()
{
   Ex0904_prac1_01();
   Ex0904_prac1_02();
   Ex0904_prac1_03();
   return 0;
}