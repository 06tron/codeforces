#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, first, possible = 1;
		std::cin >> n >> first;
		for (int i = n-1; i--;) {
			int a;
			std::cin >> a;
			if (a % first) {
				possible = 0;
			}
		}
		std::puts(possible ? "YES" : "NO");
	}
}
