#include <iostream>
#include <algorithm>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	int p[n];
	for (int i = n; i--;) {
		std::cin >> p[i];
	}
	std::sort(p, p+n);
	long long s[n+1];
	s[n] = 0;
	for (int i = n; i--;) {
		s[i] = s[i+1] + p[i];
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		std::cout << (s[n-x] - s[y+n-x]) << '\n';
	}
}
