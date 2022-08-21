#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t, b[100000]; // 06tron
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		int a[m];
		for (int i = m; i--;) {
			std::cin >> a[i];
		}
		std::sort(a, a+m);
		int first = a[0], p = first, len = 0;
		for (int i = m-1; i--;) {
			int next = a[m-i-1];
			if (next-p != 1) {
				b[len++] = next-p-1;
			}
			p = next;
		}
		b[len++] = n-p+first-1; // could be zero
		std::sort(b, b+len);
		int saved = 0;
		for (int i = len; i--;) {
			int lost = 1+4*(len-i-1);
			if (b[i] <= lost) {
				saved += b[i] == lost;
				break;
			}
			saved += b[i]-lost;
		}
		std::cout << (n-saved) << '\n';
	}
}
