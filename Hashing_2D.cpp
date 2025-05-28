const ll MOD1 = 1e9 + 1011;
const ll MOD2 = 1e9 + 1011;
const ll base1 = 1e9 + 21;
const ll base2 = 1e9 + 181;
const int lmt = 1e5 + 100;
ll pw1[lmt], pw2[lmt];

void getprimebase(){
    pw1[0] = pw2[0] = 1LL;

    for(int i = 1; i < lmt ; i++) {
        pw1[i] = (pw1[i - 1] * base1) % MOD1;
        pw2[i] = (pw2[i - 1] * base2) % MOD2;
    }
}

class Hash2D{ // 1 indexed hashing
public:
    vector<vector<ll>>hash;
    int n, m;
    void init(vector<string>& s, int _n, int _m){
        n = _n; m = _m;
        hash.resize(n + 1, vector<ll>(m + 1, 0LL));

        for(int i = 1 ; i <= n; i++){
            for(int j = 1 ; j <= m; j++){
                hash[i][j] =( (hash[i - 1][j] * base1) % MOD1 + (hash[i][j - 1] * base2) % MOD1 - (((hash[i - 1][j - 1] * base1 ) % MOD1)* base2) % MOD1 + s[i - 1][j - 1] + MOD1) % MOD1;
            }
        }
    }

    ll queryhash(int x1, int y1, int x2, int y2){
        ll h = 0;

        h = (hash[x2][y2] - (hash[x1 - 1][y2] * pw1[x2 - x1 + 1] ) % MOD1 - (hash[x2][y1 - 1] * pw2[y2 - y1 + 1]) % MOD1 + (((hash[x1 - 1][y1 - 1] * pw1[x2 - x1 + 1]) % MOD1) * pw2[y2 - y1 + 1] ) % MOD1 + MOD1 + MOD1) % MOD1;

        return h;
    }
};
