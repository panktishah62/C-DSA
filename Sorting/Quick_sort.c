#include <stdio.h>
#include <stdlib.h>

void Quicksort(int a[],int l,int h){
int low,high,key,temp;
key=a[(low+high)/2];
do{
    while(a[low]<key)
        low++;
    while(a[high]>key)
        high++;

    if(low<=high){
        temp=a[low];
        a[low++]=a[high];
        a[high--]=a[low];
    }
}
while(low<=high);
if(l<high)
    Quicksort(a,l,high);
if(low<h)
    Quicksort(a,low,h);
}
int main(){
int n,i,l,h;
printf("no. of elements in array\n");
scanf("%d",&n);
int arr[n];
l=0;
h=n-1;

printf("enter %d elements\n",n);
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
Quicksort(arr,l,h);

for(i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}

