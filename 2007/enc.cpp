#include <cstdio>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX 2000009
int n, t;
bool v0[MAX], v1[MAX];

inline long long policz(bool must_be, bool * v, int n) {
	int first_0 = 0, first_1 = 0;
	bool need_0 = false, need_1 = false;
	long long count = 0;
	for (int i = 0; i < 2*n; ++i) {
		if (v[i] != must_be) {

			if (first_0 <= i || need_0) { 
				if (first_0 < i) first_0 = i + 1;
				while (v[first_0] != 0) 
					if (first_0 < 2*n) ++first_0; else break;
			}
			if (first_1 <= i || need_1) { 
				if (first_1 < i) first_1 = i + 1;
				while (v[first_1] != 1) 
					if (first_1 < 2*n) ++first_1; else break;
			}
			need_0 = need_1 = false;
			
			if (must_be == 0) {
				count += first_0 - i;
				v[i] = 0;
				v[first_0] = 1;
				need_0 = true;
			} else {
				count += first_1 - i;
				v[i] = 1;
				v[first_1] = 0;
				need_1 = true;
			}
		}
		
		must_be = !must_be;
	}
	return count;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", &t);
		v0[i] = (t > 0 ? true : false);
		v1[i] = v0[i];
	}
	
	long long count_0 = 0, count_1 = 0;
	
	count_0 = policz(0, v0, n);
	count_1 = policz(1, v1, n);
	printf("%lld\n", MIN(count_0, count_1));
	
	return 0;
}
