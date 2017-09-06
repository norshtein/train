#include <iostream>
#include <numeric>
#include <limits>
#include<bits/stdc++.h>
using namespace std;
// ������������������ʵ����ĿҪ��Ĺ���
// ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^

int result(int x, int y) {
    map<int,int> ageToCnt;
    ageToCnt[0] = 2;

    for(int i = 1;i <= y;i++)
    {
        int totalCnt = 0;
        for(auto itor = ageToCnt.rbegin();itor != ageToCnt.rend();itor++)
        {
            int age = itor->first;
            int cnt = itor->second;
            if(cnt <= 0)
                continue;
            totalCnt += cnt;
            ageToCnt[age] -= cnt;
            if(age + 1 <= x)
                ageToCnt[age + 1] += cnt;
            if(age >= 2)
                ageToCnt[0] += cnt,totalCnt += cnt;
         }

         if(totalCnt >= 20)
         {
             auto itor = ageToCnt.rbegin();
             if(itor->second >= 4)
                 itor->second -= 4;
             else
             {
                 itor->second -= 2;
                 itor--;
                 while(itor->second < 2)
                     itor--;
                 itor ->second -= 2;
             }
         }
    }
    int ans = 0;
    for(auto p:ageToCnt)
    {
        ans += p.first * p.second;
    }
    return ans;
}
int main() {
    int x, y;
    cin >> x;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    cin >> y;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    int res = result(x,y);
    cout << res << endl;
    return 0;
}
