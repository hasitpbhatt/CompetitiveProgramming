/*
The Smallest Pair
Link	:	https://www.codechef.com/problems/SMPAIR
Author	:	hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios::sync_with_stdio(false);
	int cases;
	int numbers;
	int a[2];
	int cnt = 0;
	int n;
	cin >> cases;
	while(cases--) {
		cnt = 0;
		cin >> numbers;
		while(numbers--) {
			cin >> n;
			if(cnt < 2) {
				if(cnt == 0)
					a[0] = n;
				else if(a[0] < n)
					a[1] = n;
				else {
					a[1] = a[0];
					a[0] = n;
				}
				cnt++;
			}
			else {
				if(n < a[0]) {
					a[1] = a[0];
					a[0] = n;
				}
				else if(n < a[1]) {
					a[1] = n;
				}
			}
		}
		cout << a[0]+a[1] << endl;
	}
	return 0;
}