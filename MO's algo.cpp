const int lmt = 2e5 + 100;
int block_sz, n, q;

struct query{
    int l, r, idx;
    bool operator<(query other) const {
        return make_pair(l / block_sz, r) < make_pair(other.l / block_sz, other.r);
    }
};

void add(int i){

}

void remove(int i){

}

void solve(int tst){

    block_sz = sqrt(n);
    if(block_sz * block_sz < n) block_sz++;

    query Q[q + 1];
    for(int i = 1; i <= q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }

    sort(Q + 1, Q + q + 1);

    int L = 1, R = 0;

    for(int i = 1; i <= q; i++){
        while(R < Q[i].r){
            R++;
            add(R);
        }

        while(L > Q[i].l){
            L--;
            add(L);
        }

        while(L < Q[i].l){
            remove(L);
            L++;
        }

        while(R > Q[i].r){
            remove(R);
            R--;
        }

        // calculate answer for this query
    }
}
