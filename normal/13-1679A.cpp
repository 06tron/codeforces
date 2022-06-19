#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	long long wheels, min, max;
	for (std::cin >> tests; tests--; std::cout << max << '\n') {
		max = -1;
		std::cin >> wheels;
		if (wheels & 1 || wheels < 4) {
			continue;
		}
		min = wheels / 6;
		while ((wheels - (min * 6)) % 4) {
			--min;
		}
		min += (wheels - (min * 6)) / 4;
		std::cout << min << ' ';
		max = wheels / 4;
		while ((wheels - (max * 4)) % 6) {
			--max;
		}
		max += (wheels - (max * 4)) / 6;
	}
}
