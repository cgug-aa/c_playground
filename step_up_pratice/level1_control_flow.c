//��ϴ� ���ߴ� step_up C���α׷��� ���� LEVEL 1
//���ǹ�/�ݺ���
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//������ �����ϸ� �ݺ� ����
int main1(){
    int n;
    scanf("%d", &n);

    if((n%2)==0) for(int i=0;i<n;i++) printf("%d ", 2*i);
    else for(int i=0;i<n;i++) printf("%d ", 2*i+1);
    return 0;
}

//������ �����ϴ� ����, ������ ������ ���� �������� ���� �� ���� �ٸ� ���๮�� ������ �ݺ�
int main2(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(i%2==0) printf("¦��: %d\n", i);
        else printf("Ȧ��: %d\n", i);
    }
    printf("¦��: %d��\nȦ��: %d��", n/2, n/2+1);
    return 0;
}