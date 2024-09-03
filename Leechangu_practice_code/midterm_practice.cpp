#include <iostream>
#include <string>
using namespace std;

class Person {
   string name;
public:
   Person() { name=""; }
   Person(string name) { this->name = name; }
   string getName() { return name; }
   void setName(string name) { this->name = name; }
};

class Family {
   string name;
   Person* p; // Person 배열 포인터
   int size;  // Person 배열의 크기. 가족 구성원 수
public:
   Family(string name, int size){
    this->name=name;
    this->size=size;
    p=new Person[size];
   } // size 개수만큼 Person 배열 동적 생성
   void setName(int index, string name){
        p[index].setName(name);
   }
   void show(){
    cout<<this->name<<"가족은 다음과 같이"<< this-> size<<"명 입니다."<<endl;
    for(int i=0;i<size;i++)
    {
        cout<< p[i].getName()<<"   ";
    }
    cout <<endl;
   } // 모든 가족 구성원 출력
   ~Family(){
    delete[] p;
   }
};

int main() {
   Family simpson ("Simpson", 3); // 3명으로 구성된 Simpson 가족
   simpson.setName(0, "Mr. Simpson");
   simpson.setName(1, "Mrs. Simpson");
   simpson.setName(2, "Bart Simpson");
   simpson.show();
   return 0;
}