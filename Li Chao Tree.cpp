ll h2[lmt];// if range is small than use h2[i]=i
vector<pair<ll,ll>>tree(3*lmt,{0,1e14});

ll f(pair<ll,ll>line,ll x){//line.first=m,line.second=c,y=m*x+c
  return line.first*x+line.second;
}

void update(pair<ll,ll>line,ll L=1,ll R=n,ll at=1){
  ll mid=(L+R)>>1;
  bool lft=f(line,h2[L])<f(tree[at],h2[L]);
  bool md=f(line,h2[mid])<f(tree[at],h2[mid]);

  if(md) swap(tree[at],line);

  if(L==R) return;
  else if(lft!=md) update(line,L,mid,at*2);
  else update(line,mid+1,R,at*2+1);
}

ll query(ll x,ll L=1,ll R=n,ll at=1){
  ll mid=(L+R)>>1;
  ll cur=f(tree[at],x);
  if(L==R) return cur;
  if(x<=h2[mid]) return min(cur,query(x,L,mid,at*2));
  else return min(cur,query(x,mid+1,R,at*2+1));
}
