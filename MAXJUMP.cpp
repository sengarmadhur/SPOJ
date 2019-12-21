#include<iostream>
#include<string.h>
using namespace std;
int board[10][10];
int x[8]={2,-2,2,-2,1,-1,1,-1};
int y[8]={1,1,-1,-1,2,2,-2,-2};
void solve(int r,int c,int temp,int &ans)
{
    ans =max(ans,temp);
    for(int i=0;i<8;i++)
    {
        int cx =r+x[i],cy=c+y[i];
        if(cx>=0&&cx<10&&cy>=0&&cy<10&&board[cx][cy]==1)
        {
            board[cx][cy]=2;
            solve(cx,cy,temp+1,ans);
            board[cx][cy]=1;
        }
    }
}
int main()
{   int n,t=0;
    while(cin>>n)
    {   t++;
        memset(board,0,sizeof(board));
        if(n==0)return 0;
        int startj,total=0;
        for(int i=0;i<n;i++)
        {
            int k,j; cin>>k>>j;
            total+=j;
            if(i==0)startj =k;
            for(int kk=k;kk<k+j;kk++){board[i][kk]=1;}
        }
        board[0][startj]=2;
        int ans=0;
        solve(0,startj,1,ans);
        if(total-ans==1)printf("Case %d, %d square can not be reached.\n",t,total-ans);
        else printf("Case %d, %d squares can not be reached.\n",t,total-ans);

    }
}
