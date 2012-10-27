#include <cstdio>
#include <cmath>

#define EPS 0.000000001
#define Square( x ) ( x * x )
#define Equal( x , y ) ( ( x + EPS > y ) && ( x < y + EPS ) )

static long long A1, B1, C1, A2, B2, C2;
static long long xy[2];

inline double Distance(long long x, long long y, double * r) { return sqrt(Square((r[0] - x)) + Square((r[1] - y))); }

inline bool Check(long long x, long long y) {
	bool xy1, xy2, pp1, pp2;
	if (A1*xy[0] + B1*xy[1] + C1 > 0) xy1 = true; else xy1 = false;
	if (A2*xy[0] + B2*xy[1] + C2 > 0) xy2 = true; else xy2 = false;
	if (A1*x     + B1*y     + C1 > 0) pp1 = true; else pp1 = false;
	if (A2*x     + B2*y     + C2 > 0) pp2 = true; else pp2 = false;
	if (xy1 == pp1 && xy2 == pp2) return true;
	return false;
}

inline bool TotalCheck(long long x, long long y) {
	if (Check(x, y)) {
		if (A1*x + B1*y + C1 == 0 || A2*x + B2*y + C2 == 0)
			return false;
		else 
			return true;
	} else
		return false;
}

int main() {
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &A1, &B1, &C1, &A2, &B2, &C2, &xy[0], &xy[1]);
	long long W, W1, W2, Wxy[2];
	long long lline, X, Y;
	double dline, dxlen, dylen;
	long long P1 = 0, P2 = 0;
	bool bool1, bool2, bool3, bool4;

	W  =  A1*B2 - A2*B1;
	W1 = -C1*B2 + C2*B1;
	W2 = -A1*C2 + A2*C1;

	Wxy[0] = W1 / W;
	Wxy[1] = W2 / W;
	double Dxy[2];
	Dxy[0] = ((double) W1) / ((double) W);
	Dxy[1] = ((double) W2) / ((double) W);
	
	long long qx = Wxy[0];
	long long qy = Wxy[1];
	long long i, j, goodx, goody;
		
	double minimum = -1, len;
	for (i = Wxy[0] - 120; i < Wxy[0] + 120; ++i)
		for (j = Wxy[1] - 120; j < Wxy[1] + 120; ++j) 
			if (TotalCheck(i, j)) {
				len = Distance(i, j, Dxy);
				if (minimum > len || minimum < 0) { minimum = len; goodx = i; goody = j; }
			}
			
	if (minimum > 0) { printf("%lld %lld", goodx, goody); return 0; }
	
// Do dobra, zlosliwie to jest malutki kat miedzy prostymi

	if (A1 == 0 || A2 == 0 || B1 == 0 || B2 == 0) { // a tak zebym potem nie musial uwazac na jakies syfy...
		if (A1 == 0) { 
				dxlen = ((double) -B2) / ((double) A2) + Wxy[0];
				if (dxlen > Wxy[0]) { // +
					X = (long long) (ceil(dxlen) + (Equal(ceil(dxlen), dxlen) ? 1 : 0));
					Y = (A2 * B2 > 0 ? -1 : 1) + ((long long) (((double) -C2) / ((double) B2)));
				} else { // -
					X = (long long) (floor(dxlen) - (Equal(floor(dxlen), dxlen) ? 1 : 0));
					Y = (A2 * B2 > 0 ? 1 : -1) + ((long long) (((double) -C2) / ((double) B2)));
				}
		}
		if (A2 == 0) {
				dxlen = ((double) -B1) / ((double) A1) + Wxy[0];
				if (dxlen > Wxy[0]) { // +
					X = (long long) (ceil(dxlen) + (Equal(ceil(dxlen), dxlen) ? 1 : 0));
					Y = (A1 * B1 > 0 ? -1 : 1) + ((long long) (((double) -C1) / ((double) B1)));
				} else { // -
					X = (long long) (floor(dxlen) - (Equal(floor(dxlen), dxlen) ? 1 : 0));
					Y = (A1 * B1 > 0 ? 1 : -1) + ((long long) (((double) -C1) / ((double) B1)));
				}
		}
		if (B1 == 0) {
				dxlen = ((double) -A2) / ((double) B2) + Wxy[1];
				if (dxlen > Wxy[1]) { // +
					Y = (long long) (ceil(dxlen) + (Equal(ceil(dxlen), dxlen) ? 1 : 0));
					X = (A2 * B2 > 0 ? -1 : 1) + ((long long) (((double) -C2) / ((double) A2)));
				} else { // -
					Y = (long long) (floor(dxlen) - (Equal(floor(dxlen), dxlen) ? 1 : 0));
					X = (A2 * B2 > 0 ? 1 : -1) + ((long long) (((double) -C2) / ((double) A2)));
				}
		}
		if (B2 == 0) {  
				dxlen = ((double) -A1) / ((double) B1) + Wxy[1];
				if (dxlen > Wxy[1]) { // +
					Y = (long long) (ceil(dxlen) + (Equal(ceil(dxlen), dxlen) ? 1 : 0));
					X = (A1 * B1 > 0 ? -1 : 1) + ((long long) (((double) -C1) / ((double) A1)));
				} else { // -
					Y = (long long) (floor(dxlen) - (Equal(floor(dxlen), dxlen) ? 1 : 0));
					X = (A1 * B1 > 0 ? 1 : -1) + ((long long) (((double) -C1) / ((double) A1)));
				}
		}
		printf("%lld %lld", X, Y);
		return 0;
	}

	lline = Wxy[0];

//	long long mod = (W*B1*B2);
//	long long modx = W1 % mod;
//	long long mody = W2 % mod;
//	long long a1x = -(A1 % mod);
//	long long a2x = -(A2 % mod);

	a1 = A1 * W * B1 * B2; a2 = A2 * W * B1 * B2;
	b1 = B1 * W * B1 * B2; b2 = B2 * W * B1 * B2;
	c1 = C1; c2 = C2;
	x = xy[0] * W * B1 * B2; y = xy[1] * W * B1 * B2;
	
	wx = (-C1*B2 + C2*B1) * B1 * B2;
	wy = (-A1*C2 + A2*C1) * B1 * B2;

	

	long long s;
	if (xy[0] * W > W1) s = 1;
	else s = -1;
	
	while (P1 == P2) {
		P1 = -(A1*lline + C1) / B1;
		P2 = -(A2*lline + C2) / B2;
		if (TotalCheck(lline, P1)) {
			printf("%lld %lld", lline, P1); 
			break;
		} else if (TotalCheck(lline, P2)) {
			printf("%lld %lld", lline, P2);
			break;
		} else {
			P1 = P2;
			lline += s;
		}
	}
	
	return 0;
}

