#include<iostream>    //c���� stdio.h �� iostream���� �ٲ�
using namespace std;  //std�� ������� �ʰڴ�

int sum(int a, int b) //�Լ��� �������� �������� ���� ���� ���� �Լ�����
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

double biggest(double a[],int n)  //�迭�� ���� ȣ���Ѵ�. �迭�ȿ� �ε����� �Ƚᵵ �ȴ�. �迭�� ���ȣ�� �� ���ٸ�, �����͸� ����ߵ�.
{
   double max = 0;               //max��� ���� �����ϰ�, �� ���� �迭�� ���� ���Ѵ�.
   for (int i = 0; i < 5; i++)
      if (max < a[i])
         max = a[i];
   return(max);
}
/* ������ sol

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
   cout<<"5���� �Ǽ��� �Է��϶�>>";

}

*/

void Ex0904_prac1_03()
{
   double a[5];
   cout << "5���� �Ǽ��� �Է��϶�>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "���� ū �� = " << biggest(a,5) << endl;
}

int Ex0908_prac1_04()
{
   char c[100];
   int count=0;
   cout<<"���ڵ��� �Է��϶�(100�� �̸�)."<<endl;

   cin.getline(c, 100);    //���ڿ��� �Է� �޴µ� ���⸦ �����ؼ� �Էµȴ�. ���ڿ� ������ ����ġ��
   //cout << c <<endl;
   
   for(int i=0; i<100;i++)
   {
      // if(c[i]=='\n') break;   // \0�� �ٹٲ�
      if(c[i]=='x') count++;

   }
   cout <<'x'<< "�� ������" <<count<<endl;  //ū ����ǥ�� ���ڳ� ���ڿ�, ���� ����ǥ�� ������ �ҷ��´�.

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

   cout<<"�̸���?"; 
   cin.getline(name,100);
   cout<<"���̴�?";
   cin>>age;
   cin.ignore(100, '\n');        //����! ���� �˱�

/*cin.ignore(�ִ�Ȯ�α��ڼ�, �����ڡ� ) : �Է� ���� �����
�ִ� ����ŭ ���ۿ� �ִ� ���ڸ� �����, Ȥ�� �����ڡ��� ��Ÿ���� �����ڡ����� ����� ����
_______________________________________________________
cin >> val;
if (cin.fail() == 1) { // I/O ������ �߻��ϸ�
cin.clear(); // ��� ������Ʈ clear
cin.ignore(256, ��\n��); // �ִ� 256���� ���� ���ð���, ���๮�ڸ� ������ ������ ����
}
________________________________________________________
*/

   cout<<"�ּҴ�?";
   cin.getline(address, 100);
   
   cout<<"--------------------------------------"<<endl;
   cout<<name<<". "<<address<<". "<<age<<"��"<<endl;

   return 0;
}

int main()                       //�����Լ��� ���Ǵ� �Լ��� ��⸸ ����
{
   //Ex0904_prac1_01();
   //Ex0904_prac1_02();
   //Ex0904_prac1_03();
   //Ex0908_prac1_04();
   //Ex0908_prac1_05();
   Ex0908_prac1_06();
   return 0;
}