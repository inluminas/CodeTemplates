const int lmt=1e5+5;
vector<int>adj[lmt];
bool iscentroid[lmt];
char ans[lmt];
int n,sub[lmt],anslvl[lmt];

int dfs(int u, int p){
    sub[u]=1;
    for(int v:adj[u]){
        if(v==p or iscentroid[v]) continue;
        sub[u]+=dfs(v,u);
    }
    return sub[u];
}

int getcentroid(int u, int p){
    for(int v:adj[u]){
        if(v==p or iscentroid[v] or sub[v]<=(n/2)) continue;
        return getcentroid(v,u);
    }
    return u;
}

void compose(int u, int p,int parcentroid){
    n=dfs(u,p);
    int cen=getcentroid(u,p);
    iscentroid[cen]=true;

    anslvl[cen]=anslvl[parcentroid]+1;
    ans[cen]='A'+anslvl[cen]-1;

    for(int v:adj[cen]){
        if(iscentroid[v]) continue;
        compose(v,cen,cen);
    }
}

void solve(int tst){
    cin>>n;
    int n2=n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    compose(1,0,0);
    for(int i=1;i<=n2;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
}
