#include <iostream>
using namespace std; 

class Oval{
    int width, height;
public:
    Oval();
    Oval(int w, int h);
    ~Oval();
    int getWidth();
    int getHeight();
    void set(int w, int h);
    void show();

   
   

};
Oval::Oval()  //입력이 없었을 때 1로 초기화
{ 
    width=1;
    height=1;
};
Oval::Oval(int w, int h)
{  
    width=w;
    height=h;
};
Oval::~Oval()
{
   cout<<"Oval 소멸 : width = "<<width<<", height = "<<height<<endl;
};

int Oval::getWidth()
{

};
int Oval::getHeight()
{

};
void Oval::set(int w, int h)
{
    width=w;
    height=h;
};
void Oval::show()
{
    cout<<"width = "<<width<<", height = "<<height<<endl;
};

int main()
{
   Oval a, b(3, 4);
   a.set(10, 20);
   a.show();

   cout << b.getWidth() << ", " << b.getHeight() << endl;
}