#include <stdio.h>
#include <stdlib.h>

struct bst{
    int data;
    struct bst *rchild;
    struct bst *lchild;
    };
    struct bst *tree=NULL;

struct bst* insert(struct bst *tree,int digit){
    struct bst *ins,*temp;
    temp=tree;
    ins=(struct bst*)malloc(sizeof(struct bst));
    ins->data=digit;
    ins->rchild=NULL;
    ins->lchild=NULL;

    if(tree==NULL){
        tree=ins;
        return tree;
    }
    temp=tree;
    while(1){
        if(digit<temp->data){
            if(temp->lchild==NULL){
                temp->lchild=ins;
                break;
                }
            else
                temp=temp->lchild;
        }

            else if(digit>temp->data){
                if(temp->rchild==NULL){
                    temp->rchild=ins;
                    break;
                }

                else
                    temp=temp->rchild;
            }

            else{
                printf("duplicate node !!!!\n");
                break;
            }



    }
    return tree;

}

void traverse(struct bst *ro){
    if(ro==NULL)
        return ;
    traverse(ro->lchild);
    printf("%d\t",ro->data);
    traverse(ro->rchild);
    }

int getmax(int a,int b){
return(a>b)?a:b;
}

int get_height(struct bst *tree){
    int count=0,count1=0,count2=0;


    if(tree==NULL){
        count=0;
    }


 else{
    count1=1+get_height(tree->lchild);
    count2=1+get_height(tree->rchild);
    count=getmax(count1,count2);
    }
    return count;
}

int cnt=0;
int count_nodes(struct bst *tree){
    if(tree==NULL)
        return cnt;
   cnt++;
   count_nodes(tree->lchild);
   count_nodes(tree->rchild);
}


int main(){
int choice=0,ele;
while(choice!=5){
printf("1.INSERT ELEMENT\n");
printf("2.TRAVERSAL\n");
printf("3.GET HEIGHT\n");
printf("4.COUNT NODES\n");
printf("5.END\n");

scanf("%d",&choice);

if(choice==1){
printf("enter element\n");
scanf("%d",&ele);
tree=insert(tree,ele);
}

else if(choice==2){
traverse(tree);
printf("\n");
}

else if(choice==3){
int x=get_height(tree);
printf("height is %d\n\n",x);
}

else if(choice==4){
int y=count_nodes(tree);
printf("Number of nodes is %d\n\n",y);
}

}
return 0;

}

