#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int tests;
	std::cin >> tests;
	while (tests--) {
		int n, H, M, hNext = 50, mNext = 0;
		std::cin >> n >> H >> M;
		for (int i = n; i--;) {
			int h, m;
			std::cin >> h >> m;
			if (h < H || (h == H && m < M)) {
				h += 24;
			}
			if (m < M) {
				m += 60;
				h -= 1;
			}
			h -= H;
			m -= M;
			if (h < hNext || (h == hNext && m < mNext)) {
				hNext = h;
				mNext = m;
			}
		}
		std::cout << hNext << ' ' << mNext << '\n';
	}
}
