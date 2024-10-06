//1D SparseTable // change gcd to max/min
const int MAXlogN=21;
ll inputLen;  // n
ll input[N],Log[N],table[N][MAXlogN];

void buildSparse(){
    for(int i=1;i<=inputLen;i++) table[i][0]=input[i];
    for(int i=2;i<=inputLen;i++) Log[i]=Log[i-1] + !(i&(i-1));
    
    for(int j=1; (1<<j)<=inputLen ;j++){
        for(int i=1; (i+ (1<<j)-1) <=inputLen; i++)
            table[i][j]=gcd(table[i][j-1],table[i+(1<<(j-1))][j - 1]);
    }
}

int Query(int i,int j){
    int k=Log[j-i+1];
    return gcd(table[i][k],table[j-(1<<k)+1][k]);
}


struct SparseTable
{
    ll inputLen;  // n
    ll input[N],Log[N],table[N][21];
    SparseTable(){}
    SparseTable(vector<int> v1)
    {
        inputLen=v1.size();
        for(int i=1;i<=inputLen;i++)input[i]=v1[i-1];
        buildSparse();
    }

    void buildSparse(){
        for(int i=1;i<=inputLen;i++) table[i][0]=input[i];
        for(int i=2;i<=inputLen;i++) Log[i]=Log[i-1] + !(i&(i-1));
        
        for(int j=1; (1<<j)<=inputLen ;j++){
            for(int i=1; (i+ (1<<j)-1) <=inputLen; i++)
                table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j - 1]);
        }
    }

    int Query(int i,int j){
        int k=Log[j-i+1];
        return min(table[i][k],table[j-(1<<k)+1][k]);
    }
}; 
