#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			std::cout << (i ? i : n) << ' ';
		}
		std::cout << '\n';
	}
}
