#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, l, i;
		std::string bigint;
		std::cin >> n >> bigint;
		std::string output(n, '0');
		if (bigint[0] != '9') {
			for (int i = 0; i < n; ++i) {
				output[i] = 105 - bigint[i];
			}
		} else {
			output[0] += 2;
			for (int i = 1; i < n-2; ++i) {
				output[i] = 105 - bigint[i];
			}
			if (bigint[n-1] > '1') {
				output[n-1] = 107 - bigint[n-1];
				bigint[n-2] += 1;
			} else {
				output[n-1] = 97 - bigint[n-1];
			}
			if (bigint[n-2] > '1') {
				output[n-2] = 107 - bigint[n-2];
				int j;
				for (j = n-3; j > 0 && output[j] == '0'; --j) {
					output[j] = '9';
				}
				if (j >= 0) {
					output[j] -= 1;
				}
			} else {
				output[n-2] = 97 - bigint[n-2];
			}
		}
		std::cout << output << '\n';
	}
}