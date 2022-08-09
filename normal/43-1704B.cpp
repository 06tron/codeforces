#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, x, min, max, changes = 0;
		std::cin >> n >> x >> min;
		max = min;
		for (int i = n-1; i--;) {
			int a;
			std::cin >> a;
			if (a < min) {
				min = a;
			}
			if (a > max) {
				max = a;
			}
			if (max-min > 2*x) {
				++changes;
				max = min = a;
			}
		}
		std::cout << changes << '\n';
	}
}
