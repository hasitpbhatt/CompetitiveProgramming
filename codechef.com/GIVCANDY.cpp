/*
Link: https://www.codechef.com/SNCKPA16/problems/GIVCANDY/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;
 
#define endl "\n"
 
long long gcd(long long a,long long b) {
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
  
void fun() {
	long long a,b,c,d,k,r, tmp;
	cin >> a >> b >> c >> d;
	long long gc = gcd(c,d);
	if(abs(a-b) % gc == 0) {
		cout << "0\n";
	}
	else {
		cout << min(abs(a-b)%gc,gc-abs(a-b)%gc) << "\n";
	}
}
 
int main() {
	int n;
	cin >> n;
	while(n--) {
		fun();
	}
	return 0;
} 
