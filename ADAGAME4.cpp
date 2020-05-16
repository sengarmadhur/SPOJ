#include<bits/stdc++.h>
using namespace std;
const int n = 20000001;
int prime[n];
int sigma[n];
void sieve()
{
     for(int i =2;i<=n;i++)
     {
         if(prime[i])continue;
         for(int j=2;j*i<=n;j++)
         {
             prime[j*i] = i;
         }
     }
     for(int i=2;i<=n;i++)
     {
         if(!prime[i])prime[i]=i;
     }
     sigma[1] = 1;
     for(int i=2;i<=n;i++)
     {
         int num = i,ct=0;
         while(num%prime[i] == 0){
            ct++;
            num/=prime[i];
         }
         sigma[i] = sigma[num]*(ct+1);
     }
}
int dp[n];
int solve(int m)
{
    if(m == 0){
        return 0;
    }
    if(dp[m] != -1)return dp[m];
    for(int i=1;i<=sigma[m];i++)
    {
        if(m-i >= 0){
            if(!solve(m-i))return dp[m]=1;
        }
    }
    return dp[m]=0;
}
int main()
{
    memset(dp,-1,sizeof(dp));

     sieve();
     solve(n-1);

     int q;
     cin>>q;
     while(q--)
     {
         int m; cin>>m;
         if(dp[m])cout<<"Ada\n";
         else cout<<"Vinit\n";
     }

}
