#include <bits/stdc++.h>

using namespace std;

char s[105];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    cin >> T;
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        cin >> s;
        long long L,R;
        cin >> L >> R;
        int len = strlen(s);
        L--,R--;
        int blueCnt = 0;

        for(int i =0;i < len;i++)
        if(s[i] == 'B')
            blueCnt++;

        long long lsec = L / len;
        long long rsec = R / len;
        if(lsec == rsec)
        {
            int ans = 0;
            for(int i = L % len;i <= R % len;i++)
            if(s[i] == 'B')
                ans++;
            printf("Case #%d: %d\n",caseNum,ans);
            continue;
        }

        long long ans = 0;
        for(int i = L % len;i < len;i++)
        if(s[i] == 'B')
            ans++;

        ans += (rsec - lsec - 1) * blueCnt;
        for(int i = 0;i <= R % len;i++)
        if(s[i] == 'B')
            ans++;
        printf("Case #%d: %lld\n",caseNum,ans);
    }
    return 0;
}
