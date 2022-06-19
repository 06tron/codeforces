#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, p[] = {0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412};
	std::cin >> tests;
	while (tests--) {
		int hour, min, x, count = 0;
		char colon;
		std::cin >> hour >> colon >> min >> x;
		min += 60 * hour;
		int a = x, b = 1440;
		while (a != b) {
			if (a > b) {
				a -= b;
			} else {
				b -= a;
			}
		} // a is gcd
		for (int i = 16; i--;) {	
			count += (p[i] + (1440 - min)) % a == 0;
		}
		std::cout << count << '\n';
	}
}
