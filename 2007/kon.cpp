#include <cstdio>
#define div(x,y) ( ((x)/(y))  +  (((x)/(y))*(y) < (x) ? 1 : 0) )
#define mMAX 128
int m, l, k, s, c[mMAX], p, r;
long long v[mMAX], out = 0;

int main(void) {
	scanf("%d%d%d%d", &m, &l, &k, &s);
	for (int i = 0; i < m; ++i)
		scanf("%d", c + i);
	for (int i = 0; i < m; ++i)
		v[i] = 0;
	for (int i = 0; i < l; ++i) {
		scanf("%d%d", &p, &r);
		v[p-1] += r;
	}	
	for (int i = 0; i < m; ++i) {
		if ((v[i] - (v[i]/k)*k)*c[i] < s) v[i] = (v[i]/k)*k;
		out += v[i]*c[i] - div(v[i], k)*s;
	}
	printf("%lld\n", out);
	return 0;
}
