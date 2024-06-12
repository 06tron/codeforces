#include <iostream>
#include <cmath>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		int k[n];
		int min_k = 21;
		long double sum = 0;
		for (int i = n; i--;) {
			std::cin >> k[i];
			if (k[i] < min_k) {
				min_k = k[i];
			}
			sum += 1 / (long double) k[i];
		}
		if ((double) sum < 1) {
			long long scale = 1000000000 * (long long) min_k;
			for (int i = n; i--;) {
				int x_i = std::ceil(scale / (double) k[i]);
				std::cout << x_i << ' ';
			}
		} else {
			std::cout << -1;
		}
		std::cout << '\n';
	}
}
