#include <iostream>
#define I std::cin>>

int main() {
	int t,n,k,a,b,c,o,i;
	for (I t; t--; std::cout<<o<<'\n') {
		I n>>k>>a>>b;
		o=0;
		for (i=n-2; i--; o+=a<(a=b)-(b=c)) I c;
		o=k-1?o:(n-1)/2;
	}
}
