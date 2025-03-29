const int lmt=1e5+5;
int lvl[lmt],n,k,subn,subtree[lmt],fre[lmt];
vector<int>adj[lmt];
bool iscentroid[lmt];
ll ans=0;

int dfs(int u,int p){
    subtree[u]=1;
    for(int v:adj[u]){
        if(v==p or iscentroid[v]) continue;
        subtree[u]+=dfs(v,u);
    }
    return subtree[u];
}

int getcentroid(int u, int p){
    for(int v:adj[u]){
        if(v==p or iscentroid[v] or subtree[v]<=(subn/2)) continue;
        return getcentroid(v,u);
    }
    return u;
}

void getlvl(int u, int p,bool state){
    if(!state) fre[lvl[u]]++;
    else fre[lvl[u]]--;

    for(int v:adj[u]){
        if(v==p or iscentroid[v]) continue;
        lvl[v]=lvl[u]+1;
        getlvl(v,u,state);
    }
}

void dfs2(int u, int p){
    if(k>=lvl[u]) ans+=(fre[k-lvl[u]]);
    for(int v:adj[u]){
        if(iscentroid[v] or v==p) continue;
        dfs2(v,u);
    }
}

void compose(int u, int p, int parcentroid){
    subn=dfs(u,p);
    int cen=getcentroid(u,p);
    iscentroid[cen]=true;

    lvl[cen]=0;
    getlvl(cen,0,0);

    ans+=fre[k];

    for(int v:adj[cen]){
        if(iscentroid[v]) continue;
        getlvl(v,cen,1);
        dfs2(v,cen);
        getlvl(v,cen,0);
    }

    getlvl(cen,0,1);

    for(int v:adj[cen]){
        if(iscentroid[v]) continue;
        compose(v,cen,cen);
    }
}

void solve(int tst){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    compose(1,0,0);    
    cout<<(ans/2)<<endl;
    return;
}
