#include <cstdio>
#include <cstdlib>

int *tab = NULL, tab_l = 0;
int *res = NULL, res_l = 0;

__inline__ int sum(void)
{
	int sum = 0;
	for (int i = 0; i < tab_l; ++i)
		sum += tab[i];
	return sum;
}

__inline__ int rec()
{
	++res[sum()];

	int last6 = tab_l - 1;

	while (tab[last6] == 6) {
		if (last6 == 0) return 0;

		tab[last6] = 1;
		--last6;
	}

	++tab[last6];
	
	return 1;
}

int main(int argc, char **argv)
{
	(void)argc;

	int n = atoi(argv[1]);
	int t[n], r[6*n+1];
	double all = 1.;
	
	tab = t;
	res = r;
	tab_l = n;
	res_l = 6*n+1;

	for (int i = 0; i < tab_l; ++i) tab[i] = 1, all *= 6;
	for (int i = 0; i < res_l; ++i) res[i] = 0;

	while (rec()) ;
	
	for (int i = n; i < res_l; ++i) {
		double per = 100. * ((double)res[i]) / all;
		printf("%d : %d %f\n", i, res[i], per);
	}

	return 0;
}
