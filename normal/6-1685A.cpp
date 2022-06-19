#include <iostream>
#include <algorithm>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, a[100000];
	for (std::cin >> tests; tests--; std::cout << '\n') {
		int l;
		std::cin >> l;
		for (int i = 0; i < l; ++i) {
			std::cin >> a[i];
		}
		if (l % 2) {
			std::cout << "NO";
			continue;
		}
		std::sort(a, a+l);
		l /= 2;
		if (a[l] == a[l-1]) {
			int mid = 2;
			int next = 1;
			for (int i = 1; i < l && next; ++i) {
				mid += next = (a[l] == a[l-i-1]) + (a[l] == a[l+i]);
			}
			if (mid >= l) {
				std::cout << "NO";
				continue;
			}
		}
		std::cout << "YES\n";
		for (int i = 0; i < l; ++i) {
			std::cout << a[i] << ' ' << a[i+l] << ' ';
		}
	}
}