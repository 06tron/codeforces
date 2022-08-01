#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, possible = 1, moves = 0;
		std::cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		for (int i = n-1; i--;) {
			if (a[i+1] < i+1) {
				possible = 0;
				break;
			}
			while (a[i] >= a[i+1]) {
				a[i] /= 2;
				++moves;
			}
		}
		std::cout << (possible ? moves : -1) << '\n';
	}
}
