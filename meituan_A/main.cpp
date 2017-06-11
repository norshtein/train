#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[1005];
int b[1005];
int ans = 1e9 + 7;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0;i < m;i++)
        cin >> b[i];
    for(int be = 0;be + n - 1 < m;be++)
    {
        int now = 0;
        for(int i = 0;i < n;i++)
            now += (a[i] - b[be + i]) * (a[i] - b[be + i]);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}
