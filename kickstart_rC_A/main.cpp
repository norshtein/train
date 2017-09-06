#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt","r+",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    char answer[55];
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        string s;
        cin >> s;
        if(s.length() % 2)
            printf("Case #%d: %s\n",caseNum,"AMBIGUOUS");
        else
        {
            answer[s.length()] = 0;
            answer[1] = s[0];
            answer[s.length() - 2] = s[s.length() - 1];
            for(int i = 3;i < s.length();i+= 2)
                answer[i] = ((s[i - 1] - 'A') - (answer[i - 2] - 'A') + 26) % 26 + 'A';
            for(int i = s.length() - 4;i >= 0;i -= 2)
                answer[i] = ((s[i + 1] - 'A') - (answer[i + 2] - 'A') + 26) % 26 + 'A';
            printf("Case #%d: %s\n",caseNum,answer);
        }
    }
    return 0;
}
