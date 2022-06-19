#include <iostream>
#include <stack>
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int p[n+1];
	for (int i = 2; i < n+1; ++i) {
		std::cin >> p[i];
	}
	p[1] = 0;
	std::stack<int> s;
	for (int i = n; i; i = p[i]) {
		s.push(i);
	}
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
}
