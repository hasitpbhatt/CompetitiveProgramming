/*
Link: https://www.codechef.com/SNCKPA16/problems/MAKELIS/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;
 
#define MAX 100001
#define endl "\n"
 
int a[MAX]; // 
int d[MAX]; //
int b[MAX]; // substring length
 
int primes[] = {2,3,5,7};
int primen = 4;
 
int mx = 0;
 
void prefun(int mymax) {
	int c;
	for(int i=0;i<mymax;i++) {
		if(i == 0) {
			a[i]=b[i]=0;d[i]=0;
		}
		else if(i == 1) {
			a[i] = b[i] = 1;d[i]=1;
		}
		else {
			a[i] = MAX;
			b[i] = MAX;
			for(int j=0;j<primen;j++) {
				if(i%primes[j] == 0) {
				c = a[i/primes[j]] + primes[j];
					if(c < a[i]) {
						a[i] = c;
						b[i] = b[i/primes[j]] + 1;
						d[i] = primes[j];
					}
				}
			}
			c = a[i-1] + b[i-1];
			if(c < a[i]) {
				a[i] = c;
				b[i] = b[i-1];
				d[i] = 1;
			}
		}
		if(a[i] > mx) {
			mx = a[i];
			//cout << ":::" << i << " " << mx << endl;
		}
	}
}
 
void fun(int n) {
	if(d[n] == 1) {
		for(int i=a[n]-b[n]+1;i<=a[n];i++) {
			cout << i << " ";
		}
		fun(n-1);
	}
	else if(d[n] == 2) {
		fun(n/2);
		cout << a[n] << " ";
		cout << a[n]-1 << " ";
	}
	else if(d[n] == 3) {
		fun(n/3);
		cout << a[n] << " ";
		cout << a[n]-1 << " ";
		cout << a[n]-2 << " ";
	}
	else if(d[n] == 5) {
		fun(n/5);
		cout << a[n] << " ";
		cout << a[n]-1 << " ";
		cout << a[n]-2 << " ";
		cout << a[n]-3 << " ";
		cout << a[n]-4 << " ";
	}
	else if(d[n] == 7) {
		fun(n/7);
		cout << a[n] << " ";
		cout << a[n]-1 << " ";
		cout << a[n]-2 << " ";
		cout << a[n]-3 << " ";
		cout << a[n]-4 << " ";
		cout << a[n]-5 << " ";
		cout << a[n]-6 << " ";
	}
}
 
int main() {
	int n,q;
	cin >> n;
	prefun(MAX);
	while(n--) {
		cin >> q;
		cout << a[q] << endl;
		fun(q);
		cout << endl;
	}
	/*for(int i=0;i<n;i++) {
		cout << i << " " << a[i] << " " << b[i] << endl;
	}*/
	//cout << mx << endl;
	return 0;
} 