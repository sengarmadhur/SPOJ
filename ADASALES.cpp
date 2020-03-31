#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[100005];
int n;
vector<int>g[100005];
ll out[100005],in[100005];
void dfs_in(int child,int par)
{
    for(int v:g[child])
    {
        if(v == par)continue;
        dfs_in(v,child);
        in[child] = max(in[v]+max(0LL,a[v]-a[child]),in[child]);
    }

}

void dfs_out(int child,int par)
{
    ll mx1=-1,mx2=-1;
    for(int v:g[child])
    {
        if(v == par)continue;
        if(in[v] + max(a[v]-a[child],0LL)>mx1){mx2=mx1,mx1= in[v] + max(0LL,a[v]-a[child]);}
        else if(in[v] + max(0LL,a[v]-a[child])>mx2){mx2= in[v]+ max(0LL,a[v]-a[child]);}
    }
    ll use=0;
    for(int v:g[child])
    {
        if(v == par)continue;
        use = in[v] + max(0LL,a[v] - a[child]);
        if(use!= mx1){out[v] = max(out[child],mx1)+ max(0LL,a[child]-a[v]);}
        else{
            out[v] = max(out[child],mx2) + max(0LL,a[child]-a[v]);
        }
        dfs_out(v,child);

    }
}
int main()
{
    int q; cin>>n>>q;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        g[u+1].push_back(v+1);
        g[v+1].push_back(u+1);
    }
    dfs_in(1,0);
    dfs_out(1,0);
    /*for(int i=1;i<=n;i++)cout<<in[i]<<" ";
	cout<<endl;
	for(int j=1;j<=n;j++)cout<<out[j]<<" ";
	cout<<endl;*/
    while(q--)
    {
        int x; cin>>x;
        cout<<max(out[x+1],in[x+1])<<endl;
    }


}
