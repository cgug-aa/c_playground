//��ϴ� ���ߴ� step_up C���α׷��� ���� LEVEL 1
//�迭
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//1���� �迭 ����� �迭 ���� ���
int main1(){
    int a[5]={0, 0, 0, 0, 0};
    printf("%d", a[4]);
    return 0;
}

//1���� �迭 �ʱ�ȭ
int main2(){
    int a[5];
    for(int i=0;i<5;i++) a[i]=7;
    printf("%d", a[4]);
    return 0;
}

//1���� �迭 ������ �����
int main3(){
    int a[5];
    for(int i=0;i<5;i++)
        scanf("%d", &a[i]);
    for(int i=4;i>=0;i--)
        printf("%d ", a[i]);
    return 0;
}

//1���� �迭�� �Լ� �Ű������� ����
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