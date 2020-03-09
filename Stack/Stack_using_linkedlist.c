#include <stdio.h>
#include <stdlib.h>

struct stack{
int data;
struct stack *next;
};
struct stack *start=NULL;

void push(int x){
struct stack *insert=(struct stack*)malloc(sizeof(struct stack));
insert->data=x;
insert->next=start;
start=insert;
}

void pop(){
    if(start==NULL){
        printf("stack is already empty\n");
    }
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    temp=start;
    printf("The popped element is %d\n",temp->data);
    start=start->next;
    free(temp);
}

void display(){
    struct stack *trav=(struct stack*)malloc(sizeof(struct stack));
    trav=start;
    while(trav!=NULL){
        printf("%d\t",trav->data);
        trav=trav->next;
    }
    printf("\n");
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
