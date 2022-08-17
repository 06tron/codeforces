#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		int a[n];
		long long taken = n;
		for (int i = n; i--;) {
			std::cin >> a[i];
			taken += a[i];
		}
		std::sort(a, a+n);
		taken += a[n-1];
		taken -= a[0];
		std::puts(taken > m ? "NO" : "YES");
	}
}
