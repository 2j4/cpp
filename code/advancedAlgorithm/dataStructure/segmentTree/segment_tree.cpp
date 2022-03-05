#include<iostream>
#define int long long
using namespace std;
int a[200005];
int st[800005];
int n, q;

void build(int l, int r, int idx)
{
    if(l == r)
    {
        st[idx] = a[l];
        return;
    } 
    int m = (l+r)>>1;
    build(l, m, idx*2);
    build(m+1, r, idx*2+1);
    st[idx] = max(st[idx*2], st[idx*2+1]);
}

void update(int p, int v, int l = 1, int r = n, int idx = 1)
{
    if(l == r)
    {
        st[idx] = v;
         return;        
    }
    int m = (l+r)>>1;
    p <= m ? update(p, v, l, m, idx*2) : update(p, v, m+1, r, idx*2+1);
    st[idx] = max(st[idx<<1], st[(idx<<1)+1]);
}

int query(int pl, int pr, int l = 1, int r = n, int idx = 1)
{
    if(pl<=l && pr>=r) return st[idx];  
    int m = (l+r)>>1;
    if(pr<=m) return query(pl, pr, l, m, idx*2);
    if(pl>m) return query(pl, pr, m+1, r, idx*2+1);
    return max(query(pl, pr, l, m, idx*2), query(pl, pr, m+1, r, idx*2+1));
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    build(1, n, 1);
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        char c;  int a, b;
        cin >> c >> a >> b;
        if(c == 'C')    update(a, b);
        else    cout << query(a, b)/2 << '\n';   
    }  
}
