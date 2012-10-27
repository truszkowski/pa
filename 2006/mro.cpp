#include <cstdio>

long distance(char a, char b) {
	char c;
	if (a > b) { c = a; a = b; b = c; }
	switch (a) {
		case 'A': switch (b) { case 'B': return 1; case 'C': return 2; case 'D': return 1; case 'E': return 1; case 'F': return 2; case 'G': return 3; case 'H': return 2; } 
		case 'B': switch (b) { case 'C': return 1; case 'D': return 2; case 'E': return 2; case 'F': return 1; case 'G': return 2; case 'H': return 3; } 
		case 'C': switch (b) { case 'D': return 1; case 'E': return 3; case 'F': return 2; case 'G': return 1; case 'H': return 2; } 
		case 'D': switch (b) { case 'E': return 2; case 'F': return 3; case 'G': return 2; case 'H': return 1; } 
		case 'E': switch (b) { case 'F': return 1; case 'G': return 2; case 'H': return 1; } 
		case 'F': switch (b) { case 'G': return 1; case 'H': return 2; }
		case 'G': return 1;
	};
	return 0;
}

class Matrix33 {
	public:
		long long a[3][3];
		Matrix33() {}
		Matrix33(long long x, long long b, long long c, long long d, long long e, long long f, long long g, long long h, long long i) {
			a[0][0] = x; a[0][1] = b; a[0][2] = c;
			a[1][0] = d; a[1][1] = e; a[1][2] = f;
			a[2][0] = g; a[2][1] = h; a[2][2] = i;
		}
		virtual Matrix33 & multi(Matrix33 & m33, long long m) {
			Matrix33 newmatrix(0, 0, 0, 0, 0, 0, 0, 0, 0);
			int i, j, k;
			for (i = 0; i < 3; ++i)
				for (j = 0; j < 3; ++j) {
					for (k = 0; k < 3; ++k) 
						newmatrix.a[i][j] += a[i][k] * m33.a[k][j];
					newmatrix.a[i][j] %= m;
				}
			*this = newmatrix;
			return *this;
		}
		virtual Matrix33 & square(long long m) {
			return multi(*this, m);
		}
};

class Matrix31 {
	public:
		long long a[3];
		Matrix31() {}
		Matrix31(long long x, long long b, long long c) { a[0] = x; a[1] = b; a[2] = c; }
		virtual Matrix31 & multi(Matrix33 & m33, long long m) {
			Matrix31 newmatrix(0, 0, 0);
			int i, j;
			for (i = 0; i < 3; ++i) {
				for (j = 0; j < 3; ++j)
					newmatrix.a[i] += a[j] * m33.a[j][i];
				newmatrix.a[i] %= m;
			}
			*this = newmatrix;
			return *this;
		}
};

Matrix31 recursive(Matrix33 m33, Matrix31 m31, long long n, long long m) {
	if (n == 0) 
		return m31;
	if (n % 2 == 0) 
		return recursive(m33.square(m), m31, n / 2, m);
	return recursive(m33, m31.multi(m33, m), n - 1, m);
}

int main() {
	long long d, m, n;
	char a, b;
	scanf("%c %c %lld %lld", &a, &b, &n, &m);
	d = distance(a,b);
	if ( ( d % 2 == 1 && n % 2 == 0 ) || ( d % 2 == 0 && n % 2 == 1 ) )
		printf("0");
	else { 
		Matrix33 M(0, 2, 1, 1, 1, 0, -2, 2, 0);
		Matrix31 A(0, 2, 0);
		Matrix31 R(0, 1, 0);

		if (n % 2 == 1) {
			if (d == 3) 
				d = 0;
		} else 
			d = 1;

		if (n > 1) R = recursive(M, A, n - 2, m);
		
		if (R.a[d] < 0) R.a[d] += m;
		
		printf("%lld", (R.a[d] * (d ? 1 : 3)) % m);
		
	}
	return 0;
}
