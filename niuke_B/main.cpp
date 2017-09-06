#include<bits/stdc++.h>

using namespace std;

string s;
int times[26];

int main()
{
    cin >> s;
    for(int i = 0;i < s.length();i++)
        times[s[i] - 'a']++;

    int ans = 1;
    for(int i = 0;i < 26;i++)
        times[i] %= 2;
    for(int i = 0;i < 26;i++)
    {
        if(times[i])
            ans++;
    }
    if(ans > 1)
        ans--;

    cout << ans << endl;
    return 0;
}
