#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int n;
int replacement[205];
int krep[205];
int q[205];
int tail;
string s;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    while(true)
    {
        cin >> n;
        if(!n)
            break;

        for(int i = 1;i <= n;i++)
            cin >> replacement[i];
        int kk;
        while(cin >> kk)
        {
            if(!kk)
                break;
            memset(krep,0,sizeof(int) * (n + 1));
            cin.ignore(1,' ');
            getline(cin,s);
            int len = s.size();
            s.resize(n);
            for(int i = len;i < s.size();i++)
                s[i] = ' ';

            for(int i = 1;i <= n;i++)
            {
                if(krep[i])
                    continue;

                tail = 0;
                q[tail++] = i;
                int cursor = replacement[i];
                while(cursor != i)
                {
                    q[tail++] = cursor;
                    cursor = replacement[cursor];
                }

                int k = kk % tail;
                for(int j = 0;j < tail;j++)
                    krep[q[j]] = q[(j + k) % tail];
            }
            string answer;
            answer.resize(n);
            for(int i = 1;i <= n;i++)
                answer[krep[i] - 1] = s[i - 1];
            cout << answer << endl;
        }
        cout << endl;
    }
    return 0;
}
