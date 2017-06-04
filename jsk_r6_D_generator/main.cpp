#include <bits/stdc++.h>

using namespace std;

int h[20];
int main()
{
    sleep(1000);
    srand(time(0));
    int n = rand() % 10 + 5;
    int k = rand() % 30 + 1;
    cout << n << ' ' << k << endl;
    for(int i = 1; i<= n;i++)
        cout << (h[i] = rand() % 20 + 1) << ' ';
    cout << endl;

    int m = rand() % 10 + 5;
    vector<pair<int,int> > room;
    int temp;
    for(int i = 1;i <= m;i++)
    {
        temp = rand() % n + 1;
        room.emplace_back(temp,rand() % h[temp] + 1);
    }
    sort(room.begin(),room.end());
    room.resize(unique(room.begin(),room.end()) - room.begin());
    cout << room.size() << endl;
    for(auto item:room)
   	cout << room.first << ' ' << room.second << endl;

    return 0;
}
