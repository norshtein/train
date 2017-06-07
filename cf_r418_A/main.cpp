#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    if(k != 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    int nums[105];
    int zeroPos;
    nums[0] = -1;
    nums[n + 1] = 999;
    for(int i = 1;i <= n;i++)
    {
        cin >> nums[i];
        if(nums[i] == 0)
            zeroPos = i;
    }
    cin >> nums[zeroPos];
    for(int i = 1;i <= n;i++)
        if(nums[i] < nums[i - 1])
        {
            cout << "Yes" << endl;
            return 0;
        }

    cout << "No"<< endl;

    return 0;
}
