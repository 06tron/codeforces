#include <iostream>

int main() {
	long long f,e,z;
	for (std::cin>>f; f--; std::cout<<(e-z?z:z-1?z+1:3)<<'\n') for (std::cin>>e,z=1; !(e&z); z<<=1);
}
