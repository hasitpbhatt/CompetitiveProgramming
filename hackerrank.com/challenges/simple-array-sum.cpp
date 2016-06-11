#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
    int n, tmp;
    long sum = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
       cin >> tmp;
       sum += tmp;
    }
    cout << sum << endl;
    return 0;
}
