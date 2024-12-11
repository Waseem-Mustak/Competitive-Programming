#include <bits/stdc++.h>
using namespace std;

int const N=19;
#define ll long long

ll dp[1<<N][N];//Let dp[mask][i] be the number of Hamiltonian walks over the subset mask, starting at the
// vertex first(mask) and ending at the vertex i.
vector<int> graph[N];

ll firstSetBit(ll mask)
{
    return log2(mask&(-mask));
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll ans=0;
    for(int mask=1;mask<(1<<n);mask++)
    {   
        ll first_=firstSetBit(mask);
        if(mask==(pow(2,first_))){
            dp[mask][first_]=1;
            continue;
        }

        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0 || i==first_)continue;
            for(auto j:graph[i]){
                dp[mask][i]+=dp[mask ^ (1<<i)][j];
            }
        }

        if(__builtin_popcount(mask)<3)continue;
        for(auto vrtx:graph[first_]){
            ans+=dp[mask][vrtx];
        }

    }

    cout<<ans/2<<endl;
}
//https://codeforces.com/problemset/problem/11/D
//cses hailtonian cycle almost same idea
//https://codeforces.com/blog/entry/337 
int main(){
    int t;t=1;
    // cin>>t;
    while(t--){
        solve();
    }
} 