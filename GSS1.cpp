#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#define int long long int
using namespace std;
int getsum(int *st,int qs,int qe,int ss,int se,int curr)
{
    if(qs<=ss && qe>=se)
    {
        return st[curr];
    }
    if(qe< ss || qs>se)return 0;
    int mid = ss + ((se-ss)/2);
    int p1= getsum(st,qs,qe,ss,mid,curr*2+1);
    int p2=getsum(st,qs,qe,mid+1,se,curr*2+2);
    if(p1>p2)return p1;
    return p1;
}
int construct(int *ST,int arr[],int start,int end,int curr)
{
    if(start==end){
        ST[curr] = arr[start];
        return arr[start];
    }
    int mid = start + ((end-start)/2);
    ST[curr] = construct(ST,arr,start,mid,curr*2+1)+construct(ST,arr,mid+1,end,curr*2+2);
    return ST[curr];
}
int *constructST(int arr[],int n)
{
    int *ST;
    int x = ceil(log2(n));
    int sz = 2*(int)pow(2,x)-1;
    ST =new int[sz];
    construct(ST,arr,0,n-1,0);
    return ST;
}
int32_t main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int *sgt = constructST(arr,n);
    int m; cin>>m;
    while(m--)
    {
        int x,y;cin>>x>>y;
        int ans = -999999;
        ans = max(ans,getsum(sgt,x-1,y-1,0,n-1,0));
        cout<<ans<<endl;
    }
}

