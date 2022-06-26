#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n;
		long long z, a, max = 0;
		std::cin >> n >> z;
		for (int i = n; i--;) {
			std::cin >> a;
			if ((a | z) > max) {
				max = a | z;
			}
		}
		std::cout << max << '\n';
	}
}
