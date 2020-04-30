#include<bits/stdc++.h>
#define pii pair<int,int>
#define double long double
using namespace std;
//answer will always 0 for higher n
int main()
{
    int t; cin>>t;
    double dp[3001][3001];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    for(int i=1;i<=3000;i++){
        for(int j=1;j<=3000;j++){
            double ans = 0;
            for(int m=1;m<=6;m++){
                if(j-m>=0)ans+=dp[i-1][j-m];
            }
            dp[i][j]=ans/6.0;
        }
    }

    while(t--){

       int n,k; cin>>n>>k;
       if(n>3000 || k>3000){cout<<0<<endl; continue;}
       int res = 100*dp[n][k];
       cout<<res<<endl;
    }
}
