// checks if, in a range certain wanted numbers have odd or even apperances
// https://codeforces.com/blog/entry/85900
// problem -> You have an array A
//  and Q
//  queries, which are, say if the subarray from l
//  to r
// , (A[l]
// , A[l+1]
// , ...
// , A[r]
// ) forms a permutation.


#define randseed srand(chrono::steady_clock::now().time_since_epoch().count());

void solve(int tst){
    randseed

    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int b[n + 1];

    for(int i = 1; i <= n; i++){
        b[i] = rand();
    }

    ll pre[n + 1]; pre[0] = 0;
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] ^ b[a[i]];

    ll check[n + 1]; check[0] = 0;
    for(int i = 1; i <= n; i++){
        check[i] = check[i - 1] ^ b[1];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        ll res = pre[r] ^ pre[l - 1];

        if(res == check[r - l + 1]) cout << "It is a permutation" << endl;
        else cout << "Not a permutation" << endl;
    }
}
