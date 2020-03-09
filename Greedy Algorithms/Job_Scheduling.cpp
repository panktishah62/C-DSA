#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,max=0,i,j;
    cout<<"Enter total number of jobs.";
    cin>>n;
    int arr[n][2];
    for(i=0;i<n;i++){
        cout<<"for job "<<i+1<<endl;
        for(j=0;j<2;j++){
            cin>>arr[i][j];
            if(arr[i][0]>max)
                max=arr[i][0];

        }
    }

    int ans[max]={0},temp,min;
    int max_ele=0,index,x=n,c=max;i=n-1;

    while(max!=0){
    max_ele=0;
    for(i=0;i<n;i++){
        if(arr[i][0]==max && arr[i][1]>max_ele){
                max_ele=arr[i][1];
                index=i;
        }
    }
    ans[max-1]=max_ele;
    arr[index][0]=0;
    for(i=0;i<n;i++){
        if(arr[i][0]==max)
            arr[i][0]=max-1;
    }
    x--;
    max--;
    }
    for(i=0;i<c;i++)
        cout<<i+1<<"  ";
    cout<<endl;
    for(i=0;i<c;i++)
        cout<<ans[i]<<"   ";
return 0;
}
