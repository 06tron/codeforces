#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n;
		std::cin >> n;
		int a[n];
		for (int i = n; i--;) {
			std::cin >> a[i];
		}
		int init = 0, diff = 0, valid = 1;
		for (int i = n; i--;) {
			int b;
			std::cin >> b;
			if (init) {
				if (b) {
					if (a[i]-b != diff)  {
						valid = 0;
					}
				} else {
					if (a[i]-b > diff) {
						valid = 0;
					}
				}
			} else {
				if (b) {
					init = 1;
					if (a[i]-b < diff) {
						valid = 0;
					}
				}
				if (a[i]-b > diff) {
					diff = a[i]-b;
				}
			}
		}
		std::puts(valid ? "YES" : "NO");
	}
}
