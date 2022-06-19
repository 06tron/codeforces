#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	for (int n,q,i=(cin>>n>>q,n),x,y,p[n]; i--;) cin>>p[i];
	long long s[(sort(p, p+n),n+1)];
	for (s[i=n]=0; i--;) s[i]=s[i+1]+p[i];
	while (q--) cin>>x>>y,cout<<(s[n-x]-s[y+n-x])<<'\n';
}
