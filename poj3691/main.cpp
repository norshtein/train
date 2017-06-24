#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXLEN = 1005;
char temp[55];
char s[MAXLEN];

int getNum(char c)
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
}

struct Node{
    int ch[4];
    int fail;
    bool dangerous;
};

Node trie[MAXN];
int cnt = 0;
int totalLen = 0;

void acInsert(const char* s)
{
    int len  = strlen(s);
    totalLen += len;
    int now = 0;
    for(int i = 0;i < len;i++)
    {
        if(trie[now].ch[getNum(s[i])])
            now = trie[now].ch[getNum(s[i])];
        else
            now = trie[now].ch[getNum(s[i])] = ++cnt;
    }
    trie[now].dangerous = true;
}

void build()
{
    queue<int> q;
    for(int i = 0;i < 4;i++)
        if(trie[0].ch[i])
            q.push(trie[0].ch[i]);

    int child;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            if(!(child = trie[now].ch[i]))
                continue;

            q.push(child);

            int pre = trie[now].fail;
            while(pre && !trie[pre].ch[i])
                pre = trie[pre].fail;

            if(trie[pre].ch[i])
                trie[child].fail = trie[pre].ch[i];
            else
                trie[child].fail = 0;
            trie[child].fail = trie[pre].ch[i];
            trie[child].dangerous |= trie[trie[child]].fail;

        }
    }
}

int acCount(const char* s)
{
    int ans = 0;
    int len = strlen(s);
    int now = 0;
    int c;
    for(int i = 0;i < len;i++)
    {
        c = s[i] - 'a';
        if(!trie[now].ch[c])
        {
            while(now && !trie[now].ch[c])
                now = trie[now].fail;
        }

        if(trie[now].ch[c])
            now = trie[now].ch[c];
        if(trie[now].exist != -1)
        {
            ans += trie[now].exist;
            trie[now].exist = -1;
            int fail = trie[now].fail;
            while(trie[fail].exist != -1)
            {
                ans += trie[fail].exist;
                trie[fail].exist = -1;
                fail = trie[fail].fail;
            }
        }
    }
    return ans;
}

int main()
{
    int caseNum,N;
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        memset(trie,0,sizeof(Node) * (totalLen + 1));
        totalLen = 0;
        cnt = 0;

        scanf("%d",&N);
        for(int i = 0;i < N;i++)
        {
            scanf("%s",temp);
            acInsert(temp);
        }
        build();
        scanf("%s",s);
        printf("%d\n",acCount(s));
    }
    return 0;
}
