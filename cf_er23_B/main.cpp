#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int nums[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",nums + i);
    sort(nums,nums + n);
    int cnt[4] = {1,0,0,0};
    int pre = nums[0];
    int cursor = 0;
    for(int i = 1;i < n;i++)
    {
        if(nums[i] == pre)
            cnt[cursor]++;
        else
        {
            cnt[++cursor] = 1;
            pre = nums[i];
            if(cursor >= 3)
                break;
        }
    }

    if(cnt[0] >= 3)
    {
        int a = cnt[0];
        printf("%I64d\n",1LL * a * (a - 1) * (a - 2) / 6);
    }
    else if(cnt[0] == 2 && cnt[1] >= 1)
    {
        printf("%d\n",cnt[1]);
    }
    else if(cnt[0] == 1 && cnt[1] >= 2)
    {
        int a = cnt[1];
        printf("%I64d\n",1LL * a * (a - 1) / 2);
    }
    else if(cnt[0] == 1 && cnt[1] == 1 && cnt[2] >= 1)
    {
        printf("%d\n",cnt[2]);
    }
    else
        printf("%d\n",1);

    return 0;
}
