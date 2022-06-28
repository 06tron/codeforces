#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		long long x;
		std::cin >> x;
		int i;
		for (i = 1; !(x & i); i <<= 1);
		int y;
		if (x - i) {
			y = i;
		} else {
			y = i == 1 ? 3 : i + 1;
		}
		std::cout << y << '\n';
	}
}
