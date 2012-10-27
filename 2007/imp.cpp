#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 100009
#define TUNES 12
#ifdef MYDEBUG
#define mydebug(args...) \
  do { fprintf(stderr, ##args); \
     } while (false);
#else
#define mydebug(args...) do { } while (false);
#endif

int _maj7[10] = { 0, 2, 4, 7, 9, 11, -1 };
int _min7[10] = { 0, 2, 3, 5, 7, 9, 10, -1 };
int _dim[10]  = { 0, 2, 3, 5, 6, 8, 9, 11, -1 };
int _7[10]    = { 0, 2, 4, 7, 9, 10, -1 };
int _7b9[10]  = { 0, 1, 3, 4, 6, 7, 9, 10, -1 };
int _7x9[10]  = { 0, 1, 3, 4, 6, 8, 10, -1 };
int m, n;

class tune {
public:
	short int k;
	char t, pos;
	
	static std::pair<tune, int *> * P;
	static tune order[TUNES];
	
	tune(void) : pos(-1) {}
	tune(const tune & tn) : k(tn.k), t(tn.t), pos(tn.pos) {
		if (pos < 0) for (char i = 0; i < TUNES; ++i)
			if (order[(int)i] == *this) { pos = i; break; }
	}
	tune & operator=(const tune & tn) { 
		k = tn.k; t = tn.t; pos = tn.pos; 
		if (pos < 0) for (char i = 0; i < TUNES; ++i)
			if (order[(int)i] == *this) { pos = i; break; }
		return *this; 
	}
	
	bool operator==(const tune & tn) const {
		if (k == 1 && tn.k == 2) {
			if (t == 'C' && tn.t == 'D') return true;
			if (t == 'D' && tn.t == 'E') return true;
			if (t == 'F' && tn.t == 'G') return true;
			if (t == 'G' && tn.t == 'A') return true;
			if (t == 'A' && tn.t == 'B') return true;
		} else if (k == 2 && tn.k == 1) {
			if (tn.t == 'C' && t == 'D') return true;
			if (tn.t == 'D' && t == 'E') return true;
			if (tn.t == 'F' && t == 'G') return true;
			if (tn.t == 'G' && t == 'A') return true;
			if (tn.t == 'A' && t == 'B') return true;			
		} else if (k == tn.k)
			return (t == tn.t);
		return false;
	}
	bool operator!=(const tune & tn) const {
		return !(*this == tn);
	}
	tune & next(int p) {
		if (pos < 0) 
			for (char i = 0; i < TUNES; ++i)
				if (order[(int)i] == *this) { pos = i; break; }	
		*this = order[(pos + 1) % TUNES];
		return this->conv2(p);
	}
	tune & prev(int p) {
		if (pos < 0) 
			for (char i = 0; i < TUNES; ++i)
				if (order[(int)i] == *this) { pos = i; break; }
		*this = order[(pos + TUNES - 1) % TUNES];
		return this->conv2(p);
	}
	void load(char * in) {
		k = (in[0]=='_' ? -1 : (in[1]=='#' ? 1 : (in[1]=='b' ? 2 : 0)));
		t = in[0];
		for (char i = 0; i < TUNES; ++i)
			if (order[(int)i] == *this) { pos = i; break; }
	}
	void set(char xt, short int xk, char xpos) {
		t = xt; k = xk; pos = xpos;
	}
	tune conv(int p) const {
		tune x(*this);
		return x.conv2(p);
	}
	tune & conv2(int p) {
		if (k > 0) { // k = 1 lub 2
			switch (P[p].first.k) {
				case 2:
				if (k == 1) {
					k = 2;
					t = 'A' + (t - 'A' + 1) % ('G'-'A'+1);
				}
				break;
				case 1: case 0:
				if (k == 2) {
					k = 1;
					t = 'A' + (t - 2*'A' + 'G') % ('G'-'A'+1);
				}
				break;
				default:
mydebug("ERR: conv2: NO OPTION! %d %c\n", P[p].first.t, P[p].first.k);
			}
		}
		return *this;
	}
	tune nearest(int p) const {
		tune tn(*this), tp(*this);
		if (this->isIn(p)) return this->conv(p);
		for (;;) {
			if (tn.next(p).isIn(p)) return tn;
			if (tp.prev(p).isIn(p)) return tp;
		}
	}
	bool isIn(int p) const {
		for (int i = 0; P[p].second[i] >= 0; ++i) {
			if (order[(P[p].first.pos + P[p].second[i])%TUNES] == *this)
				return true;
		}
		return false;
	}
};

std::pair<tune, int *> __P[MAX];
std::pair<tune, int *> * tune::P = __P;
tune tune::order[TUNES];

tune I[MAX], J[MAX];

inline void algorytm(void) {
	int p = 1;
	for (int i = 1; i <= n; ++i) {
		if (I[i-1].k >= 0) {
			J[i-1] = I[i-1].nearest(p-1);
			if (!(i & 3)) {
				++p;
				if (p > m) p = 1;
			}
		}
	}
}

int main(void) {

	tune::order[ 0].set('C', 0,  0);
	tune::order[ 1].set('C', 1,  1);
	tune::order[ 2].set('D', 0,  2);
	tune::order[ 3].set('D', 1,  3);
	tune::order[ 4].set('E', 0,  4);
	tune::order[ 5].set('F', 0,  5);
	tune::order[ 6].set('F', 1,  6);
	tune::order[ 7].set('G', 0,  7);
	tune::order[ 8].set('G', 1,  8);
	tune::order[ 9].set('A', 0,  9);
	tune::order[10].set('A', 1, 10);
	tune::order[11].set('B', 0, 11);

	char inbuf[8];
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", inbuf);
		tune::P[i].first.load(inbuf);
		int s = 1;
		if (tune::P[i].first.k > 0) ++s;
		switch (inbuf[s]) {
			case 'm':
			if (inbuf[s+1]=='a') tune::P[i].second = _maj7;
			else                 tune::P[i].second = _min7;
			break;
			case 'd':
			tune::P[i].second = _dim;
			break;			
			case '7':
			if (inbuf[s+1]==0)        tune::P[i].second = _7;
			else if (inbuf[s+1]=='b') tune::P[i].second = _7b9;
			else                      tune::P[i].second = _7x9;
			break;
			default:
mydebug("ERR: main: NO OPTION! %d %c\n", s, inbuf[s]);
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", inbuf);
		I[i].load(inbuf);
	}
	for (int i = 0; i < n; ++i) {
		J[i].set('_', -1, -1);
	}
//
	algorytm();
//
	for (int i = 0; i < n; ++i)
		printf("%c%s ", J[i].t, (J[i].k==2 ? "b" : (J[i].k==1 ? "#" : "")));
	printf("\n");
	
	return 0;
}
