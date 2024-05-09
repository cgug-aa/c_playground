//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//수식
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main1(){                 //산술 연산자를 이용한 수식 표현
    int a,b;
    scanf("%d %d", &a, &b);
    printf("\n%d+%d=%d\n", a, b, a+b);
    printf("%d-%d=%d\n", a, b, a-b);
    printf("%d*%d=%d\n", a, b, a*b);
    printf("%d/%d=%d\n", a, b, a/b);
    printf("%d%%%d=%d\n", a, b, a%b);
    return 0;
}
//1. 서식문자 활용하여 printf("%c", '%')를 통해 출력 가능.
//2. %%를 통해 %를 출력할 수 있다 

int main2(){                  //연산자 우선순위를 고려한 다항식 계산
    int a, b, x;
    double result;
    printf("a와 b, x를 입력하세요:");
    scanf("%d %d %d", &a, &b, &x);
    result=(a*x*x*x-b*x*x+a*x-b)*(a+b);
    printf("\n다항식의 결과는 %.2lf입니다.", result);
    return 0;
}