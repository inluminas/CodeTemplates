vector<int>adj[lmt];
int chld[lmt],par[lmt],head[lmt],ind=1,len[lmt],cind[lmt],pos[lmt],ps;

void dfs(int u,int p){
  chld[u]=1,par[u]=p;
  for(int v:adj[u]){
    if(v==p) continue;
    dfs(v,u);
    chld[u]+=chld[v];
  }
}

void hld(int u,int p){
  if(!head[ind]) head[ind]=u;

  len[ind]++;
  cind[u]=ind;
  pos[u]=++ps;

  int to=0;
  for(int v:adj[u]){
    if(v==p) continue;
    if(!to || chld[to]<chld[v]) to=v;
  }

  if(to) hld(to,u);

  for(int v:adj[u]){
    if(v==p || v==to) continue;
    ind++;
    hld(v,u);
  }
}
