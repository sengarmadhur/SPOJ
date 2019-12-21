#include<bits/stdc++.h>
using namespace std;
int g[2001][2001]={0,0};
int color[2001]={0};
int n;
bool isBipartite(int s)
{

    color[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(g[u][u]==1)return false;
        for(int v=1;v<=n;v++)
        {
            if(g[u][v]==1 && color[v]==-1)
            {
                color[v] = 1- color[u];
                q.push(v);
            }
            else if(g[u][v]==1 && color[u]==color[v])return false;
        }
    }

    return true;
}
int main()
{
    int t=1,j=0; //cin>>t;
    while(t--)
    {   j++;
        cout<<"Enter the number of people and relation between them\n";
        int e; cin>>n>>e;
        memset(color,-1,sizeof(color));
        memset(g,0,sizeof(g));
        cout<<"\nPUT THE RELATIONS\n";
        for(int i=0;i<e;i++)
        {
            int u,v; cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }

       int ans;
       bool flag = true;
       for(int i=1;i<=n;i++)
       {
           if(color[i]== -1)
           {
               ans = isBipartite(i);
               if(ans==0)
               {
                    flag = false;
                    break;
               }
           }
       }
        if(flag==0)
            printf("Scenario #%d:\nthere is a GAY\n",j);
        else
            printf("Scenario #%d:\nNO GAY\n",j);


    }
}
