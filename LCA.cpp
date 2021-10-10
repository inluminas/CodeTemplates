int par[lmt][20];

void build(int n){
  for(int j=1;j<20;j++){
    for(int i=1;i<=n;i++){
      if(par[i][j-1]!=-1){
        par[i][j]=par[par[i][j-1]][j-1];
      }
    }
  }
}

int lca(int p,int q){
  if(lvl[p]<lvl[q]) swap(p,q);
  for(int i=19;i>=0;i--){
    if(lvl[p]-(1<<i)>=lvl[q]){
      p=par[p][i];
    }
  }
  if(p==q) return p;
  for(int i=19;i>=0;i--){
    if(par[p][i]!=-1 && par[p][i]!=par[q][i]){
      p=par[p][i],q=par[q][i];
    }
  }
  return par[p][0];
}
