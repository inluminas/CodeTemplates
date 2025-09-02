class persistent_segtree{
public:
    vector<int>tree, ver, lft, rght;
    int curpos = 0;

    void init(int N){
        tree.resize(20 * N + 1);
        ver.resize(N + 1);
        lft.resize(20 * N + 1);
        rght.resize(20 * N + 1);
    }

    void build(int at, int L, int R){
        if(L == R){
            tree[at] = 0;
            return;
        }
        int mid = (L + R ) >> 1;
        lft[at] = ++curpos, rght[at] = ++curpos;
        build(lft[at], L, mid); build(rght[at], mid + 1, R);
        tree[at] = tree[lft[at]] + tree[rght[at]];
        return;
    }

    int update(int at, int L, int R, int pos, int val){
        if(pos < L or R < pos) return at;
        
        int newat = ++curpos;

        if(L == R){
            tree[newat] = tree[at] + val;
            return newat;
        }

        int mid = (L + R ) >> 1;
        lft[newat] = update(lft[at], L, mid, pos, val);
        rght[newat] = update(rght[at], mid + 1, R, pos, val);
        tree[newat] = tree[lft[newat]] + tree[rght[newat]];
        return newat;
    }

    int query(int at, int L, int R, int l, int r){
        if(R < l or r < L or r < l) return 0;
        if(l <= L and R <= r) return tree[at];

        int mid = (L + R) >> 1;
        int x = query(lft[at], L, mid, l, r), y = query(rght[at], mid + 1, R, l, r);
        return x + y;
    }


    // given an array, in a online query for (l, r, k) -> find the kth element in between [l, r] range if [l, r] is sorted .
    // the i'th version is for i'th element of the array, and the update is on value's position (coordinate compres the values)
    // Lver = l - 1, Rver = r;
    int find_kth(int Lver, int Rver, int L, int R, int k){
        if(L == R) return L;
        int cnt = tree[lft[Rver]] - tree[lft[Lver]];
        int mid = (L + R ) >> 1;
        if(k <= cnt) return find_kth(lft[Lver], lft[Rver], L, mid, k);
        return find_kth(rght[Lver], rght[Rver], mid + 1, R, k - cnt);
    }
};

int main(){
    // kth element in sorted [l, r]

    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    
    for(int i = 1; i <= n; i++) b.push_back(a[i]);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int>mp;
    for(int i = 0; i < b.size(); i++) mp[b[i]] = i + 1;

    persistent_segtree p;
    p.init(max(n, m));
    p.ver[0] = ++p.curpos;

    p.build(1, 1, m);

    for(int i = 1; i <= n; i++){
        p.ver[i] = p.update(p.ver[i - 1], 1, m, mp[a[i]], 1);
    }

    while(q--){
        int l, r, k; cin >> l >> r >> k;

        cout << b[p.find_kth(p.ver[l - 1], p.ver[r], 1, m, k) - 1] << endl;
    }
}
