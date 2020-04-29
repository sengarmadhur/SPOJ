#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int LOW = -999999999999;
struct node{
    int pref,suff,sum,maxs;

};
node tree[200005];
int arr[50000];
void build(int nd,int start,int end)
{
    if(start>end)return;
    if(start == end){tree[nd] = (node){arr[start],arr[start],arr[start],arr[start]};return;}
    int mid = (start+end)/2;
    build(nd*2,start,mid);
    build(nd*2+1,mid+1,end);
    tree[nd].sum = tree[2*nd].sum + tree[2*nd+1].sum;
	tree[nd].pref = max(tree[2*nd].pref, tree[2*nd].sum + tree[2*nd+1].pref);
	tree[nd].suff = max(tree[2*nd +1].suff, tree[2*nd +1].sum + tree[2*nd].suff);
	tree[nd].maxs = max(max(tree[2*nd].maxs,tree[2*nd+1].maxs), tree[2*nd].suff +tree[2*nd+1].pref);
}
void update(int nd,int start,int end,int idx,int val)
{
    if(start == end){
        arr[idx] = val;
        tree[nd] = {arr[idx],arr[idx],arr[idx],arr[idx]};
    }
    else{
        int mid = (start+end)/2;
        //left
        if(start<=idx && mid>=idx){
            update(2*nd,start,mid,idx,val);
        }
        //right
        else{
            update(2*nd+1,mid+1,end,idx,val);
        }
        tree[nd].sum = tree[2*nd].sum + tree[2*nd+1].sum;
        tree[nd].pref = max(tree[2*nd].pref, tree[2*nd].sum + tree[2*nd+1].pref);
        tree[nd].suff = max(tree[2*nd +1].suff, tree[2*nd +1].sum + tree[2*nd].suff);
        tree[nd].maxs = max(max(tree[2*nd].maxs,tree[2*nd+1].maxs), tree[2*nd].suff +tree[2*nd+1].pref);
    }
}

node query(int nd,int start,int end,int l,int r)
{

    if(r<start || end<l)return {LOW,LOW,LOW,LOW};
    if(l<=start && r>=end)return tree[nd];

    int mid = (start+end)/2;

    node x1 = query(2*nd,start,mid,l,r);
    node x2 = query(2*nd+1,mid+1,end,l,r);
    node res;
    res.maxs = max(x1.suff + x2.pref, max(x1.maxs,x2.maxs));
	res.pref = max(x1.pref, x1.sum + x2.pref);
	res.suff = max(x1.suff + x2.sum, x2.suff);
	res.sum = x1.sum + x2.sum;
    return res;
}

int32_t main()
{

    int N,q; cin>>N;

    for(int i=0;i<N;i++)cin>>arr[i];
    build(1,0,N-1);

    cin>>q;
    while(q--)
    {
        int z; cin>>z;
         if(z == 1)
         {
             int l,r; cin>>l>>r; l--,r--;
             node ans =query(1,0,N-1,l,r);
                cout<<max(max(ans.pref, ans.suff), max(ans.sum, ans.maxs))<<endl;
        }
         else{
            int x,y; cin>>x>>y;
            x--;
            update(1,0,N-1,x,y);
         }
    }
}

