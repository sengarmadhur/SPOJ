#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int>adj[n];
    bitset<901> bs[n];
    string s;
    getline(cin,s);
    for (int i = 0; i < n; i ++) {

        getline(cin,s);
        int num=0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==' '){
                adj[i].push_back(num);
                bs[i][num]=1;
                num=0;
            }
            else num = num*10 + (s[j]-'0');
        }
        adj[i].push_back(num);
        bs[i][num]=1;
    }
   //finding three distinct nodes and try to finding the fourth common nodes to each
   int ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {    if(bs[i][j]==0)continue;
           for(int k=j+1;k<n;k++)
           {

              if(bs[i][k]==0 || bs[j][k]==0)continue;
              ans= ans + (bs[i]&bs[j]&bs[k]).count();
           }
       }
   }
   //All are same pairs
   //(0 1 2) & 3
   //(0,2,3) & 1
   //(0,1,3) & 2
   //(1,2,3) & 0
   cout<<ans/4;
}
