//��ϴ� ���ߴ� step_up C���α׷��� ��ȭ LEVEL 2
//�迭 ���� �� ���
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2���� �迭 ����� �迭 ���� ���
int main1(){
    int a[5][5];
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=0;
    }
    printf("%d", a[4][4]);
    return 0;
}

//2���� �迭 �ʱ�ȭ
int main2(){
    int a[5][5];                //={7}; �̷��� �����ϸ� ù��° �ε����� �ʱ�ȭ��.
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=7;          //c�� �迭�� �ϳ��� ��������� ��.
    }
    printf("%d", a[4][4]);
    return 0;
}

//2���� �迭 ������ �����
int main3(){
    int num, a[5][5];
    scanf("%d", &num);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a[i][j]=num;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//2���� �迭�� �Լ� �Ű������� ����
void sum(int a[][5]){
/*�Ű������� �ε����� �ٸ� ����
: 2���� �迭�� �޸� �󿡼� ���ӵ� ����� �����ϱ� ������
 �ּҸ� �˰� �ִٸ� ���� ũ�⸸���ε� �迭�� ��ҿ� ������ �� �ִ�.
 ���� �Լ��� �迭�� ���� ���� ���� �ַ� ���� ũ�⸸�� ����Ͽ�
 ���� ũ�⸦ �̸� ���� ���ص� �迭�� ��ҿ� ������ �� �ִ�.
*/
    int res=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            res+=a[i][j];
        }
    }
    printf("%d", res);
}
int main4(){
    int a[5][5], num;
    scanf("%d", &num);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=num;
    }
    sum(a);
    return 0;
}