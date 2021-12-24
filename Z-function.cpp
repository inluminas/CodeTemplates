int z[lmt];

void zf(int n,string s){
  s='#'+s;
  z[1]=0;
  for(int i=2,l=1,r=1;i<=n;i++){
    if(i<=r){
      z[i]=z[i-l];
    }
    while(i+z[i]<=n && s[z[i]+1]==s[i+z[i]]){
      z[i]++;
    }
    if(i+z[i]-1>r){
      l=i,r=i+z[i]-1;
    }
  }
}
