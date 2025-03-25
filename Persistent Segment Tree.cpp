const int lmt=1e5+5;
ll seg[60*lmt],lft[60*lmt],rght[60*lmt];
ll a[lmt],curpos=0,ver[lmt];
int n;

void build(int at,int L,int R){
    if(L==R){
        seg[at]=a[L];
        return;
    }
    lft[at]=++curpos, rght[at]=++curpos;
    int mid=(L+R)>>1;
    build(lft[at],L,mid); build(rght[at],mid+1,R);
    seg[at]=seg[lft[at]]+seg[rght[at]];
}

ll update(int at, int L, int R,int pos, ll v){
    if(pos<L or R<pos) return at;

    int newat=++curpos;

    if(L==R){
        seg[newat]=seg[at]+v;
        return newat;
    }

    int mid=(L+R)>>1;

    lft[newat]=update(lft[at],L,mid,pos,v);
    rght[newat]=update(rght[at],mid+1,R,pos,v);
    seg[newat]=seg[lft[newat]]+seg[rght[newat]];
    return newat;
}

ll query(int at,int L,int R,int l,int r){
    if(R<l or r<L or r<l) return 0LL;
    if(l<=L and R<=r) return seg[at];

    int mid=(L+R)>>1;
    ll x=query(lft[at],L,mid,l,r), y=query(rght[at],mid+1,R,l,r);
    return (x+y);
}



void solve(int tst){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    ver[0]=++curpos;
    build(curpos,1,n);
    int k=0;

    int q; cin>>q;
    while(q--){
        int t; cin>>t;
        if(t<2){
            int idx,pos; ll v;
            cin>>idx>>pos>>v;
            ver[++k]=update(ver[idx],1,n,pos,v);
        }else{
            int idx,l,r; cin>>idx>>l>>r;

            cout<<query(ver[idx],1,n,l,r)<<endl;
        }
    }
}
