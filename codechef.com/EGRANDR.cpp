/*
Link: https://www.codechef.com/JULY16/problems/EGRANDR/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;

void fun() {
	int n,tmp;
	cin >> n;
	long long target;
	target = 4*n;
	bool flag5 = false, flagFail = false;
	long long sum = 0;
	while(n--) {
		cin >> tmp;
		sum += tmp;
		if(tmp == 5) {
			flag5 = true;
		}
		else if(tmp == 2) {
			flagFail = true;
		}
	}
	if(flag5 && !flagFail &&(sum >= target)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}

int main() {
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}