#include <iostream>
#include <string> //string
#include <vector> //vector

using namespace std;

/*
-Ŭ������ ��ü!

c���� ����üó��
class�� ����
���������
����Լ��� �ִ´�

-string Ŭ���� �� vector Ŭ����
#include<string>
���ڿ� ����, ��, ���̵��� Ȱ���� �� �ִ�

string��ü�� ���� Ÿ���̴�.
string name; // �� ���ڿ��� ���� ��Ʈ�� ��ü
string address("����� ���ϱ� �Ｑ�� 389��); // ���ڿ� ���ͷ��� �ʱ�ȭ
string copyAddress(address); // address�� ������ copyAddress ����
*/

int Ex0922_01()
{
    char cname[]="Lee";
    string sname(cname);   //���ڿ� cname�� �ִ� �� sname���� ���簡 �ȴ�.

    cout<<sname[0]<<endl;  //�迭ó�� ������ ���� �ִ�.

    //string name ="Lee chan gu";
    string name("Lee chan gu");
    string address("chengju CBNU");

    string str=name+address;

    cout<<str<<endl;

    string str_copy=str;

    cout<<str_copy<<endl;

    cout<<str.size()<<endl;  //���ڿ��� ���̸� �˷��ش�.

    int pos=str.find("gu");  //���ڿ����� ������ �ε��� ã�� ��ġ�� �˷��ش�

    cout<<pos<<endl;


    return 0;
}

//string�� ����� ���Ƽ� �������!

/*
����

*/
int Ex0922_02()
{
    vector<int> A; //vector�� �迭�� <>�ȿ� �� ������ �ִ´�.

    cout<<A.size()<<endl;

    A.push_back(10);   //���Ϳ� ���� Ǫ���ؼ� �ִ´�.
    A.push_back(20);
    A.push_back(30);
    A.push_back(40);

    for(int i=0;i<A.size();i++)
    cout<<A[i]<<endl;

    A.clear();       //�� ���� ���͸� �ʱ�ȭ�� �� �ִ�.

    return 0;
}

/*
���� ������ private, protected, public
�� ������ �ڵ带 ���� ������ �ΰ��� �� �ִ�.

*/
class Circle{         //�������� ����ٴ� ����     
public:  //public�� ������� ������ private�� default�̹Ƿ�
         //�ܺο��� ����� �� ����.
   int radius;        //���� ����
   double getArea();   //�Լ� ����

};
//class�ȿ� �Լ��� ����� �� �Լ��� class�ۿ� ������ �� �ִ�.
//�� �� Ŭ���� �Ҽ����� ������ ���� ::�� ����Ѵ�
double Circle::getArea()
   {
    return (3.14*radius*radius);
   }


/*
class Circle{         //�������� ����ٴ� ����     
private:  //public�� ������� ������ private�� default�̹Ƿ�
         //�ܺο��� ����� �� ����.
   int radius;        //���� ����
public:
   double getArea()   //�Լ� ����
   {
    return (3.14*radius*radius);
   }
   void setRadius(int r)
   {
    radius=r;         //�̷� ������ �����ϸ� �� Ŭ������ �����ϰ� ����� �� �ִ�.
   }
};
*/
int Ex0922_03()
{
    Circle donut;     //Ŭ���� ��ü �̸�
    donut.radius = 1; // donut ��ü�� �������� 1�� ����

    double area = donut.getArea(); // donut ��ü�� ���� �˾Ƴ���
    cout << "donut ������ " << area << endl;

    Circle pizza;

    pizza.radius = 30; // pizza ��ü�� �������� 30���� ����
    area = pizza.getArea(); // pizza ��ü�� ���� �˾Ƴ���
    cout << "pizza ������ " << area << endl;

    Circle *ptr;
    ptr = &pizza;

    cout<<ptr->radius<<endl;     //�������� ������ ���� ���� ->�� ����Ѵ�
                                 //ptr->radius�� (*ptr).radius�� �� ���� �ִ�.
    cout<<ptr->getArea()<<endl;  //(*ptr).getArea()�� �ٲ� �� �ִ�.
    return 0;
}

class Rectangle{
public:
    int width;
    int height;
    int getArea()
    {
        return (width*height);
    }
};
int main()
{
   Rectangle rect;
   rect.width = 3;
   rect.height = 5;
   cout << "�簢���� ������ " << rect.getArea() << endl;
   
   return 0;
}