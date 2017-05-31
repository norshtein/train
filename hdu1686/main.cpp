#include <bits/stdc++.h>

using namespace std;

char W[10005];
char T[1000005];
int nxt[10005];

void getNext()
{
    int len = strlen(W);
    int j = nxt[0] = -1;
    int i = 0;
    while(i < len)
    {
        while(j != -1 && W[j] != W[i])
            j = nxt[j];
        nxt[++i] = ++j;
    }
}
int kmp()
{
    int ans = 0;
    int tLen = strlen(T);
    int wLen = strlen(W);
    int i = 0,j = 0;
    while(i < tLen)
    {
        while(j != -1 && W[j] != T[i])
            j = nxt[j];
        i++,j++;
        if(j == wLen)
        {
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",W,T);
        getNext();
        cout << kmp() << endl;
    }
    return 0;
}
