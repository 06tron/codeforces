#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, output;
	char p[200000];
	for (std::cin >> tests; tests--; std::cout << output << '\n') {
		int length, segment;
		std::cin >> length >> segment;
		for (int i = 0; i < length; ++i) {
			std::cin >> p[i];
		}
		output = length;
		int white = 0;
		for (int i = 0; i < segment; ++i) {
			if (p[i] == 'W')  {
				++white;
			}
		}
		output = white;
		for (int i = 0; i < length - segment; ++i) {
			if (p[i] == 'W') {
				--white;
			}
			if (p[i + segment] == 'W') {
				++white;
			}
			if (white < output) {
				output = white;
				if (white == 0) {
					break;
				}
			}
		}
	}
}
