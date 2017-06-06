#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    int temp;
    for(int i = 0;i < n;i++)
        cin >> temp, sum += temp;
    int m;
    cin >> m;
    int a,b;
    for(int i = 0;i < m;i++)
    {
        cin >> a >> b;
        if(a >= sum)
        {
            cout << a << endl;
            return 0;
        }
        else if(b >= sum)
        {
            cout << sum << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
