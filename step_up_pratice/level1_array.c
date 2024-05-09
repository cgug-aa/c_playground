//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//배열
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1차원 배열 선언과 배열 원소 사용
int main1(){
    int a[5]={0, 0, 0, 0, 0};
    printf("%d", a[4]);
    return 0;
}

//1차원 배열 초기화
int main2(){
    int a[5];
    for(int i=0;i<5;i++) a[i]=7;
    printf("%d", a[4]);
    return 0;
}

//1차원 배열 원소의 입출력
int main3(){
    int a[5];
    for(int i=0;i<5;i++)
        scanf("%d", &a[i]);
    for(int i=4;i>=0;i--)
        printf("%d ", a[i]);
    return 0;
}

//1차원 배열을 함수 매개변수로 전달
int sum(int a[]){
    return 5*a[0];
}
int main4(){
    int num, a[5];
    scanf("%d", &num);
    for(int i=0;i<5;i++) a[i]=num;
    printf("%d", sum(a));
    return 0;
}