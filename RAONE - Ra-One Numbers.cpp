#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#define int long long int
using namespace std;
vector<int>num;
int dp[10][50][50][2][2];
int F(int pos,int even,int odd,int tight,int start)
{
    if(pos == num.size())
    {
        return (even-odd)==1;
    }
    if(dp[pos][even][odd][tight][start]!=-1)return dp[pos][even][odd][tight][start];
    int res = 0;
    int k;
    if(tight==0)k=num[pos];
    else k=9;
    for(int i=0;i<=k;i++)
    {

        int ns= (start||(i>0));
        if(ns)
        {
            if((num.size()-pos-1)%2==1)
            {
                    res+=F(pos+1,even+i,odd,tight||i<k,1);
            }
            else{
                res+=F(pos+1,even,odd+i,tight||i<k,1);
            }
        }
        else{
            res+=F(pos+1,even,odd,tight||i<k,0);
        }
    }
     dp[pos][even][odd][tight][start]=res;
     return res;
}
int Fill(int n)
{
    if(n<=0)return 0;
    memset(dp,-1,sizeof(dp));
    num.clear();
    while(n)
    {
        num.push_back(n%10);n/=10;
    }
    reverse(num.begin(),num.end());
    return F(0,0,0,0,0);
}
int32_t main()
{
    int t; cin>>t;
    while(t--)
    {
        int a,b; cin>>a>>b;
        cout<<Fill(b)-Fill(a-1)<<endl;
    }
}
