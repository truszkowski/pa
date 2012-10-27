#include <cstdio>
#include <vector>

using namespace std;

bool nein = false;                          // czy kila i mogila
bool home[50009];                           // czy to domek zuczka
bool visit[50009];                          // czy odwiedzone dfsem
vector<long> route[50009];                  // tutaj sciezki
long globmax = -1;                          // maksymalny odstep miedzy dwoma zuczkami

long dfs(long v) {
	long i, max = 0, next = -1, prev = -1;
	visit[v] = true;
	if (home[v]) prev = 0;                    // jak jestem w domu...

	for (i = 0; i < (long) route[v].size(); ++i)
		if (!visit[route[v][i]])
			if ((next = dfs(route[v][i])) > -1)   // tutaj dowiadujemy sie, jakiego maxa ma ten "nizej", jak nie ma - olewamy go.
				if (prev > -1) {                    // oho wczesniej mielismy doczynienia z jakims maxem!
					if (prev + next > max)            // mamy nowego maxa !!:P
						max = prev + next;
					if (max > globmax)                // zapisujemy skrzetnie, ze do tej pory taka jest maksymalna odleglosc miedzy zuczkami
						globmax = max;
					if ((prev + next) % 2 == 1)       // oj, dupa teraz, bo nie uda sie zuczkom dojsc do jednego domku...
  					nein = true;
					if (next > prev)                  // pamietamy dalej tylko o najlepszym... tzn o maxie z prev, next
						prev = next;
				} else 
					prev = next;

	if (nein) return -1;                      // oho, zuczki maja przesrane!
	if (prev ==  0 && next == -1) return 1;   // nie bylo wczesniej maxa i ustanawiamy pierwszego !
	if (prev == -1 && next == -1) return -1;  // nie bylo i nie ma maxa...
	return prev + 1;
}

int main() {
	long a, b, i, k, m, n;

	scanf("%ld %ld", &n, &m);
	for (i = 0; i < n; ++i) {
		home[i] = false;
		visit[i] = false;
	}
	for (i = 0; i < m; ++i) {
		scanf("%ld %ld", &a, &b);
		route[a - 1].push_back(b - 1);
		route[b - 1].push_back(a - 1);
	}
	scanf("%ld", &k);
	for (i = 0; i < k; ++i) {
		scanf("%ld", &a);
		home[a - 1] = true;
	}
	
	dfs(0);                                   // jazda...
	
	if (nein || globmax < 2)                 printf("NIE");
	else                                     printf("%ld", globmax/2);
	
	return 0;
}
