#include <bits/stdc++.h>

using namespace std;

struct G{
    int idx;
    int base;
    long long price;
    G(int i = 0,int b = 0,long long p = 0):idx(i),base(b),price(p){}
    bool operator<(const G& g) const{
        return this->price < g.price;
    }
};

const int MAXN = 1e5 + 5;
G goods[MAXN];
int n,S;

long long getAnswer(int mid)
{
    for(int i = 1;i <= n;i++)
        goods[i].price = (long long)mid * goods[i].idx + goods[i].base;
    sort(goods + 1,goods + 1 + n);

    long long ans = 0;
    for(int i = 1;i <= mid;i++)
        ans += goods[i].price;
    return ans;
}
int main()
{
    scanf("%d%d",&n,&S);
    for(int i = 1;i <= n;i++)
        scanf("%d",&goods[i].base),goods[i].idx = i;

    int l = 0,r = n;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        long long ans = getAnswer(mid);
        if(ans <= S)
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << ' ' << getAnswer(l) << endl;
    return 0;
}
