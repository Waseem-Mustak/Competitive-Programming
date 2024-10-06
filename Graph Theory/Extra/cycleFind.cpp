ll visited[N],present_in_stack[N];
bool dfs(ll n,ll p){
    visited[n]=present_in_stack[n]=1;
    for(auto va:v[n]){
        if(visited[va]==0){
            if(dfs(va,n)) return true;
        }
        if((visited[va]==1)&&(present_in_stack[va]==1)&&(va!=p))  //for undirected graph  
        // if(visited[va]==1&&present_in_stack[va]==1)//for directed graph(bacause here 1->2 ans 2->1 eadge exist so ans is 1 2 1 but is undirected part at list 3 node need)
        {return true;}
    }
    present_in_stack[n]=0;
    return false;
}