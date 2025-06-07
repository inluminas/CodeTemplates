const int lmt = 2e5 + 5;
ll a[lmt], n, mx[lmt][20], pw[lmt];

void build(){
    for(int i = 2; i <= n; i++){
        pw[i] = pw[i / 2] + 1;
    }

    for(int i = 1; i <=n ; i++) mx[i][0] = a[i];

    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            if(i + (1 << (j - 1)) <= n){
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

ll query(int l, int r){
    if(r < l) return 0LL;

    int len = pw[r - l + 1];
    return max(mx[l][len], mx[r - (1 << len) + 1][len]);
}
