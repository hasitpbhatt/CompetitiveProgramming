// https://sharecode.io/section/problemset/problem/1003

#include<iostream>
using namespace std;

int main() {
	int a,b,c,num1,num2,num3,arr1[80],arr2[80],arr3[80];
	string s,ss;
	while(cin >> a >> b >> c){
		if(!(a || b || c))
			break;
		num1 = num2 = num3 = 0;
		cin >> s;
		ss = s;
		for(int i=0;s[i];i++) {
			if(s[i] >='a' && s[i]<='i'){
				arr1[num1] = i;
				num1++;
			}
			else if(s[i]>='j' && s[i]<='r') {
				arr2[num2] = i;
				num2++;
			}
			else {
				arr3[num3] = i;				
				num3++;
			}
		}
		for(int i=0;i<num1;i++) {
			ss[arr1[(i+a)%num1]] = s[arr1[i]];
		}
		for(int i=0;i<num2;i++) {
			ss[arr2[(i+b)%num2]] = s[arr2[i]];
		}
		for(int i=0;i<num3;i++) {
			ss[arr3[(i+c)%num3]] = s[arr3[i]];
		}
		cout << ss << endl;
	}
	return 0;
}