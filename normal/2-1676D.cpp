#include <iostream>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests, a[40000];
	std::cin >> tests;
	while (tests--) {
		int rows, columns;
		std::cin >> rows >> columns;
		for (int i = 0; i < rows * columns; ++i) {
			std::cin >> a[i];
		}
		int max = 0;
		for (int ir = 0; ir < rows; ++ir) {
			for (int ic = 0; ic < columns; ++ic) {
				int sum, r, c;
				sum = 0;
				r = (ir > ic) ? (c = 0, ir - ic) : (c = ic - ir, 0);
				for (; r < rows && c < columns; ++r, ++c) {
					sum += a[r * columns + c];
				}
				for (r = ir - 1, c = ic + 1; r >= 0 && c < columns; --r, ++c) {
					sum += a[r * columns + c];
				}
				for (r = ir + 1, c = ic - 1; r < rows && c >= 0; ++r, --c) {
					sum += a[r * columns + c];
				}
				max = (sum > max) ? sum : max;
			}
		}
		std::cout << max << '\n';
	}
}
