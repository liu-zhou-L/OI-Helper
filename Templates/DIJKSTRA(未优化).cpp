#include <cstdio>
#include <cstring> 

const int MAXN = 2505;

int n, m, s, t, a[MAXN][MAXN], f[MAXN];
bool flag[MAXN];

int Min(int i, int j) {
	return i < j ? i : j;
}

void dijkstra() {
	memset(f, 0x3f, sizeof(f));
	memset(flag, 0, sizeof(flag));
	f[s] = 0;
	//flag[s] = 1;
	for (int i = 1; i <= n; i++) {
		int minn = 0x3f3f3f3f;
		int k=0;
		for (int j = 1; j <= n; j++) {
			if (!flag[j]&& f[j] < minn) {
				minn = f[j];
				k=j;
			}
		}
		flag[k] = 1;
		for (int j = 1; j <= n; j++) {
			f[j] = Min(f[j], f[k] + a[k][j]);
		}
	}
	return;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		a[tmp][tmp_] = temp;
	}
	dijkstra();
	printf("%d", f[t]);
	return 0;
}
