/*
Link: https://www.codechef.com/JULY16/problems/CHEFTET/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;
 
void fun() {
	int n;
	cin >> n;
	vector<long long> A(n);
	vector<long long> B(n);
	vector<bool> used(n);
	long long sum = 0;
	for(int i=0;i<n;i++) {
		cin >> A[i];
		sum += A[i];
		used[i] = false;
	}
	for(int i=0;i<n;i++) {
		cin >> B[i];
		sum += B[i];
	}
	if(sum % n) {
		cout << -1 << endl;
		return;
	}
	sum /= n;
	for(int i=0;i<n;i++) {
		if(B[i] > sum) {
			cout << -1 << endl;
			return;	
		}
		else if(B[i] < sum) {
			if(i>0) {
				if(!used[i-1] && ((B[i]+A[i-1]) == sum)) {
					used[i-1] = true;
					continue;
				}
				else if(!used[i-1] && !used[i] && ((B[i]+A[i-1]+A[i]) == sum)) {
					used[i-1] = true;
					used[i] = true;
					continue;
				}
				else if((i<n-1) && !used[i-1] && !used[i] && !used[i+1] && ((B[i]+A[i-1]+A[i]+A[i+1]) == sum)) {
					used[i-1] = true;
					used[i] = true;
					used[i+1] = true;	
					continue;
				}
				else if((i<n-1) && !used[i-1] && !used[i+1] && ((B[i]+A[i-1]+A[i+1]) == sum)) {
					used[i-1] = true;
					used[i+1] = true;	
					continue;
				}
			}
			if(!used[i] && ((B[i]+A[i]) == sum)) {
				used[i] = true;
				continue;
			}
			if((i<n-1) && !used[i+1] && !used[i] && ((B[i]+A[i+1]+A[i]) == sum)) {
				used[i+1] = true;
				used[i] = true;
				continue;
			}
			if((i<n-1) && !used[i+1] && ((B[i]+A[i+1]) == sum)) {
				used[i+1] = true;
				continue;
			}
			cout << -1 << endl;
			return;
		}
	}
	cout << sum << endl;
}
 
int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}