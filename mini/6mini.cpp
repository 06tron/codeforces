#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t,l,i,m,n;
	for (cin>>t; t--; cout<<(l?"NO\n":"\n")) {
		cin>>l;
		int a[l];
		for (i=l; i--;) cin>>a[i];
		if (l%2==0) {
			sort(a, a+l);
			if (n=a[l/=2]==a[m=l-1]) for (m=i=0; i<l&&n; ++i) m+=n=(a[l]==a[l-i-1])+(a[l]==a[l+i]);
			if (m<l) for (cout<<"YES\n",i=l; i--||(l=0);) cout<<a[i+l]<<' '<<a[i]<<' ';
		}
	}
}
