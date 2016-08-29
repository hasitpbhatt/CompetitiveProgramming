#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i=0;i<k;i++) {
		bool flag = false;
		for(int j=n-1;j>0;j--) {
			if(s[j]=='G' && s[j-1]=='B') {
				flag = true;
				s[j] = 'B';
				s[j-1] = 'G';
				j--;
			}
		}
		if(!flag)
			break;
	}
	cout << s << endl;
	return 0;
}