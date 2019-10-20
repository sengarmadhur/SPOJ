#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int LIS(pii p[],int n)
{
	int dp[n];
	dp[0]=1;
	for(int i=1;i<n;i++)
	{	dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(p[i].second>=p[j].second)dp[i]= max(dp[i],1+dp[j]);
		}
	}
	int ans =-1;
	for(int i=0;i<n;i++)ans = max(ans,dp[i]);
	return ans;
}
int main() {
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		pii p[n];
		for(int i=0;i<n;i++)p[i] = {a[i],b[i]};
		sort(p,p+n,[](pii x,pii y){
			if(y.first>x.first)return true;
			if(y.first == x.first) return y.second>x.second;
			else return false;
		});
		//for(int i=0;i<n;i++)cout<<"("<<p[i].first<<" "<<p[i].second<<")"<<" ";
		cout<<LIS(p,n)<<endl;
	}
	return 0;
}
