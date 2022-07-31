#include <iostream>
#include <math.h>
#include <algorithm>

long long subnum(long long num, int s, int f) {
	num /= (long long) pow(27, s);
	num %= (long long) pow(27, f);
	return num;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n;
		std::cin >> n;
		long long s[n];
		std::string input[n];
		for (int i = n; i--;) {
			std::cin >> input[i];
			s[i] = 0;
			for (int j = input[i].size(); j--;) {
				s[i] += pow(27, j)*(input[i][j]-'a'+1);
			}
		}
		std::sort(s, s+n);
		for (int i = n; i--;) {
			long long num = 0;
			for (int j = input[i].size(); j--;) {
				num += pow(27, j)*(input[i][j]-'a'+1);
			}
			int substring = 0;
			for (int j = 1; j < 8; ++j) {
				if (std::binary_search(s, s+n, subnum(num, 0, j))) {
					if (std::binary_search(s, s+n, subnum(num, j, 8))) {
						substring = 1;
					}
				}
			}
			std::cout << substring;
		}
		std::cout << '\n';
	}
}
