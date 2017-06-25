#include <bits/stdc++.h>

using namespace std;

int m,b;

int main()
{
    cin >> m >> b;
    long long ans = 0;
    for(int y = 0;y <= b;y++)
    {
        int x = m * (b - y);
        ans = max(ans,(long long)(x + y) * (x + 1) * (y + 1) / 2);
    }
    cout << ans << endl;
    return 0;
}
