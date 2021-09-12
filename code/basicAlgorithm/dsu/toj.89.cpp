#include<bits/stdc++.h>
using namespace std;
int fnd[500005],
    emy[500005];

int ffnd(int x)
{
    if(x == 0) return 0;
    if(fnd[x] == x)
        return x;
    else 
        return fnd[x] = ffnd(fnd[x]);
}

void asnf(int x, int y)
{
    x = ffnd(x);
    y = ffnd(y);
    
    fnd[x] = y;
    
    if(emy[x] != 0 && emy[y] != 0)
    {
    	if (ffnd(emy[x]) != ffnd(emy[y]))
    	{
        	fnd[ ffnd(emy[x]) ] = ffnd(emy[y]);
        }
    }
    else if(emy[x] != 0)
    {
        emy[y] = ffnd(emy[x]);
    }
}

void asne(int x, int y)
{
    x = ffnd(x);
    y = ffnd(y);
    
    if (emy[x] == 0 && emy[y] == 0)
    {
	    emy[x] = y;
	    emy[y] = x;
	}
    else
	{
		if(emy[x] != 0 && ffnd(emy[x]) != ffnd(y))
		{
        	fnd[ ffnd(y) ] = ffnd(emy[x]);
        }
    	if(emy[y] != 0 && ffnd(emy[y]) != ffnd(x))
    	{
        	fnd[ ffnd(x) ] = ffnd(emy[y]);
        }
    }
        
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    string str1, str2, str3;
    
    cin >> n;
    for(int i = 1; i <= n; fnd[i] = i, i++);
    
    
    while(cin >> str1 >> str2 >> str3 >> a >> b)
    {
        if(str2 == "are")//assigned
        {
            if(str3 == "enemies")
            {
                if( ffnd(a) == ffnd(b) )
                {
                    cout << "angry\n";
                }
                else
                {
                    asne(a, b);
                }
            }
            else
            {
                if( ffnd( emy[ffnd(a)] ) == ffnd(b))
                {
                    cout << "angry\n";
                }
                else
                {
                    asnf(a, b);
                }
            }
        }
        else            //ask 
        {
            if(str3 == "enemies")
            {
                a = emy[ ffnd(a) ];
                if( ffnd(a) == ffnd(b))
                {
                    cout << "yeap\n";
                }
                else
                {
                    cout << "nope\n";
                }
            }
            else
            {
                if( ffnd(a) == ffnd(b) )
                {
                    cout << "yeap\n";
                }
                else
                {
                    cout << "nope\n";
                }
            }
        }
//        for(int i = 1; i <= n; i++)
//        {
//            cout << i << ' ' << fnd[i] << ' ' << emy[i] << '\n'; 
//        }
    }
    return 0;
}
