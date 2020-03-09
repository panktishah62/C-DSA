#include <stdio.h>
#include <stdlib.h>

struct rec{
	int data;
	struct rec *lchild;
	struct rec *rchild;
};

struct rec *tree=NULL;
int count=0;

struct rec* insert(struct rec* tree,int digit){
 struct rec* newNode;
      newNode = (struct rec*) malloc(sizeof(struct rec));

      if (newNode==NULL){
               perror("malloc");
                exit(1);
}
      newNode-> data = digit;
      newNode-> lchild= NULL;
      newNode-> rchild= NULL;

    if (tree== NULL){
    tree= newNode;
    count++;
    }


else{
if(count%2==0)
tree->rchild=insert(tree->rchild,digit);

else
tree->lchild=insert(tree->lchild,digit);

}
return tree;
}

void preorder(struct rec *ro){
if(ro==NULL)
return;
	printf(" %d\n ",ro->data);
	preorder(ro->lchild);
	preorder(ro->rchild);

}

void postorder(struct rec *ro){
if(ro==NULL)
return;
	postorder(ro->lchild);
	postorder(ro->rchild);
	printf(" %d\n ",ro->data);

}



void inorder(struct rec *ro){
if(ro==NULL)
return;
	inorder(ro->lchild);
	printf(" %d\n ",ro->data);
	inorder(ro->rchild);


}

int main(){
int choice=0,ele;
while(choice!=5){
printf("1.INSERT ELEMENT\n");
printf("2.PREORDER TRAVERSAL\n");
printf("3.POSTORDER TRAVERSAL\n");
printf("4.INORDER TRAVERSAL\n");
printf("5.END\n");

scanf("%d",&choice);

if(choice==1){
printf("enter element\n");
scanf("%d",&ele);
tree=insert(tree,ele);
}

else if(choice==2){
preorder(tree);
}

else if(choice==3){
postorder(tree);
}

else if(choice==4){
inorder(tree);
}

}
return 0;

}























