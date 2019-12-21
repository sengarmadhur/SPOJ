#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n,vector<ll>& dp)
{
    if(n<10)return n;
    if(n<1000000)
    {
        if(dp[n]>0)return dp[n];
        else{ll ans = solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp);dp[n]=max(n,ans);
            return dp[n];}
    }
    ll y= solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp);
    return max(n,y);
}
int main()
{   ll n;
    vector<ll> dp(1000000,0);

    while(cin>>n){

           cout<<solve(n,dp) <<endl;}

}
