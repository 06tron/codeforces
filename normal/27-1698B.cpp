#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, k;
		std::cin >> n >> k;
		int a, b, c, out = 0;
		std::cin >> a >> b;
		for (int i = n-2; i--;) {
			std::cin >> c;
			out += b > a + c;
			a = b;
			b = c;
		}
		if (k == 1) {
			out = (n-1)/2;
		}
		std::cout << out << '\n';
	}
}
