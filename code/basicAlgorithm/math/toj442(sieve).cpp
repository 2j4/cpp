#include<iostream>
using namespace std;
const int N = 1e7+10;
int pri[N];
int fl=0, a[2];
int main(){
    ios::sync_with_stdio(0);    cin.tie(0);
    for(int i=1; i<ran; i++)  pri[i]=1;
    for(int i=2; i<=ran; i++){
        if(pri[i] == 1){
            pri[i] = i;
            for(int j=i+i; j<=ran; j+=i)
                pri[j] = i;
        }
    }
    
    int n, x;
    cin >> x;
    for(int i0=0; i0<x; i0++){    
        cin>>n;
        int m = n;
        if(pri[m]!=1){
            while(pri[m]==pri[m/pri[m]]){
                m=m/pri[m];
            }
        }

        cout << pri[m/pri[n]] <<' ';
        if(pri[n]==1)
            cout << n << '\n';
        else
            cout << pri[n] <<'\n';   
    }    
}