#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int vis[800001];
vector<int>adj[800001];
void dfs(int x)
{
    if(vis[x])return;
    vis[x]=1;
    for(int z:adj[x])
    {
        dfs(z);
    }
}

int main()
{

    int n,m; scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)vis[i]=0;
    for(int j=0;j<m;j++)
    {
        int x,y; scanf("%d%d",&x,&y);
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            ans++;dfs(i);
        }
    }
    ans--;
    printf("%d",ans);


}
