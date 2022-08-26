#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int a, b, c, d, out;
		std::cin >> a >> b >> c >> d;
		long long dsa = d*(long long)a, csb = c*(long long)b;
		if (dsa == csb) {
			out = 0;
		} else if (dsa && csb && csb%dsa && dsa%csb) {
			out = 2;
		} else {
			out = 1;
		}
		std::cout << out << '\n';
	}
}
