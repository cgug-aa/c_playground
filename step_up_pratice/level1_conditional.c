//��ϴ� ���ߴ� step_up C���α׷��� ���� LEVEL 1
//���ǹ�
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//������ �����ϸ� ���๮ ����
int main1(){
    int score;
    scanf("%d", &score);
    if(score>60) printf("���");
    return 0;
}

//������ ������ ���� �������� ���� �� ���� �ٸ� ���๮ ����
int main2(){
    int a,b;
    scanf("%d %d", &a, &b);
    if(a>=b) printf("%d", a);
    else printf("%d", b);
    return 0;
}

//���� ���� ���ǿ� ���� ���� �ٸ� ���๮ ����
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

//���� ���� ���ǿ� ���� ���� �ٸ� ���๮ ����2
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
        printf("����");
    return 0;
}