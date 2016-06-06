/*
Link: https://www.codechef.com/SNCKPA16/problems/MAKEART/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/
 
#include<bits/stdc++.h>
using namespace std;
 
void fun() {
	long n, last = -1, tmp, lastlast = -1;
	cin >> n;
	bool flag = false;
	bool first = false, second = false, third = false;
	for(int i=0;i<n;i++) {
		cin >> tmp;
		if(flag)
			continue;
		if(!first) {
			last = tmp;
			first = true;
		}
		else {
			if(!second) {
				if(last == tmp)
					second =  true;
				else {
					last = tmp;					
				}
			}
			else {
				if(last == tmp)
					flag =  true;
				else {
					last = tmp;
					second = false;
				}
			}
		}
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
}
 
int main() {
	int n;
	cin >> n;
	while(n--)
		fun();
	return 0;
} 
Comments 
