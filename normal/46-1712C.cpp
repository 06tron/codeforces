#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n, p;
		std::cin >> n >> p;
		int a[n], b[n], j = 1;
		a[0] = p;
		b[0] = 0;
		for (int i = 1; i < n; ++i) {
			std::cin >> a[j];
			if (a[j] != p) {
				p = a[j];
				++j;
			}
			b[i] = 0;
		}
		for (int i = j; i--;) {
			++b[a[i]-1];
		}
		p = n;
		for (int i = j; i--;) {
			if (a[i] > p) {
				break;
			}
			if (b[a[i]-1] > 1) {
				break;
			}
			--b[a[i]-1];
			p = a[i];
		}
		int ops = 0;
		for (int i = n; i--;) {
			ops += b[i] > 0;
		}
		std::cout << ops << '\n';
	}
}
