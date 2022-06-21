#include <iostream>
#include <string>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		std::string s, t;
		std::cin >> s >> t;
		if (t.find('a') == std::string::npos) {
			std::cout << (1ll << s.size());
		} else {
			std::cout << (t.size() == 1 ? 1 : -1);
		}
		std::cout << '\n';
	}
}
