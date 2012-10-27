#include <iostream>
#include <string>
int n, counter = 0;
std::string a, b;

int main(void) {
	std::ios_base::sync_with_stdio(0);
	std::cin >> n >> a >> b;

	for (int i = 0; i < n; ++i)
		if (a[i] != b[i]) ++counter;

	std::cout << counter << std::endl;
	return 0;
}
