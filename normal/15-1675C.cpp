#include <iostream>
#include <string>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		std::string ans;
		int sus = 1;
		std::cin >> ans;
		if (ans.at(0) != '0' && ans.back() != '1') {
			int firstZero = ans.find('0'), lastOne = ans.rfind('1');
			if (firstZero == std::string::npos) {
				if (lastOne == std::string::npos) {
					sus = ans.size();
				} else {
					sus = ans.size() - lastOne;
				}
			} else if (lastOne == std::string::npos) {
				sus = 1 + firstZero;
			} else {
				sus = 1 + firstZero - lastOne;
			}
		}
		std::cout << sus << '\n';
	}
}
