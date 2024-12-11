#include <bits/stdc++.h>
using namespace std;
 
int const N=2000006;
int bit_=20;
#define ll long long
 
 
//problem:
// Given a fixed array A of 2N integers, we need to calculate 
//∀ x function F(x) = Sum of all A[i] such 
//that x&i = i, i.e., i is a subset of x.
// //memory optimized, super easy to code.
// for(int i = 0; i<(1<<N); ++i)
//     F[i] = A[i];
// for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
//     if(mask & (1<<i))
//         F[mask] += F[mask^(1<<i)];
// }
// The above algorithm runs in O(N*2^N) time.
 
 
 
ll ara[N];
ll dpSubset[N],dpSuperset[N];
void solve(){
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        dpSubset[ara[i]]++;
        dpSuperset[ara[i]]++;
    }
    //run over subset
    for(int i = 0;i < bit_; ++i) {
        for(int mask = 0; mask < (1<<bit_); ++mask){
            if(mask & (1<<i))
                dpSubset[mask] += dpSubset[mask^(1<<i)];
        }
    }
 
    //run over superset
    for(int i = 0;i < bit_; ++i) {
        for(int mask = (1<<bit_)-1; mask >= 0; --mask){
            if((mask & (1<<i))==0)
                dpSuperset[mask] += dpSuperset[mask^(1<<i)];
        }
    }
 
    for(int i=1;i<=n;i++){
        cout<<dpSubset[ara[i]]<<" "<<dpSuperset[ara[i]]<<" "<<n- dpSubset[((~ara[i])&((1<<bit_)-1))]  <<endl;
    }
}


// https://codeforces.com/contest/165/problem/E
// https://cses.fi/problemset/task/1654/ this code is it's solu
// https://codeforces.com/blog/entry/45223


int main(){
    int t;t=1;
    // cin>>t;
    while(t--){
        solve();
    }
} 