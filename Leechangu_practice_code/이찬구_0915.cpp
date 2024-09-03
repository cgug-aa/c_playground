#include<iostream>
using namespace std;

//포인터 복습
void Func(int a)
{
	a = 200;
	cout << "Func: " << a << endl;
	cout << "Func:& " << &a << endl;
}
void Funcptr(int* a)
{
	*a = 200;
	cout << "Func: " << *a << endl;
	cout << "Func:& " << &a << endl;
	
}
int Ex0915_01()
{
	int a = 100;
	
	int* p;
	p = &a;
	cout << &a << endl;       //&를 통해 a의 주소 출력
	cout << p << endl;        //포인터 p를 통해 주소 출력
	cout << *p << endl;       //*포인터를 통해 내용 출력
	
	//Func(a);
	Funcptr(&a);              //a의 주소를 호출해 값을 바꾼다.

	cout << &a << endl;
	cout << a << endl;

	return 0;
}
void FuncArray(int* ptr)    //배열을 받기 위해 주소를 넘겨준다.
{
	cout << "Func" << ptr << endl;     //메인 함수의 배열을 주소로 넘겨 받았으므로
	cout << "Func" << *ptr << endl;    //배열을 쓸 수 있다.
	cout << "Func" << ptr[0] << endl;
	
	for (int i=0; i < 5; i++)
		cout << ptr[i] << endl;
}
int Ex0915_02()
{
	int c[5] = {10, 20, 30, 40, 50};

	cout << c << endl;      //배열의 이름은 주소를 반환한다.
	cout << *c << endl;     //c[0]
	cout << c+1 << endl;    //주의) 배열의 이름이므로 주소를 반환한다.(4byte 추가)
	cout << *(c+1) << endl; //포인터를 사용하여 내용을 반환. c[1]
	FuncArray(c);

	int* p;
	p = c;

	cout << p << endl;
	cout << *p << endl;
	cout << p+1 << endl;
	cout << *(p+1) << endl;

	return 0;
}

/*
c와 다르게 레퍼런스 존재

레퍼런스(Reference) 선언  >>>>배열 주소와 전혀 상관없음
참조자 & 도입
이미 존재하는 변수에 대한 다른 이름 선언  >>>>별명같은 느낌
@참조 변수는 이름만 생기며
@참조 변수에 새로운 공간을 할당하지 않음
@초기화로 지정된 기존 변수 공유

int target=20;
int& ref =target;
ref =3;
>>>>> target의 내용은 3이 된다.
*/
void FuncRef(int& ttt)
{
	cout << "Ref: " << ttt << endl;
	ttt = 500;
}
int Ex0915_03()
{
	int target = 20;
	int& nickname = target;   //주의) int& nickname은 초기화를 무조건 해줘야 한다.
	nickname = -10;

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
	*c = a + b;
}
void addsub(int a, int b, int& sum, int& diff)   //a와 b는 함수에서 불러오는데만 사용되므로 &를 안 붙여도 됨
{                   //sum이랑 diff는 메인 함수로 보내줘야하므로 &나 *를 써야한다.
	sum = a + b;
	diff = a - b;
}
int Ex0915_04()
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
bool average(int a[], int size, int& avg)
{
	int sum = 0;
	if (size < 0)
		return (false);

	for (int i = 0; i < size; i++)
		sum += a[i];
	avg = (sum/size);
	return (true);
}
int main()
{
	int x[] = { 0,1,2,3,4,5};
	int avg;
	if (average(x,6,avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -1, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류 " << endl;

	return 0;
}