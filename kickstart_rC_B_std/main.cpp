//Problem B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int get() {
	char c;
	while (c = getchar(), c != '-' && (c < '0' || c > '9'));
	bool flag = (c == '-');
	if (flag)
		c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return flag ? -x : x;
}

int getCell() {
	char c;
	while (c = getchar(), c != '.' && c != 'X');
	return (c == 'X') ? 1 : 0;
}

const int MAXN = 100;

int a[MAXN][MAXN];

int main() {
    freopen("out.txt","w+",stdout);
	int totalTest = get();
	for (int test = 1; test <= totalTest; test++) {
		printf("Case #%d: ", test);
		int n = get();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = getCell();
		int r[MAXN], c[MAXN];
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		int p = 0, q = 0;
		while (p < n && r[p] != 1)
			p++;
		while (q < n && c[q] != 1)
			q++;
		if (p == n || q == n) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		sort(r, r + n);
		sort(c, c + n);
		bool ans = (r[0] == 1) && (c[0] == 1) && (a[p][q] == 1);
		for (int i = 1; ans && i < n; i++)
			ans = (r[i] == 2) && (c[i] == 2);
		bool fr[MAXN], fc[MAXN];
		memset(fr, 0, sizeof(fr));
		memset(fc, 0, sizeof(fc));
		fr[p] = fc[q] = true;
		for (int t = 1; ans && t < n; t += 2) {
			int i0 = 0;
			while (fr[i0])
				i0++;
			int j0 = 0;
			while (!a[i0][j0])
				j0++;
			int j1 = j0 + 1;
			while (!a[i0][j1])
				j1++;
			if (fc[j0] || fc[j1]) {
				ans = false;
				break;
			}
			int i1 = 0;
			while (!a[i1][j0] || i1 == i0)
				i1++;
			if (fr[i1] || !a[i1][j1]) {
				ans = false;
				break;
			}
			fr[i0] = fr[i1] = true;
			fc[j0] = fc[j1] = true;
		}
		printf(ans ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
	return 0;
}
