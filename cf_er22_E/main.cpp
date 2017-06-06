#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int n,k;
int nums[MAXN];
const int BLOCK = 321;
int dp[BLOCK + 5][MAXN];
int ri[MAXN];
vector<int> adj[MAXN];
int q;

int getAnswer(int l,int r)
{
    int lBlock = (l - 1) /  BLOCK;
    int rBlock = (r - 1) / BLOCK;
    //cout << l << ' '  << r << ' ' << lBlock << ' '  << rBlock << endl;
    int answer = 0;
    for(int i = l;i <= min(r,(lBlock + 1) * BLOCK);i++)
        if(ri[i] > r)
            answer++;

    if(lBlock == rBlock)
        return answer;

    for(int i = lBlock + 1;i < rBlock;i++)
        answer += dp[i][r + 1];
    for(int i = rBlock * BLOCK + 1;i <= r;i++)
        if(ri[i] > r)
            answer++;

    return answer;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&nums[i]);
        adj[nums[i]].push_back(i);
    }

    for(int i = 1;i <= MAXN;i++)
    {
        for(int j = 0;j < adj[i].size();j++)
        {
            int now = adj[i][j];
            if(j + k < adj[i].size())
                ri[now] = adj[i][j + k];
            else
                ri[now] = n + 1;
        }
    }

#ifdef DEBUG
    cout << n << endl;
    for(int i = 1;i <= n;i++)
        cout << ri[i] << ' ';
    cout << endl;
#endif // DEBUG

    int blockNum = n / BLOCK;
    if(n % BLOCK)
        blockNum++;

    for(int i = 0;i < blockNum;i++)
    {
        int b = i * BLOCK + 1;
        int e = min((i + 1) * BLOCK,n);
        for(int j = b;j <= e;j++)
            dp[i][ri[j]]++;
        for(int j  = n;j >= 0;j--)
            dp[i][j] += dp[i][j + 1];
    }

    int pre = 0;
    scanf("%d",&q);
    int l,r;
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&l,&r);
        l = (l + pre) % n + 1;
        r = (r + pre) % n + 1;
        if(l > r)
            swap(l,r);
        cout << (pre = getAnswer(l,r)) <<endl;
    }

    return 0;
}
