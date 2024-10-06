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
// #define el endl
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
    if(a.f==b.f)return a.s>b.s;
    else return a.f<b.f;
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
 
 
 
 
ll  ara[N],ara1[N],sparce_value_gcd[N][22],tem_1[N],v_power[24];
vector<ll>v[N];

void built_sparce_table_for_gcd(ll n)
{
    tem_1[1]=0;
    tem_1[2]=1;
    ll x=2;
    lp(i,3,n)
    {
        if(x*2<=i)
        {
            tem_1[i]=tem_1[i-1]+1;
            x*=2;
        }
        else tem_1[i]=tem_1[i-1];
    }

    v_power[0]=1;
    lp(i,1,23)
    {
        v_power[i]=v_power[i-1]*2;  // power of 2
    }

    lp(i,1,n)sparce_value_gcd[i][1]=ara[i];
    lp(j,2,21)
    {
        lp(i,1,n)
        {
            ll a=v_power[j-1];
            if(i+(a/2)<=n)sparce_value_gcd[i][j]=gcd(sparce_value_gcd[i][j-1],sparce_value_gcd[i+(a/2)][j-1]);
        }
    }
}

ll find_gcd_from_sparce_table(ll a,ll b)
{
    ll len=b-a+1;
    ll powerr=tem_1[len];
    ll effective_len=v_power[powerr];
    return gcd(sparce_value_gcd[a][powerr+1],sparce_value_gcd[b- effective_len+1][powerr+1]);
}


const int MAXN = 100005;
const int LOGN = 22;
int input[MAXN];
int MinTable[MAXN][LOGN];

//O(n logn)
void buildSparseTable_1D_min(int n){
    for(int k=0;(1<<k)<=n;k++)
    {
        for(int i=1;i+(1<<k)-1<=n;i++)
        {
            if(k==0)MinTable[i][k]=input[i];
            else
            {
                int add=1<<(k-1);
                int ret1=MinTable[i][k-1];
                int ret2=MinTable[i+add][k-1];
                MinTable[i][k]=min(ret1,ret2);
            }
            
        }
    }
}

//returns min of all A[i], where p<=i<=p
int Query(int p,int q)
{
    int k=log2(q-p+1);
    int add=1<<k;
    int ret1=MinTable[p][k];
    int ret2=MinTable[p+(q-p+1)-add][k];
    return min(ret1,ret2);
}


 
void solve()  //https://lightoj.com/problem/array-queries
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1,mid;
    cin>>n>>q;
    coutl<<el;
    lp(i,1,n)
    {
        cin>>input[i];
    }
    buildSparseTable_1D_min(n);
    lp(i,1,q)
    {
        cin>>a>>b;
        cout<<Query(a,b)<<el;
    }

}
 
 
int main()   
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
