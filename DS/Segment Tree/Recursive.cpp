ll  ara[N],store_max_data_for_seg_tree[N];
ll built_max_seg_tree(ll a,ll b,ll n){
    if(a==b)return store_max_data_for_seg_tree[n]=ara[a];
    ll mid=(a+b)/2;
    return store_max_data_for_seg_tree[n]=max(built_max_seg_tree(a,mid,2*n),built_max_seg_tree(mid+1,b,2*n+1));
}

ll find_max_from_seg_tree(ll x,ll y,ll a,ll b,ll n){
    if(b<x||a>y)return -1000000000000000000;
    if(a>=x&&b<=y)return store_max_data_for_seg_tree[n];
    ll mid=(a+b)/2;
    return max(find_max_from_seg_tree(x,y,a,mid,2*n),find_max_from_seg_tree(x,y,mid+1,b,2*n+1));
}

ll change_value_in_seg_tree(ll in,ll va,ll a,ll b,ll n){
    if(in<a||in>b)return store_max_data_for_seg_tree[n];
    if(a==b)return ara[a]=store_max_data_for_seg_tree[n]=va;
    ll mid=(a+b)/2;
    return store_max_data_for_seg_tree[n]=max(change_value_in_seg_tree(in,va,a,mid,2*n),change_value_in_seg_tree(in,va,mid+1,b,2*n+1));   
}


struct segTree
{
    ll inputLen; 
    ll  input[6*N],treeValues[6*N];
    // segTree(){}
    // segTree(vector<ll> v1)
    // {
    //     inputLen=v1.size();
    //     for(int i=1;i<=inputLen;i++)input[i]=v1[i-1];
    //     build(1,inputLen,1);
    // }

    ll build(ll a,ll b,ll n){
        if(a==b)return treeValues[n]=input[a];
        ll mid=(a+b)/2;
        return treeValues[n]=(build(a,mid,2*n)+build(mid+1,b,2*n+1));
    }


    ll query(ll x,ll y,ll a,ll b,ll n){
        if(b<x||a>y)return 0;
        if(a>=x&&b<=y)return treeValues[n];
        ll mid=(a+b)/2;
        return (query(x,y,a,mid,2*n)+query(x,y,mid+1,b,2*n+1));
    }

    ll update(ll in,ll va,ll a,ll b,ll n){
        if(in<a||in>b)return treeValues[n];
        if(a==b)return treeValues[n]=va;
        ll mid=(a+b)/2;
        return treeValues[n]=(update(in,va,a,mid,2*n)+update(in,va,mid+1,b,2*n+1));   
    }
}sg;
