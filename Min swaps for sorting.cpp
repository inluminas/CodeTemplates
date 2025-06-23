// minimum number of operations to sort a permutation , the operation is to swap any two indices (i, j) [ 1 <= i <= j <= n]
// if we make a directed graph to visualize it, we add edge from the index to the value because that position wants to to the position of the value
// a[]  = 4, 1, 3, 2
//index = 1, 2, 3, 4    -> Here the index 4 wants to go to index 2, because the value is 2, so basically we add edge, index -> a[index]. [it will always be a circle or a single node]
// for componenet the result = component size - 1, so for the whole graph, the result = n - component number
// bonus problem : for each of q queries we swap two values of the array, find the min operation for each query - > https://codeforces.com/contest/1768/problem/D

const int lmt = 2e5 + 5;
int par[lmt];
 
int findpar(int u){
    if(par[u] == u) return u;
    return par[u] = findpar(par[u]);
}
 
void merge(int u, int v){
    int pu = findpar(u), pv = findpar(v);
    if(pu == pv) return;
    par[pu] = pv;
    return;
}
 
void solve(int tst){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1; i <= n; i++){
        int p; cin >> p;
        merge(p, i);
    }
 
    bool head[n + 1];
    memset(head, 0, sizeof(head));
 
    int res = 0;
 
    for(int i = 1; i <= n; i++){
        int pi = findpar(i);
        if(head[pi]) continue;
        head[pi] = true;
        res++;  
    }
 
    res = n - res;
}
