#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

long long a[100001];
int n;

int findmax() {
	if(n==1)
		return 1;
	int j = 0;
	int mx = 1;
	for(int i=0;i<n-1;) {
		j = i+1;
		while((j<n) && (a[j-1]+1==a[j])) {
			j++;
		}
		if((j-i) > mx) {
			mx = j-i;
		}
		i = j;
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	int m;
	long long k,l;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << findmax() << endl;
	while(m--) {
		cin >> k >> l;
		a[k-1]=l;
		/*for(int i=0;i<n;i++)
			cout << a[i] << " ";
		cout << endl;*/
		cout << findmax() << endl;
	}
	return 0;
}