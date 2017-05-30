#include <bits/stdc++.h>

using namespace std;

class Saleswoman{
public:
    int minMoves(vector <int> pos, vector <int> delta)
    {
        int ans = 0;
        int sum = 0;
        int pre = 0;
        for(int i = 0;i < pos.size();i++)
        {
            if(delta[i] < 0)
            {
                if(sum >= 0 && delta[i] + sum < 0)
                    ans += pos[i] - pre,pre = pos[i];
            }
            else
            {
                if(sum < 0 && delta[i] + sum >= 0)
                    ans += (pos[i] - pre) * 3,pre = pos[i];
            }
            sum += delta[i];
        }

        ans += pos[pos.size() - 1] - pre;
        return ans;
    }
};
int main()
{
    Saleswoman sw;
    vector<int> pos = {1,2,4,8,16,32,64,128};
    vector<int> delta = {-1,-1,-1,-1,1,1,1,1};
    cout << sw.minMoves(pos,delta);
    return 0;
}
