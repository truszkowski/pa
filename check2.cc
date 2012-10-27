#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>

const int max = 1000;

long double tab[6*max+1];
long double tmp[6*max+1];

long double *power(long double *tab, int n)
{
	long double *curr = tab, *next = tmp;

	for (int i = 1, l = 6; i < n; ++i, l += 6) {
		bzero(next, sizeof(long double)*(6*max+1));

		for (int j = 0; j <= l; ++j)
			for (int k = 1; k <= 6; ++k)
				next[j+k] += curr[j];

		long double *swap = curr;
		curr = next;
		next = swap;
	}

	return curr;
}

int main(int argc, char **argv)
{
	assert(argc == 3);

	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	assert(n > 0 && n < max);
	assert(k > 0 && k <= 6*n);
	
	bzero(tab, sizeof(long double)*(6*max+1));

	for (int i = 1; i <= 6; ++i) tab[i] = 1;

	long double *res = power(tab, n);

	long double all = 1.;
	for (int i = 0; i < n; ++i) all *= 6.;

	for (int i = 7*n/2-1; i <= 7*n/2+1; ++i)
		printf("%d : %Lf ~> %Lf\n", i, res[i], 100.*res[i]/all);
	
	printf("%d\n", (int)(100.*res[k]/all));

	return 0;
}

