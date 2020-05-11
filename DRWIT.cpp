//EULER PATH
#include<bits/stdc++.h>
using namespace std;
const int N = 200;

int deg[200],vis[200];
vector<int>adj[200];

void dfs(int s)
{
    vis[s]=1;
    for(int j:adj[s])
    {
        if(!vis[j])dfs(j);
    }
}

int main()
{
        int t; cin>>t;
        while(t--)
        {
            int n; cin>>n;
            for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0,deg[i]=0;

            int k; cin>>k;
            while(k--)
            {
                int a,b,c; cin>>a>>b>>c;
                adj[a].push_back(b);
                adj[b].push_back(a);
                deg[a]+=c;
                deg[b]+=c;
            }
            dfs(1);
            bool flag =true;
            for(int i=1;i<=n;i++){
                if(!vis[i]){flag=0;break;}
            }
            if(!flag){ cout << "NO" << endl; continue;}

            int odd = 0;
            for(int i=1;i<=n;i++){
                if(deg[i]%2)odd++;
            }
            if(odd>2){ cout << "NO" << endl;}
            else if(odd == 1||odd ==2){
                int res;
                for( res=1;res<=n;res++){
                    if(deg[res]%2)break;
                }
                 cout << "YES " << res << endl;
            }
            else cout << "YES " << 1 << endl;
        }
}
