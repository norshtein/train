#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int nums[MAXN * 2];
int prefix[MAXN * 2];
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&nums[i]);
        nums[i + n] = nums[i];
    }

    for(int i = 1;i <= 2 * n;i++)

    return 0;
}
