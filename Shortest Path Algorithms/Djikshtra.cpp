#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j,k,w,s,t,m;
    cout<<"Enter the number of vertex"<<endl;
    cin>>n;
    int gr[n][n];
    cout<<"Enter weight of edges"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"Weight of "<<i+1<<" to "<<j+1<<" ";
            cin>>w;
            gr[i][j]=gr[j][i]=w;
        }
    }
    cout<<"Enter vertex from which shortest path is to be found."<<endl;
    cin>>s;
    t=s-1;
    int dj[n][3];
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            if(j==0)
                dj[i][j]=999;
            else
                dj[i][j]=0;
        }
    }
    dj[t][0]=0;
    for(j=0;j<n;j++){

        for(i=0;i<n;i++){
            if(gr[t][i]!=0){
                if(dj[i][0]>gr[t][i]+dj[t][0]){
                    dj[i][0]=gr[t][i]+dj[t][0];
                    dj[i][2]=t;
                }
            }
        }
    dj[t][1]=1;
    m=-1;
    for(k=0;k<n;k++){
        if(dj[k][1]!=1 && m<dj[k][0]){
            m=dj[k][0];
            t=k;
        }//cout<<t<<"*";
    }
}
cout<<endl<<"Vertex"<<"\t"<<"Cost"<<"\t"<<"Parent"<<endl;
for(i=0;i<n;i++){
        cout<<endl;
        cout<<i<<"\t";
    for(j=0;j<3;j++){
            if(j==1)
            continue;
        cout<<dj[i][j]<<" \t";
    }
}
return 0;
}
