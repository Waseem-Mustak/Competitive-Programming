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



 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];

vec ans_list;
void mak(ll n)
{
    if(n==1)
    {
        ans_list.clear();
        ans_list.pb(1);
        return;
    }
    if(n%2==0)
    {
        mak(n/2);
    }
    else mak((n/2)+1);
    ll tem=ans_list.size();
    lp(i,0,tem-1)
    {
        ans_list[i]*=2;
        ans_list.pb(ans_list[i]-1);
    }
    tem=ans_list.size();
    lp(i,0,tem-1)
    {
        if(ans_list[i]==n+1)
        {
            lp(j,i,tem-2)
            {
                swap(ans_list[j],ans_list[j+1]);
            }
            ans_list.pop_back();
            break;
        }
    }
}

void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n;
    m=n*n;
    mak(m);
    a=0;
    lp(i,1,n)
    {
        lp(j,1,n)
        {
            cout<<ans_list[a]<<" ";
            a++;
        }
        cout<<el;
    }
}

int main()  //https://codeforces.com/problemset/gymProblem/103828/L
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
