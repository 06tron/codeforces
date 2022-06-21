#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	while (n--) {
		string s,t;
		cin>>s>>t;
		cout<<(t.find(97)>49?1ll<<s.size():t.size()-1?-1:1)<<'\n';
	}
}
