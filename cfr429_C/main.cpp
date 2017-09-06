#include<bits/stdc++.h>

using namespace std;

const int MAXM = 2e5 + 5;

int A[MAXM];
pair<int,int> B[MAXM];
int ans[MAXM];

int main()
{
    int m;
    scanf("%d",&m);

    for(int i = 0;i < m;i++)
        scanf("%d",&A[i]);
    for(int i = 0;i < m;i++)
        scanf("%d",&B[i].first),B[i].second = i;

    sort(B,B + m);
    sort(A,A + m,greater<int>());
    for(int i = 0;i < m;i++)
        ans[B[i].second] = A[i];
    for(int i = 0;i < m;i++)
        printf("%d%c",ans[i]," \n"[i == m - 1]);
    return 0;
}
