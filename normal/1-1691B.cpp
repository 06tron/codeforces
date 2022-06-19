#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, s[100000];
	std::cin >> tests;
	while (tests--) {
		int students, idx, size, count;
		std::cin >> students >> s[0];
		idx = 0;
		size = s[0];
		count = 1;
		for (int i = 1; i < students; ++i, ++count) {
			std::cin >> s[i];
			if (s[i] > size) {
				if (count < 2) {
					for (++i; i < students; ++i) {
						std::cin >> s[i];
					}
					goto END;
				}
				s[idx] = idx + count;
				count = 0;
				size = s[i];
				idx = i;
			} else {
				s[i] = i;
			}
		}
		s[idx] = idx + count;
		if (count < 2) {
			END: std::cout << -1;
		} else {
			for (int i = 0; i < students; ++i) {
				std::cout << s[i] << ' ';
			}
		}
		std::cout << '\n';
	}
}
