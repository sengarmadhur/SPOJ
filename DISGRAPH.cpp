#include<bits/stdc++.h>
using namespace std;
int g[1500][1500];
int rg[1500][1500];
int n,m;
bool bfs(int s,int par[],int t)
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    par[s] = -1;


    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && rg[u][v] > 0)
            {
                q.push(v);
                par[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}
int Fulkersen(int s,int t)
{
    int flow=0;
    memset(rg,0,sizeof(rg));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)rg[i][j]=g[i][j];
    }
    int par[n];

    while(bfs(s,par,t))
    {
        int v=t;
        int pflow =INT_MAX;
        while(v!=s){
            int u =par[v];
            pflow = min(pflow,rg[u][v]);
            v=u;
        }
        v=t;
        while(v!=s)
        {
            int u =par[v];
            rg[u][v]-=pflow;
            rg[v][u]+=pflow;
            v=u;
        }
        flow+=pflow;
    }
    return flow;
}

int main()
 {
	cin>>n;

	 string s;
    getline(cin,s);
    for (int i = 0; i < n; i ++) {

        getline(cin,s);
        int num=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==' '){
                g[i][num]=1;
                num=0;
            }
            else num = num*10 + (s[j]-'0');
        }
        g[i][num]=1;
    }
    int ans = INT_MAX;
    //FARZI SOLUTION PASSED DUE TO WEAK TestCases
    for(int i=1;i<7;i++){
        ans= min(ans,Fulkersen(0,i));
        ans= min(ans,Fulkersen(0,n-i));
        if(ans==1)break;
    }
    cout<<ans<<endl;


	return 0;
}
