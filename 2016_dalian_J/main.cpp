#include <bits/stdc++.h>

using namespace std;

int getAns(int num)
{
    int ans = 0;
    for(int i = 0;i < 4;i++)
    {
        int mask = 0;
        for(int j = 0;j < 8;j++)
            mask += 1 << (i * 8 + j);
        int now = num & mask;
        now >>= i * 8;
        if(now == 97)
            ans++;
    }

    //cout << num << ' ' << ans;
    return ans;
}
int main()
{
    int N;
    cin >> N;
    int ans = 0;

    int num;
    for(int i = 0;i < N;i++)
    {
        cin >> num;
        ans += getAns(num);
    }
    cout << ans << endl;
    return 0;
}
