#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	int lookup[] = {32, 0, 1, 26, 2, 23, 27, 0, 3, 16, 24, 30, 28, 11, 0, 13, 4, 7, 17, 0, 25, 22, 31, 15, 29, 10, 12, 6, 0, 21, 14, 9, 5, 20, 8, 19, 18};
	std::cin >> tests;
	while (tests--) {
		int tokens, evens, splits;
		std::cin >> tokens;
		evens = 0;
		splits = 30; // 2^30 > 10^9
		for (int i = 0; i < tokens; ++i) {
			int power;
			std::cin >> power;
			if (power % 2 == 0) {
				++evens;
				int s = lookup[(power & -power) % 37];
				if (s < splits) {
					splits = s;
				}
			}
		}
		std::cout << (evens < tokens ? evens : splits + evens - 1) << '\n';
	}
}
