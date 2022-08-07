#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, prev, diff = 0, printYes = 1;
		std::cin >> n >> prev;
		for (int i = n-1; i--;) {
			int a, sub;
			std::cin >> a;
			sub = a - prev;
			if (diff < 0 && sub > 0) {
				printYes = 0;
			}
			if (sub != 0) {
				diff = sub;
			}
			prev = a;
		}
		std::puts(printYes ? "YES" : "NO");
	}
}
