const int MAXN = 4e5+10;

vector<int> adj[MAXN]; 
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int value[MAXN]; 
int currentPos;  
int segTree[MAXN * 4]; 

vector<int>w[MAXN];


int dfs(int u) {
    int size = 1, maxSubtree = 0;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int subtreeSize = dfs(v);
        size += subtreeSize;
        if (subtreeSize > maxSubtree) {
            maxSubtree = subtreeSize;
            heavy[u] = v;
        }
    }
    return size;
}


void decompose(int u, int h) {
    head[u] = h; 
    pos[u] = ++currentPos; 
    if (heavy[u] != -1) {
        decompose(heavy[u], h); 
    }
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v); 
        }
    }
}


void updateRange(int node, int start, int end, int l, int r, int val) {
    if (start > r || end < l) return; 
    if (start >= l && end <= r) { 
        segTree[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r, val);
    updateRange(node * 2 + 1, mid + 1, end, l, r, val);
}

int queryPoint(int node, int start, int end, int idx) {
    if (start == end) return segTree[node]; 
    int mid = (start + end) / 2;
    if (idx <= mid) return segTree[node] + queryPoint(node * 2, start, mid, idx);
    else return segTree[node] + queryPoint(node * 2 + 1, mid + 1, end, idx);
}

// updates all ancestors of u till root
void updateAncestors(int u, int n) {
    while (u != -1) {
        updateRange(1, 1, n, pos[head[u]], pos[u], 1);
        u = parent[head[u]]; 
    }
}

// queries the updated value of node u
int queryNode(int u) {
    return queryPoint(1, 1, currentPos, pos[u]);
}

void solve(int tst) {
    int n; 
    cin >> n;
 
    for(int i=1;i<=n;i++){
        int W; cin>>W;
        w[W].push_back(i);
    }
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    memset(heavy, -1, sizeof(heavy));
    parent[1] = -1;
    depth[1] = 0;
    currentPos = 0;
 
    
    dfs(1);
    decompose(1, 1);
}
