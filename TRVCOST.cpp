#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int g[501][501];
int n;
vector<int>dist(501,99999999);
void dijktra(int s)
{
    dist[s] = 0;
    priority_queue<pii>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        pii v = pq.top();
        pq.pop();
        for(int i=0;i<=500;i++)
        {
            if(g[v.second][i]==-1||v.second == i)continue;
            if(dist[i]> v.first + g[v.second][i]){
                dist[i] = v.first +g[v.second][i];
                pq.push({dist[i],i});
            }
        }
    }
}
int main()
{
     cin>>n;
     memset(g,-1,sizeof(g));
     for(int i=0;i<n;i++)
     {
         int a,b,w; cin>>a>>b>>w;
         g[a][b]=w;
         g[b][a]=w;
     }
     int src; cin>>src;
     dijktra(src);
     int q; cin>>q;
     while(q--)
     {

         int d; cin>>d;
         if(dist[d]<99999999)cout<<dist[d]<<endl;
         else cout<<"NO PATH\n";
     }
}
