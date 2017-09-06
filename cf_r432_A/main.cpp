#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,t;
    cin >> n >> k >> t;
    if(t >= k && t <= n)
        cout << k << endl;
    else
        cout << (t < k ? t : k - t + n) << endl;
    return 0;
}
