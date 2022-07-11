#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int price, r;
		std::cin >> price;
		for (r = 1; r * 10 <= price; r *= 10);
		std::cout << (price - r) << '\n';
	}
}
