#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
//precomputation(using bfs) shortest distance of every cell from each dirty cell dist[MAXN][MAXM][total_houses]
//visiting remaining unvisited house from particular house trying all possibilities

int dist[21][21][12];
int dp[12][1<<12];
char grid[21][21];
int n,m,MK;
vector<pii>houses;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
bool safe(int i,int j)
{
    if(i<0||j<0||i>=n||j>=m||grid[i][j]=='x')return 0;
    return 1;
}
void bfs(int h)
{   int vis[n][m];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)dist[i][j][h] = 9999;
    }
    pii start = houses[h];
    queue<pii>q;
    q.push(start);
    vis[start.first][start.second]=1;
    dist[start.first][start.second][h]=0;
    while(!q.empty())
    {
        pii cell = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x = cell.first+dx[i];
            int y =cell.second+dy[i];
            if(safe(x,y)){
                if(vis[x][y]==0){
                    vis[x][y]=1;
                    q.push({x,y});
                    dist[x][y][h] = 1 +dist[cell.first][cell.second][h];
                }
            }
        }
    }
}
void precompute()
{
    memset(dp,-1,sizeof(dp));
    houses.clear();
    pii start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '*'){
                houses.push_back({i,j});

            }
            else if(grid[i][j]=='o')start = {i,j};
        }
    }

    houses.insert(houses.begin(),start);
    MK = (1<<(houses.size()))-1;
    for(int i=0;i<houses.size();i++)bfs(i);
}

int Find(int h,int mask)
{
    if(mask==MK)return 0;
    if(dp[h][mask]!=-1)return dp[h][mask];
    int ans= INT_MAX;
    for(int i=0;i<houses.size();i++)
    {
        if((mask&(1<<i)) == 0){
            ans= min(ans,Find(i,mask|(1<<i))+dist[houses[i].first][houses[i].second][h]);
        }
    }
    return dp[h][mask]=ans;
}

int main()
{


    while(true)
    {
        cin>>m>>n;
        if(m==0 && n==0)return 0;
        //cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cin>>grid[i][j];
        }
        precompute();
        int ans= Find(0,1);
        if(ans>=9999)cout<<-1<<endl;
        else cout<<ans<<endl;

    }
}
