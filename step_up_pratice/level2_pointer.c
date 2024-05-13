//충북대 소중단 step_up C프로그래밍 심화 LEVEL 2
//포인터
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//포인터를 이용한 매개변수 전달
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main1(){
    int a,b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);               //매개변수를 넘겨줄 때 &를 통해 주소를 넘겨 달아준다.
    printf("%d %d", a, b);
    return 0;
}

//포인터 연산
int main2(){
    int a[5]={1, 2, 3, 4, 5};
    for(int i=0;i<5;i++)
        printf("%d ", *(a+i));  //a[] 가 아닌  덧셈연산으로 주소를 표현하고 값을 받아올 수 있다.
    return 0;
}

//포인터 반환
int *find(int a[]){
    int min=0;
    for(int i=1;i<5;i++){
        if(a[min]>a[i])         //배열의 값 자체로 비교하지 말고, 배열의 인덱스로 순환하며 비교한다.
            min=i;
    }
    return &a[min];
}
/*
int find(int a[]){
    int min=a[0];
    for(int i=1;i<5;i++)
        if(min>a[i])
            min=a[i];
    return min;
}
*/
int main3(){
    int a[5];
    int *p;                         //find함수에서 주소를 넘겨받기 위해 포인터 변수를 선언한다
    for(int i=0;i<5;i++) scanf("%d", &a[i]);
    p=find(a);
    printf("%d", *p);
    return 0;
}