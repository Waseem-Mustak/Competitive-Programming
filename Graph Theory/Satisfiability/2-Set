#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N=1e6+2;
#define ll long long

ll ara[N],ara1[N],ara2[N],position_of_node[N],vis[N];
vector<ll>topo_sort,eadge[N],eadge_neg[N];

void add_eadge(char c1,ll a,char c2,ll b){
    a=2*a^(c1=='-');
    b=2*b^(c2=='-');
    ll neg_a=a^1;
    ll neg_b=b^1;
    eadge[neg_b].push_back(a);
    eadge[neg_a].push_back(b);
 
    eadge_neg[a].push_back(neg_b);
    eadge_neg[b].push_back(neg_a);
}

void topo_dfs(ll n){
    vis[n]=1;
    for(auto va:eadge[n]){
        if(vis[va]==0){
            topo_dfs(va);
        }
    }
    topo_sort.push_back(n);
}

void dfs1(ll n,ll tomo){
    vis[n]=1;
    position_of_node[n]=tomo;
    for(auto va:eadge_neg[n]){
        if(vis[va]==0){
            dfs1(va,tomo);
        }
    }
}


void solve(){
    //input n 
    // initialize everything
    // input array and call add eadges properly
    // eample add_eadge('-',abs(a),'-',abs(b)); 1<=a,b<=n

    for(int i=2;i<=2*n+1;i++){
        if(vis[i]==0){
            topo_dfs(i);
        }
    }
    reverse(topo_sort.begin(),topo_sort.end());
    for(int i=0;i<=2*n+1;i++)vis[i]=0;
    ll tomo=0;
    for(int i=0;i<=2*n-1;i++){
        if(vis[topo_sort[i]]==0){
            tomo++;
            dfs1(topo_sort[i],tomo);
        }
    }
    vector<char>solution;  
    // main part
    for(int i=1;i<=n;i++){
        if(position_of_node[2*i]==position_of_node[2*i+1]){
            cout<<"NO\n";return;
        }
        if(position_of_node[2*i]<position_of_node[2*i+1]){
            solution.push_back('-');
        }
        else{
            solution.push_back('+');
        }
    }
    cout<<"YES"<<'\n';
    for(auto va:solution)cout<<va<<" ";
    cout<<'\n';
}
 
int main(){
    fast;     
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
