#include <iostream>
using namespace std;

int main() {
	long long t,s,v,z,a,b;
	for (cin>>t; v=t--; cout<<(v&&z?"yes":"no")<<'\n') {
		z=b=0;
		for (cin>>s; s--; v=(b-=a)>0?0:z&&b?0:(z=b?z:1,v)) cin>>a;
	}
}
