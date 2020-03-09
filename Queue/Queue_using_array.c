#include <stdio.h>
#include <stdlib.h>

int rear=-1,front=-1,maxsize=10;
int queue[10];

void push(int x){
if(rear==maxsize-1){
    printf("queue full");
}
else{
    queue[++rear]=x;
    if(front==-1)
        front=0;
}
}

int pop(){
    int item;
if(front==-1)
        printf("already empty");

else{
    if(front==rear){
    front=rear=-1;
}
else{
   item=queue[front];
   front++;
}
}
return item;
}

void display(){
for(int i=front;i<=rear;i++){
    printf("%d ",queue[i]);
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

