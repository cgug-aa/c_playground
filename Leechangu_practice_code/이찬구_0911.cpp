//������ ���� [*b�� &a�� ������ �� �־�� ��]

/*�����ʹ� ������ �ּҸ� ��Ÿ��

int a; ����
cout<<a; �� ��
cout<<&a; �� �ּ�
�ּҸ� �����ؼ� ����ϰ� ���� �� b=&a �� �Ǽ���������
, b�� �ּҸ� �����ϴ� �����̹Ƿ�, *�� �ٿ��� int* b;
(������ ���� int�� ū ���þ��� ���ο� ������� �����ϸ� ��)�� �����Ѵ�.
*�߿�* *b; �� b�� ��(����)�� ����.
������ ������ *�� ���̸� ������ ��.

float M[10];
cout<< M; �� M[0]�� �ּҰ� ����
cout<< &M[0];    �� �ּ�
cout<< *M;       �� ����
cout<< M+1;      �� �ּ�
cout<< *(M+1);   �� ����
cout<< M[1];     �� ����

void biggest(double* b, n)   �ּҿ� �´� ���� �����ͷ� ������
---
biggest(a,4); �̸� a�� �迭�� �ּҸ� ������ ��.
biggest()
---
*/
#include<iostream>
using namespace std;

int Ex0911_0()
{
    int n=10, m;
    char c= 'A';
    double d;

    int* p;
    p=&n;

    cout<<n<<endl;          //10�� ��µǰ�,

    *p =25;    //p�� n�� �ּҷ� ���� *p�� ���� �ٲ��� (�����͸� ���� ���� �ٲ�)

    cout<<n<<endl;          //25�� ��µȴ�.

    return 0;
}
void func(int* pointer)   //�ּҸ� �޾�
{
    cout <<pointer<<endl;   //�ּҸ� �޾�
    cout <<*pointer<<endl;  //���� �޾�

}
int Ex0911_1()
{
    int arr[6] = {1,2,3,4,5,6};
    int* chr_ptr=arr; // 1) int�� ���� ������ ���� chr_ptr�� �����ϴ� ���� �ۼ�
// chr_ptr�� arr �迭�� ����Ǿ� �ִ� �޸� �ּҰ��� ������ �ʱ�ȭ.
// ��: int* chr_ptr;

//chr_ptr = ______________;
//��: arr;
    chr_ptr++; // chr_ptr�� ���� �ϳ� ���� ���� �ּҴ� �������� ũ���� 4��ŭ ������
    cout << chr_ptr << endl;   //3) �� ������ ����Ǿ��� ���� �����?  ��:arr[1]�� �ּ�
    cout << *chr_ptr << endl;  //4) �� ������ ����Ǿ��� ���� �����?  ��:2�� ���
    cout << arr << endl;       //5) �� ������ ����Ǿ��� ���� �����?  ��:arr[0]�� �ּ�
    cout << arr+4 << endl;     //6) �� ������ ����Ǿ��� ���� �����?  ��:arr[5]�� �ּ�
    cout << &arr[3] << endl;   //7) �� ������ ����Ǿ��� ���� �����?  ��:arr[3]�� �ּ�
    cout << arr[4] << endl;    //                                    ��:5�� ���     
//arr[3]�� ���� chr_ptr�� �̿��Ͽ� ����Ʈ
//cout << ___________ << endl; 
//��: *(chr_ptr+2)
    cout << *(chr_ptr+2)<<endl;

    func(arr);      //arr�� �ּҸ� ����
//cf) &arr[3]�� 4�� �ּҸ� ������ pointer[-1]�� �ϸ� 3�� ���Ե�
    return 0;
}

int Ex0911_2()
{
    int a=10, b=20, c=30, d=40, e=50;

    int* a_ptr =&a;
    int* b_ptr =&b; 
    int* c_ptr =&c;
    int* d_ptr =&d;
    int* e_ptr =&e;

    int* ptr[5];       //������ ������ 5�� ����
    ptr[0]=&a;
    ptr[1]=&b;
    ptr[2]=&c;
    ptr[3]=&d;
    ptr[4]=&e;

    for(int i=0;i<5;i++)
        cout<<*ptr[i]<<endl;     //ptr�� �ϸ� �ּҰ� ���   *ptr���� �ϸ� ���� ���

    //cout << *a_ptr<<endl;

    return 0;
}

int Ex0911_3()
{
    int arr_0_[3]={1,2,3};
    int arr_1_[4]={11, 12, 13, 14};
    int arr_2_[5]={21, 22, 23, 24, 25};

    int* ptr[3];
    ptr[0]=arr_0_;      //ptr[0] ��ü�� ������ 
    ptr[1]=arr_1_;
    ptr[2]=arr_2_;

  //int* ptr[3]={arr_0_,arr_1_,arr_2_};

    cout<<*ptr[0]<<endl;  //*�߿�*  *ptr[0]�� ��� 1 
    cout<<*(ptr[0]+1)<<ptr[0][1]<<endl;  //*(ptr[0]+1)�� ptr[0][1]�̹Ƿ� �� �� 2�� ���

  //int** ptr2 =ptr;  //����) ptr�� �ּҸ� ���ϰ� ������ �����͸� �ѹ� �� ���ָ� ��
    return 0;
}

int main()
{
    Ex0911_3();
    return 0;
}