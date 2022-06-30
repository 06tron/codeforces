#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, last;
		std::cin >> n;
		while (n--) {
			std::cin >> last;
		}
		std::cout << last << '\n';
	}
}
