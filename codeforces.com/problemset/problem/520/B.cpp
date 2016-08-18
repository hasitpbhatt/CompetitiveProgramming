#include <bits/stdc++.h>
using namespace std;

#define MAX 2e4+1
#define INVALID -1

int main() {
	int n,m;
	cin >> n >> m;
	vector<int> v(MAX,-1);
	v[m] = 0;
	queue<int> q;
	q.push(m);
	while((v[n] == INVALID) && q.size()){
		int i = q.front();
		q.pop();
		if((i%2 == 0) && (v[i/2]==INVALID)) {
			v[i/2] = v[i]+1;
			q.push(i/2);
		}
		if((i+1 < MAX) && (v[i+1]==INVALID)){
			v[i+1] = v[i]+1;
			q.push(i+1);
		}
	}
	cout << v[n] << endl;
	return 0;
}