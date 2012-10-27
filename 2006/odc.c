#include <stdio.h>

int main() {
	long i, n;
	scanf("%ld", &n);
	if (n == 1)      printf("0\n");
	else if (n == 2) printf("1\n");
	else             printf("%ld\n", 3*(n - 2));
	printf("1 1 %ld\n", 3*n + 10);
	if (n > 1) printf("2 %ld %ld\n", n + 7, 3*n + 7);
	if (n > 2)
		for (i = 2; i < n; ++i)
			printf("%ld %ld %ld\n", i + 1, n + 8 - i, n + 6 + i);
	return 0;
}
