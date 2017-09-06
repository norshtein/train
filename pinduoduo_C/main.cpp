#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    int *h = new int[n];
    for(int i = 0;i < n;i++)
        scanf("%d",&h[i]);

    scanf("%d",&m);
    int *w = new int[m];
    for(int i = 0;i < m;i++)
        scanf("%d",&w[i]);

    sort(h,h + n);
    sort(w,w + m);
    int hCursor = 0,wCursor = 0,ans = 0;

    while(wCursor < m)
    {
        if(hCursor < n && w[wCursor] >= h[hCursor])
            hCursor++,ans++;
        wCursor++;
    }
    cout << ans << endl;
    return 0;
}
