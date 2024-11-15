#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=2e5+2;
const int M=1e9+7;
long long NN=316,MM,S,K;
long long test_case; 
 
#define ll long long
#define lp(i,a,b) for(ll i=a;i<=b;i++)
#define rlp(i,a,b) for(ll i=a;i>=b;i--)
#define vec vector<long long>
#define pb push_back
#define rpb pop_back
#define f first
#define s second
#define el "\n"
#define pri(ara,n) for(ll i=1;i<=n;i++)cout<<ara[i]<<" ";cout<<el;
#define priv(vec) for(auto va:vec)cout<<va<<" ";cout<<"\n";
#define srt(ara,n) sort(ara+1,ara+1+n);
#define srtv(vec) sort(vec.begin(), vec.end());
#define revv(vec) reverse(vec.begin(), vec.end());
#define coutl cout<<"Case "<<test_case<<": "
#define in(ara,n) cin>>n;lp(i,1,n)cin>>ara[i];
#define all(ara,n,m) lp(i,1,n)ara[i]=m;
#define index(indexed_Set,val) indexed_Set.order_of_key(val)
#define value(indexed_Set,ind) *indexed_Set.find_by_order(ind) 
#define pi 2*acos(0.0)
#define Mems(dp,n) memset(dp,n,sizeof(dp))

bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    // return a>b;
    if(a.f==b.f)return a.s<b.s;
    else return a.f>b.f;
}
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
//ll arr[1001][1001];



 


struct PST {

    struct node{
        int lNode=0,rNode=0;
        ll val=0;
    }Node[40*N];  // size of array N

    int nodePos=0;

    int build(int l, int r) {  // return node position
        int curNode= ++nodePos;
        if(l==r)return curNode;
        int mid=(l+r)>>1;
        Node[curNode].lNode=build(l,mid);
        Node[curNode].rNode=build(mid+1,r);
        Node[curNode].val=Node[Node[curNode].lNode].val 
                        + Node[Node[curNode].rNode].val;
        return curNode;
    }

    int upd(int preNode,int l,int r,int pos,ll val){// return node position
        int curNode= ++nodePos;
        Node[curNode]=Node[preNode];

        if(l==r){
            Node[curNode].val+=val;
            return curNode;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            Node[curNode].lNode=upd(Node[preNode].lNode,l,mid,pos,val);
            Node[curNode].rNode=Node[preNode].rNode;
        }
        else{
            Node[curNode].lNode=Node[preNode].lNode;
            Node[curNode].rNode=upd(Node[preNode].rNode,mid+1,r,pos,val);
        }
        Node[curNode].val=Node[Node[curNode].lNode].val 
                        + Node[Node[curNode].rNode].val;
        return curNode;
    }

    ll getSum(int curNode,int l,int r,int x,int y){//i need from x to y
        if(x>y)return 0;
        if(x==l && y==r)return Node[curNode].val;
        int mid=(l+r)>>1;
        return getSum(Node[curNode].lNode,l,mid,x,min(y,mid))
              +getSum(Node[curNode].rNode,mid+1,r,max(x,mid+1),y);
    }

    int kthSmallest(int preNode,int curNode,int l,int r,ll k){
        if(l==r)return l;
        ll cnt=Node[Node[curNode].lNode].val-Node[Node[preNode].lNode].val;
        int mid=(l+r)>>1;
        if(cnt>=k) return kthSmallest(Node[preNode].lNode,Node[curNode].lNode,l,mid,k);
        else return kthSmallest(Node[preNode].rNode,Node[curNode].rNode,mid+1,r,k-cnt);
    }
};


int Root[N];
ll input[N],actualValueOfCompressedValue[N],nxt[N];

map<ll,ll>compressedValue;
void compressArray(ll n)
{
    compressedValue.clear();
    lp(i,1,n)
    {
        compressedValue[input[i]];
        actualValueOfCompressedValue[i]=0;
    }
    ll cnt=0;
    for(auto va:compressedValue)
    {
        compressedValue[va.first]= ++cnt;
        actualValueOfCompressedValue[cnt]=va.first;
    }
}

void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    PST pst;   //distinct elements in range
    cin>>n>>q;

    lp(i,1,n)cin>>input[i];
    map<ll,ll>mp;
    rlp(i,n,1)
    {
        if(mp[input[i]]==0)
        {
            nxt[i]=n+1;
            mp[input[i]]=i;
        }
        else
        {
            nxt[i]=mp[input[i]];
            mp[input[i]]=i;
        }
    }
    Root[0]=pst.build(1,n+1);
    lp(i,1,n)
    {
        Root[i]=pst.upd(Root[i-1],1,n+1,nxt[i],1);
    }

    while(q--)
    {
        cin>>l>>r;
        cout<<pst.getSum(Root[r],1,n+1,r+1,n+1)-pst.getSum(Root[l-1],1,n+1,r+1,n+1)<<el;
    }


    // for kthSmallest/////////////
    // PST pst;
    // cin>>n>>q;

    // lp(i,1,n)cin>>input[i];
    // compressArray(n);


    // Root[0]=pst.build(1,n);
    // lp(i,1,n)
    // {
    //     Root[i]=pst.upd(Root[i-1],1,n,compressedValue[input[i]],1);
    // }

    // while(q--) 
    // {
    //     cin>>l>>r>>k;
    //     ans=pst.kthSmallest(Root[l-1],Root[r],1,n,k);
    //     cout<<actualValueOfCompressedValue[ans]<<el;
    // }
}
//the code returns k-th number in a range l to r if the range were sorted
//https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree
int main()
{
    fast;
    ll t=1;
    // cin>>t;
    test_case=1;
    while(t--)
    {
        solve();
        test_case++;
    }
} 