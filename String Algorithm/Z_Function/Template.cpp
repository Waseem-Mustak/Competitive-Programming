vector<ll> z_function(string s){
    ll n=s.size();
    vector<ll> zVec(n);
    for(ll i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            zVec[i]=min(zVec[i-l],r-i+1);
        }
        while(i+zVec[i]<n && s[zVec[i]]==s[i+zVec[i]]){
            zVec[i]++;
        }
        if(i+zVec[i]-1>r){
            l=i;
            r=i+zVec[i]-1;
        }
    }
    return zVec;
}
