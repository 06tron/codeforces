#include <iostream>
#include <string>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::string out;
	for (std::cin >> tests; tests--; std::cout << out << '\n') {
		out = "YES";
		int len, b = 0, j = 0;
		std::cin >> len;
		std::string s, t;
		std::cin >> s >> t;
		for (int i = 0; i < len; ++i) {
			std::cout << i << ": " << s[i] << ", " << j << ": " << t[i] << '\n';
			if (s[i] != 'b') {
				while (j < len && t[j] == 'b') {
					--b;
					std::cout << "(-)";
					++j;
				}
				if (s[i] != t[j]) {
					out = "NO1";
					break;
				} else {
					++j;
				}
			} else {
				++b;
				std::cout << "(+)";
			}
		}
		while (j < len && t[j] == 'b') {
			--b;
			std::cout << "[-]";
			++j;
		}
		if (b) {
			out = "NO2";
		}
	}
}
// aaabbbccc
// abaacbbcc

int b = 0, v = 1, c = 1;
for (int i = 0; i < len; ++i) {
	switch (s[i]) {
	case 'a':
		if (c) {

		} else {
			b += t[i] == 'b';
			v = t[i] != 'c';
		} break;
	case 'c':
		if (c) {
			
		} else {

		} break;
	default:
		if (c) {

		} else {

		}
	}
}

// aaaa<-(b)aaaaa
// bbbbb(a)->bbbb
// bbbb<-(c)bbbbb
// ccccc(b)->cccc