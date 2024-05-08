#include<stdio.h>
#define _CRT_SECURE_NO_WARNING

int main1(){
    float a;

    scanf("%f", &a);
    printf("%.1f", a);

    return 0;
}

int main2(){
    double pi=3.14;
    int r;
    double cir;

    scanf("%d", &r);
    cir=2*r*pi;
    printf("%f", cir);

    return 0;
}

int main3(){
    double area, pi=3.14;
    int r;

    scanf("%d", &r);
    area=pi*r*r;
    printf("%.2f", area);

    return 0;
}