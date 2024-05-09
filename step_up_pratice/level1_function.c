//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//함수 정의 및 사용
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//함수 작성과 호출
void hello_world(){
    printf("Hello World");
}
int main1(){
    hello_world();
    return 0;
}

//함수의 값 반환
double factorial_2(int n){
    double res=1;
    for(int i=1;i<=n;i++)
        res*=i;
    return res;
}
int main2(){
    int n;
    scanf("%d", &n);
    printf("%.lf", factorial_2(n));
    return 0;
}

//함수의 인자 사용
int add(int a, int b){
    return a+b;
}
int main3(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", add(a, b));
    return 0;
}
 
//재귀함수
double factorial(int n){
    if(n<1) return 1;
    else return n*factorial(n-1);
}
int main4(){
    int n;
    scanf("%d", &n);
    printf("%.lf", factorial(n));
    return 0;
}