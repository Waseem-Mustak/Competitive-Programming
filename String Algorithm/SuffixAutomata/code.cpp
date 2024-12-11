#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3000000;
 
ll cnt[N];  //cnt[i]= how many total times every string ends in state i appears 
ll dp[N];  // dp[i]=how many total times every string ends in state i appears as prefix of any string
// dp[i] helps for counting total distinct substring,
// cnt[i] helps for counting total occarance of substring
struct SuffixAuto {
    struct State {
        int len, link;
        int next[26];
        State(int _len = 0, int _link = -1) : len(_len), link(_link) {
            memset(next, -1, sizeof(next));
        }
    };
 
    vector<State> states;
    int last;
 
    SuffixAuto() {}
 
    SuffixAuto(const string &S) {
        init(S);
    }
 
    inline int state(int len = 0, int link = -1) {
        states.emplace_back(len, link);
        return states.size() - 1;
    }
 
    void init(const string &S) {
        states.clear();
        states.reserve(2 * S.size());
        for(int i=0;i<=2*S.size();i++)cnt[i]=0;
        last = state();
        for (char c : S)
            extend(c);
    }
 
    void extend(char _c) {
        int c = _c - 'a'; // change for different alphabet
        int cur = state(states[last].len + 1), P = last;
        cnt[cur]=1; //extra
        while (P != -1 && states[P].next[c] == -1) {
            states[P].next[c] = cur;
            P = states[P].link;
        }
        if (P == -1)
            states[cur].link = 0;
        else {
            int Q = states[P].next[c];
            if (states[P].len + 1 == states[Q].len)
                states[cur].link = Q;
            else {
                int C = state(states[P].len + 1, states[Q].link);
                cnt[C]=0; //extra ,its 0 brcause clone state
                copy(states[Q].next, states[Q].next + 26, states[C].next);
                while (P != -1 && states[P].next[c] == Q) {
                    states[P].next[c] = C;
                    P = states[P].link;
                }
                states[Q].link = states[cur].link = C;
            }
        }
        last = cur;
    }
};
 
SuffixAuto sa;
string s1;
int n;
 
ll countOcarrance(string s)
{
    int p=0;
    int len=0;
    for(auto c:s)
    {
        p=sa.states[p].next[c-'a'];
        if(p==-1)break;
        len++;
    }
    if(len==s.size())return cnt[p];
    else return 0;
}
 
void calCnt()
{
    vector<pair<int,int>>v(sa.states.size());
    for (int i = 0; i < sa.states.size(); i++)
        v[i] = {sa.states[i].len, i};
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    for (auto va : v){
        auto len=va.first,id=va.second;
        if (sa.states[id].link != -1)
            cnt[sa.states[id].link] += cnt[id];
    }
    cnt[0] = 1; // dorkar onujayi change korte hobe
}
 
ll dfs(int par)
{
    if(dp[par])return dp[par];
    for(int i=0;i<26;i++){
        if(sa.states[par].next[i]!=-1)dp[par]+=dfs(sa.states[par].next[i]);
    }
    // dp[par]+=cnt[par];  
    dp[par]++; // for finding distinct subsstring use this
    return dp[par];
}
 
 
void Find(ll k){
    string res = "";
    int u=0;
    while(k){  //for distinct
    // while(k>=cnt[u]){
        // k-=cnt[u];
        for(int i=0;i<26;i++){
            if( sa.states[u].next[i] != -1 ){
                if( dp[ sa.states[u].next[i] ]<k ){ // for distinct 
                // if( dp[ sa.states[u].next[i] ]<=k ){ // else
                    k-=dp[ sa.states[u].next[i] ];
                }else{
                    k--; //for distinct else comment it
                    res+= (char)( i+'a' );
                    u = sa.states[u].next[i];
                    break;
                }
            }
        }
    }
    cout<<res<<endl;
}
 
 
void solve()
{
    cin>>s1;
    n=s1.size();
    sa.init(s1);
 
    calCnt();
    dfs(0);
    ll nth;
    cin>>nth;
    Find(nth);
}
 
int main(){
    int t;
    // cin>>t;
    t=1;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    
}