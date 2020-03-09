#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    string msg;
    cout<<"Enter the the message"<<endl;
    cin>>msg;

    sort(msg.begin(),msg.end());
    cout<<endl<<msg<<endl;
    int cnt=0,c=0,i,j,m=0;

    for(i=0;i<msg.size();i++){
       if(msg[i]!=msg[i+1])
        cnt++;
    }

    char ac[cnt];
    int af[cnt],k=-1;
     for(i=0;i<msg.size();i++){
       if(msg[i]!=msg[i+1]){
        ac[++k]=msg[i];
        af[k]=c+1;
        c=0;
       }
        else
            c++;
    }

    //SORTING
    int temp;
    char t;
    for(i=0;i<cnt-1;i++){
            m=i;
        for(j=i+1;j<cnt;j++)
          if(af[j]<af[m])
            m=j;
            temp=af[i];
            af[i]=af[m];
            af[m]=temp;
            t=ac[i];
            ac[i]=ac[m];
            ac[m]=t;
    }

    int arr[cnt-1];k=cnt-1;
    arr[0]=af[0];
    int l=2,co=cnt-2,bits;

    for(i=0;i<cnt;i++){
            m=0,j=0;

           if(i!=0 && i!=1)
              co=cnt-(++l);
            bits+=af[i]*(co+1);
    }
    cout<<"bits required for the above message : "<<bits<<endl;

return 0;
}
