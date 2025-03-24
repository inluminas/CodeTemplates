const int lmt=1e5+5;
int head[lmt],heavy[lmt],par[lmt],lvl[lmt],curpos=0,n,b[lmt],a[lmt],pos[lmt],seg[4*lmt];
vector<int>adj[lmt];

int dfs(int u, int p){
    par[u]=p;
    lvl[u]=lvl[p]+1;
    int sz=1,mx=0;
    for(int v:adj[u]){
        if(v==p) continue;
        int subtree=dfs(v,u);
        if(subtree>mx){
            mx=subtree;
            heavy[u]=v;
        }
        sz+=subtree;
    }
    return sz;
}

void hld(int u, int h){
    head[u]=h;
    pos[u]=++curpos;
    b[curpos]=a[u];
    
    if(!heavy[u]) return;
    
    hld(heavy[u],h);

    for(int v:adj[u]){
        if(v==par[u] or v==heavy[u]) continue;
        hld(v,v);
    }
}

void build(int at,int L,int R){
    if(L==R){
        seg[at]=b[L];
        return;
    }
    int mid=(L+R)>>1;
    build(at*2,L,mid); build(at*2+1,mid+1,R);
    seg[at]=seg[at*2]+seg[at*2+1];
}

void update(int at,int L, int R, int pos, int val){
    if(L==R){
        seg[at]+=val;
        return;
    }
    int mid=(L+R)>>1;
    if(pos<=mid) update(at*2,L,mid,pos,val);
    else update(at*2+1,mid+1,R,pos,val);
    seg[at]=seg[at*2]+seg[at*2+1];
}

int query(int at,int L,int R,int l,int r){
    if(r<L or R<l or r<l) return 0LL;
    if(l<=L && R<=r) return seg[at];
    int mid=(L+R)>>1;
    int x=query(at*2,L,mid,l,r), y=query(at*2+1,mid+1,R,l,r);
    return (x+y);
}

int getans(int u, int v){
    int res=0;
    while(head[u]!=head[v]){
        if(lvl[head[u]]<lvl[head[v]]) swap(u,v);
        res+=query(1,1,n,pos[head[u]],pos[u]);
        u=par[head[u]];
    }
    if(lvl[u]>lvl[v]) swap(u,v);
    res+=query(1,1,n,pos[u],pos[v]);
    return res;
}
