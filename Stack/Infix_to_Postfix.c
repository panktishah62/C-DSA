#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1;
char array[25];

void push(char x){
if(top==24){
   printf("stack overflow");}
else{
    array[++top]=x;
}
}

char pop(){
    char item;
if(top==-1){
    printf("stack underflow");
}
else{
    item=array[top];
    top--;
}
return item;
}

int preced(char ch){
if(ch==47)// divide /
    return 5;
else if(ch==42)//multiply *
    return 4;
else if(ch==43)//addition +
    return 3;
else if(ch==45)//subtraction -
    return 3;
    else if(ch==35)//hash #
        return 1;
}

void in_to_post(char infix[]){
int length;
static int index=0,pos=0;
char symbol,temp;
char postfix[25];
length=strlen(infix);
push('#');

while(index<length){
    symbol=infix[index];
    switch(symbol){
    case '(': push(symbol);
              break;

    case ')': temp=pop();
              while(temp!='('){
                        postfix[pos]=temp;
                        pos++;
                        temp=pop();
                    }
              break;

    case '+':
    case '-':
    case '/':
    case '*':
        while(preced(array[top])>=preced(symbol)){
            temp=pop();
            postfix[pos]=temp;
            pos++;
        }
        push(symbol);
        break;

    default: postfix[pos++]=symbol;
             break;

    }
    index++;

}
while(top>0){
    temp=pop();
    postfix[pos++]=temp;
}

postfix[pos++]='\0';
puts(postfix);

}



int main(){
char infix[25];
printf("enter infix notation\n");
gets(infix);
in_to_post(infix);
return 0;
}
