#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 1e6 + 5;
int nums[MAXN];
int maxl[MAXN];
int maxr[MAXN];
int minl[MAXN];
int minr[MAXN];
const int INF = 1e9;

pair<int,int> maxq[MAXN];
pair<int,int> minq[MAXN];
int t1 = 0,t2 = 0;
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&nums[i]);

    maxq[++t1] = make_pair(INF,-1);
    minq[++t2] = make_pair(-INF,-1);
    for(int i = 0;i < n;i++)
    {
        while(t1 && nums[i] > maxq[t1].first)
            t1--;
        while(t2 && nums[i] < minq[t2].first)
            t2--;
        maxl[i] = i - maxq[t1].second - 1;
        minl[i] = i - minq[t2].second - 1;
        maxq[++t1] = make_pair(nums[i],i);
        minq[++t2] = make_pair(nums[i],i);
    }

    t1 = t2 = 0;
    maxq[++t1] = make_pair(INF,n);
    minq[++t2] = make_pair(-INF,n);
    for(int i = n - 1;i >= 0;i--)
    {
        while(t1 && nums[i] >= maxq[t1].first)
            t1--;
        while(t2 && nums[i] <= minq[t2].first)
            t2--;
        maxr[i] = maxq[t1].second - i - 1;
        minr[i] = minq[t2].second - i - 1;
        maxq[++t1] = make_pair(nums[i],i);
        minq[++t2] = make_pair(nums[i],i);
    }

    long long ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += (long long)(maxl[i] + 1) * (maxr[i] + 1) * nums[i];
        ans -= (long long)(minl[i] + 1) * (minr[i] + 1) * nums[i];
    }
    cout << ans << endl;
    return 0;
}
