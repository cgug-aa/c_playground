/*1���� �ǽ�*/

#include<iostream>
//<iostream> ��������� ������ ���� �ҽ��� Ȯ���ϵ��� ����
//<iostream> ��� ����: ������� ���� Ŭ������ ��ü, ���� ���� �����
//using namespace std; �� ���� std���� �� ��� ��

void ex1()
{
    std::cout << "My name is Hoon.\n\n"; //C++���� ��°�ü�� cout �̿�
    //cout<< �� �������� ���
    //<<������ ������ �⺻���� ������ �����ϸ� �ڵ����� ������ ���� ���߾� ���
}
void ex2()
{
    std::cout << "������Ű��к�\n23��\n��� �����Ͼ�\n\n";
}
void ex3()
{
	int sum = 0;
	for (int n = 0; n < 11; n++)
	{
		sum += n;
	}
	std::cout << "1���� 10���� ���� �����" << sum << "�Դϴ�.\n\n";
	//����, ���ڿ� ���

	//char c='#';
	//std::cout<<c<<5.5<<'-'<<"Hi";
	//����(c), ����(5.5), ����(-), ���ڿ�(Hi) ���
}
void ex4()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= i; j++) std:: cout << "*";
		std::cout << "\n";
	}
}

int main()
{
	ex1();
	ex2();
	ex3();
	ex4();

	return 0;
}