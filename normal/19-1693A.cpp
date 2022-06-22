#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int size, valid = 1, zeros = 0;
		long long b = 0;
		std::cin >> size;
		while (size-- > 0) {
			long long next;
			std::cin >> next;
			if (b > next) {
				valid = 0;
			} else {
				b -= next;
				if (b == 0) {
					zeros = 1;
				} else if (zeros) {
					valid = 0;
				}
			}
		}
		if (b) {
			valid = 0;
		}
		std::cout << (valid ? "yes" : "no") << '\n';
	}
}
