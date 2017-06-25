#include <bits/stdc++.h>

using namespace std;

int T;
const int MAXN = 1e5 + 5;
char a[MAXN];
char b[MAXN];

int preA[MAXN][4];
int preB[MAXN][4];
int lenA,lenB;

inline int getCode(char c)
{
    switch(c)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    }
    return -1;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",a + 1,b + 1);
        lenA = strlen(a + 1);
        lenB = strlen(b + 1);
        for(int i = 0;i <= lenA + 1;i++)
        {
            for(int j = 0;j < 4;j++)
                preA[i][j] = 0;
        }
        for(int i = 0;i <= lenB + 1;i++)
        {
            for(int j = 0;j < 4;j++)
                preB[i][j] = 0;
        }

        for(int i = 1;i <= lenA;i++)
            preA[i][getCode(a[i])] = 1;
        for(int i = 1;i <= lenB;i++)
            preB[i][getCode(b[i])] = 1;

        for(int i = 1;i <= lenA + 1;i++)
        {
            for(int j = 0;j < 4;j++)
                preA[i][j] += preA[i - 1][j];
        }
        for(int i = 1;i <= lenB + 1;i++)
        {
            for(int j = 0;j < 4;j++)
                preB[i][j] += preB[i - 1][j];
        }

        int len = (lenA + lenB) / 2;
        int answer = 0;
        for(int cut = 0;cut <= min(lenA,len);cut++)
        {
            int bcut = len - cut;
            int now = 0;
            for(int j = 0;j < 4;j++)
                now += min(preA[cut][j] + preB[bcut][j],preA[lenA][j] - preA[cut][j] + preB[lenB][j] - preB[bcut][j]);
            //cout << cut << ' ' << now << endl;
            answer = max(answer,now);
        }
        cout << answer << endl;
    }


    return 0;
}
