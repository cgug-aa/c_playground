#include <iostream>
using namespace std;


/*
���� ������
private : �ش� Ŭ������ ����Լ������� ���ٱ���
protected : �Ļ�Ŭ������ ����Լ������� ���ٱ���
public : Ŭ���� �ۿ����� ���ٱ���

-�����ڸ� �����̺����� �����, ȣ���� ��(�Լ�, ���� ��) ������ �߻��Ѵ�.
-������ �Լ��� get�̳� set���� �����Ѵ�.

const�� ����
*/

class Ram {
   char mem[100*1024]; // 100KB �޸�
   int size;
public:
   Ram(); // mem�� 0���� �ʱ�ȭ�ϰ� size�� 100*1024�� �ʱ�ȭ
   ~Ram(); // "�޸� ���ŵ�" ���ڿ� ���
   char read(int address); // address �ּ��� �޸𸮸� �о� ����
   void write(int address, char value); // address �ּҿ� value ����
// �ּҰ� ������ ����� ���� �߻��ϸ� �����޽��� �����
};

Ram::Ram()
{
    size=100*1024;
    for(int i=0;i<size;i++)
        mem[i]=0;
    //memset(mem,0,size);  mem�� char�� �ƴ϶� int�� bit ������ 4�� �ؾߵ�
};
Ram::~Ram()
{
    cout<<"�޸� ���ŵ�"<<endl;
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
    ram.write(100, 20); // 100 ������ 20 ����
    ram.write(101, 30); // 101 ������ 30 ����
    char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
    ram.write(102, res); // 102 ������ 50 ����
    cout << "102 ������ �� = " << (int)ram.read(102) << endl; // 102 ���� �޸� �� ���
}
