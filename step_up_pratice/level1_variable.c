//충북대 소중단 step_up C프로그래밍 기초 LEVEL 1
//변수의 선언과 사용
#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main1(){            //입력받은 소수 출력하기
    float a;

    scanf("%f", &a);
    printf("%.1f", a);

    return 0;
}

int main2(){            //입력받은 정수의 길이를 반지름으로 갖는 원의 둘레 구하기
    double pi=3.14;
    int r;
    double cir;

    scanf("%d", &r);
    cir=2*r*pi;
    printf("%f", cir);

    return 0;
}

int main3(){            //입력받은 정수의 길이를 반지름으로 갖는 원의 넓이 구하기
    double area, pi=3.14;
    int r;

    scanf("%d", &r);
    area=pi*r*r;
    printf("%.2f", area);

    return 0;
}