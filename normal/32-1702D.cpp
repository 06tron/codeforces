#include <iostream>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		std::string w;
		int goal, price = 0;
		std::cin >> w >> goal;
		for (int i = w.size(); i--;) {
			price += w[i]-'a'+1;
		}
		int letters[26] = {0};
		if (price > goal) {
			std::string sorted = w;
			std::sort(sorted.begin(), sorted.end());
			for (int i = w.size(); i-- && price > goal;) {
				price -= sorted[i]-'a'+1;
				++letters[sorted[i]-'a'];
			}
		}
		for (int i = 0; i < w.size(); ++i) {
			if (letters[w[i]-'a']-- <= 0) {
				std::cout << w[i];
			}
		}
		std::cout << '\n';
	}
}
