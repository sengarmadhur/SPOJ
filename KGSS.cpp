#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define pii pair<int,int>
#define ff first
#define pb push_back
#define ss second
pii tree[1000000];
pii mg(pii a,pii b)
{
    vector<int>v;
    v.pb(a.ff),v.pb(a.ss),v.pb(b.ff),v.pb(b.ss);
    sort(v.begin(),v.end());
    return {v[3],v[2]};
}
void build(int node,int start,int end,int arr[])
{
    if(start == end){
        tree[node] = {arr[start],0};
    }
    else{
        int mid = (start+end)/2;
        build(2*node,start,mid,arr);
        build(2*node+1,mid+1,end,arr);
        tree[node] = mg(tree[2*node],tree[2*node+1]);
    }
}
void update(int node,int start,int end,int idx,int val,int arr[])
{
    if(start == end){
        arr[idx] = val;
        tree[node] = {arr[idx],0};
    }
    else{
        int mid = (start+end)/2;
        //left
        if(start<=idx && mid>=idx){
            update(2*node,start,mid,idx,val,arr);
        }
        //right
        else{
            update(2*node+1,mid+1,end,idx,val,arr);
        }
        tree[node] = mg(tree[2*node],tree[2*node+1]);
    }
}
pii query(int node,int start,int end,int l,int r)
{
    //cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
    if(r < start || end < l)
    {
        return {0,0};
    }
    if(l<=start && end<=r){
        return tree[node];
    }

        int mid = (start+end)/2;
        pii x1 = query(2*node,start,mid,l,r);
        pii x2 = query(2*node +1,mid+1,end,l,r);
        return mg(x1,x2);
}
int32_t main()
{
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        build(1,0,n-1,arr);
        int q; cin>>q;
        while(q--)
        {
            char c;
            int p,q;
             cin>>c>>p>>q;
            if(c == 'U')
            {
                update(1,0,n-1,p-1,q,arr);
            }
            else{

                pii ans = query(1,0,n-1,p-1,q-1);
               cout<<ans.ff+ans.ss<<endl;
            }
        }
}

