#include <cstdio>

typedef unsigned long long Long;

inline Long up(Long a, Long n, Long k) {
	Long b = 1;
	while (n)
		if (n & 1) { b = (a*b)%k; --n; }
		else { a = (a*a)%k; n /= 2; }
	return b;
}

inline Long gcd(Long a, Long b) {
	Long d; 
	do { a %= b; d = a; a = b; b = d; } while (d != 0);
	return a;
}

int main() {
	Long d, e, i, k, n, p;
	scanf("%llu %llu %llu", &p, &e, &k);
	d =  (p - 1) / gcd(p - 1, e);
	for (i = 0; i < k; ++i) {
		scanf("%llu", &n); 
		if (up(n, d, p) == 1) 
			printf("TAK\n");
		else 
			printf("NIE\n");
	}
	return 0;
}
