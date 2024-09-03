/*1주차 실습*/

#include<iostream>
//<iostream> 헤더파일을 컴파일 전에 소스에 확장하도록 지시
//<iostream> 헤더 파일: 입출력을 위한 클래스와 객체, 변수 등이 선언됨
//using namespace std; 를 쓰면 std따로 안 적어도 됨

void ex1()
{
    std::cout << "My name is Hoon.\n\n"; //C++에의 출력객체인 cout 이용
    //cout<< 값 형식으로 출력
    //<<연산자 다음에 기본형의 변수를 지정하면 자동으로 데이터 형에 맞추어 출력
}
void ex2()
{
    std::cout << "정보통신공학부\n23세\n통신 엔지니어\n\n";
}
void ex3()
{
	int sum = 0;
	for (int n = 0; n < 11; n++)
	{
		sum += n;
	}
	std::cout << "1에서 10까지 더한 결과는" << sum << "입니다.\n\n";
	//변수, 문자열 출력

	//char c='#';
	//std::cout<<c<<5.5<<'-'<<"Hi";
	//변수(c), 숫자(5.5), 문자(-), 문자열(Hi) 출력
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