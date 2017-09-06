#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long maxPositive[4],minPositive[4],maxNegative[4],minNegative[4];
    for(int i = 0;i < 3;i++)
    {
        maxPositive[i] = -1;
        minPositive[i] = INT_MAX;
        maxNegative[i] = INT_MIN;
        minNegative[i] = 1;
    }

    int n;
    scanf("%d",&n);
    int tmp;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&tmp);
        if(tmp >= 0)
        {
            maxPositive[3] = minPositive[3] = tmp;
            int cursor = 3;
            while(cursor >= 1 && maxPositive[cursor] > maxPositive[cursor - 1])
                swap(maxPositive[cursor],maxPositive[cursor - 1]),cursor--;
            cursor = 3;
            while(cursor >= 1 && minPositive[cursor] < minPositive[cursor - 1])
                swap(minPositive[cursor],minPositive[cursor - 1]),cursor--;
        }
        else
        {
            maxNegative[3] = minNegative[3] = tmp;
            int cursor = 3;
            while(cursor >= 1 && maxNegative[cursor] > maxNegative[cursor - 1])
                swap(maxNegative[cursor],maxNegative[cursor - 1]),cursor--;
            cursor = 3;
            while(cursor >= 1 && minNegative[cursor] < minNegative[cursor - 1])
                swap(minNegative[cursor],minNegative[cursor - 1]),cursor--;
        }
    }

    long long ans = LLONG_MIN;
    if(maxPositive[2] >= 0)
        ans = max(ans,maxPositive[0] * maxPositive[1] * maxPositive[2]);
    if(maxPositive[0] >= 0 && minNegative[1] < 0)
        ans = max(ans,maxPositive[0] * minNegative[0] * minNegative[1]);
    if(maxNegative[2] != INT_MIN)
        ans = max(ans,maxNegative[0] * maxNegative[1] * maxNegative[2]);
    if(maxNegative[0] != INT_MIN && minPositive[1] != INT_MAX)
        ans = max(ans,maxNegative[0] * minPositive[0] * minPositive[1]);
    cout << ans << endl;

    return 0;
}
