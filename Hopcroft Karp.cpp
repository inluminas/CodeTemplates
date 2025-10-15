// Minimum path cover in a DAG = N - Maximum Bipartite matching in a graph of (uin, uout) version of original graph
// if in original graph (u -> v), then (uout -> vin)
class Hopcroft{
public:
    int n, res = 0;
    vector<int>mt, dis;
    vector<vector<int>>adj;
    Hopcroft(int n1, int n2){
        n = n1;
        adj.resize(n1 + n2 + 1);
        mt.resize(n1 + n2 + 1);
        dis.resize(n1 + n2 + 1);
    }

    void add_edge(int u, int v){
        adj[u].push_back(n + v);
    }

    bool bfs(){
        queue<int>q;
        for(int u = 1; u <= n; u++){
            dis[u] = 1e9;
            if(!mt[u]){
                q.push(u); dis[u] = 0;
            }
        }
        dis[0] = 1e9;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dis[mt[v]] == 1e9){
                    dis[mt[v]] = dis[u] + 1;
                    q.push(mt[v]);
                }
            }
        }
        return dis[0] != 1e9;
    }

    bool dfs(int u){
        if(!u) return true;
        for(int v : adj[u]){
            if(dis[mt[v]] == dis[u] + 1 and dfs(mt[v])){
                mt[u] = v;
                mt[v] = u;
                return true;
            }
        }
        dis[u] = 1e9;
        return false;
    }

    int maximum_matching(){
        while(bfs()){
            for(int u = 1; u <= n; u++) if(!mt[u] and dfs(u)) res++;
        }
        return res;
    }
};
