#include<iostream>
using namespace std;

#define MAX 10000007
#define endl "\n"

long long pow(long long exponent, long long power) {
	if(power == 1)
		return exponent;
	else if(exponent && !power)
		return 1;
	long long a = pow(exponent, power>>1);
	a *= a;
	a %= MAX;
	if(power&1) {
		a *= exponent;
		a %= MAX;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	long long n,k;
	while(cin >> n >> k) {
		if(n+k) {
			cout << (2*pow(n-1,n-1)+pow(n,n)+2*pow(n-1,k)+pow(n,k))%MAX << endl;
		}
		else {
			break;
		}
	}
	return 0;
}