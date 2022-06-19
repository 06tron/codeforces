#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int x;
	std::cin >> x;
	int min = 0;
	while (x) {
		min += x & 1;
		x >>= 1;
	}
	std::cout << min;
}
