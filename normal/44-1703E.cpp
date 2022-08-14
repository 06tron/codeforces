#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, ops = 0;
		std::cin >> n;
		std::string a[n];
		for (int i = n; i--;) {
			std::cin >> a[i];
		}
		--n;
		for (int i = (n+2)/2; i--;) {
			for (int j = (n+1)/2; j--;) {
				int sum = a[i][j]-'0';
				sum += a[j][n-i]-'0';
				sum += a[n-i][n-j]-'0';
				sum += a[n-j][i]-'0';
				ops += sum > 2 ? 4-sum : sum;
			}
		}
		std::cout << ops << '\n';
	}
}
