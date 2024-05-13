//충북대 소중단 step_up C프로그래밍 심화 LEVEL 2
//구조체
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//구조체 정의, 변수 선언 및 사용
struct pos{                     //구조체의 이름과 같이 선언
  int x, y;
};
int main1(){
    struct pos p;               //구조체의 이름을 선언하고, 구조체 변수를 함께 선언해준다.
    p.x=1;
    p.y=3;
    printf("%d %d", p.x, p.y);
    return 0;
}

//구조체 변수 초기화
int main2(){
    struct pos p={1, 3};
    printf("%d %d", p.x, p.y);
    return 0;
}

//구조체 멤버 입출력
int main3(){
    struct pos p;
    scanf("%d %d", &p.x, &p.y);
    printf("%d %d", p.x, p.y);
    return 0;
}

//구조체를 함수의 매개 변수로 전달
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
    printf("%d %d", p.x, p.y);          //왜 여기선 swap의 결과가 반영되지 않을까??
    return 0;
}

//함수에서 구조체 반환
struct pos swap(struct pos p){         //구조체를 반환할땐 구조체의 이름도 함수 변수형에 포함해야 돼!
    int  tmp;
    tmp=p.x;
    p.x=p.y;
    p.y=tmp;
    return p;                          //구조체 반환에는 포인터가 따로 필요없다(구조체 자체가 주소야)
};
int main5(){
    struct pos p;
    //struct pos* pointer;
    
    scanf("%d %d", &p.x, &p.y);
    p=swap(p);
    printf("%d %d", p.x, p.y);
    return 0;
}

//구조체 배열 선언과 원소 사용
int main6(){
    struct pos parr[3];
    for(int i=0; i<3;i++)
        scanf("%d %d", &parr[i].x, &parr[i].y);
    printf("%d %d", parr[2].x, parr[2].y);
    return 0;
}

//중첩된 구조체 정의와 멤버 사용
struct Date{
    int year, month, day;
};
struct BirthDay{
    char name[10];
    //Q2)   char* name;   과 차이점이 뭘까?
    struct Date bday;
};
int main7(){
    struct BirthDay D;
    gets(D.name);
    scanf("%d %d %d", &D.bday.year, &D.bday.month, &D.bday.day);

    printf("%s\n%d %d %d\n", D.name, D.bday.year, D.bday.month, D.bday.day);
    return 0;
}

//구조체 포인터의 사용
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