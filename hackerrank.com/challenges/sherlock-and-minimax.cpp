#include<bits/stdc++.h>
using namespace std;

long fun(long a, long b, long c, long d) {
    long mid = (c + d) >> 1;
    if(a <= mid) {
        if(b >= mid) {
            return mid;
        }
        else {
            return b;
        }
    }
    else {
        return a;
    }
}

int main() {
    long i, n, p , q, mmin = -1, mini = -1;
    cin >> n;
    vector<long> a(n);
    for(i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    cin >> p >> q;
    if( p < a[0]) {
        mmin = a[0]-p;
        mini = p;
        p = a[0];
    }
    if( q > a[n-1]) {
        if(q-a[n-1] > mmin) {
            mmin = q-a[n-1];
            mini = q;
        }
        q = a[n-1];
    }
    for(i=0;i<n-1;i++) {
        if((p <= a[i+1]) && (p <= q)) {
            long m = fun(p,q,a[i],a[i+1]);
            long r = min(abs(m-a[i]),abs(m-a[i+1]));
            if( r > mmin) {
                mmin = r;
                mini = m;
            }
            p = a[i+1];
        }
    }
    cout << mini << endl;
    return 0;
}