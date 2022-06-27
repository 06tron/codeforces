#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, s, head = 0;
		std::cin >> n >> s;
		int a[n];
		for (int sum = 0, i = 0; i < n; ++i) {
			std::cin >> a[i];
			if (sum < s) {
				sum += a[i];
			}
			if (sum == s) {
				++sum;
				head = i + 1;
			}
		}
		if (head == 0) {
			std::cout << (s ? -1 : 0) << '\n';
		} else {
			while (head < n && a[head] == 0) ++head;
			int tail = 0, max = head - tail;
			while (head < n) {
				++head;
				while (head < n && a[head] == 0) ++head;
				while (tail < n && a[tail] == 0) ++tail;
				++tail;
				if (head - tail > max) {
					max = head - tail;
				}
			}
			std::cout << (n - max) << '\n';
		}
	}
}
