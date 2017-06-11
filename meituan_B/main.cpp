#include <bits/stdc++.h>

using namespace std;

int n;
int nums[(1 << 20) + 5];

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",nums + i);
    int my = nums[0];
    sort(nums,nums + n);
    int rnk = upper_bound(nums,nums + n,my) - nums;
    int round = 0;
    while((1 << round) <= rnk)
        round++;
    cout << --round << endl;
    return 0;
}
