#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		int snake[n*n];
		for (int i = n*n; i--;) {
			snake[i] = i&1 ? (n*n)-(i>>1) : 1+(i>>1);
		}
		for (int i = n; i--;) {
			for (int j = n; j--;) {
				std::cout << snake[i&1 ? j+n*i : n-j-1+n*i] << ' ';
			}
			std::cout << '\n';
		}
	}
}
