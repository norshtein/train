#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1,y1,x2,y2;
    int a,b;
    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    int xabs = abs(x2 - x1);
    int yabs = abs(y2 - y1);
    if(xabs % a || yabs % b)
    {
        puts("NO");
        return 0;
    }
    if(xabs / a % 2 == yabs / b % 2)
        puts("YES");
    else
        puts("NO");
    return 0;
}
