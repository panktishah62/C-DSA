#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,ele,flag=0;
printf("no. of elements in array\n");
scanf("%d",&n);
int arr[n];
printf("enter elements\n");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("enter the element to be searched\n");
scanf("%d",&ele);
for(i=0;i<n;i++){
    if(ele==arr[i]){
        printf("element found at location %d ",i+1);
        flag=1;
        break;
    }
}
if(flag==0){
    printf("element not found\n");
}

}
