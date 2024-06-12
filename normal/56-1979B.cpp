#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		// number of trailing zeros in x^y
		int x, y;
		std::cin >> x >> y;
		int ant = x^y;
		int i = 0;
		while (~ant & 1) {
			ant >>= 1;
			++i;
		}
		std::cout << (1<<i) << '\n';
	}
}
