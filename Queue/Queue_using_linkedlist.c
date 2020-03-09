#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;
    struct queue *next;
};
struct queue *start=NULL;

void push(int x){
struct queue *insert=(struct queue*)malloc(sizeof(struct queue));
struct queue *temp=start;
insert->data=x;
insert->next=NULL;
if(start==NULL){
    start=insert;
}
     while(temp->next!=NULL){
        temp=temp->next;
     }
     temp->next=insert;
     free(temp);
}

void pop(){
    if(start==NULL){
        printf("queue is already empty\n");
    }
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp=start;
    printf("The popped element is %d\n",temp->data);
    start=start->next;
    free(temp);
}

void display(){
    struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
    temp=start;

    while(temp->next!=NULL){
        printf("%d ",temp->data);
    }
        printf("%d ",temp->data);
        free(temp);


}

int main(){
int opt,value,popped=0;
    while(opt!=4){

printf("which operation do you want to perform?\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Traverse\n");
printf("4.Exit\n");

scanf("%d",&opt);

        switch(opt){
    case 1:printf("enter the value\n");
            scanf("%d",&value);
            push(value);
            break;
    case 2: pop();
            break;
    case 3: display();
            break;
        }
}
return 0;
}
