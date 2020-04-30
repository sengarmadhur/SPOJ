#include<bits/stdc++.h>
#define int long long int
using namespace std;
int temp;
int mat[1030][1030];
int vis[1030][1030];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(int i,int j)
{
    vis[i][j]=1;
    temp++;
    for(int k=0;k<4;k++){
       int x = i +dx[k];
       int y = j+ dy[k];
       if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && mat[x][y]==1){
         dfs(x,y);
       }
    }
}
int gcd(int a,int b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}
int32_t main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char z; cin>>z;
                if(z == '~')mat[i][j]=0;
                else mat[i][j]=1;
            }
        }
        int q = n*m;
        int p = 0;

        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 1){
                    temp = 0;
                    dfs(i,j);
                    p+=temp*temp;
                }
            }
        }
        int g= gcd(p,q);
        p/=g;
        q/=g;
        if(q == 1)cout<<p<<endl;
        else cout<<p<<" / "<<q<<endl;
    }
}
