//충북대 소중단 step_up C프로그래밍 자료구조 LEVEL 4
//자료구조
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//연결리스트를 이용하여 스택 구현
#include<stdlib.h>
typedef struct node{
    int data;                   //노드의 데이터
    struct node* next;          //다음 노드의 주소를 갖는다.
}stack_s;
stack_s *top_s=NULL;                //스택의 탑의 주소는 널값을 갖는다.

void push_s(int data){
    stack_s *new_node=(stack_s*)malloc(sizeof(stack_s));
    //새로운 스택 포인터는 스택의 크기만큼 동적할당을 받는다?
    if(new_node=NULL){
        printf("스택이 가득 차다");
        exit(1);        //함수를 나가게됨.
    }

    new_node->data=data;        //new_node의 주소포인터를 통해 데이터를 넣어준다.
    new_node->next=top_s;         //다음 노드의 주소는 top을 가리키게 한다.
    top_s=new_node;               //new_node를 탑으로 선언해준다.
}
int pop_s(){
    stack_s *del;                 //삭제할 노드의 주소
    int value;
    if(top_s==NULL){
        printf("스택이 비어있다.");
        exit(1);
    }
    value=top_s->data;
    del=top_s;
    top_s=top_s->next;              //Q3 top을 삭제했으면, top이전의 노드가 top이 되어야되는거 아님?
                                //이렇게 되면, top의 다음 노드가 top이 되는게 아닌가
    free(del);                  //삭제할 노드의 메모리를 해제시킴
    return value;
}
void print_s(){
    stack_s *i;                   //출력할 노드의 포인터변수
    stack_s *count=top_s;           //가장 상위 노드
    i=count;                    //출력할 노드로 top을 지정

    while(i!=NULL){             //top이 NULL값이 아닐때 반복
        printf("%d\n", i->data);//출력할 노드의 데이터 출력
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
        rear->next=new_node;        //값이 들어오긴 전 rear의 다음 노드를 입력한 노드로 하고
        rear=new_node;              //값이 들어온 후 들어온 노드를 새로운 rear로 만든다.
    }
}
int dequeue(){
    int value;
    struct node *del;
    
    if(front==NULL){
        printf("큐가 비어있습니다.");
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

