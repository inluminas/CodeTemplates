using T = __int128;

T extended_euclid(T a, T b, T &x, T &y){
    T x1 = 0, y1 = 1; x = 1, y = 0;
    while(b){
        T q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

pair<T, T> CRT(T a1, T m1, T a2, T m2){
    T p, q;
    T g = extended_euclid(m1, m2, p, q);
    if(a1 % g != a2 % g) return {0, -1};
    T m = m1 / g * m2;
    p = (p % m + m) % m, q = (q % m + m) % m;
    T x = (p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m;
    return {x, m};
}