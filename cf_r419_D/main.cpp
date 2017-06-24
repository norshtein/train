#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main()
{
    int n;
    cin >> n;
    int temp;
    for(int i = 1;i <= n;i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    int sign = 1;
    while(nums.size() > 1)
    {
        cout << sign << endl;
        vector<int> temp;
        int s = sign;
        for(int i = 0;i < nums.size() - 1;i++)
        {
            temp.push_back(s ? nums[i] + nums[i + 1] : nums[i] - nums[i + 1]);
            s ^= 1;
        }
        sign = s;
        nums = temp;
    }
    cout << nums[0] << endl;

    return 0;
}
