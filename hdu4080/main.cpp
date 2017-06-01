#include <bits/stdc++.h>

using namespace std;

const int MAXN = 40005;
const int magicNum = 233;

typedef long long ull;
ull mod1 = 1e9 + 7;
ull mod2 = 1e9 + 9;
ull xp1[MAXN],hsh1[MAXN],xp2[MAXN],hsh2[MAXN];
int m,len;
char s[MAXN];
map<pair<ull,ull> ,int> times;

void init()
{
    xp1[0] = 1,xp2[0] = 1;
    for(int i = 1;i < MAXN;i++)
    {
        xp1[i] = xp1[i - 1] * magicNum % mod1;
        xp2[i] = xp2[i - 1] * magicNum % mod2;
    }
}

pair<int,int> getHash(int i,int len)
{
    ull a1 = ((hsh1[i] - hsh1[i + len] * xp1[len]) % mod1 + mod1) % mod1;
    ull a2 = ((hsh2[i] - hsh2[i + len] * xp2[len]) % mod2 + mod2) % mod2;
    return make_pair(a1,a2);
}

void work()
{
    hsh1[len] = 0,hsh2[len] = 0;
    for(int i = len - 1;~i;i--)
    {
        hsh1[i] = (hsh1[i + 1] * magicNum + (s[i] - 'a' + 1)) % mod1;
        hsh2[i] = (hsh2[i + 1] * magicNum + (s[i] - 'a' + 1)) % mod2;
    }
}
bool vaild(int l,int& occ)
{
    occ = -1;
    times.clear();
    for(int i = 0;i + l <= len;i++)
    {
        if(++times[getHash(i,l)] >= m)
            occ = i;
    }
    return occ != -1;
}

int main()
{
    init();
    while(scanf("%d",&m) && m)
    {
        scanf("%s",s);
        len = strlen(s);
        work();

        int l = 1,r = len - m + 1;
        int occ,answer = 0,temp;

        if(r == 1)
        {
            if(vaild(1,occ))
            {
                printf("1 %d\n",len - 1);
                continue;
            }
        }

        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(vaild(mid,temp))
                l = mid,answer = true,occ = temp;
            else
                r = mid - 1;
        }

        if(vaild(l,temp))
            answer = true,occ = temp;
        if(!answer)
            puts("none");
        else
            printf("%d %d\n",l,occ);
    }
    return 0;
}
