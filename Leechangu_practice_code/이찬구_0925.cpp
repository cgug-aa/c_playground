#include <iostream>
using namespace std;

/*
������
-��ü�� �����Ǵ� �������� �ڵ����� ȣ��Ǵ� ��� �Լ�
-��ü�� ������ �� ��ü�� �ʿ��� �ʱ�ȭ�� ����
�Ҹ���
-��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� ��� �Լ�
-��ü�� �Ҹ�� �� ��ü�� ������ ����
*/
class CirCle0925{
public:
    int radius;
    //int* MEM;
    CirCle0925();       //������
    CirCle0925(int r);  //������ 
    ~CirCle0925();      //�Ҹ���
    double getArea();   //�Լ��� Ŭ������ �����ϰ�
};
/*
���ȭ��:
������ 1�� �� ����
������ 100�� �� ����
������ 100�� �� �Ҹ�
������ 1�� �� �Ҹ�

-�����Լ��� �����鼭 �Ҹ��Ű�� ��
������ AB������,
�Ҹ��� BA����
*/

CirCle0925::~CirCle0925()
{
    //delete[] MEM;
    cout<<"������ "<<radius<<"�� �� �Ҹ�"<<endl;   //�Ҹ��� �� ��µ� ����
}
CirCle0925::CirCle0925()   //�Լ��� �ۿ� �����ش�.
{
    //MEM= new int [10000*10000]; //�̷��� �޸𸮸� �÷��ָ� pc�� �޸𸮸� ���� ��Ƹ԰� ��
                                     //���� �Ҹ��ڰ� �ʿ���.
    radius = 1;
    cout<<"������ "<<radius<<"�� �� ����"<<endl;
}
CirCle0925::CirCle0925(int r)  //�Ķ���Ͱ� �޶� �ٸ� �Լ��� ����Ѵ�.
{
    //MEM= new int [10000*10000];

    radius = r;
    cout<<"������ "<<radius<<"�� �� ����"<<endl;
}
double CirCle0925::getArea()
{
    return (3.14*radius*radius);
}

int FFF()
{
    //CirCle0925 A(); �Ķ���Ͱ� �����Ƿ� ����Ʈ ���� 1�� ����������
    CirCle0925 A(100); 
    CirCle0925 B(100); //int r�� 100�� �Ķ���ͷ� ������
    
    return 0;
}
//CirCle0925�� ���Ե� �Լ��� ����� �Ҹ�ȴ�.
//CirCle0925 gA(1000);
//CirCle0925 gB(2000);    //�۷ι� ������ ���� ���� �����
int Ex0925_01()
{
    CirCle0925 A;
    CirCle0925 B(30);
    FFF();

    return 0;
}
/*
���ȭ��:
������ 1000�� �� ����
������ 2000�� �� ����
������ 1�� �� ����
������ 30�� �� ����
������ 100�� �� ����
������ 100�� �� ����
������ 100�� �� �Ҹ�
������ 100�� �� �Ҹ�
������ 30�� �� �Ҹ�
������ 1�� �� �Ҹ�
������ 2000�� �� �Ҹ�
������ 1000�� �� �Ҹ�

-������ �Ҹ��� ����
*/

class Rectangle{
public:
    double width, height;
    /*bool isSquare;
    Rectangle(int width=2, int height=2){
        if(width == height)
            isSquare='True';
    }           ���� �ǽ��ߴ� �ڵ�
    */
    Rectangle();       //for rect1 ������ ���� Ŭ������ ������ �̸�
    Rectangle(int w_in, int h_in=3){ //������ for rect2,3  <**����Ʈ���� �ڿ��� ����!!>
      width=w_in;
      height=h_in;
    }
    bool isSquare(){
        if(width==height)
            return true;
        else
            return false;
    }
};
Rectangle::Rectangle(){
    width=0;
    height=0;
}

int main()
{
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1�� ���簢���̴�." << endl;
    if(rect2.isSquare()) cout << "rect2�� ���簢���̴�." << endl;
    if(rect3.isSquare()) cout << "rect3�� ���簢���̴�." << endl;
    
    
    
    return 0;
}