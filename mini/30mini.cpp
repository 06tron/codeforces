#include <iostream>
using namespace std;

int main() {
	int t,n,m,i;
	for (cin>>t; t--;) for (cin>>n>>m; n--; puts("")) for (i=m; i--; cout<<!(n+1&2^i+1&2)<<' ');
}
