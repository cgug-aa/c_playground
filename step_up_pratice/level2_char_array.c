//��ϴ� ���ߴ� step_up C���α׷��� ��ȭ LEVEL 2
//���� �迭 ���� �� ���
#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//���ڿ� ����� �ʱ�ȭ
int main1(){
    char str[30]="Hello World!";
    for(int i=0;i<30;i++)
        printf("%c", str[i]);
    //  =printf("%s", str)
    return 0;
}

//���ڿ� �����
int main2(){
    char str[30];
    gets(str);              //gets �Լ��� ���� ���ڿ��� �Է¹��� �� �ִ�.
    printf("%s", str);
    return 0;
}

//���ڿ� ��
int main3(){
    char str1[10], str2[10];
    gets(str1);
    gets(str2);
    if(strcmp(str1,str2)<0)     //�� �������� ������ �� ���� �����Ѵ�.
        printf("%s", str1);
    else
        printf("%s", str2);
    return 0;
}

//���ڿ� ����
int main4(){
    char str1[20], str2[20];
    gets(str1); gets(str2);
    printf("%s\n%s\n", str1, str2);
    for(int i=0;i<20;i++) str1[i]=str2[i];
    printf("%s\n%s\n", str1, str2);
    return 0;
}