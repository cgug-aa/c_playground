#include<iostream>
using namespace std;

int main()
{
    char a[5]={'a', 's', ' ', ';', 'h'};
//&a[1], &a[2] 등으로 배열의 주소를 알 수 있다.
//a[2]는 *(a+2)와 같은 값으로 동일하다.
//a+2은 주소 *(a+2)는 값
//
    char* p;
    p=a;

    printf("vla = 0x%x  %c %c 0x%x\n", a+1, *(a+1), a[1], &a[1]);

    char* p;
    p=&a[3];
    printf("%c", *p);

//p가 들어있는 자리의 값이 나온다.
//printf(%c,*(p+1)) 를 하면 a[4]의 값이 나온다.
//a[3]와 *(a+3)가 같기 때문에 p[-1]은 a[2]의 값이 나온다.

    return 0;
}