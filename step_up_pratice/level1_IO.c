//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//입출력

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main1(){                     //자료형에 따른 데이터 입력       
    int a;
    double b;
    char c;

    scanf("%d %lf %c", &a, &b, &c);

    printf("%d\n%.2lf\n%c", a, b, c);
    return 0;
}

int main2(){                    //출력_자료형에 따른 데이터 출력
    char a;
    float b;

    scanf("%c", &a);
    b=a;
    printf("\n%d\n%c\n%.2f", b, b, b);
    return 0;
}
//문자를 문자, 정수형으로 출력하는 것은 가능하지만, 실수형으로는 불가능
//실수는 실수형만 가능