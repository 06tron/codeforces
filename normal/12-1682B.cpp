#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, andsum = -1;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			int p;
			std::cin >> p;
			if (p != i) {
				andsum = andsum < 0 ? p : andsum & p;
			}
		}
		std::cout << andsum << '\n';
	}
}
