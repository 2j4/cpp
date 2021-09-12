#include<iostream>
using namespace std;
int a[1000000],sum,dp[1024][1024];

int main() {
    
    int n;    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];    
        sum+=a[i];
        if(n&1)        
            dp[i][i]=a[i];
        else         
            dp[i][i]=0;
    }
    
    for(int len=2; len<=n; len++){
        for(int l=1, r=len; l<n-1, r<=n; l++, r++){
            if((n-len) & 1)    
                dp[l][r]=min(dp[l+1][r], dp[l][r-1]);
            else            
                dp[l][r]=max(dp[l+1][r]+a[l], dp[l][r-1]+a[r]);
        }
    }
    cout<<dp[1][n]<<' '<<sum-dp[1][n]<<'\n';
}