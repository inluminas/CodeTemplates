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

void propagate(int at, int L, int R){
    if(!lazy[at]) return;
    seg[at] += ((R - L + 1) * lazy[at]);
    if(L != R){
        lazy[at << 1] += lazy[at], lazy[at << 1 | 1] += lazy[at];
    }
    lazy[at] = 0;
    return;
}

void build(int at,int L,int R){
    lazy[at] = 0;
    if(L==R){
        seg[at]=b[L];
        return;
    }
    int mid=(L+R)>>1;
    build(at*2,L,mid); build(at*2+1,mid+1,R);
    seg[at]=seg[at*2]+seg[at*2+1];
}

void update(int at, int L, int R, int l, int r, int val){
    propagate(at, L, R);
    if(r < l or R < l or r < L) return;
    if(l <= L and R <= r){
        lazy[at] += val;
        propagate(at, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(at << 1, L, mid, l, r, val);
    update(at << 1 | 1, mid + 1, R, l, r, val);
    seg[at] = seg[at << 1] + seg[at << 1 | 1];
}

int query(int at,int L,int R,int l,int r){
    propagate(at, L, R);
    if(r<L or R<l or r<l) return 0LL;
    if(l<=L && R<=r) return seg[at];
    int mid=(L+R)>>1;
    int x=query(at*2,L,mid,l,r), y=query(at*2+1,mid+1,R,l,r);
    return (x+y);
}

void hldupdate(int u, int v, int val){
    while(head[u] != head[v]){
        if(dep[head[u]] < dep[head[v]]) swap(u, v);
        update(1, 1, n, pos[head[u]], pos[u], val);
        u = par[head[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    update(1, 1, n, pos[u], pos[v], val);
    return;
}

int hldquery(int u, int v){
    int res = 0;
    while(head[u] != head[v]){
        if(dep[head[u]] < dep[head[v]]) swap(u, v);
        res += query(1, 1, n, pos[head[u]], pos[u]);
        u = par[head[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    res += query(1, 1, n, pos[u], pos[v]);
    return res;
}
