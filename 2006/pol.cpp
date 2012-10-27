#include <cstdio>

using namespace std;

static long x[5000009];
static long l[5000009];
static long left[5000009], ileft = 0, iileft = 0;
static long right[5000009], iright = 0, iiright = 0;

inline bool EMPTY_LEFT(void) { return (iileft < ileft); }
inline bool EMPTY_RIGHT(void) { return (iiright < iright); }
inline long TOP_LEFT() { return left[ileft]; }
inline long TOP_RIGHT() { return right[iright]; }

inline void POP(long i, long m) {
	long tmp;
	if (left[ileft] < i - m + 1) ++ileft;
	if (right[iright] < i - m + 1) ++iright;
}

inline void PUSH(long i) {
	if (EMPTY_LEFT()) {
		ileft = 0;
		iileft = 0;
		left[ileft] = i;
	} else {
		left[++iileft] = i;
		while (x[left[iileft - 1]] < x[left[iileft]] && iileft > ileft)
			left[--iileft] = i;
	}
	if (EMPTY_RIGHT()) {
		iright = 0;
		iiright = 0;
		right[iright] = i;
	} else {
		right[++iiright] = i;
		while (
			x[right[iiright - 1]] + l[right[iiright - 1]]  > x[right[iiright]] + l[right[iiright]]
			&& iiright > iright)
			right[--iiright] = i;
	}
}

int main() {
	long a, b, c, d;
	long long s = 0;
	unsigned long i, lli, lri;
 
	scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
  
  for (i = 0; i < b; ++i) {
		scanf("%ld %ld", &x[i], &l[i]);
		POP(i, c); PUSH(i);
		lli = TOP_LEFT(); lri = TOP_RIGHT();
		if (x[lri] + l[lri] - x[lli] >= d && i + 1 >= c)
			s += (long long) (x[lri] + l[lri] - x[lli] - d + 1);
printf("1 -> %lu %lu = %lld\n", x[lli], x[lri] + l[lri], s);
	} 
	ileft = 0; iileft = -1;
	iright = 0; iiright = -1; 
	if (c != d) {
		for (i = 0; i < b; ++i) {
			POP(i, d); PUSH(i);
			lli = TOP_LEFT(); lri = TOP_RIGHT();
			if (x[lri] + l[lri] - x[lli] >= c && i + 1 >= d)
				s += (long long) (x[lri] + l[lri] - x[lli] - c + 1);
printf("2 -> %lu %lu = %lld\n", x[lli], x[lri] + l[lri], s);
		}
	}
	printf("%lld", s);
	return 0;
}
