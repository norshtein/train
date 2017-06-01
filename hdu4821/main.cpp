#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int magicNum = 233;
const int MAXN = 1e5 + 5;
ull xp[MAXN],hsh[MAXN];
int M,L;
char s[MAXN];
map<ull,int> times[MAXN];
set<ull> nums[MAXN];
int len;
ull getHash(int idx,int len)
{
    return hsh[idx] - hsh[idx + len] * xp[len];;
}
void init()
{
    xp[0] = 1;
    for(int i = 1;i < MAXN;i++)
        xp[i] = xp[i - 1] * magicNum;
}

void work()
{
    hsh[len] = 0;
    for(int i = len - 1; ~i ;i--)
        hsh[i] = hsh[i + 1] * magicNum + (s[i] - 'a') + 1;
}

bool insrt(int i)
{
    int pre = i - L * M;
    if(pre >= 0)
    {
        ull preCode = getHash(pre,L);
        if(--times[i % L][preCode] == 1)
            nums[i % L].erase(preCode);
    }

    ull hashCode = getHash(i,L);
    if(++times[i % L][hashCode] > 1)
        nums[i % L].insert(hashCode);

    return nums[i % L].size() == 0;
}
int main()
{
    init();
    while(scanf("%d%d",&M,&L) != EOF)
    {
        scanf("%s",s);
        len = strlen(s);
        work();
        for(int i = 0;i < L;i++)
            times[i].clear(),nums[i].clear();

        for(int i = 0;i < (M  - 1)* L;i++)
            insrt(i);

        int ans = 0;
        for(int i = (M - 1) * L;i + L<= len;i++)
            if(insrt(i))
                ans++;
        cout << ans << endl;
    }
    return 0;
}
