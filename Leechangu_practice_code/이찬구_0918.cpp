#include<iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{//big은 메인함수로 다시 보내줘야 하니까 레퍼런스를 사용했다.
	
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
char& find(char a[], char c, bool& success)
{
	success = false;

	for (int i = 0;; i++)         //;;으로 나중값을 공백으로 두면 계속 반복
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
	char& loc = find(s, 'M', b);    //a[i]를 받아
	if (b == false)
	{
		cout << "M을 발견할 수 없다." << endl;
		return 0; 
	}
	loc = 'm';          // a[i]의 값인 'M' 위치에 'm' 기록
	cout << s << endl;  // "mike"가 출력됨
}
int Sum(int a=-20, int b=-10, int c=10)   //int c=10이라 해도 총합은 60이 된다.
{                                 //하지만 메인함수에서 c값을 전달해주지 않으면,
	                              //c값을 디폴트로 10이 된다.
	return (a + b + c);           //디폴트 값을 설정할 땐 끝에서부터 설정해야한다.
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
double diff(double a, double b)  //인덱스와 출력 타입이 다르면 함수 이름이 같아도 다른 함수로 취급
                                 //c언어에서는 안된다.
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
int main()
{
	f();
	f('%');
	f('@', 5);
	return 0;
}