#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50005;

char s[MAXN];
char t[MAXN];
int nxt[MAXN];
int sLen,tLen;

void getNext()
{
    nxt[0] = -1;
    int i = 0,j = -1;
    while(i < sLen)
    {
        while(j != -1 && s[j] != s[i])
            j = nxt[j];
        nxt[++i] = ++j;
    }
}


int main()
{
    while(scanf("%s %s",s,t) != EOF)
    {
        sLen = strlen(s);
        tLen = strlen(t);
        getNext();

        int i = max(0,tLen - sLen);
        int j = 0;
        while(i < tLen)
        {
            while(j != -1 && s[j] != t[i])
                j = nxt[j];
            ++i,++j;
        }
        for(int i = 0;i < j;i++)
            putchar(s[i]);
        printf("%s%d\n",j ? " " : "",j);
    }

    return 0;
}
