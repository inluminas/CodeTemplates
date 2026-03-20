struct SuffixArray{
    string s;
    int n;
    vector<int>p, c, lcp;
    SuffixArray(string _s){
        s = _s + '$';
        n = (int)s.size();
        build();
        buildlcp();
    }

    void counting_sort(vector<int>&p, vector<int>&c){
        vector<int>cnt(n);
        for(int x : c) cnt[x]++;
        vector<int>pos(n);
        pos[0] = 0;
        for(int i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<int>res(n);
        for(int x : p){
            int i = c[x];
            res[pos[i]] = x;
            pos[i]++;
        }
        p = res;
    }

    void build(){
        vector<pair<char, int>>a(n);
        for(int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        p.resize(n); c.resize(n);
        for(int i = 0; i < n; i++) p[i] = a[i].ss;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            c[p[i]] = c[p[i - 1]] + (a[i].ff != a[i - 1].ff);
        }

        int k = 0;

        while((1LL << k) < n){
            for(int i = 0; i < n; i++){
                p[i] = (p[i] - (1LL << k) + n) % n;
            }

            counting_sort(p, c);
            vector<int>res(n);
            res[p[0]] = 0;

            for(int i = 1; i < n; i++){
                pair<int, int> now = {c[p[i]], c[(p[i] + (1LL << k)) % n]};
                pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1LL << k)) % n]};
                res[p[i]] = res[p[i - 1]] + (prev != now);
            }

            c = res;
            k++;
        }
    }

    void buildlcp(){
        lcp.resize(n + 1);
        int k = 0;
        for(int i = 0; i < n - 1; i++){
            int pi = c[i];
            int j = p[pi - 1];
            while(s[i + k] == s[j + k]) k++;
            lcp[c[i]] = k;
            k = max(0LL, k - 1);
        }
    }
};