#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
    long n;
    long long tmp,sum = 0;
    cin >> n;
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> tmp;
       sum += tmp;
    }
    cout << sum << endl;
    return 0;
}
