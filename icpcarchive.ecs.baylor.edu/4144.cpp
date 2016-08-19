#include<bits/stdc++.h>
using namespace std;

int findmax(string &s, int index, int maxChange, int n) {
	int k = maxChange;
	int ans = -1;
	int cnt = 0;
	for(int i=index,j=index;(i>=0) && (j<n) && (k>=0);j++,i--) {
		if(s[i]!=s[j]) {
			if(k==0)
				break;
			k--;
		}
		ans+=2;
	}
	k = maxChange;
	for(int i=index,j=index+1;(i>=0) && (j<n) && (k>=0);j++,i--) {
		if(s[i]!=s[j]) {
			if(k==0)
				break;
			k--;
		}
		cnt+=2;
	}
	return max(cnt,ans);
}

void fun() {
	string s;
	int k;
	cin >> s >> k;
	cin.ignore();
	int len = s.size();
	int ans = len?1:0;
	for(int i=0;i<len;i++) {
		ans = max(ans,findmax(s,i,k, len));
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
}