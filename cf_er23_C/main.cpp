#include <bits/stdc++.h>

using namespace std;

long long n,s;

int getSum(long long num)
{
    int ans = 0;
    while(num)
    {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main()
{
    cin >> n >> s;
    long long l = 0,r = n;
    if(r - getSum(r) < s)
    {
        puts("0");
        return 0;
    }

    while(l < r)
    {
        long long mid  = (l + r) / 2;
        if(mid - getSum(mid) >= s)
            r = mid;
        else
            l = mid + 1;
        //cout << mid << endl;
    }

    cout << n - l + 1<< endl;
    return 0;
}
