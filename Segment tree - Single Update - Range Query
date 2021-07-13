int sum[3*lmt];

void build(int at,int L,int R){
  if(L==R){
    sum[at]=a[L];
    return;
  }
  int mid=(L+R)>>1;
  build(at*2,L,mid);
  build(at*2+1,mid+1,R);
  sum[at]=sum[at*2]+sum[at*2+1];
}

void update(int at,int L,int R,int pos,int u){
  if(L==R){
    sum[at]+=u;
    return;
  }
  int mid=(L+R)>>1;
  if(pos<=mid) update(at*2,L,mid,pos,u);
  else update(at*2+1,mid+1,R,pos,u);
  sum[at]=sum[at*2]+sum[at*2+1];
}

int query(int at,int L,int R,int l,int r){
  if(r<L || R<l || r<l) return 0;
  if(l<=L && R<=r) return sum[at];
  int mid=(L+R)>>1;
  int x=query(at*2,L,mid,l,r),y=query(at*2+1,mid+1,R,l,r);
  return x+y;
}
