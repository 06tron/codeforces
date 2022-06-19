#include <iostream>
#define I std::cin>> 

int main() {
	int t,o,l,s,w,i,p[7<<15];
	for (I t; t--; std::cout<<o<<'\n') {
		I l>>s;
		for (char c=w=i=0; i<l; ++i) w+=(I c,(p[i]=c==87)&&i<s);
		for (o=w,i=0; i<l-s; ++i) if (w+=p[i+s]-p[i],w<o&&(o=w,1)&&!w) break;
	}
}