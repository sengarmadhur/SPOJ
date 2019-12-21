#include<iostream>
#include<cmath>
#include<set>
#include<map>
#define ll long long int
using namespace std;
map<int,int>s;
void precompute()
{  s[1]=1;int pos=1;
    for(int i=2;i<=1000000;i++)
    {   bool flag =true;
        for(int j=2;j<101 && j*j*j<=i;j++)
        {
            if(i%(j*j*j)==0){flag =false; break;}
        }
        if(flag)s[i]=++pos;
    }
}
int main()
{
    precompute();
   int t=0,T; cin>>T;
   while(t^T){
    t++;
    int n; cin>>n;
    if(s.find(n)!=s.end()){
        cout<<"Case "<<t<<": "<<s[n]<<endl;
    }
    else{
        cout<<"Case "<<t<<": Not Cube Free"<<endl;
    }
   }
}
