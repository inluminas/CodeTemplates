const ll lmt = 2e5 + 10;
ll c[lmt], n, sz[lmt], cnt[lmt], res[lmt], freq[lmt], last = 0;
vector<ll>adj[lmt];

void getsz(ll u, ll p){
    sz[u] = 1;
    for(ll v : adj[u]){
        if(v == p) continue;
        getsz(v, u); sz[u] += sz[v];
    }
}

void add(ll u, ll p, ll x, ll avoid){
    cnt[c[u]] += x;

    for(ll v : adj[u]){
        if(v == p or v == avoid) continue;
        add(v, u, x, avoid);
    }
}

void dsu(ll u, ll p, bool keep){
    ll bigchild = -1;
    for(ll v : adj[u]){
        if(v == p ) continue;
        if(bigchild == -1 or sz[bigchild] < sz[v]) bigchild = v; 
    }
    for(ll v : adj[u]){
        if(v == p or v == bigchild) continue;
        dsu(v, u, 0);
    }
    if(bigchild != -1) dsu(bigchild, u, 1);
    add(u, p, 1, bigchild);

    // calculate results for all queries of node u

    if(!keep) add(u, p, -1, -1);
}
