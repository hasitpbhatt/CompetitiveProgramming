/*
Author : Hasit ( hasit.p.bhatt@gmail.com )
*/

// Union find

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int ffind(vector<int>& parent, int a) {
	if(parent[a] == a)
		return a;
	return (parent[a] = ffind(parent,parent[a]));
}

void join(vector<int>& parent, int a, int b) {
	parent[ffind(parent,a)] = ffind(parent, b);
}

void fun() {
	int n,q,a,b;
	char c;
	string s;
	cin >> n;
	cin.ignore();
	vector<int> parent(n);
	for(int i=0;i<n;i++) {
		parent[i] = i;
	}
	int successful=0;
	int unsuccessful=0;
	getline(cin,s,'\n');
	while(s.length()) {
		//cout << s << s.length() << endl;
		stringstream ss(s);
		ss >> c;
		//ss.ignore();
		ss >> a >> b;
		a--;
		b--;
		if(c == 'c') {
			join(parent,a,b);
		} else {
			if(ffind(parent,a) == ffind(parent,b)) {
				successful++;
			}
			else {
				unsuccessful++;
			}
		}
		getline(cin,s,'\n');
	}
	cout << successful << "," << unsuccessful << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		fun();
		if(t)
		cout << endl;
	}
	return 0;
}