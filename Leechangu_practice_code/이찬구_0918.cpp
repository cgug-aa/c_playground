#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{//big�� �����Լ��� �ٽ� ������� �ϴϱ� ���۷����� ����ߴ�.
	
	if (a == b)
		return true;
	else if (a > b)
	{
		big = a;
		return false;
	}
	else
	{
		big = b;
		return false;
	}
}
int Ex0918_01()
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
char& find(char a[], char c, bool& success)
{
	success = false;

	for (int i = 0;; i++)         //;;���� ���߰��� �������� �θ� ��� �ݺ�
	{
		if (a[i]=='\0')
			return a[i];
		else if (a[i] == c)
		{
			success = true;
			return a[i];
		}
	}
}
int Ex0918_02()
{
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);    //a[i]�� �޾�
	if (b == false)
	{
		cout << "M�� �߰��� �� ����." << endl;
		return 0; 
	}
	loc = 'm';          // a[i]�� ���� 'M' ��ġ�� 'm' ���
	cout << s << endl;  // "mike"�� ��µ�
}
int Sum(int a=-20, int b=-10, int c=10)   //int c=10�̶� �ص� ������ 60�� �ȴ�.
{                                 //������ �����Լ����� c���� ���������� ������,
	                              //c���� ����Ʈ�� 10�� �ȴ�.
	return (a + b + c);           //����Ʈ ���� ������ �� ���������� �����ؾ��Ѵ�.
}
int Ex0918_03()
{
	int a = 10, b = 20, c = 30;
	int d, e, f, g;

	d=Sum(a, b,c);
	e = Sum(a, b);
	f = Sum(a);
	g = Sum();
	cout << d << '\n' << e << '\n' << f << '\n' << g;

	return 0;
}
int diff(int a, int b)
{
	return (a - b);
}
double diff(double a, double b)  //�ε����� ��� Ÿ���� �ٸ��� �Լ� �̸��� ���Ƶ� �ٸ� �Լ��� ���
                                 //c������ �ȵȴ�.
{
	return (a - b);
}
int Ex0918_04()
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
int main()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}