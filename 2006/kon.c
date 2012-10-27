#include <stdio.h>

int main() {
	long a = 1, b = 1, c, n;
	scanf("%ld", &n);
	n %= 60;
	while (n--) { c = b; b = (a + b) % 10; a = c; }
	printf("%ld", a);
	return 0;
}
