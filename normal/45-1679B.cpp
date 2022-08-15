#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, q; // 06tron
	std::cin >> n >> q;
	int a[n], info[n], id = 0;
	long long base = 0, diff = 0;
	for (int j = n; j--;) {
		std::cin >> a[j];
		diff += a[j];
		info[j] = id;
	}
	for (int j = q; j--;) {
		int t, i, x;
		std::cin >> t;
		if (t == 1) {
			std::cin >> i;
		}
		std::cin >> x;
		if (t == 1) {
			diff += x-(info[n-i] == id ? a[n-i] : base);
			a[n-i] = x;
			info[n-i] = id;
		} else {
			base = x;
			diff = 0;
			++id;
		}
		std::cout << (diff+n*base) << '\n';
	}
}
