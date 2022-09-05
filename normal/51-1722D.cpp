#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		int change[n];
		long long sum = 0;
		for (int i = n; i--;) {
			char p;
			std::cin >> p;
			int seen = (p == 'R') ? i : n-i-1;
			sum += seen;
			change[i] = ((i >= n/2) ? i : n-i-1) - seen;
		}
		std::sort(change, change+n);
		for (int i = n; i--;) {
			sum += change[i];
			std::cout << sum << ' ';
		}
		std::cout << "\n";
	}
}
