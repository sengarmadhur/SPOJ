
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int g[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>g[i][j];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<n;j++)temp+=g[i][j];
        ans= min(ans,temp);
    }
    cout<<2*ans<<endl;
}
