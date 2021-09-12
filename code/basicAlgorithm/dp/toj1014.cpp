#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int dp[1<<17][17], t[17], n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 1;

    for(int s = 1; s < (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(s&(1<<i)){
                for(int k = 0; k < n; k++){
                    int x = dp[s&~(1<<i)][k] + abs(i-k);
                    dp[s][i] = min(dp[s][i], ((x-1)/t[i] + 1) *t[i]);
                }
            }
        }
    }
    int res = 0x7f7f7f7f;
    
    for (int i = 0; i < n; i++){
        res = min( res, dp[(1<<n)-1][i]);
    }
    cout << res << '\n';
}