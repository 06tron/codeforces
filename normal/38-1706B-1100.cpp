#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, c[100000], h[100000];
	std::cin >> tests;
	while (tests--) {
		int n, pos = 1;
		std::cin >> n;
		for (int i = n; i--;) {
			std::cin >> c[i];
			h[i] = 0;
		}
		for (int i = n; i--;) {
			int height = h[n-c[i]];
			if (!height || pos == height > 0) {
				h[n-c[i]] = -(pos ? height + 1 : height - 1);
			}
			pos = !pos;
		}
		for (int i = n; i--;) {
			std::cout << (h[i] > 0 ? h[i] : -h[i]) << ' ';
		}
		std::cout << '\n';
	}
}
