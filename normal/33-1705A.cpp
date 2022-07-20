#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, x, possible = 1;
		std::cin >> n >> x;
		int h[2*n];
		for (int i = 2*n; i--;) {
			std::cin >> h[i];
		}
		std::sort(h, h+2*n);
		for (int i = n; i--;) {
			if (h[i+n]-h[i] < x) {
				possible = 0;
			}
		}
		std::puts(possible ? "YES" : "NO");
	}
}
