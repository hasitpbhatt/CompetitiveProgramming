#include<bits/stdc++.h>
using namespace std;

void fun() {
	int c;
	cin >> c;
	cout << c << " ";
	cin.ignore();
	int curr = 0;
	string s;
	getline(cin,s,'\n');
	int q;
	cin >> q;
	int a;
	int len = s.length();
	while(q--) {
		cin >> a;
		curr += a;
		if(curr >= len) {
				curr = curr % len;
				/*if(c&1) {
					curr = a;
				}*/
		}
		else if(curr < 0) {
			curr+=len;
			/*if(c&1) {
					curr = len+a-1;
				}*/
		}
		//curr = (curr+len+a)%len;
		cout << s[curr];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}