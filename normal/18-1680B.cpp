#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int r, c, left = -1, explodes = 0;
		std::cin >> r >> c;
		while (r--) {
			std::string row;
			std::cin >> row;
			if (left < 0) {
				left = row.find('R');
			} else if (!explodes && row.find('R') < left) {
				explodes = 1;
			}
		}
		std::cout << (explodes ? "NO" : "YES") << '\n';
	}
}
