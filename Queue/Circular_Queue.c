#include <stdio.h>
#include <stdlib.h>

int rear=-1,front=-1,maxsize=5,i;
int queue[5];

void push(int x){
if(front==(rear+1)%maxsize){
    printf("queue full");
}
else{
    if(front==-1 && rear==-1)
        front=rear=0;

    else
        rear=(rear+1)%maxsize;

    queue[rear]=x;
}
}


int pop(){
    int item;
if(front==-1)
        printf("already empty");

else{
    item=queue[front];

    if(front==rear){
    front=rear=-1;
    }
    else
    front=(front+1)%maxsize;

}
return item;
}

void display(){
if(front==-1){
    printf("queue empty");
}

else{
        i=0;
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    if(front>rear){
        for(i=front;i<maxsize;i++)
            printf("%d ",queue[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",queue[i]);
    }
}
}


int main(){
int opt,value,popped=0;
    while(opt!=4){

printf("which operation do you want to perform?\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display / Traverse\n");
printf("4.Exit\n");

scanf("%d",&opt);

        switch(opt){
    case 1:printf("enter the value\n");
            scanf("%d",&value);
            push(value);
            break;
    case 2:popped=pop();
             printf("The element popped is %d\n",popped);
             break;
    case 3: display();
            break;
        }
}
return 0;
}

