#include<iostream>
using namespace std;

//������ ����
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
	cout << &a << endl;       //&�� ���� a�� �ּ� ���
	cout << p << endl;        //������ p�� ���� �ּ� ���
	cout << *p << endl;       //*�����͸� ���� ���� ���
	
	//Func(a);
	Funcptr(&a);              //a�� �ּҸ� ȣ���� ���� �ٲ۴�.

	cout << &a << endl;
	cout << a << endl;

	return 0;
}
void FuncArray(int* ptr)    //�迭�� �ޱ� ���� �ּҸ� �Ѱ��ش�.
{
	cout << "Func" << ptr << endl;     //���� �Լ��� �迭�� �ּҷ� �Ѱ� �޾����Ƿ�
	cout << "Func" << *ptr << endl;    //�迭�� �� �� �ִ�.
	cout << "Func" << ptr[0] << endl;
	
	for (int i=0; i < 5; i++)
		cout << ptr[i] << endl;
}
int Ex0915_02()
{
	int c[5] = {10, 20, 30, 40, 50};

	cout << c << endl;      //�迭�� �̸��� �ּҸ� ��ȯ�Ѵ�.
	cout << *c << endl;     //c[0]
	cout << c+1 << endl;    //����) �迭�� �̸��̹Ƿ� �ּҸ� ��ȯ�Ѵ�.(4byte �߰�)
	cout << *(c+1) << endl; //�����͸� ����Ͽ� ������ ��ȯ. c[1]
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
c�� �ٸ��� ���۷��� ����

���۷���(Reference) ����  >>>>�迭 �ּҿ� ���� �������
������ & ����
�̹� �����ϴ� ������ ���� �ٸ� �̸� ����  >>>>������ ����
@���� ������ �̸��� �����
@���� ������ ���ο� ������ �Ҵ����� ����
@�ʱ�ȭ�� ������ ���� ���� ����

int target=20;
int& ref =target;
ref =3;
>>>>> target�� ������ 3�� �ȴ�.
*/
void FuncRef(int& ttt)
{
	cout << "Ref: " << ttt << endl;
	ttt = 500;
}
int Ex0915_03()
{
	int target = 20;
	int& nickname = target;   //����) int& nickname�� �ʱ�ȭ�� ������ ����� �Ѵ�.
	nickname = -10;

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
	*c = a + b;
}
void addsub(int a, int b, int& sum, int& diff)   //a�� b�� �Լ����� �ҷ����µ��� ���ǹǷ� &�� �� �ٿ��� ��
{                   //sum�̶� diff�� ���� �Լ��� ��������ϹǷ� &�� *�� ����Ѵ�.
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
	if (average(x,6,avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ����" << endl;

	if (average(x, -1, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;

	return 0;
}