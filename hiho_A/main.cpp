#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int romanToInt(string s) {
        int tagVal[256];
        tagVal['I'] = 1;
        tagVal['V'] = 5;
        tagVal['X'] = 10;
        tagVal['C'] = 100;
        tagVal['M'] = 1000;
        tagVal['L'] = 50;
        tagVal['D'] = 500;
        int val = 0;
        for(int i = 0; i < s.length(); i++){
            if(i+1 >= s.length() || tagVal[s[i+1]] <= tagVal[s[i]])
                val += tagVal[s[i]];
            else
                val -= tagVal[s[i]];
        }
        return val;
}

struct Em{
    string name;
    string time;
    int ttime;

    bool operator<(const Em& e) const{
        return this->name != e.name ? this->name < e.name : this->ttime < e.ttime;
    }
} em[MAXN];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i = 0;i < N;i++)
        cin >> em[i].name >> em[i].time,em[i].ttime = romanToInt(em[i].time);

    sort(em,em + N);
    for(int i = 0;i < N;i++)
        cout << em[i].name << ' ' << em[i].time << endl;
    return 0;
}
