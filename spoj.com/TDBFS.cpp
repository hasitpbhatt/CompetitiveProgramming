#include <bits/stdc++.h>
using namespace std;

void dfs(vector < vector<int> > v, int vertex) {
	vector<bool> visited(v.size());
	stack<int> s;
	s.push(vertex);
	while(!s.empty()) {
		int next = s.top();
		s.pop();
		if(visited[next])
			continue;
		else {
			visited[next] = true;
			cout << next+1 << " ";
			for(vector<int>::reverse_iterator i = v[next].rbegin(); i != v[next].rend(); i++) {
				if(!visited[*i])
					s.push(*i);
			}
		}
	}
}

void bfs(vector < vector<int> > v, int vertex) {
	vector<bool> visited(v.size());
	queue<int> s;
	s.push(vertex);
	while(!s.empty()) {
		int next = s.front();
		s.pop();
		if(visited[next])
			continue;
		else {
			visited[next] = true;
			cout << next+1 << " ";
			for(vector<int>::iterator i = v[next].begin(); i != v[next].end(); i++) {
				if(!visited[*i])
					s.push(*i);
			}
		}
	}
}


void fun() {
	int a,b,n,m;
	cin >> n;
	vector < vector<int> > v(n, vector<int>());
	for(int i=0;i<n;i++) {
		cin >> a;
		a--;
		cin >> m;
		for(int j=0;j<m;j++) {
			cin >> b;
			b--;
			v[a].push_back(b);
		}
	}
	while(cin >> a >> b) {
		if(a+b == 0)
			break;
		a--;
		if(b == 0) {
			dfs(v,a);
		} else {
			bfs(v,a);
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "graph " << i << endl;
		fun();
	}
	return 0;
}