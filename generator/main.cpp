#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int h[20];
vector<int> gToC[100];

int main()
{
    sleep(1);
    srand(time(0));
    int n = rand() % 10 + 5;
    int m = rand() % n + 1;
    cout << n << ' ' << m << endl;
    for(int i = 0;i < m;i++)
    {
        int k = rand() % n + 1;
        cout << k << ' ';
        for(int j = 0;j < k;j++)
        {
            int idx = rand() % n + 1;
            if(find(gToC[i].begin(),gToC[i].end(),idx) != gToC[i].end())
            {
                j--;
                continue;
            }
            gToC[i].push_back(idx);
            cout << idx << ' ';
        }
        cout << endl;
    }

    int m1 = rand() % (n * (n - 1) / 2) + 1;
    cout << m1 << endl;
    set<pair<int,int> > edges;
    for(int i = 0;i < m1;i++)
    {
        int u = rand() % n + 1;
        int v;
        do
        {
            v = rand() % n + 1;
        }while(v == u);
        if(edges.count(make_pair(min(u,v),max(u,v))))
        {
            i--;
            continue;
        }

        int c = rand() % 20 + 1;
        edges.insert(make_pair(min(u,v),max(u,v)));
        cout << u << ' ' << v << ' ' << c << endl;

    }

    int m2 = rand() % (m * (m - 1) / 2) + 1;
    cout << m2 << endl;
    edges.clear();
    for(int i = 0;i < m2;i++)
    {
        int u = rand() % m + 1;
        int v;
        do
        {
            v = rand() % m + 1;
        }while(v == u);

        if(edges.count(make_pair(min(u,v),max(u,v))))
        {
            i--;
            continue;
        }

        int c = rand() % 20 + 1;
        edges.insert(make_pair(min(u,v),max(u,v)));
        cout << u << ' ' << v << ' ' << c << endl;

    }

    int s = rand() % n + 1;
    int t = rand() % n + 1;
    cout << s << ' ' << t <<endl;

    return 0;
}
