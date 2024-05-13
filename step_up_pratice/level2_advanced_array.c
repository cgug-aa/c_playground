//충북대 소중단 step_up C프로그래밍 심화 LEVEL 2
//배열 정의 및 사용
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//2차원 배열 선언과 배열 원소 사용
int main1(){
    int a[5][5];
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=0;
    }
    printf("%d", a[4][4]);
    return 0;
}

//2차원 배열 초기화
int main2(){
    int a[5][5];                //={7}; 이렇게 선언하면 첫번째 인덱스만 초기화됨.
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j]=7;          //c는 배열을 하나씩 선언해줘야 돼.
    }
    printf("%d", a[4][4]);
    return 0;
}

//2차원 배열 원소의 입출력
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

//2차원 배열을 함수 매개변수로 전달
void sum(int a[][5]){
/*매개변수의 인덱스가 다른 이유
: 2차원 배열은 메모리 상에서 연속된 블록을 형성하기 때문에
 주소를 알고 있다면 열의 크기만으로도 배열의 요소에 접근할 수 있다.
 따라서 함수가 배열을 전달 받을 때는 주로 열의 크기만을 명시하여
 행의 크기를 미리 알지 못해도 배열의 요소에 접근할 수 있다.
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