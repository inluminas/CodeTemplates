struct Matrix{
    int n, m;
    vector<vector<int>>a;
    Matrix(){}
    Matrix(int _n, int _m){
        n = _n, m = _m;
        a.assign(n, vector<int>(m, 0));
    }
    Matrix(vector<vector<int>>v){
        n = (int)v.size();
        m = (n > 0 ? (int)v[0].size() : 0);
        a = v;
    }
    inline void make_unit(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = (i == j);
            }
        }
    }
    inline Matrix operator +(const Matrix &b){
        Matrix ans = Matrix(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Matrix operator -(const Matrix &b){
        Matrix ans = Matrix(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
            }
        }
        return ans;
    }
    inline Matrix operator *(const Matrix &b){
        Matrix ans = Matrix(n, b.m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < b.m; j++){
                for(int k = 0; k < m; k++){
                    ans.a[i][j] = (ans.a[i][j] + (a[i][k] * b.a[k][j]) % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline Matrix pow(int k){
        Matrix ans = Matrix(n, n);
        Matrix tmp = a;
        ans.make_unit();
        while(k){
            if(k & 1LL) ans = ans * tmp;
            tmp = tmp * tmp;
            k >>= 1LL;
        }
        return ans;
    }
    inline Matrix &operator += (const Matrix &b){
        return *this = (*this) + b;
    }
    inline Matrix &operator -= (const Matrix &b){
        return *this = (*this) - b;
    }
    inline Matrix &operator *= (const Matrix &b){
        return *this = (*this) * b;
    }
    inline bool operator == (const Matrix &b){
        return a == b.a;
    }
    inline bool operator != (const Matrix &b){
        return a != b.a;
    }
};