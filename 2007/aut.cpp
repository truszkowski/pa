#include <cstdio>
#include <algorithm>
#define MAX 1010101
int t1, t2, m, n1, n2;
std::pair<int,int> v1[MAX], v2[MAX];
int min = -1, tmp = -1, fit = -1;

bool comp(const std::pair<int,int> & p1, const std::pair<int,int> & p2) {
	if (p1.first < p2.first) return true;
	if (p1.first > p2.first) return false;
	if (p1.second < p2.second) return true;
	return false;
}

int main(void) {
	scanf("%d%d%d%d%d", &t1, &t2, &m, &n1, &n2);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n1; ++j) scanf("%d", &v1[i*n1+j].first);
		for (int j = 0; j < n1; ++j) v1[i*n1+j].second = v1[j].first;
		for (int j = 0; j < n2; ++j) scanf("%d", &v2[i*n2+j].first);
		for (int j = 0; j < n2; ++j) v2[i*n2+j].second = v2[j].first;
	}
	
	min = t2 - t1;
#ifdef MYDEBUG
	printf("min = %d (%d,%d,%d)\n", min, m, n1, n2);	
#endif

	for (int i = 1; i < m; ++i) {
		std::sort(v1+i*n1, v1+(i+1)*n1, comp);
		std::sort(v2+i*n2, v2+(i+1)*n2, comp);
		fit = -1;
		int i1 = 0, i2 = 0, f1 = -1;
		while (i1 < n1) {
			while (v1[i*n1+i1].first > v2[i*n2+i2].first && i2 < n2) {
				if (f1 >= 0) {
					fit = (v1[i*n1+f1].second-t1) + (t2-v2[i*n2+i2].second) + (v2[i*n2+i2].first-v1[i*n1+f1].first);
#ifdef MYDEBUG
					printf("MIN1: %d -> %d %d (%d %d) [%d,%d]->[%d,%d]\n", 
						i, fit, min, i1, i2, v1[i*n1+f1].second, v1[i*n1+f1].first, v2[i*n2+i2].first, v2[i*n2+i2].second);
#endif
					if (fit < min) min = fit;
				}
				++i2;
			}
			if (i2 == n2) break;
			if ((v1[i*n1+i1].second-t1) < 0) { ++i1; continue; }
			if ((t2-v2[i*n2+i2].second) < 0) { ++i2; continue; }
			if (f1 < 0) f1 = i1;
			tmp = (v1[i*n1+i1].second-t1) + (t2-v2[i*n2+i2].second) + (v2[i*n2+i2].first-v1[i*n1+i1].first);
			fit = (v1[i*n1+f1].second-t1) + (t2-v2[i*n2+i2].second) + (v2[i*n2+i2].first-v1[i*n1+f1].first);
#ifdef MYDEBUG
			printf("MIN2: %d -> %d %d %d (%d %d) [%d,%d] [%d,%d]->[%d,%d] { i<f : %d + %d < %d + %d }\n", 
				i, tmp, fit, min, i1, i2, v1[i*n1+f1].second, v1[i*n1+f1].first, v1[i*n1+i1].second, v1[i*n1+i1].first, v2[i*n2+i2].first, v2[i*n2+i2].second,
				(v2[i*n2+i2].first-v1[i*n1+i1].first), (v1[i*n1+i1].second-t1), (v2[i*n2+i2].first-v1[i*n1+f1].first), (v1[i*n1+f1].second-t1));
#endif
			if ((v2[i*n2+i2].first-v1[i*n1+i1].first)+(v1[i*n1+i1].second-t1) < (v2[i*n2+i2].first-v1[i*n1+f1].first)+(v1[i*n1+f1].second-t1))
				f1 = i1;
			if (fit < tmp) tmp = fit;
			if (tmp < min) min = tmp;
			++i1;
		}
#ifdef MYDEBUG		
		printf("3: min = %d\n", min);
#endif
	}
	
	printf("%d\n", min);
	return 0;
}
