#include <cstdio>
#define MAX 4096
#define USEFULL 36
typedef long long LL;
LL n, k, v[MAX][USEFULL+1];

int main(void) {
	scanf("%lld%lld", &n, &k);
	v[0][1] = 1; --k;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i && j <= USEFULL; ++j)
			v[i][j] = v[i-1][j] + v[i][j-1];

	for (int i = 1; i <= n; ++i) {
		if (k < v[n][i]) {
			for (int j = 0; j < n-i+1; ++j) printf("("); printf(")");
			
			while (n > 1) {
				if (k < v[n][i-1]) {
					--i; printf("(");
				} else {
					k -= v[n][i-1]; --n;
					printf(")");
				}	
			}
			printf("\n");
			return 0;
		} else
			k -= v[n][i];
	}

	return 0;
}
