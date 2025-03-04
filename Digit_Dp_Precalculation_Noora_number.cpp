//https://toph.co/p/noora-number

//A number is a "Noora" number if the count of distinct digits of the number is equal to the maximum digit of the number. So, 123 is a Noora number but 124 is not. Some of the first Noora numbers are 1, 11, 12, 20, 21, 103, 111, 112, ....
//Given n, you have to tell how many Noora numbers are smaller or equal to n.

void solve(int tst){
    string s; cin>>s;
    int n=s.size();

    ll ans=0;
    int cnt[10], mask=0;
    memset(cnt,0,sizeof(cnt));

    for(int i=0;i<n;i++){
        for(int c=(!i ? '1' : '0') ; c<s[i] ; c++){
            ans+=res[n-i-1][mask|(1LL<<(c-'0'))];
        }

        for(int c='1';i and c<='9';c++){
            ans+=res[n-i-1][(1LL<<(c-'0'))];
        }

        mask|=(1LL<<(s[i]-'0'));
    }

    ans+=res[0][mask];

    cout<<ans<<endl;
    return;
}

int main(){
    fastio

    for(int mask=0;mask<(1LL<<10);mask++){
        int mx=-1,cnt=0;
        for(int i=0;i<10;i++) if(mask&(1LL<<i)){
            mx=i,cnt++;
        }
        check[mask]=(mx==cnt);
    }

    for(int digit=0;digit<10;digit++) dp[1][(1LL<<digit)]++;
    
    for(int i=2;i<20;i++){
        for(int mask=0;mask<(1LL<<10);mask++){
            res[0][mask]=check[mask];
            if(dp[i-1][mask]){
                for(int digit=0;digit<10;digit++){
                    dp[i][mask|(1LL<<digit)]+=dp[i-1][mask];
                }
            }
        }
    }

    // precalculation
    // res[i][mask] - > we haave a mask of presented digits and i empty spaces, how many ways we can fill the empty spaces with digits such that the mask becomes noora
    // noora masks example : 0100.. , 101000, 011000...., 110100...
    // the maximum digit present in the mask == the number of digits present in the mask

    for(int mask1=0;mask1<(1LL<<10);mask1++) for(int mask2=0;mask2<(1LL<<10);mask2++){

        if(!check[mask1|mask2]) continue; // not a noora number

        for(int i=0;i<19;i++){
            res[i][mask2]+=dp[i][mask1];
        }
    }

    ll t; cin>>t;
    for(ll i=1;i<=t;i++) solve(i);

}
