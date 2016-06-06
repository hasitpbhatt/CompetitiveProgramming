/*
Link: https://www.codechef.com/SNCKQL16/problems/KTTABLE
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/
 
#include<bits/stdc++.h>
using namespace std;
 
long long fun() {
	long long t,a[10000],b,cnt = 0, dist;
	cin >> t;
	for(int i = 0 ; i < t ; i++ ) {
		cin >> a[i];
	}
	for(int i = 0 ; i < t ; i++ ) {
		if(i == 0)
			dist = a[i];
		else
			dist = a[i]-a[i-1];
		cin >> b;
		if(b<=dist)
			cnt++;
	}
	return cnt;
}
 
int main() {
	int n;
	cin >> n;
	while(n--) {
		cout << fun() << endl;
	}
	return 0;
} 