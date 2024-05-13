//충북대 소중단 step_up C프로그래밍 심화 LEVEL 2
//문자 배열 정의 및 사용
#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//문자열 선언과 초기화
int main1(){
    char str[30]="Hello World!";
    for(int i=0;i<30;i++)
        printf("%c", str[i]);
    //  =printf("%s", str)
    return 0;
}

//문자열 입출력
int main2(){
    char str[30];
    gets(str);              //gets 함수를 통해 문자열을 입력받을 수 있다.
    printf("%s", str);
    return 0;
}

//문자열 비교
int main3(){
    char str1[10], str2[10];
    gets(str1);
    gets(str2);
    if(strcmp(str1,str2)<0)     //더 작을수록 사전상 더 빨리 등장한다.
        printf("%s", str1);
    else
        printf("%s", str2);
    return 0;
}

//문자열 복사
int main4(){
    char str1[20], str2[20];
    gets(str1); gets(str2);
    printf("%s\n%s\n", str1, str2);
    for(int i=0;i<20;i++) str1[i]=str2[i];
    printf("%s\n%s\n", str1, str2);
    return 0;
}