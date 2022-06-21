#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int a, b;
		std::cin >> a >> b;
		while (a > 0 || b > 0) {
			if (b > 0) {
				std::cout << 1;
				--b;
			}
			if (a > 0) {
				std::cout << 0;
				--a;
			}
		}
		std::cout << '\n';
	}
}
