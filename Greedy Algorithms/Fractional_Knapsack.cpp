 #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(float a[],int n){
    int ind;float m=0;
    for(int i=0;i<n;i++){
        if(a[i]>m)
        {
            m=a[i];
            ind=i;
        }
    }
    return ind;
}

int main()
{
    int n,i,j,load=0,weight,pro=0,remain,index;
    cout<<"Enter number of items."<<endl;
    cin>>n;
    cout<<"Enter total weight"<<endl;
    cin>>weight;
    float arr[n][3];float rat[n];
    for(i=0;i<n;i++){
            cout<<"for item "<<i+1<<" enter weight and volume."<<endl;
        for(j=0;j<2;j++){
            cin>>arr[i][j];
        }
       rat[i]=float(arr[i][1]/arr[i][0]);//cout<<rat[i]<<" ";
       arr[i][2]=rat[i];
    }
    cout<<endl;
    i=0;
   while(load<weight && i<n){
       index=func(rat,n);
        if(load+arr[index][0]<=weight){
            pro+=arr[index][1];
            load+=arr[index][0];
        }
        else{
            remain=weight-load;
            pro+=(remain*arr[index][1])/arr[index][0];
            load+=remain;
        }

    rat[index]=0;
    i++;
   }
   cout<<"Profit: "<<pro<<endl;
return 0;
}
