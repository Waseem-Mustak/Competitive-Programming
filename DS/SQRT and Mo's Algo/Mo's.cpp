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
 
ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}
ll gcd(ll a,ll b) 
{
    return __gcd(a,b);
}
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N],ara4[N],answers[N],frequency[N];
 
vector<ll>v[N];















ll block;
bool myComparison_for_Square_Root_Decomposition(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)    // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f/block != b.f.f/block)  // means two are in different block based on L
    {
        return a.f.f/block < b.f.f/block;
    }
    else return a.f.s<b.f.s;   // if they are in same block then sort based on R value
}



void compressed_and_map_big_number_to_small_number(ll n)
{
    map<ll,ll> tem;
    ll compressed_number=1;
    lp(i,1,n)
    {
        if(tem[ara[i]]==0)   // not compressed
        {
            tem[ara[i]]=compressed_number;
            ara[i]=compressed_number;
            compressed_number++;
        }
        else
        {
            ara[i]=tem[ara[i]];   // already compressed
        }
    }
}
void MOs_algo()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>q;
    block=sqrt(n);

    lp(i,1,n)cin>>ara[i];
    compressed_and_map_big_number_to_small_number(n);  // for ara[]
    // pri(ara,n);

    vector<pair<pair<ll,ll>,ll>>v1,v2;
    lp(i,1,q)
    {
        cin>>a>>b;
        v1.pb({{a,b},i});
    }
    sort(v1.begin(), v1.end(), myComparison_for_Square_Root_Decomposition);

    ll distinct=0;
    ll prev_L=0;
    ll prev_R=-1;
    ll R,L;
    frequency[ara[0]]=0;   // all for initial stage

    lp(i,1,q)
    {
        L=v1[i-1].f.f;
        R=v1[i-1].f.s;

        while(1)
        {
            if(prev_R<R)
            {
                prev_R++;
                if(frequency[ara[prev_R]]==0)distinct++;
                frequency[ara[prev_R]]++;
            }
            else break;
        }

        while(1)
        {
            if(prev_L<L)
            {
                
                if(frequency[ara[prev_L]]==1)distinct--;
                frequency[ara[prev_L]]--;
                prev_L++;
            }
            else break;
        }

        while(1)
        {
            if(prev_R>R)
            {
                if(frequency[ara[prev_R]]==1)distinct--;
                frequency[ara[prev_R]]--;
                prev_R--;
            }
            else break;
        }

        while(1)
        {
            if(prev_L>L)
            {
                prev_L--;
                if(frequency[ara[prev_L]]==0)distinct++;
                frequency[ara[prev_L]]++;
            }
            else break;
        }

        ll pos=v1[i-1].s;
        answers[pos]=distinct;
    }

    lp(i,1,q)cout<<answers[i]<<el;
}



void solve()
{
    MOs_algo();

}

int main()        //https://cses.fi/problemset/task/1734
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
