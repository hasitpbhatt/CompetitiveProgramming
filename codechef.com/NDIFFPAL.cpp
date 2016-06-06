/*
Link: https://www.codechef.com/SNCKPA16/problems/NDIFFPAL/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;
 
void fun() {
	int n;
	cin >> n;
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	for(int i=0;i<n;i++)
		cout << str[i%26];
	cout << "\n";
}
 
int main() {
	int n;
	cin >> n;
	while(n--) {
		fun();
	}
	return 0;
} 