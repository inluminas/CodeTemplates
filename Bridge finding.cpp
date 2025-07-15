const int lmt = 1e5 + 5;
vector<int>adj[lmt];
ll n, m;
ll ans, tin[lmt], low[lmt], timer;
bool vis[lmt];

void dfs(int u, int p){
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    bool parent_skipped = false;
    for(int v : adj[u]){
        if(v == p and !parent_skipped){ // handles multi-edge cases
            parent_skipped = true;
            continue;
        }

        if(vis[v]){
            low[u] = min(low[u], tin[v]);
            continue;
        }

        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if(low[v] > tin[u]){
            // is_bridge(u, v)
        }
    }
}
