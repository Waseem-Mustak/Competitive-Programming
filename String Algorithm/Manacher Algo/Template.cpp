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
 

 
ll  ara[N],ara1[N],ara2[N],ara3[N];
 
vector<ll>v[N];


struct manacher       // creating a vector which will store for every position of string the longest length in right and left side which is a Palindromic substring
{
    string str;
    long long size;
    vector<long long> Palindrome_len;
    manacher(string s)
    {
        for(auto x:s)
        {
            str.push_back('#');
            str.push_back(x);
        }
        str.push_back('#');
        size=str.size();
        // cout<<str<<el;
        build();
    }

    void build()
    {
        Palindrome_len.resize(size,1);
        long long l=1,r=1;
        for(int i=1;i<size;i++)
        {
            Palindrome_len[i]=max((long long)0,min(r-i,Palindrome_len[l+r-i]));
            while(i+Palindrome_len[i]<size && i-Palindrome_len[i]>=0 &&str[i+Palindrome_len[i]]==str[i- Palindrome_len[i]])
            {
                Palindrome_len[i]++;
            }
            if(i+Palindrome_len[i]>r)
            {
                l=i- Palindrome_len[i];
                r=i+Palindrome_len[i];
            }
        }
        // priv(Palindrome_len);
    }

    string getLongestPalindrome()
    {
        long long tem=0;
        for(auto x:Palindrome_len)tem=max(tem,x);
        for(int i=0;i<size;i++)
        {
            if(tem==Palindrome_len[i])
            {
                string st;
                for(int j=i-tem+1;j<=i+tem-1;j++)
                {
                    if(str[j]!='#')st.push_back(str[j]);
                }
                return st;
            }
        }
    }
};


void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    string s1;
    cin>>s1;
    manacher m1(s1);
    cout<<m1.getLongestPalindrome();
}

int main()    //https://cses.fi/problemset/task/1111
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
