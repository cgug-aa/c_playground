//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//조건문/반복문
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//조건이 만족하면 반복 실행
int main1(){
    int n;
    scanf("%d", &n);

    if((n%2)==0) for(int i=0;i<n;i++) printf("%d ", 2*i);
    else for(int i=0;i<n;i++) printf("%d ", 2*i+1);
    return 0;
}

//조건이 만족하는 동안, 조건이 만족할 때와 만족하지 않을 떄 서로 다른 실행문의 실행을 반복
int main2(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(i%2==0) printf("짝수: %d\n", i);
        else printf("홀수: %d\n", i);
    }
    printf("짝수: %d개\n홀수: %d개", n/2, n/2+1);
    return 0;
}