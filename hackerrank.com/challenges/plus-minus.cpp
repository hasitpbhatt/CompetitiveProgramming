#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    long n,tmp;
    cin >> n;
    double a = 0,b = 0,c = 0;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        if(tmp > 0)
            a++;
        else if(tmp < 0)
            b++;
        else
            c++;
    }
    a /= n;
    b /= n;
    c /= n;
    cout.precision(9); cout << fixed;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}