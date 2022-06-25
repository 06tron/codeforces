#include <iostream>

int f(int c[10], int i, int count, int sum) {
	if (count == 3) {
		return sum % 10 == 3;
	}
	if (count > 3 || i > 9) {
		return 0;
	}
	if (c[i] > 1 && f(c, i+1, count+2, sum+2*i)) {
		return 1;
	}
	if (c[i] > 0 && f(c, i+1, count+1, sum+i)) {
		return 1;
	}
	return f(c, i+1, count, sum) || f(c, i+1, 0, 0);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, v;
	for (std::cin >> tests; tests--; std::puts(v ? "YES" : "NO")) {
		int length, next, c[10] = {0};
		std::cin >> length;
		for (int i = length; i--;) {
			std::cin >> next;
			++c[next % 10];
		}
		v = 0;
		if (c[1] > 2) {
			v = 1;
			continue;
		}
		v = f(c, 0, 0, 0);
	}
}
