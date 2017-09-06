#include<bits/stdc++.h>

using namespace std;

int cnt[26];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        char c;
        cin >> c;
        cnt[c - 'a']++;
    }
    int maxNum = 0;
    for(int i = 0;i < 26;i++)
        maxNum = max(maxNum,cnt[i]);
    if(maxNum <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
