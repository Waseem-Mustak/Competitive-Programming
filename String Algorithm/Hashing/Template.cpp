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
 
 
 
 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];
 
 
 
 
 
 
 
 
 
// part of double HASH *******************************************************************************************************
 
 
 
 
 
 
const int HashStringSize = 2000009;
ll mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
ll bases[2] = {137, 281};
ll pwbase[2][HashStringSize];
 
void Preprocess(){
    pwbase[0][0] = pwbase[1][0] = 1;
    for(ll i = 0; i < 2; i++){
        for(ll j = 1; j < HashStringSize; j++){
            pwbase[i][j] = (pwbase[i][j - 1] * bases[i]) % mods[i];
        }
    }
}
 
 

struct Hashing 
{
    ll size;  // check size<
    string s1;  // 0 indexed
    vector<pair<ll,ll>>Hash;   // 1 indexed
    Hashing(){}
 
    Hashing(string s)
    {
        s1=s;
        size=s1.size();
        Hash.push_back({0,0});  // first position 0
        for(int i=0;i<size;i++)
        {
            ll tem=s1[i]-'a'+1;
            pair<ll,ll>p;
            p.first=  (((Hash[i].first*bases[0])%mods[0])+((tem*bases[0])%mods[0]))%mods[0];
            p.second=  (((Hash[i].second*bases[1])%mods[1])+((tem*bases[1])%mods[1]))%mods[1];
            Hash.push_back(p);
            // cout<<Hash[i+1].first<<" "<<Hash[i+1].second<<endl;
        }
    }
 
    pair<ll,ll> get_hash(ll l,ll r)   // 1 indexed
    {
        assert(1<=l&&l<=r&&r<=size);
        pair<ll,ll>p;
        p.first=(Hash[r].first-((pwbase[0][(r-l+1)]*Hash[l-1].first)%mods[0])+mods[0])%mods[0];
        p.second=(Hash[r].second-((pwbase[1][(r-l+1)]*Hash[l-1].second)%mods[1])+mods[1])%mods[1];
        return p;
    }
};
 
 
//part of single hash *************************************************************************************************************************************
 
 
 
 
 
 
 
//here i first used double hash
// then got TLE
// Because so many mod operation(mod usually takes log(n) time)
// but switched to single Hash
// and for mod=1000000007 and 1000000009 got WA
// for mod =1072857881 got AC
// dont know why
 
 
// ll mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
// ll bases[2] = {137, 281};
// ll pwbase[2][HashStringSize];
 
 
//************************************
 
 
// const int HashStringSize = 2000009;
// ll mods=1072857881;
// ll bases=137;
// ll pwbase[HashStringSize];
 
// void Preprocess(){
//	 pwbase[0]= 1;
//		 for(ll j = 1; j < HashStringSize; j++){
//			 pwbase[j] = (pwbase[j - 1] * bases) % mods;
//	 }
// }
 
 
 
// struct Hashing
// {
//	 ll size;
//	 string s1;  // 0 indexed
//	 vector<ll>Hash;   // 1 indexed
//  Hashing(){}
//	 Hashing(string s)
//	 {
//		 s1=s;
//		 size=s1.size();
//		 Hash.push_back(0);  // first position 0
//		 for(int i=0;i<size;i++)
//		 {
//			 ll tem=s1[i]-'a'+1;
//			 ll p;
//			 p=(((Hash[i]*bases))+((tem*bases)))%mods;
//			 Hash.push_back(p);
//		 }
//	 }
     
//	 ll get_hash(ll l,ll r)   // 1 indexed
//	 {
//		 assert(1<=l&&l<=r&&r<=size);
//		 ll p;
//		 p=(Hash[r]-pwbase[(r-l+1)]*Hash[l-1])%mods;
//		 if(p<0)p+=mods;
//		 return p;
//	 }
// };
 
 
 
 
 
 
 
void solve()		//https://cses.fi/problemset/task/2106
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    string s1;
    cin>>s1; 
    n=s1.size();
    Hashing h1(s1);
    a=1;
    b=n;
    bool tem;
    while(b-a>1)
    {
        vector<pair<pair<ll,ll>,ll>>v1;
        ll mid=(a+b)/2;
        tem=false;
        lp(i,1,n-mid+1)
        {
            v1.pb({h1.get_hash(i,i+mid-1),i});
        }
        srtv(v1);
        for(int i=0;i<(v1.size()-1);i++)
        {
            if(v1[i].f==v1[i+1].f)
            {
                tem=true;
            }
        }
        if(tem==true)
        {
            a=mid;
        }
        else b=mid;
    }
    ans=-1;
    vector<pair<pair<ll,ll>,ll>>v1;
    ll mid=b;
    tem=false;
    lp(i,1,n-mid+1)
    {
        v1.pb({h1.get_hash(i,i+mid-1),i});
    }
    srtv(v1);
    for(int i=0;i<(v1.size()-1);i++)
    {
        if(v1[i].f==v1[i+1].f)
        {
            tem=true;
            ans=v1[i].s;
        }
    }
    if(tem)
    {
        lp(i,ans,ans+b-1)
        {
            cout<<s1[i-1];
        }
        return;
    }
    
  
    ans=-1;
    v1.clear();
    mid=a;
    tem=false;
    lp(i,1,n-mid+1)
    {
        v1.pb({h1.get_hash(i,i+mid-1),i});
    }
    srtv(v1);
    for(int i=0;i<(v1.size()-1);i++)
    {
        if(v1[i].f==v1[i+1].f)
        {
            tem=true;
            ans=v1[i].s;
        }
    }
    if(tem)
    {
        lp(i,ans,ans+a-1)
        {
            cout<<s1[i-1];
        }
        return;
    }
    cout<<-1<<el;
}
 
int main()
{
    fast;
    ll t=1;
    // cin>>t;
    test_case=1;
    Preprocess();
    while(t--)
    {
        solve();
        test_case++;
    }
}
