//��ϴ� ���ߴ� step_up C���α׷��� �ڷᱸ�� LEVEL 4
//�ڷᱸ��
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

//����
int stack[100], top;
void push(int x){
    if(top>=SIZE-1)
        printf("\nSTACK is overflow\n");
    else{
        top++;
        stack[top]=x;
    }

}
int pop(){
    if(top<=-1)
        printf("\nSTACK is underflow");
    else{
        top--;
        return stack[top+1];
    }
}
void display(){
    if(top>=0)
        for(int i=top;i>0;i--)
            printf("%d\n", stack[i]);
    else
        printf("The STACK is empty");
}
int main_stack(){
    top=-1;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    pop();
    display();
    return 0;
}

//ť
int queue[SIZE];
int Rear=-1;
int Front=-1;
int dequeue(){
    if((Rear-Front)<0)
        printf("����÷ο�");
    else{
        Front++;
        return queue[Front-1];
    }
}
void enqueue(int x){
    if((Rear-Front)>100)
        printf("�����÷ο�.");
    else{
        if(Front==-1){
            Front++;
            Rear++;
            queue[Rear]=x;
        }
        else{
            Rear++;
            queue[Rear]=x;
        }
        
    }
}
void show(){
    int q_size=Rear-Front;
    if((q_size)<0)
        printf("ť�� ����ֽ��ϴ�");
    else{
        for(int i=Front;i<=Rear;i++){
            if(i==Rear)
                printf("%d <- Rear\n", queue[i]);
            else if(i==Front)
                printf("Front -> %d ", queue[i]);
            else
                printf("%d ", queue[i]);
            }
    }
}
int main2(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    show();
    
    dequeue();
    dequeue();
    show();
    return 0;
} 