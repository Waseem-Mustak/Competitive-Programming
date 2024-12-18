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
#define Mems(p,n) memset(p, n, sizeof(p))

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



 
ll  ara[N],ara1[N],ara2[N],visited[N];
 
vector<ll>v[N];





ll starting_pos[N],low[N];

ll tim=0;

vector<pair<ll,ll>>IS_BRIDGE;       

void find_bridge(ll node,ll parent)   //https://cp-algorithms.com/graph/bridge-searching.html
{
    visited[node]=1;
    tim++;
    low[node]=starting_pos[node]=tim;
    for(auto child:v[node])
    {
        if(child==parent)continue;
        if(visited[child]==0)
        {
            find_bridge(child,node);
            low[node]=min(low[node],low[child]);

            if(low[child]>starting_pos[node])   //part of bridge
            {
                if(node<child)IS_BRIDGE.pb({node,child});
                else IS_BRIDGE.pb({child,node});
            }
            else                // mearge them with one parent by DSU
            { 
                // Union(node,child);
            }
        }
        else
        {
            low[node]=min(low[node],starting_pos[child]);
        }
    }
}


vector<ll> articulation_point;

void find_articulation_points(ll node,ll parent)   //https://cp-algorithms.com/graph/cutpoints.html
{
    visited[node]=1;
    tim++;
    low[node]=starting_pos[node]=tim;
    ll child_count=0;
    for(auto child:v[node])
    {
        if(child==parent)continue;
        if(visited[child]==0)
        {
            find_articulation_points(child,node);
            low[node]=min(low[node],low[child]);

            if(low[child]>=starting_pos[node] && parent!=0)   //part of articulation_points
            {
                // IS_BRIDGE.pb({node,child});
                articulation_point.pb(node);  // this can contain same node multiple times,so for final ans, use set in main funnction

            }
            else                // mearge them with one parent by DSU
            { 
                // Union(node,child);
            }
            child_count++;
        }
        else
        {
            low[node]=min(low[node],starting_pos[child]);
        }
    }
    if(parent==0 && child_count>1) // just for root
    {
        articulation_point.pb(node);
    }
}



///////////////////////////////////another bridge algo by dfsTree
ll hasBridge=0,cntNode=0;
ll lvl[N],dp[N];
//dp[u]as the number of back-edges passing over the 
 //edge between u and its parent. Then,
 //https://codeforces.com/blog/entry/68138
void DFSBridge(int u){
     lvl[1]=1; //do it in main func
     cntNode++;
  dp[u]=0;
  for(int v:graph[u]){
    if(lvl[v]==0){ /* edge to child */
      lvl[v]=lvl[u]+1;
      DFSBridge(v);
      dp[u]+=dp[v];
    }else if(lvl[v]<lvl[u]){ /* edge upwards */
      dp[u]++;
    }else if(lvl[v]>lvl[u]){ /* edge downwards */
      dp[u]--;
    }
  }
  /* the parent edge isn't a back-edge, subtract 1 to compensate */
  dp[u]--;
  if(lvl[u]>1 && dp[u]==0){
    hasBridge++;
  }
}



 

void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>m;

    // initialize
    lp(i,0,n)
    {
        v[i].clear();
        starting_pos[i]=low[i]=0;
        visited[i]=0;
    }
    articulation_point.clear();
    tim=0;



    lp(i,1,m)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    lp(i,1,n)
    {
        if(visited[i]==0)find_articulation_points(i,0);
    }


    set<ll>tem;
    for(auto va:articulation_point)tem.insert(va);
    coutl<<tem.size()<<el;
}

int main()   //https://lightoj.com/problem/ant-hills
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
