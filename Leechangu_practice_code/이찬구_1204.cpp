#include<iostream>
#include<string.h>
#include<string>      //���ڿ� ��(strcmp), ����(strcpy), ���� ����
#include<vector>      //vector����
//#include "cal.h"      //������� ����
using namespace std;


//0901 �ǽ�

//<iostream> ��������� ������ ���� �ҽ��� Ȯ���ϵ��� ����
//<iostream> ��� ����: ������� ���� Ŭ������ ��ü, ���� ���� �����
//using namespace std; �� ���� std���� �� ��� ��

void Ex0901_1()
{
    std::cout << "My name is changu.\n\n"; //C++���� ��°�ü�� cout �̿�
    //cout<< �� �������� ���
    //<<������ ������ �⺻���� ������ �����ϸ� �ڵ����� ������ ���� ���߾� ���
}
void Ex0901_2()
{
    std::cout << "������Ű��к�\n23��\n��� �����Ͼ�\n\n";
}
void Ex0901_3()
{
	int sum = 0;
	for (int n = 0; n < 11; n++)
		sum += n;
	std::cout << "1���� 10���� ���� �����" << sum << "�Դϴ�.\n\n";
	
    //����, ���ڿ� ���

	//char c='#';
	//std::cout<<c<<5.5<<'-'<<"Hi";
	//����(c), ����(5.5), ����(-), ���ڿ�(Hi) ���
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

//0904 �ǽ�

//�Լ��� �������� �������� ���� ���� ���� �Լ�����
//�տ� �Լ��� �ۼ��ϸ� ���� ���� �� �ص� ��
int sum(int a, int b) //ó�� ���� a, �� ���� b
{                    
   int k;
   int res = 0;   //���
   for (k = a; k <= b; k++)
      res += k;

   return (res);
}
int Ex0904_1()    //1���� �Է°����� ���� ��Ÿ���� �Լ�
{
   int n = 0;
   cout << "������ �Է��ϼ���>>"<<endl;
   cin >>n ;
    if (n <= 0){
        cout << "����� �Է��ϼ���!\n";
        return 0;
        }
    cout << "1���� " << n << "������ ���� " << sum(1, n) <<"�Դϴ�\n" << endl;
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
   cout << "5���� �Ǽ��� �Է��϶�>>";

   for (int i = 0; i < 5; i++)
      cin >> a[i];
   cout << "���� ū �� = " << biggest(a,5) << endl;  //�迭�� �ε����� �迭�̸�����
}
int Ex0904_main()
{
   Ex0904_1();
   Ex0904_2();
   Ex0904_3();
   return 0;
}

//0908 �ǽ�

//cin.ignore(�ִ�Ȯ�α��ڼ�, �����ڡ� ) : �Է� ���� �����
//�ִ� ����ŭ ���ۿ� �ִ� ���ڸ� �����, Ȥ�� �����ڡ��� ��Ÿ���� �����ڡ����� ����� ����
//cin >> val;
//if (cin.fail() == 1) {      // ����� ������ �߻��ϸ�
//cin.clear();                // ��� ������Ʈ clear
//cin.ignore(256, ��\n��);      // �ִ� 256���� ���� ���ð���, ���๮�ڸ� ������ ������ ����
//}
int Ex0908_1()
{
    char c[100];
    int count=0;
    cout<<"���ڵ��� �Է��϶�(100�� �̸�)."<<endl;

    cin.getline(c, 100);//���ڿ��� �Է� �޴µ� ���⸦ �����ؼ� �Էµȴ�.
    //cout<<c<<endl;      ���ڿ� ������ ����ġ��
    for(int i=0; i<100;i++)
   {
      if(c[i]=='\n') break;   // \0�� �ٹٲ�
      if(c[i]=='x') count++;
   }
    cout <<'x'<< "�� ������" <<count<<endl; //ū ����ǥ�� ���ڳ� ���ڿ�,
    return 0;                              //���� ����ǥ�� ������ �ҷ��´�.
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
   cout<<"�̸���?";
   cin.getline(name, 100);  //getline�� ����� ���Ⱑ ���Ե�. name�� 100����
   cout<<"���̴�?";
   cin>>age;
   cin.ignore(100, '\n');   //�ռ� �Է�(cin)���� ������ ���� ������ 
                            //������ ������� ���� �Է°��� �� ���´�
   cout<<"�ּҴ�?";
   cin.getline(address, 100);
   cout<<"--------------------------------------"<<endl;
   cout<<name<<". "<<address<<". "<<age<<"��"<<endl;
   return 0;
}

//������
int Ex0908_4()
{
    char a[5]={'a', 'b', 'c', 'd', 'e'};
//&a[1], &a[2] ������ �迭�� �ּҸ� �� �� �ִ�.
//a[2]�� *(a+2)�� ���� ������ �����ϴ�.
//a+2�� �ּ� *(a+2)�� ��
    char * p;
    p=a;  //a�� �迭�̴ϱ� �ּҰ� ��
    printf("vla =0x%x %c %c 0x%x \n", a+1, *(a+1), a[1], &a[1]);//�ּ�, ��, ��, �ּ�
    char *p1;
    p1=&a[3];
    printf("%c", *p1);
//p1�� ����ִ� �ڸ��� ���� ���´�.
//printf("%c", *(p1+1))�� �ϸ� a[4]�� ���� ���´�.
//a[3]�� *(a+3)�� ���� ������ p1[-1]�� a[2]�� ���� ���´�.
    return 0;
}

//0911 �ǽ�

//������ [*b�� &a�� ������ �� �־�� ��]
//�����ʹ� ������ �ּҸ� ��Ÿ��

//int a;    ����
//cout<<a;  �� ��
//cout<<&a; �� �ּ�
//�ּҸ� �����ؼ� ����ϰ� ���� �� b=&a �� �Ǽ���������
//b�� �ּҸ� �����ϴ� �����̹Ƿ�, *�� �ٿ��� int *b;
//(������ ���� int�� ū ���þ��� ���ο� ������ �����ϸ� ��)�� �����Ѵ�.
//*b; �� b�� ��(����)�� ����.
//������ ������ *�� ���̸� ������ ��.

//float M[10];  �迭����
//cout<<M;      �� �ּ�
//cout<<&M[0];  �� ����
//cout<<*M;     �� ����
//cout<<M+1;    �� �ּ�
//cout<<*(M+1)  �� ����
//cout<<M[1];   �� ����
int Ex0911_0()
{
   int n=10, m;
   char c = 'A';
   double d;
   int *p;
   p=&n;
   cout<<n<<endl; //10�� ���
   *p=25;         //p�� ���� n�� �ּҷ� ����
//*p�� ���� �ٲ���(�����͸� ���� ���� �ٲ�)
   cout<<n<<endl; //25�� ��µȴ�.
   return 0;
}
void func(int* pointer)    //�ּҸ� �޾ƾ� �ϴϱ� �����͸� ���ش�.
{
   cout<<pointer<<endl;    //�ּҸ� �޾�
   cout<<*pointer<<endl;   //���� �޾�
}
int Ex0911_1()
{
   int arr[6]={1,2, 3, 4, 5, 6};
   int* chr_ptr=arr;
//������ ������ �����ϰ�, �ּ�(�迭)�� �־��ش�.
   chr_ptr++;           //������ �ּ� �ϳ� �߰� arr[1]
   cout<<chr_ptr<<endl; //arr[1]�� �ּ�
   cout<<*chr_ptr<<endl;//arr[1]�� ��
   cout<<arr<<endl;     //arr[0]�� �ּ�
   cout<<arr+4<<endl;   //arr[5]�� �ּ�
   cout<<&arr[3]<<endl; //arr[3]�� �ּ�
   cout<<arr[4]<<endl;  //arr[4]�� ��
   cout<<*(chr_ptr+2)<<endl; //arr[3]�� ��
   func(arr);
   return 0;
}
int Ex0911_2()  //���������� ������ ��
{
   int a=10, b=20, c=30, d=40, e=50;
   int* a_ptr =&a;    //�׳� �����ϱ� �ּҸ� ���� �� &�� �ٿ��� �־���
   int* b_ptr =&b; 
   int* c_ptr =&c;
   int* d_ptr =&d;
   int* e_ptr =&e;

   int* ptr[5];       //������ ������ 5�� ����
   ptr[0]=&a;
   ptr[1]=&b;
   ptr[2]=&c;
   ptr[3]=&d;
   ptr[4]=&e;
   for(int i=0;i<5;i++)
      cout<<*ptr[i]<<endl;
   //ptr�� �ϸ� �ּҰ� ���   *ptr���� �ϸ� ���� ���
   //cout << *a_ptr<<endl;
   return 0;
}
int En0911_3()   //���������� �迭�� ��
{
   int arr_0_[3]={1,2,3};
   int arr_1_[4]={11, 12, 13, 14};
   int arr_2_[5]={21, 22, 23, 24, 25};
   int* ptr[3];
   ptr[0]=arr_0_;      //ptr[0] ��ü�� ������ 
   ptr[1]=arr_1_;
   ptr[2]=arr_2_;
//int* ptr[3]={arr_0_,arr_1_,arr_2_};
   cout<<*ptr[0]<<endl;  //*�߿�*  *ptr[0]�� ��� 1 
   cout<<*(ptr[0]+1)<<ptr[0][1]<<endl;  //*(ptr[0]+1)�� ptr[0][1]�̹Ƿ� �� �� 2�� ���
//int** ptr2 =ptr;  //����) ptr�� �ּҸ� ���ϰ� ������ �����͸� �ѹ� �� ���ָ� ��
   return 0;
}

//0915 �ǽ�

//������ ����

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
   cout<<&a<<endl;  //a�� �ּ�
   cout<<p<<endl;   //a�� �ּ�
   cout<<*p<<endl;  //100
   //Func(a);         //���� �ٲ�������
   Funcptr(&a);       //a�� ���� �ٲ�
   cout<<&a<<endl;
   cout<<a<<endl;
   return 0;
}
void FuncArray(int* ptr)   //�迭�� �ޱ� ���� �ּҸ� �Ѱ��ش�.
{
   cout<<"Func"<<ptr<<endl;   //�ּ�
   cout<<"Func"<<*ptr<<endl;  //ptr[0]��
   cout<<"Func"<<ptr[0]<<endl;//ptr[0]��
   for(int i=0;i<5;i++)
      cout<<ptr[i]<<endl;  //ptr ���� ��� ��
}
int Ex0915_2()
{
   int c[5]={10, 20, 30, 40 ,50};
   cout<<c<<endl;      //�迭�� �̸��� �ּҸ� ��ȯ
   cout<<*c<<endl;     //c[0]
   cout<<c+1<<endl;    //����)�迭�� �̸��̹Ƿ� �ּҸ� ��ȯ�Ѵ�.
   cout<<*(c+1)<<endl; //�����͸� ����Ͽ� ���� ��ȯ. 20
   FuncArray(c);
   int* p;
   p=c;
   cout<<p<<endl;
   cout<<*p<<endl;
   cout<<p+1<<endl;
   cout<<*(p+1)<<endl;
   return 0;
}
//c�� �ٸ��� ���۷��� ����
//���۷��� ���� >>> �迭 �ּҿ� ���� �������
//�̹������ϴ� ������ ���� �ٸ� �̸� ���� >>>����
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
	int& nickname = target;   //����) int& nickname�� �ʱ�ȭ�� ������ ����� �Ѵ�.
	nickname = -10;           //���۷��� nickname �����ϰ�, targetó�� ���ڴ�.

	cout << target << endl;
	FuncRef(target);
	cout << target << endl;   //���� �ٲ�� �ȴ�. �迭�� �ƴ϶� ���� ��ü�� ���̱� ������
	return 0;
}
void swap(int& a, int& b)    //���۷��� ������ �־��ָ� ���� �ٲ��.
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void adder(int a, int b, int& c)  //&�� ������� ������ �� �Լ��� a,b,c�� ���� �Լ��� a,b,c�� �ٸ� ������ �ȴ�.
{
	c = a + b;
}
void adder(int a, int b, int* c)  //���۷��� ���� �����ͷ� ���� ȣ���Ҷ��?
{
	*c = a + b;    //������ ���� �ٲ�����ϴϱ� *�� ����
}
void addsub(int a, int b, int& sum, int& diff)   //a�� b�� �Լ����� �ҷ����µ��� ���ǹǷ� &�� �� �ٿ��� ��
{                   //sum�̶� diff�� ���� �Լ��� ��������ϹǷ� &�� *�� ����Ѵ�.
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
bool average(int *a, int size, int& avg)  //int a[]��� �ᵵ ��
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
	if (average(x,6,avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ����" << endl;

	if (average(x, -1, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;

	return 0;
}

//0918 �ǽ�

//

bool bigger(int a, int b, int& big)
{//big�� �����Լ��� �ٽ� ������� �ϴϱ� ���۷����� ����ߴ�.
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
int Ex0918_1()         //������ ũ�⸦ ���ϴ� �ǽ�
{
	int x, y, big;
	bool b;
	cout << "�� ������ �Է��ϼ���>>";
	cin >> x >> y;
	b = bigger(x, y, big);
	//cout << b << endl;
	if (b)
		cout << "same" << endl;
	else
		cout << "ū ����" << big << endl;
	return 0;
}
char& find(char a[], char c, bool& success)  //���� �� ���ڸ� ã���ְ�
{
	success = false;              //���ʿ� false�� �ʱⰪ�� �ְ�
	for (int i = 0;; i++)         //;;���� ���߰��� �������� �θ� ��� �ݺ�
	{
		if (a[i]=='\0')
			return a[i];            //ã�� ���ڰ� ������ �ٹٲ��� ���
		else if (a[i] == c)        //ã�� ���� ã���� �� ������ ������
		{
			success = true;
			return a[i];
		}
	}
}
int Ex0918_2()        //����� �빮�ڸ� �ҹ��ڷ� �ٲٴ� ����
{
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);    //a[i]�� ������ �޾����ϱ� ���� �������� ����
   // & ���� �־��� ��
	if (b == false){
		cout << "M�� �߰��� �� ����." << endl;
		return 0;
	}
	loc = 'm';          // a[i]�� ���� 'M' ��ġ�� 'm' ���
	cout << s << endl;  // "mike"�� ��µ�
}
int Sum(int a=-20, int b=-10, int c=10)   //int c=10�̶� �ص� ������ 60�� �ȴ�.
{//������ �����Լ����� c���� ���������� ������,
//c���� ����Ʈ�� 10�� �ȴ�.
	return (a + b + c);//����Ʈ ���� ������ �� ���������� �����ؾ��Ѵ�.
}
int Ex0918_3()
{
	int a = 10, b = 20, c = 30;
	int d, e, f, g;

	d=Sum(a, b,c);
	e = Sum(a, b);
	f = Sum(a);
	g = Sum();    //�Ű������� ������ �Լ��� �ִ� ����Ʈ ������ ��
	cout << d << '\n' << e << '\n' << f << '\n' << g;
	return 0;
}
int diff(int a, int b){
	return (a - b);
}
double diff(double a, double b)  
//�ε����� ��� Ÿ���� �ٸ��� �Լ� �̸��� ���Ƶ� �ٸ� �Լ��� ���
//c������ �ȵȴ�.
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
//'unsigned int'�� UINT�����ؼ� ����;
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

//0922 �ǽ�

//Ŭ������ ��ü
//c���� ����üó�� class�� ���� '�������'�� '����Լ�'�� �ִ´�
//string ��ü�� ���� Ÿ��
//string name; �� ���ڿ� ���� ��Ʈ�� ��ü
//string address("����� ���ϱ� �Ｑ�� 389") ���ڿ� ���ͷ��� �ʱ�ȭ
//string copyAddress(address) address�� ������ copyAddress ����

int Ex0922_1()      //string�� ��� �ǽ�
{
   char cname[]="Lee";
   string sname(cname);   //���ڿ� cname�� �ִ� �� sname���� ���簡 �ȴ�.
   cout<<sname[0]<<endl;  //�迭ó�� ������ ���� �ִ�.
   //string name ="Lee chan gu";
   string name("Lee chan gu");
   string address("chengju CBNU");
   string str=name+address;  //���ڿ� �ΰ��� ����
   cout<<str<<endl;
   
   string str_copy=str;
   cout<<str_copy<<endl;
   cout<<str.size()<<endl;  //.size()�� ���ڿ��� ���̸� �˷��ش�.

   int pos=str.find("gu");  //.find()�� ��ǥ ������ �ε��� ��ġ�� �˷��ش�
   cout<<pos<<endl;
   return 0;
}
//���� �ǽ�
int Ex0922_2()
{
   vector<int> A; //vector�� �迭�� <>�ȿ� �� ������ �ִ´�.
   cout<<A.size()<<endl;
   A.push_back(10);   //���Ϳ� ���� Ǫ���ؼ� �ִ´�.
   A.push_back(20);
   A.push_back(30);
   A.push_back(40);

   for(int i=0;i<A.size();i++)
   cout<<A[i]<<endl;
   A.clear();       //�� ���� ���͸� �ʱ�ȭ�� �� �ִ�.
   return 0;
}
//Ŭ����
//���� ������ private, protected, public
class Circle_0922{
public:              //public�� ������� ������ private�� ����Ʈ�̹Ƿ� 
   int radius;       //�ܺο��� ����� �� ����.
   double getArea(); //����, �Լ� ����
};
//Ŭ���� �Ҽ��� ��Ÿ���� ���� ::�� ���ش�.
double Circle_0922::getArea(){
   return (3.14*radius*radius);
}
//Ŭ������ �������� ����ٴ� ����
int Ex0922_3()
{
   Circle_0922 donut;     //Ŭ���� ��ü(������) �̸�
   donut.radius = 1;      //donut ��ü�� �������� 1�� ����
   double area = donut.getArea(); // donut ��ü�� ���� �˾Ƴ���
   cout << "donut ������ " << area << endl;

   Circle_0922 pizza;
   pizza.radius = 30;      // pizza ��ü�� �������� 30���� ����
   area = pizza.getArea(); // pizza ��ü�� ���� �˾Ƴ���
   cout << "pizza ������ " << area << endl;

   Circle_0922 *ptr;
   ptr = &pizza;                //�����Ͱ� Ŭ���� pizza�� ����Ŵ
   cout<<ptr->radius<<endl;     //�������� ������ ���� ���� ->�� ����Ѵ�
                                //ptr->radius�� (*ptr).radius�� �� ���� �ִ�.
   cout<<ptr->getArea()<<endl;  //(*ptr).getArea()�� �ٲ� �� �ִ�.
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
int Ex0922_4()  //�ǽ� 4-3
{
   Rectangle_0922 rect;
   rect.width = 3;              //Ŭ���� ���� ������ ���� �־���
   rect.height = 5;
   cout << "�簢���� ������ " << rect.getArea() << endl;
   return 0;
}

//0925 �ǽ�

//������:-��ü�� �����Ǵ� �������� �ڵ����� ȣ��Ǵ� ��� �Լ�
//       -��ü�� ������ �� ��ü�� �ʿ��� �ʱ�ȭ�� ����
//�Ҹ���:-��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� ��� �Լ�
//       -��ü�� �Ҹ�� �� ��ü�� ������ ����
//       -�����Լ��� ������ �Ҹ��.
class CirCle_0925{
public:
   int radius;
   //int* MEM;
   CirCle_0925();       //������
   CirCle_0925(int r);  //������ 
   ~CirCle_0925();      //�Ҹ���
   double getArea();   //�Լ��� Ŭ������ �����ϰ�
};
CirCle_0925::CirCle_0925(){   //�Լ��� �ۿ� �����ش�.
   //MEM= new int [10000*10000]; //�̷��� �޸𸮸� �÷��ָ� pc�� �޸𸮸� ���� ��Ƹ԰� ��
                                 //���� �Ҹ��ڰ� �ʿ���.
   radius = 1;
   cout<<"������ "<<radius<<"�� �� ����"<<endl;
}
CirCle_0925::CirCle_0925(int r){  //�Ķ���Ͱ� �޶� �ٸ� �Լ��� ����Ѵ�.
   //MEM= new int [10000*10000];
   radius = r;
   cout<<"������ "<<radius<<"�� �� ����"<<endl;
}
double CirCle_0925::getArea(){
   return (3.14*radius*radius);
}
CirCle_0925::~CirCle_0925(){
   //delete[] MEM;
   cout<<"������ "<<radius<<"�� �� �Ҹ�"<<endl;   //�Ҹ��� �� ��µ� ����
}
int Ex0925_1()
{
   //CirCle_0925 A(); �Ķ���Ͱ� �����Ƿ� ����Ʈ ���� 1�� ����������
   CirCle_0925 A(100); 
   CirCle_0925 B(200); //int r�� 200�� �Ķ���ͷ� ������
   return 0;
}  //������ �Ҹ��� ����
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
   ~Rectangle_0925(){      //rect1,2,3�� �� �Ҹ�ǹǷ� 3�� ��µȴ�.
      cout<<"Ŭ���� �Ҹ�"<<endl;
   }
};
int Ex0925_2()
{
   Rectangle_0925 rect1;
   Rectangle_0925 rect2(3,5);
   Rectangle_0925 rect3(3);
   if(rect1.isSquare()) cout << "rect1�� ���簢���̴�." << endl;
   if(rect2.isSquare()) cout << "rect2�� ���簢���̴�." << endl;
   if(rect3.isSquare()) cout << "rect3�� ���簢���̴�." << endl;
   return 0;
}

//1013 �ǽ�

//���� ������
//Ŭ������ ��� ���ϰ� cpp���Ϸ� �и��Ͽ� �ۼ�
//Ŭ���� ����(Ŭ���� �̸�.h)
//Ŭ���� ����(����Լ��� ����)&Ŭ������ ����� ������� include
//main.cpp ����� ������� ����

//��������� �ߺ��ؼ� �����ϸ�, ��������
//1st) ��������� �̸��� ���� �ɺ��� �����. Ŭ�����̸�_H
//2nd) ������� �տ� #ifndef �ɺ�, #define �ɺ�
//3rd) ��������� ���� ���� #endlif�� �߰��Ѵ�.
class Adder_1013{
    int op1,op2;
public:
    Adder_1013(int a, int b); //������
    int process();       //���� �Լ�
};

class Calculator_1013{
public:
   void run();     //���� �Լ�
};
Adder_1013::Adder_1013(int a, int b){
   op1=a;
   op2=b;
}
int Adder_1013::process(){
   return op1+op2;
}

void Calculator_1013::run(){
   cout<<"�� ���� ���� �Է��ϼ���."<<endl;
   int a, b;
   cin>>a>>b;
   Adder_1013 adder(a,b);
   cout<<adder.process()<<endl;
}
void cal(){
   Calculator_1013 calc;  //class ���� ����
   calc.run();       //class ����
   //���ο��� �����ϱ� ���� �Լ�
   //cal �ȿ��� Calculator ���� �ȿ��� adder process�� ����
}
void cal();

int Ex1013()
{
   cal();
   return 0;
}

//1016 �ǽ�

//����������
//private: �ش� Ŭ������ ����Լ������� ���ٱ��� ���
//protected: �Ļ�Ŭ������ ����Լ������� ���ٱ���
//public: Ŭ���� �ۿ����� ���ٱ���
//�����ڸ� �����̺����� �����, ȣ���� ��(�Լ�, ���� ��) �����߻�
//������ �Լ��� get�̳� set���� �����Ѵ�.

class Ram{
   char mem[100*1024];     // 100kb �޸�
   int size;
public:
   Ram();     //mem�� 0���� �ʱ�ȭ �ϰ� size�� 100*1024�� �ʱ�ȭ
   ~Ram();    //"�޸� ���ŵ�" ���ڿ� ���
   char read(int address); //address�ּ��� �޸𸮸� �о� ����
   void write(int address, char value);
   //address �ּҿ� value ����
   //�ּҰ� ������ ����� ���� �߻��ϸ� ���� �޽��� �����,
};
Ram::Ram()
{
   size=100*1024;
   for(int i=0;i<size;i++)
      mem[i]=0;
//memset(mem,0,size); mem�� char�� �ƴ϶� int�� bit������ 4�� �ؾߵ� 
}
Ram::~Ram(){
   cout<<"�޸� ���ŵ�"<<endl;
}
char Ram::read(int address){
   return mem[address];
}
void Ram::write(int address, char value){
   mem[address]=value;
}
int Ex1016_1(){
   Ram ram;
   ram.write(100, 20);//100������ 20����
   cout<<"100������ ��="<<(int)ram.read(100)<<endl;

   ram.write(101, 30);//101������ 30����
   cout<<"101������ ��="<<(int)ram.read(101)<<endl;

   char res=ram.read(100)+ram.read(101);//20+30=50
   ram.write(102, res);//102������ 50����
   cout<<"102������ ��="<<(int)ram.read(102)<<endl;
   //102���� �޸� �� ���
   return 0;
}

//static

//class�� ��� ��ġ�� ���α׷��� ������ ��ü�� ���� ����
//class A�� class B�� ��ġ�� ���� �����Ǵ� ������ ���� �� �ִµ�
//�̸� static���� ������ �� �ִ�.

class Person_1016{
public:
   double money;
   void addMoney(int money_in){
      money+=money_in;
   }
   static int sharedMoney_1;//����
   static void addShared(int n){
      sharedMoney_1+=n;
   }
};
int Person_1016::sharedMoney_1=10;
//�̷��� static������ �����س�����. �۷ι� ����ó��
int Ex1016_2(){
   Person_1016 A, B;  //���� �ٸ� class
   //������ ��ġ�� �ʹ�~ �̰� static���� ��߰ڳ�
   //A.sharedMoney=B.sharedMoney
   A.sharedMoney_1=100;
   B.sharedMoney_1=200;
   //������ sharedMoney�� ���� ������ ����غ���
   //cout<<A.sharedMoney<<endl; //200���� ��µ�
   cout<<Person_1016::sharedMoney_1<<endl;
   //Person::sharedMoney�� ������ �� ���� �� �򰥸�
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
   double money;   //���μ��� ��
   void addMoney(int money_in){
      money+=money_in;
   }
   static int sharedMoney;  //����
   static void addShared(int n){
      sharedMoney+=n;
   }
   string name; //��ü�̸�
   Person_1016_2(){money=0;}
   Person_1016_2(string name_in){
      money=0;
      name=name_in;
   }
   ~Person_1016_2(){
      cout<<name<<"'s mmoney = "<<money<<endl;
   } //������� ��ü�� 2���ϱ� �Ҹ��� �� ���� �ǰ�
     //���� KANG�̶� KIM�� �� ����
};
int Person_1016_2::sharedMoney=0;  //��������ó�� �ʱ�ȭ ����ߵ�
int EX1016_4(){
   Person_1016_2 A("KANG"), B("KIM");
   //3��
   A.addMoney(100);
   A.addShared(5);
   B.addMoney(200);
   B.addShared(5);

   //4��
   A.addMoney(100);
   A.addShared(5);
   B.addMoney(200);
   B.addShared(5);

   cout<<"���� = "<<Person_1016_2::sharedMoney<<endl;
   Person_1016_2::addShared(100);
   cout<<"���� = "<<Person_1016_2::sharedMoney<<endl;
   return 0;
}

//1020 �ǽ�

//�������� ��ü�� �������
//��ü�� �迭ó�� ������ ������ �� �ִ�.
//��ü�̸��� �ε����� ���ٰ� ������ �� �ִ�. ��ü�̸�[i]=�ϳ��� ��ü

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
//      cout<<"����"<<cir[i].getArea()<<endl;
//   }

   Circle1020* p; //���� *p�� * p�� �ٸ���
   p=cir;         //��ü�� �ּҸ� �����ͷ� ����Ŵ
   //(*p).setRadius(-100); //*p�� ���� cir[0]�̹Ƿ� ���� cir[0]�� �ٲ��.
   p->setRadius(-100); //�� ����� ������ �ٲ�

   p=&(cir[1]);  //p�� �ּ� �����̹Ƿ� &�� ���� �ּҸ� �־���� �Ѵ�.
   p->setRadius(-100); //cir[1]�� ������ �ٲ�
   
   p++;
   p->setRadius(-100); //cir[2]�� ������ �ٲ�
   (*p).setRadius(-500); //cir[2]�� ���� -500�� ��.
//   for(int i=0;i<3;i++){
//      cout<<"����"<<cir[i].getArea()<<endl;
//   }
   p[0].setRadius(-400);  //cir��� p�� �� �� �ִ�.
   p[1].setRadius(-400);
   p[2].setRadius(-400);

//   for(int i=0;i<3;i++){
//      cout<<"����"<<cir[i].getArea()<<endl;
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
   Color screenColor(255, 0, 0); //�������� screenColor ��ü ����
   Color* p;
   p=&screenColor;   //p�� screebColor�� �ּҸ� ��������
   p->showColor();   //p�� show()�� �̿��Ͽ� screen �� ���
   Color colors[3];  //Color�� ������ �迭 colors ����. ���Ҵ� 3��
   p=colors;         //p�� colors �迭�� ����Ű���� �ڵ� �ۼ�

   p[0].setColor(255, 0, 0);
   p[1].setColor(0, 255, 0);
   p[2].setColor(0, 0, 255);

   for(int i=0;i<3;i++){
      p[i].showColor();
      // (*(p+1))->showColor; �ε� ����
      // (p+1)->showColor; �� ����
   }

   return 0;
}

//1023 �ǽ�

//��ü�� ���� ���� �� ��ȯ
//������Ÿ�� *�����ͺ��� = new ������Ÿ�� ;
//delete[] �����ͺ���;
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
      delete[] data; //�̷��� �ڵ����� �������ָ鼭 ����
   }
};
int Ex1023_1(){
   allocTEST E(100);
   for(int i=0; i<E.size;i++)
      E.data[i];
   int A[3]={100, 200, 300};
   int* B=(int*)malloc(3*sizeof(int)); //3ĭ ¥�� ���� ����
   B[0]=100; B[1]=200; B[2]=300;
   free(B);    //�Ҵ�� �޸� ����

   //������ sol
   float* C=new float[3];  //3ĭ¥�� float�� ����
   C[0]=100; C[1]=200; C[2]=300;
   delete[] C;  //�Ҵ�� �޸� ����

   int n=100;
   int* p;
   p=&n;

   //int D[n] //�迭�� �ε����� ������ �Ǽ� ���̿����Ѵ�.
   int* D=new int[n];  //�̷��Դ� �����־�
   delete[] D;

   return 0;
}
class Member{
public:
   string name;
   Member(){name=" ";}
   Member(string name_in){name=name_in;}
   string getName(){ return name;}//�̸� ���
   void setName(string name_in){name=name_in;}
};
class Family{
   string family_name;
   Member* p;  //Ŭ����Member�� �����͸� ������. p[3];
   int size;   //Member �迭�� ũ��. ���������� ��
public:
   Family(){}
   Family(string family_name_in, int size_in){
      size=size_in;
      family_name=family_name_in;
      p=new Member[size_in];     //�����ͺ���=new ������(Ŭ������)[����]
      if(p==NULL)
         cout<<"�޸� �Ҵ� ����"<<endl;
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
   Family simpson; //���� 3������ ������ ����
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
//�⸻��� ����

//1030 �ǽ�

//���� ������
//���� ���� ȣ��� �Ű� ���� ��ü�� �����ڰ� ������� �ʴ� ����?
//ȣ��Ǵ� ������ ������ ��ü ���¸� �Ű� ���� ��ü�� �״�� �����ϱ� ����

//���� �ּҿ� ���� ȣ��� ����� ��

//���� ��ü ���� �� ���� �ڵ�
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
   //Ŭ���� ������ �Ű� ��Ƥ�
    _Circle_ tmp;  //A�� B�� ���� ���� ȣ���� �ϸ� �ٸ� ��ü�� ��������Ƿ� ���� �ٲ��� ����
    tmp = A;       //����(&)�� ���� ȣ���� �ؾߵ� (_Circle_& A, _Circle_& B)
    A = B;
    B = tmp;
}
void SwapCircle(_Circle_* A, _Circle_* B) {
    _Circle_ tmp;   
    tmp = *A;  //���⼭�� �ּ��̴ϱ� �����͸� �ٿ���ߵ�
    *A = *B;
    *B = tmp;
}
void SwapCircle(_Circle_& A, _Circle_* B) {
    _Circle_ tmp;   //����� �� �� �ִ�.
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
    obj.setRadius(R);  //������ ���� �ּ��� �� ���� Ȯ��
}
void readRadius(_Circle_* obj) {  //�����ͷ� �غ��Կ�
    cout << "[2] ���� ������ �������� �Է��Ͻÿ�>>" << endl;
    int R;
    cin >> R;
    //(* obj).setRadius(R);  //�����ϱ� *�� �������
    obj->setRadius(R);       //obj�� ��ü �����ʹϱ� �̷��� �� �� �־�.
}
int Ex1030_1()
{
    _Circle_ donut;         //Ŭ���� ��ü �ϳ��� �ι� ���
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
    Accumulator& add(int n);// value�� n�� ���� ���� �����Ѵ�.
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
int Ex1030_2() {
    Accumulator acc(10);
    acc.add(5).add(6).add(7);      // acc�� value ����� 28�� �ȴ�.
    cout << acc.getValue() << endl; // 28 ���

    return 0;
}
class _Accumulator_ {
    int value;     //private�ϱ� �ܺο��� ȣ�� �ȵ�,
public:
    _Accumulator_(int value); // �Ű����� value�� ��� value�� �ʱ�ȭ�Ѵ�.
    _Accumulator_ add(int n);// value�� n�� ���� ���� �����Ѵ�.
    int get(); // ������ �� value�� �����Ѵ�.
};
_Accumulator_::_Accumulator_(int value) {this->value = value;}
int _Accumulator_::get() { return value; }
_Accumulator_ _Accumulator_::add(int n){
   value+=n;
   return *this;
}
int Ex1030_2_1() {         //Accumulator& add(int n) -> Accumulator add(int n) �� ��
    _Accumulator_ acc(10);
    acc.add(5).add(6).add(7);  // acc�� value ����� 28�� �ȴ�.
    cout << acc.get() << endl; // 28 ���
    return 0;
}
//****PDF [����]�� ��°��� 28�� �ƴ϶� 15�̴�.
//�� ������?
//Q1

//���� ��������� 
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
    _Student_(){ strcpy(name, ""); }    //strcpy�� ù��° �ε����� �׸�, �ι�° �ε����� source�� �ִ´�
    _Student_(char* name) {
        strcpy(this->name, name);    
    }
    ~_Student_(){}
    void showName() { cout << "�̸��� " << name << endl; }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};
int Ex1030_4() {
//Q2
    _Student_ A((char*)"KANG"), B((char*)"KIM");   //(char*)�� ���� �������� ����
    B.showName();
    B = A;   //���� ����-���� �Ҵ��� �����ϱ� ������
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
    ~Student() {
        delete[] name;
    }
    void showName() {
        cout << "�̸��� " << name << endl;
    }
    void setName(char* name) {
        strcpy(this->name, name);
    }
};
int Ex1030_5(){          //Ex1030_4�� ���غ���

    Student A((char*)"KANG"), B;
    B = A;           //���� ���縦 �ϸ�
    B.showName();
    B.setName((char*)"PARK");
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
int Ex1127_04() {

    Adder_1127 adder;
    Subtractor_1127 subtractor;
    adder.run();
    subtractor.run();

    return 0;
}

// 1204 �ǽ�

// ���ø�
// p10���� �� �˾Ƶα�.
// template �����ص� Ŭ������ �Լ� �տ� �ٽ� ����� ��

//stack�� queue�� ������  stack�� ���� �ֱٿ� �����ź��� ���´�.
//queue�� fifo

template <class T> 
class Stack {
protected:
    int m_size;   //stack�� �뷮
    int m_top;    //stack�� ����ִ� �������� ����
    T *m_buffer;  //stack �޸�
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
void Stack<T>::Push(T value) {   // <>���̿� Ÿ���� ����.
    m_buffer[m_top]=value;
    m_top++;
}
template <class T> 
T Stack<T> ::Pop() {
    m_top--;
    return m_buffer[m_top];  //���ϰ��� m_top-1�̴ϱ� �̸� ���ٿ��� -1�� ����
}
int Ex1204_0(){
    Stack<int> iStack(10);   //int Ÿ���� �ٷ�� ���� ��ü ����
    Stack<double> dStack(10); //double Ÿ���� �ٷ�� ���� ��ü ����
    
    for(int i=0;i<10;i++)
        iStack.Push(i);
    for(int i=0;i<10;i++)
        int n = iStack.Pop();

    dStack.Push(3.5); 
    double d = dStack.Pop();

    return 0;
}

//C=A-B;
// �����̾�׷��� �����ϸ鼭 �����ϸ� ���� ��
template <class T>
bool CheckItem(T item, T* minus, int sizeMinus){
    for(int i=0;i<sizeMinus;i++){
        if(minus[i]==item)//���� ���Ұ� ����
            return true;
    }
    return false; //���� ���Ұ� ����
}
template <class T>
T* remove(T* src, int sizeSrc, T minus[], int sizeMinus, int& retSize)
{   //�ּҸ� ��������
    T* C=new T[sizeSrc];  //�迭�� ����� ���ڰ� ���ߵ� ���� �����Ҵ� �ع�����.
    int count=0;

    for(int i=0;i<sizeSrc;i++){
        if(false==CheckItem(src[i],minus, sizeMinus)){
            C[count]=src[i];
            count++;
        }
    }
    retSize=count;   //c�迭�� ������ ������ �˷���
    return C;
};
int Ex1204_1() {
    // remove() �Լ��� int�� ��üȭ�ϴ� ���

    cout << "���� �迭 {1,2,3,4}���� ���� �迭 {-3,5,10,1,2}�� ���ϴ�" << endl;
    int x[]={1,2,3,4};
    int y[]={-3,5,10,1,2};
    int retSize;
    
    int* p = remove<int>(x, 4, y, 5, retSize);  //remove�Լ��� �ּҸ� ��ȯ�ϹǷ� p�� �������� �ּҷ��Ѵ�.
    
    if(retSize == 0) {
        cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c �迭�� ��� ���� ���
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // �Ҵ���� �迭 ��ȯ
    }
// remove() �Լ��� double�� ��üȭ�ϴ� ���
// �̰��� �ۼ�
}
int main() {
    // remove() �Լ��� int�� ��üȭ�ϴ� ���

    cout << "�Ǽ� �迭 {1,2,3,4}���� �Ǽ� �迭 {-3,5,10,1,2}�� ���ϴ�" << endl;
    double x[]={1.0,2.0,3.0,4.0};
    double y[]={-3.0,5.0,10.0,1.0,2.0};
    int retSize;
    
    double* p = remove<double>(x, 4, y, 5, retSize);  //remove�Լ��� �ּҸ� ��ȯ�ϹǷ� p�� �������� �ּҷ��Ѵ�.
    
    if(retSize == 0) {
        cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
        return 0;
    }
    else {
        for(int i=0; i<retSize; i++) // c �迭�� ��� ���� ���
            cout << p[i] << ' ';
        cout << endl;
        delete [] p; // �Ҵ���� �迭 ��ȯ
    }
    return 0;
}
//�ǽ� 12-2�� ���ص� �ɵ�?