#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		int a[n];
		for (int i = n; i--;) {
			std::cin >> a[i];
		}
		int min_n = 1000000001;
		for (int i = n; i--;) {
			if (i > 0 && a[i-1] < min_n && a[i-1] >= a[i]) {
				min_n = a[i-1];
			}
			if (i < n-1 && a[i+1] < min_n && a[i+1] >= a[i]) {
				min_n = a[i+1];
			}
		}
		std::cout << min_n-1 << '\n';
	}
}
