//��ϴ� ���ߴ� step_up C���α׷��� ��ȭ LEVEL 2
//������
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//�����͸� �̿��� �Ű����� ����
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main1(){
    int a,b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);               //�Ű������� �Ѱ��� �� &�� ���� �ּҸ� �Ѱ� �޾��ش�.
    printf("%d %d", a, b);
    return 0;
}

//������ ����
int main2(){
    int a[5]={1, 2, 3, 4, 5};
    for(int i=0;i<5;i++)
        printf("%d ", *(a+i));  //a[] �� �ƴ�  ������������ �ּҸ� ǥ���ϰ� ���� �޾ƿ� �� �ִ�.
    return 0;
}

//������ ��ȯ
int *find(int a[]){
    int min=0;
    for(int i=1;i<5;i++){
        if(a[min]>a[i])         //�迭�� �� ��ü�� ������ ����, �迭�� �ε����� ��ȯ�ϸ� ���Ѵ�.
            min=i;
    }
    return &a[min];
}
/*
int find(int a[]){
    int min=a[0];
    for(int i=1;i<5;i++)
        if(min>a[i])
            min=a[i];
    return min;
}
*/
int main3(){
    int a[5];
    int *p;                         //find�Լ����� �ּҸ� �Ѱܹޱ� ���� ������ ������ �����Ѵ�
    for(int i=0;i<5;i++) scanf("%d", &a[i]);
    p=find(a);
    printf("%d", *p);
    return 0;
}