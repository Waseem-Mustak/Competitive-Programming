/////Sarray
struct sortCyclicShiftStr{
    string str;int size;
    vector<int> powerOfTwo;
    vector<int> P,C;   // p[i] means string started from P[i]th
//(o index) position is the ith lexografically longest substring
// C[i] means string started from ith position is the 
//C[i]th lexographically logest string of all distrinc substring
    sortCyclicShiftStr(string s){
        str=s;size=s.size();
        P.resize(size);
        C.resize(size);
        build();}
    void build(){
        int tem_num=1;
        for(int i=0;i<31;i++){
            powerOfTwo.push_back(tem_num);
            tem_num*=2;}
        vector<int>tem_vec[258];
        for(int i=0;i<size;i++){tem_vec[str[i]].push_back(i);}
        int pos=0;
        for(int i=0;i<258;i++){
            for(auto val:tem_vec[i]){
                P[pos]=val;pos++;
        }} 
        C[P[0]]=0;int classes=0;
        char cur,prev;
        pair<int,int> curp,prevp;
        for (int i=1;i<size;i++){
            cur=str[P[i]];
            prev=str[P[i-1]];
            if(cur!=prev)classes++;
            C[P[i]]=classes;}        
        vector<int>temP(size),temC(size),cnt(size);
        for(int i=0;powerOfTwo[i]<size;i++){
            for(int j=0;j<size;j++){
                cnt[j]=0;
                temP[j]=P[j]-powerOfTwo[i];
                if(temP[j]<0)temP[j]+=size;
            }
            for(int j=0;j<size;j++){cnt[C[temP[j]]]++;}
            for(int j=1;j<=classes;j++){cnt[j]+=cnt[j-1];}
            for(int j=size-1;j>=0;j--){
                P[cnt[C[temP[j]]]-1]=temP[j];
                cnt[C[temP[j]]]--;}
            temC[P[0]]=0;
            classes=0;
            for(int j=1;j<size;j++){
                curp={C[P[j]],C[(P[j]+powerOfTwo[i])%size]};
                prevp={C[P[j-1]],C[(P[j-1]+powerOfTwo[i])%size]};
                if(curp!=prevp)classes++;
                temC[P[j]]=classes;
            }C=temC;
    }}
    vector<int> getP(){return P;}
    vector<int> getC(){return C;}
};
 
struct suffixArray{
    vector<int> SA; //SA[i] means string started from SA[i]th(0 index)
    //position is the ith lexografically longest suffix
    string s;int n;
    suffixArray(string st){
        s=st;n=st.size();st+="#";
        sortCyclicShiftStr min_cyclick_shift(st);
        vector<int>tem=min_cyclick_shift.getP();
        for(int i=1;i<=n;i++){SA.push_back(tem[i]);}}
    vector<int> getSuffixArray(){return SA;}  
    int leftmostPosition(string ss){
        int m=ss.size();int a=0;int b=n-1;
        while(b-a>1){
            int mid=(a+b)/2;int x=0;
            bool flag=true;
            for(int i=SA[mid];i<n;i++){
                if(x<m){
                    if(s[i]<ss[x]){
                        a=mid;flag=false;
                        break;}
                    else if(s[i]>ss[x]){
                        b=mid;flag=false;
                        break;}
                    x++;}
                else break;
            }
            if(flag){
                if(x<m)a=mid;
                else b=mid;}
        }
        int x=0;bool flag=true;
        for(int i=SA[a];i<n;i++){
            if(x<m){
                if(s[i]!=ss[x])flag=false;x++;
            }else break;
        }
        if(x<m)flag=false;
        if(flag)return a;
        x=0;flag=true;
        for(int i=SA[b];i<n;i++){
            if(x<m){
                if(s[i]!=ss[x])flag=false;x++;
            }else break;
        }
        if(x<m)flag=false;
        if(flag)return b;
        return -1;
    }
 
 
    int rightmostPosition(string ss){
        int m=ss.size();int a=leftmostPosition(ss);
        if(a==-1)return a;int b=n-1;
        while(b-a>1){
            int mid=(a+b)/2;int x=0;bool flag=true;
            for(int i=SA[mid];i<n;i++){
                if(x<m){
                    if(s[i]<ss[x]){
                        a=mid;flag=false;
                        break;}
                    else if(s[i]>ss[x]){
                        b=mid;flag=false;
                        break;}
                    x++;
                }else break;
            }
            if(flag){
                if(x<m)b=mid;
                else a=mid;
        }}
        int x=0;bool flag=true;
        for(int i=SA[b];i<n;i++){
            if(x<m){
                if(s[i]!=ss[x])flag=false;x++;
            }else break;
        }
        if(x<m)flag=false;if(flag)return b;x=0;
        flag=true;
        for(int i=SA[a];i<n;i++){
            if(x<m){
                if(s[i]!=ss[x])flag=false;x++;
            }else break;
        }
        if(x<m)flag=false;if(flag)return a;
        return -1;
    }
 
 
    vector<int> lcp_construction(){ //lcp[i] is equal to the length of the longest 
    //common prefix of the suffixes starting at SA[i] and SA[i+1]  SA means suffix array
        vector<int>rank(n,0),lcp(n-1,0);    
        for(int i=0;i<n;i++)rank[SA[i]]=i;int k=0;
        for(int i=0;i<n;i++){
            if(rank[i]==n-1){
                k=0;continue;}
            else{
                int j=SA[rank[i]+1];
                while(i+k<n && j+k<n && s[i+k]==s[j+k])k++;
                lcp[rank[i]]=k;
                if(k>0)k--;
        }}return lcp;
    }
};

/////////////STring Trie
struct Node{
    Node *position[26];
    long long cntEndwith=0;
    long long cntPrefix=0;
    bool containsKey(char ch){return (position[ch-'a']!=NULL);}
    Node * get(char ch){return position[ch-'a'];}
    void put(char ch,Node * node){position[ch-'a']=node;}  
};
 
class Trie{
public:
    Node *root;
public:
    Trie(){root= new Node();}
    ~Trie(){del(root);}
    void del(Node *node){
        for(char ch='a';ch<='z';ch++){
            if(node->containsKey(ch)){
                del(node->get(ch));
          }}
        delete(node);
    }
    void insert(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->cntPrefix++;
        }
        node->cntEndwith++;
    } 
    long long countWordsEqualTo(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return 0;
            else node=node->get(word[i]);
        }return node->cntEndwith;
    }
 
    int countWordsStartingWith(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return 0;
            else node=node->get(word[i]);
        }return node->cntPrefix;
    }
    void erase(string &word){
        Node * node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return;
            else{
                node=node->get(word[i]);
                node->cntPrefix--;
          }}node->cntEndwith--;
     }
};


struct manacher
{
    string str;long long size;
    vector<long long> PalLen;
    manacher(string s){
        for(auto x:s){
            str.push_back('#');
            str.push_back(x);}
        str.push_back('#');
        size=str.size();
        build();
    }
    void build(){
        PalLen.resize(size,1);
        long long l=1,r=1;
        for(int i=1;i<size;i++){
            PalLen[i]=max((long long)0,min(r-i,PalLen[l+r-i]));
            while(i+PalLen[i]<size && i-PalLen[i]>=0 &&str[i+PalLen[i]]==str[i- PalLen[i]]){PalLen[i]++;}
            if(i+PalLen[i]>r){
                l=i- PalLen[i];
                r=i+PalLen[i];
    }}}
    string getLongestPalindrome(){
        long long tem=0;
        for(auto x:PalLen)tem=max(tem,x);
        for(int i=0;i<size;i++){
            if(tem==PalLen[i]){
                string st;
                for(int j=i-tem+1;j<=i+tem-1;j++){
                    if(str[j]!='#')st.push_back(str[j]);}
                return st;
    }}}
};

//KMP
vector<long long> lpsOfKmp(string s){
    long long n=s.size();
    vector<long long> array(n);
    array[0]=0;long long j=0;
    for(int i=1;i<n;i++){
        while((j>0)&&(s[i]!=s[j])){j=array[j-1];}
        if(s[i]==s[j])j++;
        array[i]=j;
    }return array;
}

vector<ll> Zfunc(string s){
    ll n=s.size();
    vector<ll> Ztem(n);
    for(ll i=1,l=0,r=0;i<n;i++){
        if(i<=r)Ztem[i]=min(Ztem[i-l],r-i+1);
        while(i+Ztem[i]<n && s[Ztem[i]]==s[i+Ztem[i]]){Ztem[i]++;}
        if(i+Ztem[i]-1>r){
            l=i;
            r=i+Ztem[i]-1;}
    }return Ztem; 
}

int lexoMinRotedString(string s){ 
    s = s + s; 
    int i=0,j=1,k=0,len=s.size(); 
    while(i+k<len&&j+k<len){
        if(s[i+k]==s[j+k])k++;
        else if(s[i+k]<s[j+k]){j=max(j+k+1,i+1);k=0;}
        else {i=max(i+k+1,j+1);k=0;}
    }return min(i, j);
}



//////LCA of tree
const int N = 3e5 + 9, LG = 18;
vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int dist(int u, int v) {
  int l = lca(u, v);
  return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
int go(int u, int v, int k) {
  int l = lca(u, v);
  int d = dep[u] + dep[v] - (dep[l] << 1);
  assert(k <= d);
  if (dep[l] + k <= dep[u]) return kth(u, k);
  k -= dep[u] - dep[l];
  return kth(v, dep[v] - dep[l] - k);
}

////////HLD
ll node,q,tim=0;
ll values[N],shuffledValues[N],startTime[N],chainNum[N],subtreeSiz[N];
vector<ll>graph[N];
ll depth[N],Parr[200003][20],segTreeVal[N];

void dfs(ll u,ll p,ll d){
    Parr[u][0]=p;
    depth[u]=d;ll ans=0;
    for(auto v:graph[u]){
        if(v!=p){
            dfs(v,u,d+1);
            ans+=subtreeSiz[v];
    }}
    subtreeSiz[u]=ans+1;
}
 
void dfsHLD(ll u,ll p,ll top_node_of_chain){
    tim++;
    startTime[u]=tim;
    shuffledValues[tim]=values[u];
    chainNum[u]=top_node_of_chain;
    ll bigger_subtree=0,tem=0;
    for(auto v:graph[u]){
        if(v!=p){
            if(subtreeSiz[v]>tem){
                tem=subtreeSiz[v];
                bigger_subtree=v;
    }}}
    if(bigger_subtree)dfsHLD(bigger_subtree,u,top_node_of_chain); //same chain
    for(auto v:graph[u]){
        if(v!=p){
            if(v!=bigger_subtree){
                dfsHLD(v,u,v);    //new chain
}}}}
// segment tree iteratively
void update(ll index,ll value){
    index+=node;
    segTreeVal[index]=value;
    index/=2;
    while(index){
        segTreeVal[index]=max(segTreeVal
            [2*index],segTreeVal[2*index+1]);
        index/=2;
}}
 
ll query(ll index_1,ll index_2){
    ll ans=0;
    index_1+=node;
    index_2+=node+1;
    while(index_1<index_2){
        if(index_1 & 1){
            ans=max(ans,segTreeVal[index_1++]);}
        if(index_2 & 1){
            ans=max(ans,segTreeVal[--index_2]);}
        index_1/=2;
        index_2/=2;
    }return ans;
}

ll maxOfpathAtoB(ll a,ll b){
    ll ans=0;
    while(chainNum[a]!=chainNum[b]){
        if(depth[chainNum[a]]<depth[chainNum[b]]){
            swap(a,b);}
        ans=max(ans,query(startTime[chainNum[a]],startTime[a]));
        a=Parr[chainNum[a]][0];}
    if(depth[a]>depth[b])swap(a,b);
    ans=max(ans,query(startTime[a],startTime[b]));
    return ans;
}

ll lcaByHLD(ll a,ll b){
    while(chainNum[a]!=chainNum[b]){
        if(depth[chainNum[a]]<depth[chainNum[b]])swap(a,b);
        a=Parr[chainNum[a]][0];}
    if(depth[a]>depth[b])swap(a,b);
    return a;
}
 
void solve(){//take input
    dfs(1,0,0);
    tim=0;
    dfsHLD(1,0,1);// node,parent,chainNum
    for(int i=1;i<=node;i++){
        update(i,shuffledValues[i]);}
    while(q--){
        if(a==1){
            cin>>a>>x;
            update(startTime[a],x);}
        else{
            cin>>a>>b;
            cout<<maxOfpathAtoB(a,b)<<el;}
}}


// Centroid decomposition
Given a tree of n nodes, your task is to count
the number of distinct paths that consist of exactly k edges.
vector<ll> graph[N];
ll subtree_size[N],cnt[N];
ll ans,max_depth;
bool processed[N];
ll n,k;
ll dfsSubtreeSize(ll u,ll p=-1){
    subtree_size[u]=1;
    for(auto v:graph[u]){
        if((processed[v]==false)&&(v!=p)){
            subtree_size[u]+=dfsSubtreeSize(v,u);}}
    return subtree_size[u];
}
 
ll dfsFindCentroid(ll u,ll tree_size,ll p=-1){
    for(auto v:graph[u]){
        if((processed[v]==false)&&(v!=p)){
            if(subtree_size[v]*2>tree_size){
                return dfsFindCentroid(v,tree_size,u);
    }}}return u;
}
 
void get_cnt(ll node,ll parent,bool filling,ll depth=1){
    cnt[0]=1;
    if(depth>k)return;
    max_depth=max(max_depth,depth);
    if(filling==true)cnt[depth]++;
    else ans+=cnt[k-depth];
    for(auto va:graph[node]){
        if(va!=parent && processed[va]==false){
            get_cnt(va,node,filling,depth+1);
}}}
 
void dfsCentroidDec(ll node=1){
    ll centroid=dfsFindCentroid(node,dfsSubtreeSize(node));
    processed[centroid]=true;
    max_depth=0;
    for(auto va:graph[centroid]){
        if(processed[va]==false){
            get_cnt(va,centroid,false);
            get_cnt(va,centroid,true);
    }}
    fill(cnt + 0, cnt + max_depth + 1, 0);
    for(auto va:graph[centroid]){
        if(processed[va]==false)dfsCentroidDec(va);
}}
 
void solve(){
    cin>>n>>k;ans=0;//input
    dfsCentroidDec(1);
    cout<<ans<<el;}



///////////////////////////////////MST by DSU(from DS part)
////////////////////////////////////Bridges
vector<pair<ll,ll>>IS_BRIDGE;       

void find_bridge(ll node,ll parent){
    visited[node]=1;tim++;
    low[node]=starting_pos[node]=tim;
    for(auto child:v[node]){
        if(child==parent)continue;
        if(visited[child]==0){
            find_bridge(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>starting_pos[node]){   //part of bridge
                if(node<child)IS_BRIDGE.pb({node,child});
                else IS_BRIDGE.pb({child,node});
            }
            else{}// mearge them with one parent by DSU
        }
        else low[node]=min(low[node],starting_pos[child]);
    }
}


vector<ll> articulation_point;
void find_articulation_points(ll node,ll parent) {
    visited[node]=1;tim++;
    low[node]=starting_pos[node]=tim;ll child_count=0;
    for(auto child:v[node]){
        if(child==parent)continue;
        if(visited[child]==0){
            find_articulation_points(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=starting_pos[node] && parent!=0){   //part of articulation_points
                articulation_point.pb(node);  // this can contain same node multiple times,so for final ans, use set in main funnction
            }
            else {} // mearge them with one parent by DSU
            child_count++;
        }
        else low[node]=min(low[node],starting_pos[child]);
    }
    if(parent==0 && child_count>1)articulation_point.pb(node);
}
///////////////////////////////////Dijkstra
void dijkstra(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q ;
    q.push({0,1});Distance[1]=0;
    while(!q.empty()){
        auto present_node=q.top();q.pop();
        if(visited[present_node.s]==1)continue;
        visited[present_node.s]=1;
        for(auto child: v[present_node.s]){
            if(present_node.f+child.s < Distance[child.f]){
                Distance[child.f]=present_node.f+child.s;
                q.push({Distance[child.f] , child.f});
                father[child.first]=present_node.second;
            }
}}}
////////////////////////////////////floyd warshall
lp(i,1,m){
    cin>>a>>b>>c;
    Distance[a][b]=min(Distance[a][b],c);
    Distance[b][a]=min(Distance[b][a],c);
}

lp(k,1,n){
    lp(i,1,n){
        lp(j,1,n){
            Distance[i][j]=min(Distance[i][j],Distance[i][k]+Distance[k][j]);
}}}
/////////////////////////////////////bellman ford
vector<pair<pair<ll,ll>,ll>>v1;
lp(i,1,n-1){
    lp(j,0,m-1){
        a=v1[j].f.f;b=v1[j].f.s;
        c=v1[j].s;if(Distance[a]==1e18)continue;
        if(Distance[a]+c < Distance[b])Distance[b]=Distance[a]+c;
    }
}
ans=Distance[n];
run n times again and check Distance[n] with ans for cycle
//////////////////////////////cycle find in directed or undi.. graph
bool dfs(ll n,ll p){
    visited[n]=1;present_in_stack[n]=1;
    for(auto va:v[n]){
        if(visited[va]==0){
            if(dfs(va,n))return true;
        }
        // if((visited[va]==1)&&(present_in_stack[va]==1)&&(va!=p))  //for undirected graph  
        if((visited[va]==1)&&(present_in_stack[va]==1)){        // for directed graph
            st.push(va);return true;
        }
    }
    st.pop();present_in_stack[n]=0;return false;
}

/////////////////////////////////2-Sat by Strongly connected component
vector<ll>eadge[N],eadge_neg[N];
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
vec topo_sort;
void topo_dfs(ll n){
    vis[n]=1;
    for(auto va:eadge[n]){
        if(vis[va]==0){topo_dfs(va);
        }
    }topo_sort.push_back(n);
}
void dfs1(ll n, ll tomo){
    vis[n]=1;position_of_node[n]=tomo;
    for(auto va:eadge_neg[n]){
        if(vis[va]==0) {
            dfs1(va,tomo);
        }
    }
}
 
void solve(){
    cin>>n>>m;
    lp(i,1,n){
        char c1,c2;
        scanf(" %c %lld %c %lld", &c1, &a, &c2, &b);
        add_eadge(c1,a,c2,b);
    }
    lp(i,2,2*m+1){
        if(vis[i]==0)topo_dfs(i);
    }
    revv(topo_sort);
    lp(i,0,2*m+1)vis[i]=0;
    ll tomo=0;
    lp(i,0,2*m-1){
        if(vis[topo_sort[i]]==0){
            tomo++;dfs1(topo_sort[i],tomo);
        }
    }
    vector<char>solution;
    vec solution_2;
    ll taken_council_member=0;
    for(i=1;i<=m;i++){
        if(position_of_node[2*i]==position_of_node[2*i+1]){
            cout<<"-1"<<el;return;
        }
        if(position_of_node[2*i]<position_of_node[2*i+1]){
            solution.push_back('-');
        }
        else{
            solution.push_back('+');
            taken_council_member++;
            solution_2.push_back(i);
        }
    }
    priv(solution);
}

///////////////////////////////////////////////////// Euler cycle for undirected graph
ll eadge_vis[N];vector<pair<ll,ll>>v[N];
vec path; // a euler cycle path
void dfs(ll n=1){ 
    while(!v[n].empty()){
        auto va=v[n].back();
        v[n].pop_back();
        int child=va.f;
        int eadge_number=va.s;
        if(eadge_vis[eadge_number])continue;
        eadge_vis[eadge_number]=1;
        dfs(child);
    }
    path.pb(n);
}
// for input,,v[i].pb({a,i});eadge_vis[i]=0;//i for eadge number
// for any node,v[i].size() is odd or path size!=(totalEadge+1) print -1
///////////////from 1 to n find a euler path (directed graph)
ll eadge_out[N],eadge_in[N];vector<ll>v[N];vec path;
void dfs(ll n=1){
    while(!v[n].empty()){
        auto va=v[n].back();
        v[n].pop_back();
        int child=va;
        dfs(child);
    }
    path.pb(n);
}
void euler_path_directed(){//take input
    lp(i,2,n-1)if(eadge_in[i]!=eadge_out[i])-1;
    if((eadge_out[1]- eadge_in[1]!=1)||(eadge_in[n]- eadge_out[n]!=1))-1;
    dfs(1);
    if(path.size()!=(m+1))cout<<-1;
    revv(path);priv(path);
}
///////////////////////total_Hamiltonian_path(directed)
vector<ll>v_in[N],v_out[N],v2[N];
vector<ll> set_bits[2000000];ll dp[2000000][21];
void total_Hamiltonian_path() //n<=20{
    cin>>n>>m;
    lp(i,1,m){
        cin>>a>>b;
        v_in[a].pb(b);
        v_out[b].pb(a);
    }ara[1]=1;
    lp(i,2,20){ara[i]=ara[i-1]*2;}
    x=pow(2,n)-1;ll tem=x;
    lp(i,1,x){
        a=__builtin_popcount(i);
        v2[a].pb(i);  
        lp(j,1,n){
            if(ara[j]&i){
                set_bits[i].pb(j);
            }
        }
    }
    dp[1][1]=1;
    for(S=2;S<=tem;S++){
        if((S&1)==0) continue;
        if((S&ara[n])&&(S!=tem))continue; 
        for(auto j:set_bits[S]){
            i=j;
            for(auto x:v_out[i]){
                if(ara[x]&S){
                    dp[S][i]=(dp[S][i]+dp[S^ara[i]][x])%M;                }
            }
        }
    }
    x=pow(2,n)-1;
    cout<<dp[x][n];
}
 
// Let $dp[S][i]$ be the number of routes that visit all the cities in the subset
// $S$ and end at city $i$. The transitions will then be:
 
 
// dp[S][i]= sum of all dp[S\{i}][x]  where x is adjacent of i and,x is a member of set S
// s\{i} means subset S without i

//////////////////////////////////////////Max flow min cut
vector<ll>who_are_responsible_2;
void bfs1(ll n){ //for min cut,directed graph
    ..same
    while(!q.empty()){...
        who_are_responsible_2.push_back(a);
        for(auto va:v[a]){
            if((ara[va]==0)&&(weight[a][va]>0)){ q.push(va);...
            }
        }q.pop();}}

void bfs(ll n){
    queue<ll>q;q.push(n);ara[n]=1;
    while(!q.empty()){
        ll a=q.front();
        for(auto va:v[a]){
            if((ara[va]==0)&&(weight[a][va]>0)){
                q.push(va);ara[va]=1;
                father[va]=a;
            }
        }
        q.pop();
    }
}
long long max_flow(ll n){
    long long a,b,ans;ans=0;
    while(1){
        for(int i=1;i<=n;i++)ara[i]=0;
        bfs(1);
    if(ara[n]==0)break;
 
        vector<long long> path;
        long long tem_n=n;
        while(father[tem_n]!=0){
            path.pb(father[tem_n]);
            tem_n=father[tem_n];
        }
        revv(path);path.pb(n);
        long long tem_size=path.size();
        long long tem_min=INT_MAX;
        for(int i=1;i<tem_size;i++){
            a=path[i-1];b=path[i];
            tem_min=min(tem_min,weight[a][b]);
        }
        for(int i=1;i<tem_size;i++){
            a=path[i-1];b=path[i];
            weight[a][b]-=tem_min;
            weight[b][a]+=tem_min;
        }
        ans+=tem_min;
    }
    return ans;
}

void solve(){
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,c,d,x,y,z,ans,ans1;
    cin>>n>>m;
    lp(i,1,m){
        cin>>a>>b>>c;v[a].pb(b);
        v[b].pb(a);
        weight[a][b]+=c;
    }
    cout<<max_flow(n);
}





//////////////////////////////////////
////convexHull
ll orientation(const pair<ll,ll> &a,const pair<ll,ll> &b,const pair<ll,ll> &c){
    ll tem=(b.f-a.f)*(c.s-a.s)-(c.f-a.f)*(b.s-a.s);
    if (tem < 0) return -1; // clockwise
    if (tem > 0) return +1; // counter clockwise
    return 0;}
bool ccw(const pair<ll,ll> &a,const pair<ll,ll> &b,const pair<ll,ll> &c,bool include_coolinear){
    if(orientation(a,b,c)==1)return true;
    else if(orientation(a,b,c)==-1)return false;
    else return include_coolinear;
}
bool cw(const pair<ll,ll> &a,const pair<ll,ll> &b,const pair<ll,ll> &c,bool include_coolinear){
    if(orientation(a,b,c)==-1)return true;
    else if(orientation(a,b,c)==1)return false;
    else return include_coolinear;
}
void convex_hull(bool include_coolinear){
    ll i,j,k,l,m,n,o,p,q,r,t,a,b,h,c,d,e,f,x,y,z,ans,ans1;
    cin>>n;vector<pair<ll,ll>>input;
    lp(i,1,n){
        cin>>a>>b;input.pb({a,b});}
    sort(input.begin(), input.end());
    vector<pair<ll,ll>>up,down;
    pair<ll,ll>p1=input[0],p2=input[n-1];
    up.pb(p1);down.pb(p1);
    lp(i,1,n-1){
        if((i==n-1)||(cw(p1,input[i],p2,include_coolinear))){
            while(up.size()>=2){
                if(!cw(up[up.size()-2],up[up.size()-1],input[i],include_coolinear)){
                    up.pop_back();
                }else break;
            }up.push_back(input[i]);
        }
        if((i==n-1)||(ccw(p1,input[i],p2,include_coolinear))){
            while(down.size()>=2){
                if(!ccw(down[down.size()-2],down[down.size()-1],input[i],include_coolinear)){
                    down.pop_back();
                }else break;
            }down.push_back(input[i]);
     }}
    vector<pair<ll,ll>>vec_ans;
    for(i=0;i<up.size();i++)vec_ans.push_back(up[i]);
    for(i=down.size()-2;i>0;i--)vec_ans.push_back(down[i]);
    cout<<vec_ans.size()<<el;
     for(auto va:vec_ans){cout<<va.f<<" "<<va.s<<el;}
}
 
void solve(){convex_hull(true);}


//habijabi
ll is_it_in_right_left_or_touch(ll x1,ll y1,ll x2,ll y2,ll x,ll y){
    ll a=(y-y1)*(x2-x1)-(y2-y1)*(x-x1);
    if(a==0)return 0;     // touch
    if(a>0)return 1;if(a<0)return -1;
}
 
ll is_one_point_between_two_points(ll x1,ll y1,ll x2,ll y2,ll x,ll y){
    if(is_it_in_right_left_or_touch(x1,y1,x2,y2,x,y)==0){
        if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
        if((x>=x1)&&(x<=x2)&&(y>=y1)&&(y<=y2))return 1;
        else return 0;}
    else return 0;
}
 
ll Polygon_Area(ll n){
    ll a=0,b=0,ans;
    lp(i,0,n-1){
        if(i==n-1){
            a+=(Polygon_points[i].f*Polygon_points[0].s);
            b+=(Polygon_points[i].s*Polygon_points[0].f);}
        else{
            a+=(Polygon_points[i].f*Polygon_points[i+1].s);
            b+=(Polygon_points[i].s*Polygon_points[i+1].f);
    }}return abs(a-b);   // double of area
}
 
ll is_it_lies_on_right_side_or_not(ll x1,ll y1,ll x2,ll y2,ll x,ll y){
    if(y1>y2){
        swap(x1,x2);
        swap(y1,y2);}
    if((y>=y1)&&(y<=y2)){
        if(y1==y2){
            if(min(x1,x2)>=x)return 0;
            else return -5;   // ekdom touch e korena
        }
        else{
            if(is_it_in_right_left_or_touch(x1,y1,x2,y2,x,y)==1){
                if(y==y2)return -1;   // niche
                else if(y==y1)return 1;   // upore
                else return 5;   // puropuri intersect
            }else return -5;   // ekdom touch e korena
        }}else return -5;      // ekdom touch e korena
}
 
 
void insideOutsideOrBoundary(ll x,ll y,ll n){
    set<ll>stt;
    lp(i,0,n-1){
        if(i==n-1){
            if(is_one_point_between_two_points(Polygon_points[i].f,
                Polygon_points[i].s,Polygon_points[0].f,Polygon_points[0].s,x,y)==1){
                cout<<"BOUNDARY"<<el;
                return;
        }}
        else{
            if(is_one_point_between_two_points(Polygon_points[i].f,Polygon_points[i].s,
                Polygon_points[i+1].f,Polygon_points[i+1].s,x,y)==1){
                cout<<"BOUNDARY"<<el;return;
    }}}
    ll tem=0;vec v1;
    lp(i,0,n-1){
        if(i==n-1){
            ll tem_1=is_it_lies_on_right_side_or_not(Polygon_points[i].f,Polygon_points[i].s,Polygon_points[0].f,Polygon_points[0].s,x,y);
            if(tem_1!=0)v1.pb(tem_1);}
        else{
            ll tem_1=is_it_lies_on_right_side_or_not(Polygon_points[i].f,Polygon_points[i].s,Polygon_points[i+1].f,Polygon_points[i+1].s,x,y);
            if(tem_1!=0)v1.pb(tem_1);
    }}
    ll tem_2=v1.size();
    if(tem_2>0){
        lp(i,0,tem_2-1){if(v1[i]==5)tem++;}
        lp(i,0,tem_2-2){if((v1[i]==1&&v1[i+1]==-1)||(v1[i]==-1&&v1[i+1]==1))tem++;}
    }
    if(tem%2==1)cout<<"INSIDE"<<el;
    else cout<<"OUTSIDE"<<el;
}
ll number_of_lattice_points_on_line(ll x1,ll y1,ll x2,ll y2){
    ll a=abs(y1-y2);ll b=abs(x1-x2);
    if(a==0)return b+1;else if(b==0)return a+1;
    return ((a*b)/lcm(a,b))+1;
}
ll number_of_lattice_points_on_polygon(ll n){
    ll ans=0;
    lp(i,0,n-1){
        if(i==n-1){ans+=number_of_lattice_points_on_line(Polygon_points[i].f,Polygon_points[i].s,Polygon_points[0].f,Polygon_points[0].s);}
        else{ans+=number_of_lattice_points_on_line(Polygon_points[i].f,Polygon_points[i].s,Polygon_points[i+1].f,Polygon_points[i+1].s);}
    }return ans-n;}
ll number_of_lattice_points_inside_polygon(ll n){
    ll area=Polygon_Area(n)/2;
    ll tem=number_of_lattice_points_on_polygon(n);
    return area+1-(tem/2);}
    // area = number_of_lattice_points_inside_polygon+
    //(number_of_lattice_points_on_polygon/2)-1;