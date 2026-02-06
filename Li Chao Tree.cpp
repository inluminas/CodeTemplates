ll h[lmt];// if range is small than use h[i]=i

struct Line{
    int m, c; // y = mx + c, can also use ax + by + c = 0;
    Line(){
        m = 0, c = 0;
    }
    Line(int _m, int _c){
        m = _m, c = _c;
    }
    int value(int x) return m * x + c;
};

const int lmt = 2e5 + 10;
vector<Line>tree(lmt * 4, Line(0, 1e16));
// for minimum in range Line(0, 1e16), for maximum in range Line(0, -1e16);

void add_line(int at, int L, int R, Line nw){
    int mid = (L + R) >> 1;
    bool lft = nw.value(h[L]) < tree[at].value(h[L]);
    bool md = nw.value(h[mid]) < tree[at].value(mid); 
    // make a compare function if the values are too big to compare

    if(!md) swap(nw, tree[at]);

    if(L == R) return;
    if(lft != md) add_line(at << 1, L, mid, nw);
    else add_line(at << 1 | 1, mid + 1, R, nw);
}

// updating the line in the range h[l] to h[r]
void update(int at, int L, int R, int l, int r, Line nw){
    if(r < L or R < l or r < l) return;
    if(l <= L and R <= r){
        add_line(at, L, R, nw);
        return;
    }

    int mid = (L + R) >> 1;
    update(at << 1, L, mid, l, r, nw);
    update(at << 1 | 1, mid + 1, R, l, r, nw);
}

Line query(int at, int L, int R, int x){
    if(L == R) return tree[at];
    
    int mid = (L + R) >> 1;
    Line res;
    if(x <= h[mid]) res = query(at << 1, L, mid, x);
    else res = query(at << 1 | 1, mid, R, x);

    if(res.value(x) > tree[at].value(x)) swap(res, tree[at]);
    // make a compare function if the values are too big to compare
    return res;
}
