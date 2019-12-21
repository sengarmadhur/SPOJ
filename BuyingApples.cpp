#include<bits/stdc++.h>
using namespace std;

int main()
{
        int t; cin>>t;
        while(t--)
        {
            int n,k; cin>>n>>k;
            int v[k+1];
            memset(v,-1,sizeof(v));
            for(int i=1;i<=k;i++)cin>>v[i];
            int dp[k+1];dp[0]=0;
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=k;i++)
            {   int minn =999999;
                for(int j=1;j<=i;j++)
                {
                   if(v[j]>-1)
                   {
                       minn = min(minn, v[j]+dp[i-j]);

                   }

                } dp[i] =minn;
            }
            /*  for(int i=1;i<=k;i++)
            {
                for(int j=1;j<=k;j++)
                {
                 cout<<dp[i][j]<<" ";
                }cout<<endl;
            }*/
            if(dp[k]!=999999)cout<<dp[k]<<endl;
            else cout<<-1<<endl;
        }
}
