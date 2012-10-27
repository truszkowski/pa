#include <algorithm>
#include <cstdio>
#define div(x,y) ( ((x)/(y))  +  (((x)/(y))*(y) < (x) ? 1 : 0) )
#define mMAX 128
#define lMAX 1000009
#define sMAX 1024
int m, l, k, s, c[mMAX], p, r, z[mMAX];
long long v[mMAX], out = 0;
bool sums[sMAX];
typedef std::pair<int, int> PR;
PR pr[lMAX];

int main(void) {
	scanf("%d%d%d%d", &m, &l, &k, &s);
	for (int i = 0; i < m; ++i) scanf("%d", c + i); 
	for (int i = 0; i < m; ++i) v[i] = 0;
	for (int i = 0; i < l; ++i) {
		scanf("%d%d", &p, &r);
		pr[i].first = p - 1;
		pr[i].second = r;
		v[p-1] += r;
	}

	std::sort(pr, pr + l);
	for (int i = 0; i < m; ++i) z[i] = (v[i] - (v[i]/k)*k);
	
// A teraz to co misie lubia najbardziej...

	int rez = 0, pre = 0;
	
	while (pre < m) {

		if (z[pre]*c[pre] < s && z[pre] > 0) { // trzeba ciachnac cos z ogona.
			for (int i = 0; i <= s; ++i) sums[i] = false;
			int cut = 0; // gdzie tniemy, 0 - nigdzie,

			while (pr[rez].first < pre && rez < l) ++rez;
			
			while (pr[rez].first == pre && rez < l) { 
// tu trzeba przemielic wszystkie rezerwacje na konkretna 
// prezentacje pr[rez].first == pre.

				if (pr[rez].second*c[pre] < s) { // kryterium aby ok?
// Rezerwacja, ktora trzeba wziazc pod uwage,

					for (int i = cut; i >= 0; i -= c[pre]) {
// zaczynamy od góry, i skaczemy po wielkrotnosciach c[pre],

						if (sums[i]) { 
// trzeba dodac nowe potencjalne rozwiazanie,
							sums[i+pr[rez].second*c[pre]] = true;
						
// Potrzeba jest zaktualizowac zmienna cut,
							if (cut <= z[pre]*c[pre]) {
// Gdy tniemy przed "przejsciem",
								if (pr[rez].second*c[pre]+i > cut)
									cut = pr[rez].second*c[pre]+i;
							} else if (pr[rez].second*c[pre]+i >= z[pre]*c[pre]) {
// Gdy tniemy juz po przejsciu,
								if (pr[rez].second*c[pre]+i <= cut)
									cut = pr[rez].second*c[pre]+i;
							}

						}
						
// Jesli juz sie wpasowalo to konczymy.
						if (sums[z[pre]*c[pre]]) break;

					}

					sums[pr[rez].second*c[pre]] = true;
					
// I znow...
					if (cut <= z[pre]*c[pre]) {
						if (pr[rez].second*c[pre] > cut)
							cut = pr[rez].second*c[pre];
					} else if (pr[rez].second*c[pre] >= z[pre]*c[pre]) {
						if (pr[rez].second*c[pre] <= cut)
							cut = pr[rez].second*c[pre];
					}
					
// Jak wczesniej, jesli sie wpasowalo to hop.
					if (sums[z[pre]*c[pre]]) break;
				}
				
				++rez;
			}
			
//if (pre == 0)
//fprintf(stderr, "%d %d %lld\n", cut, z[pre], v[pre]);
			
// jesli okaze sie, ze mozna pozbyc sie rezerwacji to siup...
			if (cut >= z[pre]*c[pre] && cut < s) 
				v[pre] = v[pre] - cut/c[pre];
		} 
		

		
		++pre;
	}
	
// No i podliczamy...

	for (int i = 0; i < m; ++i)
		out += v[i]*((long long) c[i]) - ((long long) s)*(div(v[i], ((long long) k)));

	printf("%lld\n", out);
	return 0;
}
