#include <stdio.h>

int main() {
	long i, n, s = 0;
	scanf("%ld", &n);
	for (i = 1; i <= n; ++i) s += i;
	if (s == n*(n + 1)/2)
		printf("%ld", s);
	else
		printf("Czy¿by znana mi matematyka uleg³a zmianom?\n");
	return 0;
}
