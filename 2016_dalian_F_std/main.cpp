#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int maxn = 1e5;
const LL mod = 1e9+7;

LL add[maxn], mul[maxn];

void exgcd(LL a, LL b, LL& d, LL& x, LL& y){  //扩展欧几里得
    if(!b){ d = a; x = 1; y = 0;}
    else{
        exgcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

LL inv(LL a, LL n){   //求逆元
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return (x+n)%n;
}

void init(){
    memset(add, 0, sizeof(add));
    memset(mul, 0, sizeof(mul));
    add[0] = add[1] = 1;
    add[2] = 2;
    mul[0] = mul[1] = 1;
    mul[2] = 2;
    for(LL i = 3; i < maxn; i++){
        add[i] = add[i-1]+i;
        mul[i] = (mul[i-1]*i)%mod;
    }
}

int main(){
    init();
    LL T, x;
    scanf("%I64d", &T);
    while(T--){
        scanf("%I64d", &x);
        if(x <= 4){
            printf("%I64d\n", x);
            continue;
        }
        int l = 2, r = maxn-5;
        while(l < r){
            int mid = (l+r+1)/2;
            if(add[mid] <= x) l = mid;
            else r = mid-1;
        }
        LL temp = x - add[l];
        if(temp == l) printf("%I64d\n", mul[l]*inv(2, mod)%mod*(l+2)%mod);
        else if(temp == 0) printf("%I64d\n", mul[l]);
        else printf("%I64d\n", mul[l-temp]*mul[l+1]%mod*inv(mul[l-temp+1], mod)%mod);
    }
    return 0;
}
