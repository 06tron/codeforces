#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, m, sum = 0;
		std::cin >> n >> m;
		while (n--) {
			int a;
			std::cin >> a;
			sum += a;
		}
		std::cout << (m > sum ? 0 : sum - m) << '\n';
	}
}
