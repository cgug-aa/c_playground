//��ϴ� ���ߴ� step_up C���α׷��� ���� LEVEL 1
//���ǹ�

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//������ �����ϴ� ���� �ݺ� ����
int main1(){
    int a,i=1, sum=0;
    scanf("%d", &a);

    while(i<=a){
        sum+=i;
        i++;
    }
    printf("%d", sum);
    return 0;
}

//������ �����ϴ� ���� �ݺ� �����ϴٰ� Ư�� ��Ȳ�� �߻��ϸ� �ǳʶٱ�
int main2(){
    int a, b, count=0;
    scanf("%d %d", &a, &b);
    while(a<=b){
        if(a%2==0) count++;
        a++;
    }
    printf("%d", count);
    return 0;
}

//������ �����ϴ� ����(�Ǵ� ���� Ƚ��) �ݺ� ����
int main3(){
    int n;
    double factorial=1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    printf("%.lf", factorial);

    return 0;
}

//�ݺ� ���� ���� �� �ٸ� �ݺ� ������ ���� �ݺ� ����
int main4(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}