#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int V = 500005;
struct edge
{
    int x, y, c;
}e[V];
bool operator<(edge e1, edge e2) {return e1.c < e2.c;}
int p[V], n, m, d = 0;


void init()
{
    for(int i = 0; i < n; p[i] = i, i++);
}

int fp(int x)
{
    return x == p[x] ? x : ( p[x] = fp(p[x]) );
}

int uni(int x, int y)
{
    p[ fp(x) ] = fp(y);
}   

int main()
{
    cin >> n >> m;   
    for(int i = 0; i < n; p[i] = i, i++);    
    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        e[i].x = a, 
        e[i].y = b,
        e[i].c = cost;
    }

    sort(e, e+m);
    
    int i, j;
    for(i  = 0, j = 0; i < n-1 && j < m; j++)
    {
        if(fp(e[j].x) == fp(e[j].y))
        {
            continue;
        }

        uni(e[j].x, e[j].y);
        d += e[j].c;
        i++;
    }
    
    if(i == n-1) 
    {
        cout << d << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
    
    return 0;
}
