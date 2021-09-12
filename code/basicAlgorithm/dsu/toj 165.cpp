#include<iostream>
#include<vector>
using namespace std;
int p[100005];
int n, m;

void init(int n)
{
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int findp(int x)
{
    if(p[x] == x) return x;
    return p[x] = findp(p[x]);
}

void uni(int x, int y)
{
    x = findp(x), y = findp(y);
    p[x] = y;
}

int main()
{
    int nn;
    cin >> nn;
    while(nn--)
    {
        cin >> n >> m;
        init(n);
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            uni(b, a);
        }
        for(int i = 1; i <= n; i++)
        {
            cout << findp(i) << '\n';
        }
    }
    
}

/*
2

5 3
1 2
1 3
5 2

6 5
1 2
3 1
4 5
6 4
1 4
*/
