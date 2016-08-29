#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	long long cnt = 0;
	char c,state = '0';
	cin >> n;
	while(n--) {
		cin >> c;
		if(state == '0')
			state = c;
		else if(c == state)
			cnt++;
		else
			state = c;
	}
	cout << cnt << endl;
	return 0;
}