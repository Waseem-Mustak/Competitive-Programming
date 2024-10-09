ll Distance[N],visited[N];
vector<pair<ll,ll>>v[N];

void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q ; // min priority queue
    q.push({0,1});
    Distance[1]=0;
    while(!q.empty()){
        auto present_node=q.top();
        q.pop();
        if(visited[present_node.s]==1)continue;   // already visited
        visited[present_node.s]=1;
        for(auto child: v[present_node.s]){
            if(present_node.f+child.s < Distance[child.f]){
                Distance[child.f]=present_node.f+child.s;
                q.push({Distance[child.f] , child.f});
            }
        }
    }
}

ll father[N];
vector<ll>v[N];
void bfs(ll n){
    queue<ll>q;q.push(n);
    vis[n]=1;
    while(!q.empty()){
        ll a=q.front();
        for(auto va:v[a]){
            if(vis[va]==0){
                q.push(va);
                vis[va]=1;
                father[va]=a;
            }
        }
        q.pop();
    }
}
