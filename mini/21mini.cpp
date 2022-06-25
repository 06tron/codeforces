#include <iostream>
#define I std::cin>>

int f(int *c, int i, int k, int s) {
	return k==3?s%10==3:k<3&&i<10&&(c[i]>1&&f(c,i+1,k+2,s+2*i)||c[i]>0&&f(c,i+1,k+1,s+i)||f(c,i+1,k,s)||f(c,i+1,0,0));
}

int main() {
	int t,v,l,n;
	for (I t; t--; std::puts(v?"YES":"NO")) {
		I l;
		int c[10]={0},i=l;
		for (; i--; ++c[n%10]) I n;
		v=c[1]>2?1:f(c,0,0,0);
	}
}
