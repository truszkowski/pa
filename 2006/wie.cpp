#include <cstdio>

#define MAX 100009
#define abs(x) ((x) > 0 ? (x) : - (x))

static long w1[MAX][2], w1n, w1s;
static long w2[MAX][2], w2n;

void udrl(long w[MAX][2], long n, long & ui, long & di, long & ri, long & li) {
	long u, d , r, l;
	u = d = w[0][1]; ui = di = 0;
	r = l = w[0][0]; ri = li = 0;
	for (i = 1; i < n; ++i) { 
		if (u < w[i][1]) { u = w[i][1]; ui = i; }
		if (d > w[i][1]) { d = w[i][1]; di = i; }
		if (r < w[i][0]) { r = w[i][0]; ri = i; }
		if (l > w[i][0]) { l = w[i][0]; li = i; }
	}
}


long sum(long w[MAX][2], long n) {
	long u, d, r, l, ui, di, ri, li, i, dx, dy, s;
	udrl(w, n, ui, di, ri, li);
	u = w[ui][1];
	d = w[di][1];
	l = w[li][0];
	r = w[ri][0];
	s = 2 * (u - d) * (r - l);
	for (i = 0; i < n; ++i) {
		dx = abs(w[(i + di)%n][0] - w[(i + di + 1)%n][0]);
		dy = abs(w[(i + di)%n][1] - w[(i + di + 1)%n][1]);
		s -= dx * dy;
		s -= dx * abs(
			(w[(i + di)%n][0] > w[(i + di + 1)%n][0] ? d : u)
			 -
			((w[(i + di)%n][0] > w[(i + di + 1)%n][0] && w[(i + di)%n][1] < w[(i + di + 1)%n][1]) ||
			 (w[(i + di)%n][0] < w[(i + di + 1)%n][0] && w[(i + di)%n][1] > w[(i + di + 1)%n][1]) ? 
				w[(i + di)%n][1] : w[(i + di + 1)%n][1]) 
		);
	}
	return s;
}



int main() {
	long i, j;
	bool bool1;
	scanf("%ld %ld", &w1n, &w2n);
	for (i = 0; i < w1n; ++i) scanf("%ld %ld", &w1[i][0], &w1[i][1]);
	for (i = 0; i < w2n; ++i) scanf("%ld %ld", &w2[i][0], &w2[i][1]); 
	
	w1s = sum(w1, w1n);
	
	long u1, u1i, d1, d1i, r1, r1i, l1, l1i;
	udrl(w1, w1n, u1i, d1i, r1i, l1i);
	u1 = w1[u1i][1];
	d1 = w1[d1i][1];
	l1 = w1[l1i][0];
	r1 = w1[r1i][0];
	
	long u2, u2i, d2, d2i, r2, r2i, l2, l2i;
	udrl(w2, w2n, u2i, d2i, r2i, l2i);
	u2 = w2[u2i][1];
	d2 = w2[d2i][1];
	l2 = w2[l2i][0];
	r2 = w2[r2i][0];
	
	for (i = 0; i < w1n; ++i) {
		x1 = w1[(i + d1i)%w1n][0]; 
		y1 = w1[(i + d1i)%w1n][1]; 
		x2 = w2[(i + d2i)%w2n][0]; 
		y2 = w2[(i + d2i)%w2n][1]; 
		
		
	}
	
	return 0;
}
