//��ϴ� ���ߴ� step_up C���α׷��� ��ȭ LEVEL 2
//����ü
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//����ü ����, ���� ���� �� ���
struct pos{                     //����ü�� �̸��� ���� ����
  int x, y;
};
int main1(){
    struct pos p;               //����ü�� �̸��� �����ϰ�, ����ü ������ �Բ� �������ش�.
    p.x=1;
    p.y=3;
    printf("%d %d", p.x, p.y);
    return 0;
}

//����ü ���� �ʱ�ȭ
int main2(){
    struct pos p={1, 3};
    printf("%d %d", p.x, p.y);
    return 0;
}

//����ü ��� �����
int main3(){
    struct pos p;
    scanf("%d %d", &p.x, &p.y);
    printf("%d %d", p.x, p.y);
    return 0;
}

//����ü�� �Լ��� �Ű� ������ ����
void swap4(struct pos p){
    int  tmp;
    tmp=p.x;
    p.x=p.y;
    p.y=tmp;
    printf("%d %d\n", p.x, p.y);
};
int main4(){
    struct pos p;
    scanf("%d %d", &p.x, &p.y);
    swap4(p);
    printf("%d %d", p.x, p.y);          //�� ���⼱ swap�� ����� �ݿ����� ������??
    return 0;
}

//�Լ����� ����ü ��ȯ
struct pos swap(struct pos p){         //����ü�� ��ȯ�Ҷ� ����ü�� �̸��� �Լ� �������� �����ؾ� ��!
    int  tmp;
    tmp=p.x;
    p.x=p.y;
    p.y=tmp;
    return p;                          //����ü ��ȯ���� �����Ͱ� ���� �ʿ����(����ü ��ü�� �ּҾ�)
};
int main5(){
    struct pos p;
    //struct pos* pointer;
    
    scanf("%d %d", &p.x, &p.y);
    p=swap(p);
    printf("%d %d", p.x, p.y);
    return 0;
}

//����ü �迭 ����� ���� ���
int main6(){
    struct pos parr[3];
    for(int i=0; i<3;i++)
        scanf("%d %d", &parr[i].x, &parr[i].y);
    printf("%d %d", parr[2].x, parr[2].y);
    return 0;
}

//��ø�� ����ü ���ǿ� ��� ���
struct Date{
    int year, month, day;
};
struct BirthDay{
    char name[10];
    //Q2)   char* name;   �� �������� ����?
    struct Date bday;
};
int main7(){
    struct BirthDay D;
    gets(D.name);
    scanf("%d %d %d", &D.bday.year, &D.bday.month, &D.bday.day);

    printf("%s\n%d %d %d\n", D.name, D.bday.year, D.bday.month, D.bday.day);
    return 0;
}

//����ü �������� ���
void swap8(struct pos *p1, struct pos *p2){
    struct pos p3;
    p3=*p2;
    *p2=*p1;
    *p1=p3;
};
int main8(){
    struct pos p1, p2;
    scanf("%d %d", &p1.x, &p1.y);
    scanf("%d %d", &p2.x, &p2.y);
    swap8(&p1, &p2);
    printf("%d %d\n%d %d", p1.x, p1.y, p2.x, p2.y);
    return 0;
}