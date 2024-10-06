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
#define Mems(dp,n) memset(dp,n,sizeof(dp))

bool myComparison(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)  // for vector sorting  1st element small to learge (if same then second element large to small)
{
    if(a.f.f==b.f.f)return a.f.s>b.f.s;
    else return a.f.f<b.f.f;
}
bool cmp1(const pair<ll,ll> &a,const pair<ll,ll> &b)	// for vector sorting  1st element small to learge (if same then second element large to small)
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



vector<ll> graph[N];
ll col[N];
ll ans;
vector<map<ll,ll>> cnt(N);

ll dfs(ll u,ll p=0)
{
    ll big_node=-1;
    for(auto v:graph[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            if(big_node==-1 || cnt[big_node].size()<cnt[v].size())
            {
                big_node=v;
            }
        }
    }


    for(auto v:graph[u])
    {
        if(v!=p)
        {
            if(v!=big_node)
            {
                for(auto tem:cnt[v])
                {
                    ll colour=tem.first;
                    ll count=tem.second;
                    if(colour!=col[u])
                    {
                        ans+=(cnt[big_node][colour]*count);
                    }
                    cnt[big_node][colour]+=count;
                }
            }
        }
    }

    if(big_node!=-1)
    {
        swap(cnt[big_node],cnt[u]);
    }

    ans+=cnt[u][col[u]];
    cnt[u][col[u]]=1;
}
void solve()
{
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        cnt[i].clear();
    }
    for(int i=1;i<=n;i++)
    {
        cin>>col[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ans=0;
    dfs(1);
    cout<<ans<<el;
    
}

int main()  //https://codeforces.com/contest/1923/problem/E
{  //https://codeforces.com/blog/entry/44351
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
