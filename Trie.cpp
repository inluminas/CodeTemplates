int adj[lmt][26],idx=1;

void insert(string s){
  int now=1;
  for(int i=0;i<s.size();i++){
    int num=s[i]-'a';
    if(!adj[now][num]){
      idx++;
      adj[now][num]=idx;
    }
    now=adj[now][num];
  }
}

void dfs(int u){
  for(int i=0;i<26;i++){
    if(!adj[u][i]) continue;
    dfs(adj[u][i]);
  }
}

void del(int u){
  for(int i=0;i<26;i++){
    if(!adj[u][i]) continue;
    del(adj[u][i]);
    adj[u][i]=0;
  }
}
