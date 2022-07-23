#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n;
		long long sum = 0;
		std::cin >> n;
		while (n--) {
			int a;
			std::cin >> a;
			if (n && (sum || a)) {
				sum += a ? a : 1;
			}
		}
		std::cout << sum << '\n';
	}
}
