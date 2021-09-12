#include <iostream>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 1e5+10;
int a[N];
int sum[N];
int n, k;
bool small(int x){
    int l=0, r=0, cnt=0, ans = a[0];
    while(l<n){
        while(ans<x && r<n-1){
            ans+=a[r], r++;
        }
        if(ans>=x) cnt+=n-r;
        ans-=a[l], l++;
    }
    if(cnt >= k)return 1;
    return 0;
}

int main(){
    cin >> n >> k;
    int maxn = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i) sum[i] = sum[i-1];
        sum[i] += a[i];
        maxn = max(maxn, a[i]);
    }
    int l=0, r=sum[n-1]+5;
    while(l<r){
        int m = (l+r)/2;
        if(small(m)){
            l = m+1;
        }
        else r = m;
    }
    cout << l-1 << '\n';

}