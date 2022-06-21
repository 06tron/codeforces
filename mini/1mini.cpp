#include <iostream>
using namespace std;

int main() {
	int t,n,i,j,v,c,s[100000];
	for (cin>>t; t--; cout<<'\n') {
		cin>>n>>s[0];
		v=s[j=0];
		for (i=c=1; i<n; ++i,++c) {
			cin>>s[i];
			if (v&&s[i]>v) {
				s[j]=j+c;
				v=c<2?0:s[j=i];
				c=0;
			}
			s[i]=i;
		}
		s[j]=j+c;
		if (v&&c>1) for (i=0; i<n; ++i) cout<<s[i]<<' ';
		else cout<<-1;
	}
}
