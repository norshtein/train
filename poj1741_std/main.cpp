#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 10;

struct node {
    int v, w;
};

int n, k, root, Max, ans;
vector <node> tree[MAXN];
vector <int> dis;
int sz[MAXN], maxv[MAXN];
bool vis[MAXN];

void init() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) tree[i].clear();
}

void dfs_size(int u, int pre) {         // ���ÿ�������Ĵ�С���Լ�ÿ���ڵ��������
    sz[u] = 1; maxv[u] = 0;
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) {
        int v = tree[u][i].v;
        if (v == pre || vis[v]) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
        maxv[u] = max(maxv[u], sz[v]);
    }
}

void dfs_root(int r, int u, int pre) {  // �ҳ���uΪ��������������
    maxv[u] = max(maxv[u], sz[r] - sz[u]);
    if (Max > maxv[u]) {
        Max = maxv[u];
        root = u;
    }
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) {
        int v = tree[u][i].v;
        if (v == pre || vis[v]) continue;
        dfs_root(r, v, u);
    }
}

void dfs_dis(int u, int pre, int d) {    // �����ǰ���������е㵽���ľ���
    dis.push_back(d);
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++) {
        int v = tree[u][i].v, w = tree[u][i].w;
        if (v == pre || vis[v]) continue;
        dfs_dis(v, u, d + w);
    }
}

int cal(int u, int d) {         // ���㵱ǰ�����кϷ��ĵ����
    int res = 0;
    dis.clear(); dfs_dis(u, -1, d);
    sort (dis.begin(), dis.end());
    int i = 0, j = dis.size() - 1;
    while (i < j) {
        while (dis[i] + dis[j] > k && i < j) --j;
        res += j - i;
        ++i;
    }
    return res;
}

void dfs(int u) {               // �ܵ�dfs���
    Max = n;
    dfs_size(u, -1);
    dfs_root(u, u, -1);
    ans += cal(root, 0);
    vis[root] = true;
    int cnt = tree[root].size(), rt = root; // һ��Ҫע���������root��ȫ�ֱ������ڵݹ�֮����ܸı䣬��Ҫ��ǰ����������
    for (int i = 0; i < cnt; i++) {
        int v = tree[rt][i].v, w = tree[rt][i].w;
        if (vis[v]) continue;
        ans -= cal(v, w);
        dfs(v);
    }
}

int main() {
    //freopen("in", "r", stdin);
    while (scanf("%d%d", &n, &k), n || k) {
        init();
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            tree[u].push_back((node){v, w});
            tree[v].push_back((node){u, w});
        }
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
