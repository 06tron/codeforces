#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n; // 06tron
	std::cin >> n;
	int b[n][n], tilable = 1;
	for (int i = n; i--;) {
		std::string row;
		std::cin >> row;
		for (int j = row.size(); j--;) {
			b[i][j] = row[j] == '.';
		}
	}
	for (int i = n; i--;) {
		for (int j = n; j--;) {
			if (b[i][j] && (!j || j == n-1 || i < 2 || !(b[i-1][j]-- && b[i-1][j-1]-- && b[i-1][j+1]-- && b[i-2][j]--))) {
				tilable = 0;
				break;
			}
		}
		if (!tilable) {
			break;
		}
	}
	std::puts(tilable ? "YES": "NO");
}
