//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//조건문

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//조건이 만족하는 동안 반복 실행
int main1(){
    int a,i=1, sum=0;
    scanf("%d", &a);

    while(i<=a){
        sum+=i;
        i++;
    }
    printf("%d", sum);
    return 0;
}

//조건이 만족하는 동안 반복 실행하다가 특정 상황이 발생하면 건너뛰기
int main2(){
    int a, b, count=0;
    scanf("%d %d", &a, &b);
    while(a<=b){
        if(a%2==0) count++;
        a++;
    }
    printf("%d", count);
    return 0;
}

//조건이 만족하는 동안(또는 일정 횟수) 반복 실행
int main3(){
    int n;
    double factorial=1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    printf("%.lf", factorial);

    return 0;
}

//반복 구조 내의 또 다른 반복 구조에 의한 반복 실행
int main4(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}