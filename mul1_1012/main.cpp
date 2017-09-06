#include<bits/stdc++.h>

namespace IO {
    const int MAXBUFFER = 4e7;
    char buf[MAXBUFFER]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MAXBUFFER, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}

using namespace std;
using namespace IO;

const int MAXN = 1e6 + 5;
typedef long long LL;

struct Pos{
    int l,r;
    int idx;

    bool operator<(const Pos& p)const
    {
        return this->l != p.l ? this->l < p.l : this->r > p.r;
    }
} pos[MAXN];

int n;
const int MOD = 1e9 + 7;
LL fac[MAXN];
LL inv[MAXN];
LL f[MAXN];
void init()
{
    fac[0] = fac[1] = inv[0] = inv[1] = f[0] = f[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        f[i] = f[MOD % i] * (MOD - MOD / i) % MOD;
        inv[i] = inv[i - 1] * f[i] % MOD;
    }
}
LL C(LL m,LL n)
{
    return fac[m] * inv[n] % MOD * inv[m - n] % MOD;
}

int now;

int buildTree(int L,int R)
{
    if(pos[now].l != L || pos[now].r != R)
        return 0;
    if(L == R)
        return 1;

    int pivot = pos[now].idx;
    LL temp = 1;
    if(pivot - 1 >= L)
        ++now,temp =  temp * buildTree(L,pivot - 1) % MOD;
    if(pivot + 1 <= R)
        ++now,temp = temp * buildTree(pivot + 1,R) % MOD;
    temp = temp * C(R - L,pivot - L) % MOD;
    return temp;
}

int main()
{
    init();

    int caseNum = 0;
    IO::begin();
    while(read(n))
    {
        for(int i = 1;i <= n;i++)
            read(pos[i].l);
        for(int i = 1;i <= n;i++)
            read(pos[i].r);
        for(int i = 1;i <= n;i++)
            pos[i].idx = i;

        sort(pos + 1,pos + 1 + n);
        now = 1;
        printf("Case #%d: %d\n",++caseNum,buildTree(1,n));
    }
    return 0;
}
