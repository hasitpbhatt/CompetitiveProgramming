#include <bits/stdc++.h>
using namespace std;

long long dfs(vector< vector<long long> >& adjList, int index) {
    long long ans = 1;
    for(int i : adjList[index]) {
        ans = max(ans, dfs(adjList,i)+1);
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    vector< vector<long long> > adjList(n,vector<long long>());
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i] != -1) {
            adjList[v[i]-1].push_back(i);
        }
    }
    
    long long ans = 0;
    for(int i=0;i<n;i++) {
        if(v[i] == -1) {
            ans = max(ans, dfs(adjList,i));
        }
    }
    cout << ans << "\n";
    return 0;
}