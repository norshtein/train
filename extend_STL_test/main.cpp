#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//��һ�������͵������������Խ����޸���ʵ�����д洢��ͬ���������͡�
tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
t;


int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
        t.insert(i + 1);

    int cur = 0;
    while(n)
    {
        cur = (cur + k - 1) % n--;
        auto p = t.find_by_order(cur);
        cout << *p << ' ';
        t.erase(p);
    }
    return 0;
}
