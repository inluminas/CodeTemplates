//https://www.spoj.com/problems/NUMTSN/

//A number is said to be a 369 number if:
//The count of 3s is equal to the count of 6s and the count of 6s is equal to the count of 9s.
//The count of 3s is at least 1.
//For Example 12369, 383676989, 396 all are 369 numbers whereas 213, 342143, 111 are not.
//Given A and B find how many 369 numbers are there in the interval [A, B]. Print the answer modulo 1000000007.

string a,b; cin>>a>>b;
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());

while(a.size()<b.size()) a=a+'0';

reverse(a.begin(), a.end());
reverse(b.begin(), b.end());

int n=a.size();

ll dp[n][33][33][2][2][2]; // [dif1]-> 3's - 6's + 17, [dif2]-> 6's - 9's + 17, [u]-> if there has been at least one 3
//[f1] - > 1 : it is equal to b
//     - > 0 : it is less than b
//[f2] - > 1 : it is equal to a
//     - > 0 : it is greater than a


memset(dp,0,sizeof(dp));

for(int i=a[0]-'0';i<=b[0]-'0';i++){
    dp[0][(i==3)-(i==6)+16][(i==6)-(i==9)+16][i==(b[0]-'0')][i==(a[0]-'0')][i==3]++;
}

for(int i=1;i<n;i++){
    for(int dif1=0;dif1<33;dif1++) for(int dif2=0;dif2<33;dif2++){
        for(int u=0;u<2;u++){
            for(int f1=0;f1<2;f1++) for(int f2=0;f2<2;f2++){

                if(!dp[i-1][dif1][dif2][f1][f2][u]) continue;

                // always put the digit loop last, optimizes time complexcity

                for(int digit=0;digit<10;digit++){

                    if((f1 && digit>(b[i]-'0')) || (f2 && digit<(a[i]-'0'))) continue;

                    bool x=f1&(digit==(b[i]-'0'));
                    bool y=f2&(digit==(a[i]-'0'));

                    int o=dif1+(digit==3)-(digit==6), p=dif2+(digit==6)-(digit==9);
                    
                    if(o<0 || o>32 || p<0 || p>32) continue;

                    dp[i][o][p][x][y][u|(digit==3)]+=dp[i-1][dif1][dif2][f1][f2][u];
                    dp[i][o][p][x][y][u|(digit==3)]%=mod;
                }
            }
        }
    }
}

ll ans=0;

for(int f1=0;f1<2;f1++) for(int f2=0;f2<2;f2++){
    ans+=dp[n-1][16][16][f1][f2][1];
    ans%=mod;
}

cout<<ans<<endl;
return;
