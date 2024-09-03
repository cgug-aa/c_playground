#include <iostream>
using namespace std;


/*
접근 지정자
private : 해당 클래스의 멤버함수에서의 접근까지
protected : 파생클래스의 멤버함수에서의 접근까지
public : 클래스 밖에서의 접근까지

-생성자를 프라이빗으로 만들면, 호출할 때(함수, 변수 다) 오류가 발생한다.
-접근자 함수는 get이나 set으로 접근한다.

const는 생략
*/

class Ram {
   char mem[100*1024]; // 100KB 메모리
   int size;
public:
   Ram(); // mem을 0으로 초기화하고 size를 100*1024로 초기화
   ~Ram(); // "메모리 제거됨" 문자열 출력
   char read(int address); // address 주소의 메모리를 읽어 리턴
   void write(int address, char value); // address 주소에 value 저장
// 주소가 범위를 벗어나는 오류 발생하면 에러메시지 출력함
};

Ram::Ram()
{
    size=100*1024;
    for(int i=0;i<size;i++)
        mem[i]=0;
    //memset(mem,0,size);  mem이 char가 아니라 int면 bit 단위를 4로 해야됨
};
Ram::~Ram()
{
    cout<<"메모리 제거됨"<<endl;
};
char Ram::read(int address)
{
    return mem[address];
};
void Ram::write(int address, char value)
{
    mem[address]=value;
};
int main() {
    Ram ram;
    ram.write(100, 20); // 100 번지에 20 저장
    ram.write(101, 30); // 101 번지에 30 저장
    char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
    ram.write(102, res); // 102 번지에 50 저장
    cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 메모리 값 출력
}
