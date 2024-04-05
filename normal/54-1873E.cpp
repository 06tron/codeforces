#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n, x;
		std::cin >> n >> x;
		int a[n];
		for (int i = n; i--;) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		int h = a[0];
		int len = 1;
		while (true) {
			while (len < n && a[len] == a[len-1]) {
				++len;
			}
			if (len == n || a[len]-a[len-1] > x/len) {
				break;
			}
			x -= (a[len]-a[len-1])*len;
			h = a[len];
			++len;
		}
		std::cout << h+x/len << '\n';
	}
}
