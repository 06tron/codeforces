#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		long long x;
		x = (c/b+1)*b+a;
		std::cout << x << ' ' << b << ' ' << c << '\n';
	}
}
