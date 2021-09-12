#include<iostream>
using namespace std;
int decade = 0 , com = 1;

void toten(string x,int b){
    int ans1 = 0, len = x.size();
    for(int i=0; i<len; i++)
        ans1 = (ans1+x[i]-'0')*b;
    decade = ans1/b;
}

int  power(int a, int b){
    int ret = 1;
    for(int i=b; i; i>>=1, a*=a)
         if(i&1)  ret*=a;
    return ret;
}

int main(){
    int a2, sum = 0;
    string a1;
    cin >> a2 >> a1;
    const int len = a1.size();

    if(a2!=10)
        toten(a1,a2);
    else
        for(int i=len-1,j=1;i>=0;i--,j*=10)
            decade += (a1[i]-'0')*j;
    
    for(int j=0;j<len;j++)
        sum += power(a1[j]-'0', len);
 
     if(sum == decade)
         cout << "YES\n";
     else
         cout << "NO\n";
}