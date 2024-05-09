//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//조건문
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//조건이 만족하면 실행문 실행
int main1(){
    int score;
    scanf("%d", &score);
    if(score>60) printf("통과");
    return 0;
}

//조건이 만족할 때와 만족하지 않을 때 서로 다른 실행문 실행
int main2(){
    int a,b;
    scanf("%d %d", &a, &b);
    if(a>=b) printf("%d", a);
    else printf("%d", b);
    return 0;
}

//여러 가지 조건에 따라 서로 다른 실행문 실행
int main3(){
    int score;
    scanf("%d", &score);

    if(score>85) printf("A");
    else if(score>70) printf("B");
    else if(score>50) printf("C");
    else if(score>35) printf("D");
    else if(score>20) printf("E");
    else printf("F");
    return 0;
}

//여러 가지 조건에 따라 서로 다른 실행문 실행2
int main4(){
    int score;
    scanf("%d", &score);
    if(score>=0&&score<=100){
        if(score>=90) printf("A");
        else if(score>=80) printf("B");
        else if(score>=70) printf("C");
        else if(score>=60) printf("D");
        else printf("F");
    }
    else
        printf("오류");
    return 0;
}