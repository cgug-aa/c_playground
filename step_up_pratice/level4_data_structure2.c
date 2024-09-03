//��ϴ� ���ߴ� step_up C���α׷��� �ڷᱸ�� LEVEL 4
//�ڷᱸ��
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//���Ḯ��Ʈ�� �̿��Ͽ� ���� ����
#include<stdlib.h>
typedef struct node{
    int data;                   //����� ������
    struct node* next;          //���� ����� �ּҸ� ���´�.
}stack_s;
stack_s *top_s=NULL;                //������ ž�� �ּҴ� �ΰ��� ���´�.

void push_s(int data){
    stack_s *new_node=(stack_s*)malloc(sizeof(stack_s));
    //���ο� ���� �����ʹ� ������ ũ�⸸ŭ �����Ҵ��� �޴´�?
    if(new_node=NULL){
        printf("������ ���� ����");
        exit(1);        //�Լ��� �����Ե�.
    }

    new_node->data=data;        //new_node�� �ּ������͸� ���� �����͸� �־��ش�.
    new_node->next=top_s;         //���� ����� �ּҴ� top�� ����Ű�� �Ѵ�.
    top_s=new_node;               //new_node�� ž���� �������ش�.
}
int pop_s(){
    stack_s *del;                 //������ ����� �ּ�
    int value;
    if(top_s==NULL){
        printf("������ ����ִ�.");
        exit(1);
    }
    value=top_s->data;
    del=top_s;
    top_s=top_s->next;              //Q3 top�� ����������, top������ ��尡 top�� �Ǿ�ߵǴ°� �ƴ�?
                                //�̷��� �Ǹ�, top�� ���� ��尡 top�� �Ǵ°� �ƴѰ�
    free(del);                  //������ ����� �޸𸮸� ������Ŵ
    return value;
}
void print_s(){
    stack_s *i;                   //����� ����� �����ͺ���
    stack_s *count=top_s;           //���� ���� ���
    i=count;                    //����� ���� top�� ����

    while(i!=NULL){             //top�� NULL���� �ƴҶ� �ݺ�
        printf("%d\n", i->data);//����� ����� ������ ���
        i=count->next;           //
        count=count->next;
    }
    printf("\n");
}
int main1(){
    push_s(1);
    push_s(2);
    push_s(3);
    push_s(4);
    push_s(5);
    print_s();

    pop_s();
    pop_s();
    print_s();
    return 0;
}

struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int value){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    if((front==NULL)&&(rear==NULL)){
        front=rear=new_node;
    }
    else{
        rear->next=new_node;        //���� ������ �� rear�� ���� ��带 �Է��� ���� �ϰ�
        rear=new_node;              //���� ���� �� ���� ��带 ���ο� rear�� �����.
    }
}
int dequeue(){
    int value;
    struct node *del;
    
    if(front==NULL){
        printf("ť�� ����ֽ��ϴ�.");
        exit(1);
    }
    value=front->data;
    del=front;
    front=front->next;
    free(del);
    return value;
  
}
void display(){
    struct node * temp;
    if((front == NULL)&&(rear == NULL))
        printf("\nQueue is Empty\n");
    else{
        temp=front;
        while(temp){
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    dequeue();
    dequeue();
    display();
    return 0;
}

