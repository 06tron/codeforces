#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int i, a[n];
	long long e[n], w[n];
	for (i = 0; i < n; ++i) {
		std::cin >> a[i];
		e[i] = i ? e[i-1] + (a[i] < a[i-1] ? a[i-1]-a[i] : 0) : 0;
	}
	while (i--) {
		w[i] = (i != n-1) ? w[i+1] + (a[i] < a[i+1] ? a[i+1]-a[i] : 0) : 0;
	}
	while (m--) {
		int s, t;
		std::cin >> s >> t;
		std::cout << (--s < --t ? e[t] - e[s] : w[t] - w[s]) << '\n';
	}
}
