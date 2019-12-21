//MS
#include<iostream>
#include<string.h>
#include<algorithm>
#define int long long int
using namespace std;
int32_t main(){
int t=1;//cin>>t;
while(t--){
    cout<<"MADHUR SENGAR\n";
    int n;cin>>n;
    int f[100000];
    cout<<"FACTORIAL OF 1000000 is\n";
    memset(f,0,sizeof(f));
    f[0]=1;
    int sz=1;
    for(int i=2;i<=n;i++){
        int carry=0;
        for(int j=0;j<sz;j++){
            int temp =f[j]*i+carry;
            f[j]=temp%10;
            carry=temp/10;
        }
        while(carry){
            f[sz++]=carry%10;
            carry/=10;
        }
    }
    for(int i=sz-1;i>=0;i--)cout<<f[i];
    cout<<endl;}
}
