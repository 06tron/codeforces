#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t; // 06tron
	std::cin >> t;
	int id = 0, incr = 1 << 18;
	long allSeen[200000] = {};
	while (t--) {
		int n, seqExist = 0;
		std::cin >> n;
		int kValues[n];
		int* pValues[n];
		for (int i = n; i--;) {
			int k;
			std::cin >> k;
			kValues[i] = k;
			pValues[i] = (int*) malloc(k * sizeof(int));
			while (k--) {
				int p;
				std::cin >> p;
				pValues[i][k] = p;
				if ((allSeen[p] & incr - 1) != id) {
					allSeen[p] = id;
				}
				allSeen[p] += incr;
			}
		}
		while (n--) {
			int k;
			for (k = kValues[n]; k--;) {
				if (allSeen[pValues[n][k]] == id + incr) {
					break;
				}
			}
			if (k < 0) {
				seqExist = 1;
				break;
			}
		}
		std::puts(seqExist ? "Yes" : "No");
		++id;
	}
}
