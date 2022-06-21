#include <iostream>
using namespace std;

int main() {
	int t,a,b;
	for (cin>>t; t--; cout<<'\n') for (cin>>a>>b; a|b; cout<<(a?--a,b?--b,10:0:!!b--));
}
