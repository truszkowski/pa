#include <stdio.h>

int main() {
	long l, p = 0, w, s = 1;
	scanf("%ld", &l);
	while (l--) {
		scanf("%ld", &w);
		s *= (w + 1) % 9;
    s %= 9;
		if (w) p = 1;
	}
	if (!p)
		printf("0");
	else
		printf("%ld", (--s<1) ? (s + 9) : s);
	return 0;
}
