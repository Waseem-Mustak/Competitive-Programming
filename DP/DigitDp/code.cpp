#include <bits/stdc++.h>
using namespace std;

int const N=505;
#define ll long long

ll dp[20][2][20];
ll func(string &num,ll pos,ll flag,ll cnt){ 
    if(pos==num.size()){
        if(cnt>3)return 0;
        else return 1;
    }
    if(dp[pos][flag][cnt]!=-1)return dp[pos][flag][cnt];
    ll limit= (flag==1?num[pos]-'0':9);
    ll ans=0;
    for(int i=0;i<=limit;i++){
        ll updatedCnt=cnt+(i>0);
        ans+=func(num,pos+1,flag & (i==limit),updatedCnt);
    }
    return dp[pos][flag][cnt]=ans;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    string s=to_string(b);
    ll right=func(s,0,1,0);
    memset(dp,-1,sizeof(dp));
    s=to_string(a-1);
    ll left=func(s,0,1,0);
    cout<<right-left<<endl;
}
//https://codeforces.com/contest/1036/problem/C
int main(){
    int t;t=1;
    cin>>t;
    while(t--){
        solve();
    }
} 