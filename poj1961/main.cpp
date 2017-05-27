#include <iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;

const int MAXN = 1e6 + 5;
char s[MAXN];
int nnext[MAXN];

int main()
{
    int caseNum = 0;
    int len;
    while(scanf("%d",&len) != EOF && len)
    {
        scanf("%s",s);
        int j = nnext[0] = -1;
        int i = 0;
        while(i < len)
        {
            while(j != -1 && s[i] != s[j])
                j = nnext[j];
            nnext[++i] = ++j;
        }

        printf("Test case #%d\n",++caseNum);
        for(i = 2;i <= len;i++)
        {
            if(nnext[i] && i % (i - nnext[i]) == 0)
                printf("%d %d\n",i,i / (i - nnext[i]));
        }
        putchar('\n');
    }
    return 0;
}
