#include<iostream>
#include<cmath>
using namespace std;
int mem[1001];
void solve()
{   int k=1;
    int prime[]={ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127 };
    for(int i=30;i<=100000;i++)
    {   int c=0;
        int temp =i;
        for(int j=0;prime[j]<=sqrt(i);j++)
        {
            if(temp%prime[j]==0)
            {
                c++;
                while(temp%prime[j]==0)temp/=prime[j];
            }

        }
        if(temp>1)c++;
        if(c>=3)mem[k++]=i;
        if(k>1000)break;
    }
}
int main()
{
    int t; cin>>t;
    solve();
    while(t--)
    {
        int n; cin>>n;
        cout<<mem[n]<<endl;
    }
}
