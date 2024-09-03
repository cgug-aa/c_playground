//포인터 시작 [*b랑 &a를 구분할 수 있어야 돼]

/*포인터는 변수의 주소를 나타냄

int a; 에서
cout<<a; 는 값
cout<<&a; 는 주소
주소를 복사해서 사용하고 싶을 때 b=&a 는 실수형이지만
, b는 주소를 저장하는 변수이므로, *를 붙여서 int* b;
(포인터 변수 int랑 큰 관련없는 새로운 변수라고 생각하면 됨)로 선언한다.
*중요* *b; 는 b의 값(내용)이 나옴.
포인터 변수에 *을 붙이면 내용이 됨.

float M[10];
cout<< M; 은 M[0]의 주소가 나옴
cout<< &M[0];    은 주소
cout<< *M;       은 내용
cout<< M+1;      은 주소
cout<< *(M+1);   은 내용
cout<< M[1];     은 내용

void biggest(double* b, n)   주소에 맞는 값을 포인터로 가져옴
---
biggest(a,4); 이면 a는 배열의 주소를 보내게 돼.
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

    cout<<n<<endl;          //10이 출력되고,

    *p =25;    //p로 n의 주소로 가서 *p로 값을 바꿔줌 (포인터를 통해 값을 바꿈)

    cout<<n<<endl;          //25가 출력된다.

    return 0;
}
void func(int* pointer)   //주소를 받아
{
    cout <<pointer<<endl;   //주소를 받아
    cout <<*pointer<<endl;  //값을 받아

}
int Ex0911_1()
{
    int arr[6] = {1,2,3,4,5,6};
    int* chr_ptr=arr; // 1) int에 대한 포인터 변수 chr_ptr을 선언하는 문장 작성
// chr_ptr이 arr 배열이 저장되어 있는 메모리 주소값을 갖도록 초기화.
// 답: int* chr_ptr;

//chr_ptr = ______________;
//답: arr;
    chr_ptr++; // chr_ptr의 값을 하나 증가 따라서 주소는 변수형의 크기인 4만큼 증가됨
    cout << chr_ptr << endl;   //3) 옆 문장이 실행되었을 때의 결과는?  답:arr[1]의 주소
    cout << *chr_ptr << endl;  //4) 옆 문장이 실행되었을 때의 결과는?  답:2가 출력
    cout << arr << endl;       //5) 옆 문장이 실행되었을 때의 결과는?  답:arr[0]의 주소
    cout << arr+4 << endl;     //6) 옆 문장이 실행되었을 때의 결과는?  답:arr[5]의 주소
    cout << &arr[3] << endl;   //7) 옆 문장이 실행되었을 때의 결과는?  답:arr[3]의 주소
    cout << arr[4] << endl;    //                                    답:5가 출력     
//arr[3]의 값을 chr_ptr을 이용하여 프린트
//cout << ___________ << endl; 
//답: *(chr_ptr+2)
    cout << *(chr_ptr+2)<<endl;

    func(arr);      //arr의 주소를 보내
//cf) &arr[3]로 4의 주소를 보내고 pointer[-1]을 하면 3을 갖게됨
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

    int* ptr[5];       //포인터 변수를 5개 잡음
    ptr[0]=&a;
    ptr[1]=&b;
    ptr[2]=&c;
    ptr[3]=&d;
    ptr[4]=&e;

    for(int i=0;i<5;i++)
        cout<<*ptr[i]<<endl;     //ptr로 하면 주소가 출력   *ptr으로 하면 값이 출력

    //cout << *a_ptr<<endl;

    return 0;
}

int Ex0911_3()
{
    int arr_0_[3]={1,2,3};
    int arr_1_[4]={11, 12, 13, 14};
    int arr_2_[5]={21, 22, 23, 24, 25};

    int* ptr[3];
    ptr[0]=arr_0_;      //ptr[0] 자체가 변수야 
    ptr[1]=arr_1_;
    ptr[2]=arr_2_;

  //int* ptr[3]={arr_0_,arr_1_,arr_2_};

    cout<<*ptr[0]<<endl;  //*중요*  *ptr[0]은 출력 1 
    cout<<*(ptr[0]+1)<<ptr[0][1]<<endl;  //*(ptr[0]+1)은 ptr[0][1]이므로 둘 다 2를 출력

  //int** ptr2 =ptr;  //참고) ptr의 주소를 구하고 싶으면 포인터를 한번 더 써주면 돼
    return 0;
}

int main()
{
    Ex0911_3();
    return 0;
}