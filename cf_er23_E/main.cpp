#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 * 32 + 5;

struct Node{
    int ch[2];
    int cnt;

} trie[MAXN];
int nodeNum = 0;

void trieInsert(int num,int delta)
{
    int now = 0;
    for(int shift = 30;shift >= 0;shift--)
    {
        int nowDigit = (num & (1 << shift) ? 1 : 0);
        if(!trie[now].ch[nowDigit])
            trie[now].ch[nowDigit] = ++nodeNum;
        now = trie[now].ch[nowDigit];
        trie[now].cnt += delta;
        //cout << num << ' ' << shift << ' ' << now << ' ' << nowDigit << endl;
    }
}
int getAnswer(int p,int l)
{
    int answer = 0;
    int now = 0;
    for(int shift = 30;shift >= 0;shift--)
    {
        int pd = p & (1 << shift) ? 1 :0;
        int ld = l & (1 << shift) ? 1 :0;
        //cout << pd << ' ' << ld << ' ' << shift << endl;
        if(pd == 1 && ld == 0)
            now = trie[now].ch[1];
        else if(pd == 0 && ld == 1)
        {
            answer += trie[trie[now].ch[0]].cnt;
            now = trie[now].ch[1];
        }
        else if(pd == 1 && ld == 1)
        {
            answer += trie[trie[now].ch[1]].cnt;
            now = trie[now].ch[0];
        }
        else
            now = trie[now].ch[0];

        if(trie[now].cnt == 0)
            break;
    }
    return answer;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int op,p,l;
        scanf("%d",&op);
        if(op == 1 || op == 2)
        {
            scanf("%d",&p);
            trieInsert(p,op & 1 ? 1 :-1);
        }
        else
        {
            scanf("%d%d",&p,&l);
            printf("%d\n",getAnswer(p,l));
        }
    }
    return 0;
}
