#include<bits/stdc++.h>
using namespace std;
long long int calc(string s)
{
    long long int dp[5001];
    for(int i=0;i<s.length();i++)dp[i]=0;
   dp[0]=1;

    for(int i=1;i<s.length();i++)
    {   int x =(s[i-1]-'0')*10 +(s[i]-'0');
        if(s[i]-'0'>0)dp[i]=dp[i-1];
        if(x<=26 && x>9){
                if(i==1)dp[i]=dp[i]+1;
                else dp[i] =dp[i]+dp[i-2];
        }

    }
    return dp[s.length()-1];

}
int main()
{
    string s; while(cin>>s)
    {   if(s=="0")return 0;
        cout<<calc(s)<<endl;
    }
}
