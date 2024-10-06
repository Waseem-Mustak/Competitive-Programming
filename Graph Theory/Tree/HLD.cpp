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
 
#define ll int
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
 
 
//ll store_2_to_the_power_ith_upper_node[1001][1001];
 
 
 
 
ll node,q,tim;
ll values[N],shuffled_values[N],starting_time[N],chain_number[N],total_node_in_subtree[N];
vector<ll>graph[N];
 
// for lca
ll  depth[N];
ll store_2_to_the_power_ith_upper_node[200003][20];
ll  store_max_data_for_seg_tree[N];
 
void dfs(ll u,ll p,ll d){
    store_2_to_the_power_ith_upper_node[u][0]=p;
    depth[u]=d;
    ll ans=0;
    for(auto v:graph[u]){
        if(v!=p){
            dfs(v,u,d+1);
            ans+=total_node_in_subtree[v];
        }
    }
    total_node_in_subtree[u]=ans+1;
}
 
void dfs_HLD(ll u,ll p,ll top_node_of_chain)
{
    tim++;
    starting_time[u]=tim;
    shuffled_values[tim]=values[u];
    chain_number[u]=top_node_of_chain;
 
    ll bigger_subtree=0;
    ll tem=0;
    for(auto v:graph[u]){
        if(v!=p)
        {
            if(total_node_in_subtree[v]>tem)
            {
                tem=total_node_in_subtree[v];
                bigger_subtree=v;
            }
        }
    }
    if(bigger_subtree)dfs_HLD(bigger_subtree,u,top_node_of_chain); //same chain
 
    for(auto v:graph[u]){
        if(v!=p)
        {
            if(v!=bigger_subtree)
            {
                dfs_HLD(v,u,v);    //new chain
            }
        }
    }
}
 
 
 
 
 
 
 
// ll kth_upper_element(ll a,ll k)  // will return the kth upper node of node a
// {
//     ll c=0;
//     while(k)
//     {
//         if(k&1)
//         {
//             a=store_2_to_the_power_ith_upper_node[a][c];
//         }
//         c++;
//         k/=2;
//     }
//     return a;
// }
 
// ll lca(ll a,ll b)
// {
//     ll tem_a=a;
//     ll tem_b=b;
//     if(depth[a]>depth[b])  // balancing both node in same level
//     {
//         a=kth_upper_element(a,depth[a]-depth[b]);
//     }
//     else
//     {
//         b=kth_upper_element(b,depth[b]-depth[a]);
//     }
 
 
//     ll x=depth[a];
//     ll y=0;
//     ll c,d,p;
//     while(x-y>1)  // finding LCA by binary search
//     {
//         ll mid=(x+y)/2;
//         p=x-mid;
//         c=kth_upper_element(a,p);
//         d=kth_upper_element(b,p);
//         if(c==d)y=mid;
//         else
//         {
//             a=c;
//             b=d;
//             x=mid;
//         }
//     }
//     ll LCA;
//     if(a==b)LCA=a;
//     else LCA=kth_upper_element(a,x-y);
//     return LCA;
// }
 
 
// segment tree iteratively
void update(ll index,ll value)
{
    index+=node;
    store_max_data_for_seg_tree[index]=value;
    index/=2;
    while(index)
    {
        store_max_data_for_seg_tree[index]=max(store_max_data_for_seg_tree[2*index],store_max_data_for_seg_tree[2*index+1]);
        index/=2;
    }
}
 
ll query(ll index_1,ll index_2)
{
    ll ans=0;
    index_1+=node;
    index_2+=node+1;
 
    while(index_1<index_2)
    {
        if(index_1 & 1)
        {
            ans=max(ans,store_max_data_for_seg_tree[index_1++]);
        }
        if(index_2 & 1)
        {
            ans=max(ans,store_max_data_for_seg_tree[--index_2]);
        }
        index_1/=2;
        index_2/=2;
    }
    return ans;
}
 
 
 
// ll built_max_seg_tree(ll a,ll b,ll n)
// {
//     if(a==b)return store_max_data_for_seg_tree[n]=shuffled_values[a];
//     ll mid=(a+b)/2;
//     return store_max_data_for_seg_tree[n]=max(built_max_seg_tree(a,mid,2*n),built_max_seg_tree(mid+1,b,2*n+1));
// }
 
// ll find_max_from_seg_tree(ll x,ll y,ll a,ll b,ll n) // first two variable is my range for finding min
// {
//     if(b<x||a>y)return -1000000000;
//     if(a>=x&&b<=y)return store_max_data_for_seg_tree[n];
//     ll mid=(a+b)/2;
//     return max(find_max_from_seg_tree(x,y,a,mid,2*n),find_max_from_seg_tree(x,y,mid+1,b,2*n+1));
// }
 
// ll change_value_in_seg_tree(ll in,ll va,ll a,ll b,ll n)
// {
//     if(in<a||in>b)return store_max_data_for_seg_tree[n];
//     if(a==b)return shuffled_values[a]=store_max_data_for_seg_tree[n]=va;
//     ll mid=(a+b)/2;
//     return store_max_data_for_seg_tree[n]=max(change_value_in_seg_tree(in,va,a,mid,2*n),change_value_in_seg_tree(in,va,mid+1,b,2*n+1));   
// }
 
 
 
// ll max_value_from_a_path(ll a,ll b)  //got TLE
// {
//     ll ans=0;
//     ll lca_tem=lca(a,b);
//     while(chain_number[a]!=chain_number[lca_tem])
//     {
//         ans=max(ans,find_max_from_seg_tree(starting_time[chain_number[a]],starting_time[a],1,node,1));
//         a=store_2_to_the_power_ith_upper_node[chain_number[a]][0];  //parent of chain_number[a]
//     }
//     ans=max(ans,find_max_from_seg_tree(starting_time[lca_tem],starting_time[a],1,node,1));
 
//     while(chain_number[b]!=chain_number[lca_tem])
//     {
//         ans=max(ans,find_max_from_seg_tree(starting_time[chain_number[b]],starting_time[b],1,node,1));
//         b=store_2_to_the_power_ith_upper_node[chain_number[b]][0];  //parent of chain_number[a]
//     }
//     ans=max(ans,find_max_from_seg_tree(starting_time[lca_tem],starting_time[b],1,node,1));
//     return ans;
// }
 
ll max_value_from_a_path_2(ll a,ll b)
{
    ll ans=0;
    while(chain_number[a]!=chain_number[b])
    {
        if(depth[chain_number[a]]<depth[chain_number[b]])
        {
            swap(a,b);
        }
        ans=max(ans,query(starting_time[chain_number[a]],starting_time[a]));
        // ans=max(ans,find_max_from_seg_tree(starting_time[chain_number[a]],starting_time[a],1,node,1));
        a=store_2_to_the_power_ith_upper_node[chain_number[a]][0];
    }
    if(depth[a]>depth[b])swap(a,b);
    ans=max(ans,query(starting_time[a],starting_time[b]));
    // ans=max(ans,find_max_from_seg_tree(starting_time[a],starting_time[b],1,node,1));
    return ans;
 
}
 


ll lca_by_HLD(ll a,ll b)
{
    while(chain_number[a]!=chain_number[b])
    {
        if(depth[chain_number[a]]<depth[chain_number[b]])swap(a,b);
        a=store_2_to_the_power_ith_upper_node[chain_number[a]][0];
    }
    if(depth[a]>depth[b])swap(a,b);
    return a;
}


void solve()
{
 
    // cin>>node;
    // lp(i,1,node)
    // {
    //     ll a;
    //     cin>>a;
 
    // }
 
 
 
    cin>>node>>q;
    for(int i=1;i<=node;i++)cin>>values[i];
    for(int i=1;i<=node-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1,0,0);
    tim=0;
    dfs_HLD(1,0,1);// node,parent,chain_number
 
 
 
    //lca
    // for(int i=1;i<=19;i++)  // storing 1st,2nd,4th,8th,16th upper node of every node
    // {           // 0 index 1st upper(parent) ,1 index means 2nd upper
    //     for(int j=1;j<=node;j++)
    //     {
    //         store_2_to_the_power_ith_upper_node[j][i]=store_2_to_the_power_ith_upper_node[store_2_to_the_power_ith_upper_node[j][i-1]][i-1];
    //     }
    // }
 
    for(int i=1;i<=node;i++)
    {
        update(i,shuffled_values[i]);
    }
 
    // built_max_seg_tree(1,node,1);
 
    while(q--)
    {
        ll a,b,x;
        cin>>a;
        if(a==1)
        {
            cin>>a>>x;
            update(starting_time[a],x);
            // change_value_in_seg_tree(starting_time[a],x,1,node,1);
        }
        else
        {
            cin>>a>>b;
 
            cout<<max_value_from_a_path_2(a,b)<<" ";
        }
    }
 
}
 
int main()   //https://cses.fi/problemset/result/8471139/
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
