ll sum[3*lmt],lazy[3*lmt];

void propagate(int at,int L,int R){
  sum[at]+=(R-L+1)*lazy[at];
  if(L==R){
    lazy[at]=0;
    return;
  }
  lazy[at*2]+=lazy[at],lazy[at*2+1]+=lazy[at],lazy[at]=0;
  return;
}

void update(int at,int L,int R,int l,int r,ll val){
  propagate(at,L,R);
  if(r<L || R<l || r<l) return;
  if(l<=L && R<=r){
    lazy[at]+=val;
    propagate(at,L,R);
    return;
  }
  int mid=(L+R)>>1;
  update(at*2,L,mid,l,r,val);
  update(at*2+1,mid+1,R,l,r,val);
  sum[at]=sum[at*2]+sum[at*2+1];
}

ll query(int at,int L,int R,int l,int r){
  propagate(at,L,R);
  if(r<L || R<l || r<l) return 0LL;
  if(l<=L && R<=r) return sum[at];
  int mid=(L+R)>>1;
  return query(at*2,L,mid,l,r)+query(at*2+1,mid+1,R,l,r);
}
