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




//sparce table 2D copied from https://github.com/AnikSarker/ACM-Library/blob/master/DS/SparseTable/SparseTable%20(Square%20Query).cpp
const int MAXN = 1005;
const int LOGN = 10;
int input[MAXN][MAXN];
int MaxTable[MAXN][MAXN][LOGN];

//O(n^2 logn)
//Supports Square Query
void buildSparseTable_2D(int n){
    for(int k=0;(1<<k)<=n;k++)
    {
        for(int i=1;i+(1<<k)-1<=n;i++)
        {
            for(int j=1;j+(1<<k)-1<=n;j++)
            {
                if(k==0)MaxTable[i][j][k]=input[i][j];
                else
                {
                    int add=1<<(k-1);
                    int ret1=max(MaxTable[i][j][k-1],MaxTable[i+add][j][k-1]);
                    int ret2=max(MaxTable[i][j+add][k-1],MaxTable[i+add][j+add][k-1]);
                    MaxTable[i][j][k]=max(ret1,ret2);
                }
            }
        }
    }
}

//returns max of all A[i][j], where p<=i<=p+s-1 and q<=j<=q+s-1
int Query(int p,int q,int s)
{
    int k=log2(s);
    int add=1<<k;
    int ret1=max(MaxTable[p][q][k],MaxTable[p+s-add][q][k]);
    int ret2=max(MaxTable[p][q+s-add][k],MaxTable[p+s-add][q+s-add][k]);
    return max(ret1,ret2);
}



void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n>>m;
    coutl<<el;
    lp(i,1,n)
    {
        lp(j,1,n)
        {
            cin>>input[i][j];
        }
    }
    buildSparseTable_2D(n);
    lp(i,1,m)
    {
        cin>>a>>b>>c;
        cout<<Query(a,b,c)<<el;
    }
}

int main()   //https://lightoj.com/problem/square-queries
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
