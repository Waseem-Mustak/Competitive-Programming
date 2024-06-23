ll siz[N],rnk[N],parent[N];
ll global_ans_number_of_connected_component,
    global_ans_max_size_from_all_connected_components;

void make(ll n) {// create node
    parent[n]=n;rnk[n]=1;
    siz[n]=1;
}

ll find(ll n) {     // return the supreme parent of n
    if(parent[n]==n)return n;
    else return parent[n]=find(parent[n]);
}


void Union(ll a,ll b){  // add node a and b in one set
    a=find(a);
    b=find(b);
    // if(a!=b)   // union by rank
    // {
    //   if(rnk[a]<rnk[b])
    //   {
    //       swap(a,b);
    //   }
    //   parent[b]=a;
    //   if(rnk[a]==rnk[b])
    //   {
    //       rnk[a]++;
    //   }
    // }

    if(a!=b)   // union by size
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
        
        global_ans_number_of_connected_component--;
        global_ans_max_size_from_all_connected_components=
            max(siz[a],global_ans_max_size_from_all_connected_components);
    }
}
