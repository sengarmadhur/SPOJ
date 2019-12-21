#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 +7;
ll a[1000001];
void pre()
{
    a[2]=2;
    for(int i=3;i<1e6+1;i++)
    {
        a[i] = (a[i-1]*(a[i-1]+1))%MOD;
    }
}
int main()
{
    int t; cin>>t;
    pre();
    while(t--)
    {
      int n; cin>>n;
      cout<<(a[n]%MOD)<<endl;
    }
}

