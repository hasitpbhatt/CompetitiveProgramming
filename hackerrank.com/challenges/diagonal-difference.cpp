#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n;
    cin >> n;
    long long tmp, diff = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> tmp;
            if(i == j)
                diff += tmp;
            if(i + j + 1 == n) 
                diff -= tmp;
        }
    }
    cout << abs(diff) << endl;
    return 0;
}