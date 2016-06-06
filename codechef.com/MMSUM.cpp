/*
Link: https://www.codechef.com/SNCKQL16/problems/MMSUM
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
 
long long fun() {
	long long t,a[100001],b[100001],c[100001];
	cin >> t;
	long long mx;
	for(long long i=0;i<t;i++) {
		cin >> a[i];
		if(i==0)
			mx = a[i];
		else if(a[i] > mx)
			mx = a[i];
	}
	for(long long i=t-1;i>=0;i--) {
		if(i == t-1)
			b[i] = a[i];
		else if(b[i+1] > 0)
			b[i] = b[i+1] + a[i];
		else
			b[i] = a[i];
		if(b[i] > mx)
			mx = b[i];
	}
	for(long long i=0;i<t;i++) {
		if(i==0)
			c[i] = a[i];
		else if(c[i-1] > 0)
			c[i] = c[i-1] + a[i];
		else
			c[i] = a[i];
		if(c[i] > mx)
			mx = c[i];
	}
	/*for(long long i=0;i<t;i++)
		cout << b[i] << " ";
	cout << endl;
	for(long long i=0;i<t;i++)
		cout << c[i] << " ";
	cout << endl;*/
	for(long long i=1;i<t-1;i++) {
		if(c[i-1]+b[i+1] > mx)
			mx = c[i-1]+b[i+1];
	}
	return mx;
}
 
int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--)
		cout << fun() << endl;
	return 0;
} 