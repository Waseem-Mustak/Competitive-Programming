#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> multi_indexed_set;
 
 
const int N=1e6+2;
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
 




struct BIT_2D           // starttttttttttttttttt
{
    vector<vector<long long>>bit;  // 1 indexing
    int size;
    BIT_2D(int n) {bit.resize(n+2,vector<long long>(n+2,0));size=n;}

    void update(int x,int y,long long val){  // update a value just in bit array not in main array
        int xx=x;
        while(xx<=size){
            int yy=y;
            while(yy<=size)
            {
                bit[xx][yy]+=val;
                yy+=(yy & -yy);
            }
            xx+=(xx & -xx);
        }
    }

    long long sum(int x,int y){   // returning sum from ara[1][1] to ara[x][y]
        long long ans=0;
        int xx=x;
        while(xx>0){
            int yy=y;
            while(yy>0)
            {
                ans+=bit[xx][yy];
                yy-=(yy & -yy);
            }
            xx-=(xx & -xx);
        }
        return ans;
    }
};


void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    coutl<<el;
    n=1001;
    BIT_2D bit(n);
    cin>>q;
    lp(i,1,q)
    {
        cin>>x;
        if(x==0)
        {
            cin>>a>>b;
            a++;
            b++;
            if(bit.sum(a,b)-bit.sum(a-1,b)-bit.sum(a,b-1)+bit.sum(a-1,b-1)==0)
            {
                bit.update(a,b,1);
            }
        }
        else
        {
            cin>>x>>y>>a>>b;
            x++;
            y++;
            a++;
            b++;
            cout<<bit.sum(a,b)-bit.sum(x-1,b)-bit.sum(a,y-1)+bit.sum(x-1,y-1)<<el;
        }
    }
}

int main()    //https://lightoj.com/problem/points-in-rectangle
{
    fast;
    ll t=1;
    cin>>t;
    test_case=1;
    while(t--)
    {
        solve();
        test_case++;
    }
} 
