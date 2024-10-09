loop(i,1,n){
    loop(j,1,n){
        if(i==j)Distance[i][j]=0;
        else Distance[i][j]=1e18;
    }
}
loop(i,1,m)
{
    cin>>a>>b>>c;
    Distance[a][b]=min(Distance[a][b],c);
    Distance[b][a]=min(Distance[b][a],c);
}

loop(k,1,n){
    loop(i,1,n){
        loop(j,1,n)
        {
            Distance[i][j]=min(Distance[i][j],Distance[i][k]+Distance[k][j]);
        }
    }
}