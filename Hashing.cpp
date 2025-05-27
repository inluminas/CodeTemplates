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

class Hash{ // 1 indexed hashing
public:
    vector<ll>hash1,hash2;
    int n;
    void init(string s){ // for numbers -> vector<ll>s
        n = s.size();
        hash1.resize(n + 2, 0LL);
        hash2.resize(n + 2, 0LL);
        for(int i = 1; i <= n; i++){
            hash1[i] = ((hash1[i - 1] * base1) % MOD1 + s[i - 1]) % MOD1;
            hash2[i] = ((hash2[i - 1] * base2) % MOD2 + s[i - 1]) % MOD2;
        }
    }

    ll queryhash(int l, int r){
        ll h1 = 0LL, h2 = 0LL;

        h1 = (hash1[r] - (hash1[l - 1] * pw1[r - l + 1]) % MOD1 + MOD1 ) % MOD1;
        h2 = (hash2[r] - (hash2[l - 1] * pw2[r - l + 1]) % MOD2 + MOD2 ) % MOD2;

        return (h1 << 32) | h2;
        // return h1;
    }
};
