#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n;
int answer;
tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
t;

void dfs(int p,int l,int digit,int pre)
{
    if(digit < 0)
        return;
    int mask;
    for(int choice = 0;choice <= 1;choice++)
    {
        mask = choice ? (1 << digit) : 0;
        if(((p & mask) ^ mask) < (l & mask))
        {
            int high = pre + (mask | (mask - 1));
            int low = pre + mask;
            answer += t.order_of_key(high) - t.order_of_key(low);
            if(*t.find_by_order(t.order_of_key(low)) == low)
                answer++;
        }
        else if(((p & mask) ^ mask) == (l & mask))
            dfs(p,l,digit - 1,mask + pre);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int op,p,l;
        scanf("%d",&op);
        if(op == 1)
        {
            scanf("%d",&p);
            t.insert(p);
        }
        else if(op == 2)
        {
            scanf("%d",&p);
            t.erase(p);
        }
        else
        {
            scanf("%d%d",&p,&l);
            answer = 0;
            dfs(p,l,30,0);
            printf("%d\n",answer);
        }
    }
    return 0;
}
