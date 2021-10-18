int pai[lmt];

void pf(int n,string s){
  pai[1]=0;
  s='#'+s;
  for(int i=2;i<=n;i++){
    int l=pai[i-1];
    while(l>0 && s[l+1]!=s[i]){
      l=pai[l];
    } 
    if(s[i]==s[l+1]) l++;
    pai[i]=l;
  }
  return;
}
