#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e9 + 5;
int n,m;
pair<int,int> it[MAXN];

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&it[i].first,&it[i].second);
        sort(it,it + n);
        int cursor = 0;
        //int preb = it[0].first,pree = it[0].second;
        for(int i = 1;i < n;i++)
        {
            if(it[i].first <= it[cursor].second + 1)
                it[cursor].second = max(it[i].second,it[cursor].second);
            else
                it[++cursor] = it[i];
        }

        it[++cursor] = make_pair(2000000005,2000000005);

        int ans = m;
        int use = 0;
        int tmp = it[0].second - it[0].first + 1;
        int now = 0;
        for(int i = 0;i < cursor;i++)
        {
            while(use <= m && now < cursor)
            {
                if(use + (it[now + 1].first - it[now].second - 1) <= m)
                {
                    use += it[now + 1].first - it[now].second - 1;
                    tmp += it[now + 1].first - it[now].second - 1+ it[now + 1].second - it[now + 1].first + 1;
                    now++;
                }
                else
                {
                    ans = max(ans,tmp + m -use);
                    break;
                }
            }

            if(it[i + 1].first - it[i].second - 1 <= m)
            {
                use -= it[i + 1].first - it[i].second - 1;
                tmp -= it[i + 1].first - it[i].first;
            }
            else
            {
                use = 0;
                tmp = it[i + 1].second - it[i + 1].first + 1;
                now = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
