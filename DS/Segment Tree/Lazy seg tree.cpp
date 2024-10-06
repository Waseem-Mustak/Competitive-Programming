ll  ara[N],lazy[N],store_min[N];

ll build(ll a,ll b,ll n){
    lazy[n]=0;
    if(a==b)return store_min[n]=ara[a];
    ll mid=(a+b)/2;
    return store_min[n]=min(build(a,mid,2*n),build(mid+1,b,2*n+1));
}

void lazy_propagate(ll a,ll b,ll n){
    store_min[n]+=lazy[n];
    if(a!=b){
        lazy[2*n]+=lazy[n];
        lazy[(2*n)+1]+=lazy[n];
    }
    lazy[n]=0;
}

ll find_range_min(ll l,ll r,ll a,ll b,ll n){
    lazy_propagate(a,b,n);

    if(b<l||a>r)return 1000000000000000000;
    if(a>=l&&b<=r)return store_min[n];
    ll mid=(a+b)/2;
    return min(find_range_min(l,r,a,mid,2*n),find_range_min(l,r,mid+1,b,2*n+1));
}

ll range_increase(ll l,ll r,ll va,ll a,ll b,ll n){
    lazy_propagate(a,b,n);

    if((b<l)||(a>r)) return store_min[n];
    if((a>=l)&&(b<=r)){
        lazy[n]+=va;
        lazy_propagate(a,b,n);
        // if(a!=b){
        //     lazy[2*n]+=va;
        //     lazy[(2*n)+1]+=va;
        // }
        // store_min[n]+=(va);
        return store_min[n];
    }
    ll mid=(a+b)/2;
    return store_min[n]=min(range_increase(l,r,va,a,mid,2*n),range_increase(l,r,va,mid+1,b,2*n+1));
}



struct lazyTree
{
    ll inputLen;  // n
    ll  input[N],lazy[N],treeValues[N];
    lazyTree(){}
    lazyTree(vector<ll> v1)
    {
        inputLen=v1.size();
        for(int i=1;i<=inputLen;i++)input[i]=v1[i-1];
        buildLazyTree(1,inputLen,1);
    }

    ll buildLazyTree(ll a,ll b,ll n){
        lazy[n]=0;
        if(a==b)return treeValues[n]=input[a];
        ll mid=(a+b)/2;
        return treeValues[n]=max(buildLazyTree(a,mid,2*n),buildLazyTree(mid+1,b,2*n+1));
    }

    void lazy_propagate(ll a,ll b,ll n){
        treeValues[n]+=lazy[n];
        if(a!=b){
            lazy[2*n]+=lazy[n];
            lazy[(2*n)+1]+=lazy[n];
        }
        lazy[n]=0;
    }

    ll query(ll l,ll r,ll a,ll b,ll n){
        lazy_propagate(a,b,n);

        if(b<l||a>r)return -1000000000000000;
        if(a>=l&&b<=r)return treeValues[n];
        ll mid=(a+b)/2;
        return max(query(l,r,a,mid,2*n),query(l,r,mid+1,b,2*n+1));
    }

    ll range_increase(ll l,ll r,ll va,ll a,ll b,ll n){
        lazy_propagate(a,b,n);

        if((b<l)||(a>r)) return treeValues[n];
        if((a>=l)&&(b<=r)){
            lazy[n]+=va;
            lazy_propagate(a,b,n);
            // if(a!=b){
            //     lazy[2*n]+=va;
            //     lazy[(2*n)+1]+=va;
            // }
            // treeValues[n]+=(va);
            return treeValues[n];
        }
        ll mid=(a+b)/2;
        return treeValues[n]=max(range_increase(l,r,va,a,mid,2*n),range_increase(l,r,va,mid+1,b,2*n+1));
    }
};
