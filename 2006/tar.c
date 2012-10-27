#include <stdio.h>

long parr[2000009], pgi = 0, pti = 0;
long garr[1000009], gi = 0;
long tarr[1000009], ti = 0;
char sarr[2000009];
long i, n, si = 0;

int main() {
	scanf("%ld %s", &n, sarr);

	for (i = 0; i < 2*n; ++i)
		if (sarr[i] == 'g') {
			parr[i] = ++pgi;
			if (ti > 0)
				printf("%ld %ld\n", parr[i], parr[tarr[--ti]]);
			else 
				garr[gi++] = i;
		} else {
			parr[i] = ++pti;
			if (gi > 0)
				printf("%ld %ld\n", parr[garr[--gi]], parr[i]);
			else 
				tarr[ti++] = i;
		}
	return 0;
}
