#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int num, m, j, mMin, jMin = mMin = 1000000001;
		std::cin >> num;
		int a[num];
		for (int i = 0; i < num; ++i) {
			std::cin >> a[i];
			if (i & 1) {
				if (a[i] < jMin) {
					j = i;
					jMin = a[i];
				}
			} else if (a[i] < mMin) {
				m = i;
				mMin = a[i];
			}
		}
		std::cout << (num & 1 ? "Mike\n" : jMin < mMin ? "Mike\n" : jMin != mMin ? "Joe\n" : j < m ? "Mike\n" : "Joe\n");
	}
}
