#include <iostream>

int main() {
	int x,y=0;
	std::cin>>x;
	do y+=x&1;
	while (x/=2);
	std::cout<<y;
}