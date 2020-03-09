#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int top=-1;
float array[25];

void push(float x){
   // printf("%c\t",x);
if(top==24){
   printf("stack overflow");}
else{
    array[++top]=x;
   // printf("%d ",array[top]);
}
}

float pop(){
    float item;
if(top==-1){
    printf("stack underflow");
}
else{
    item=array[top];
    top--;
}
//printf("%f\t",item);
return item;
}

float evaluate(char suffix[],float data[]){
int i=0;
float op1,op2,res;
char ch;

while(suffix[i]!='\0'){
        ch=suffix[i];
if(isalpha(suffix[i])){
        printf("%f ",data[i]);
    push(data[i]);
}
else{
    op2=pop();
    op1=pop();
    switch(ch){
    case '+': push(op1+op2);
              break;

    case '-': push(op1-op2);
              break;

    case '*': push(op1*op2);
              break;

    case '/': push(op1/op2);
              break;

    case '^': push(pow(op1,op2));
              break;

              }

}
i++;
}
res=pop();//printf("%d",res);
return res;
}




int main(){
char postfix[25];
int i=0;
float val[25],ans;
printf("enter postfix notation");
gets(postfix);

while(postfix[i]!='\0'){

    if(isalpha(postfix[i])){
        printf("enter value of %c",postfix[i]);
        scanf("%d",&val[i]);
        }
        i++;printf("%d ",val[i]);
}
ans=evaluate(postfix,val);
printf("\n%d",ans);
return 0;
}
