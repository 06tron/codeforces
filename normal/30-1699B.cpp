#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, m;
		std::cin >> n >> m;
		while (n--) {
			for (int i = m; i--;) {
				std::cout << !((n+1 & 2) ^ (i+1 & 2)) << ' ';
			}
			std::cout << '\n';
		}
	}
}
