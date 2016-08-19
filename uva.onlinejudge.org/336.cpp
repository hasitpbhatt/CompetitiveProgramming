#include <bits/stdc++.h>
using namespace std;

map < int, vector<int> > m;

int bfs(int a,int b) {
	map< int, bool > visited;
	map< int, int > dist;
	queue<int> q;
	q.push(a);
	int count = 0;
	dist[a] = 0;
	if(m.find(a) == m.end())
		return 0;
	while(!q.empty()) {
		int next = q.front();
		q.pop();
		if(visited.find(next) != visited.end())
			continue;
		int distance = dist[next];
		visited[next] = true;
		count++;
		if(distance == b) {
			continue;
		}
		for(vector<int>::iterator it = m[next].begin(); it != m[next].end(); it++) {
			if(visited.find(*it) == visited.end()) {
				if(dist[*it] != 0)
					dist[*it] = min(dist[*it],distance+1);
				else
					dist[*it] = distance+1;
				q.push(*it);
			}
		}
	}
	return count;
}

int main() {
	int t;
	int a,b;
	int count = 1;
	while(cin >> t) {
		if(!t)
			break;
		m.clear();
		set<int> allNodes;
		for(int i=0;i<t;i++) {
			cin >> a >> b;
			allNodes.insert(a);
			allNodes.insert(b);
			m[a].push_back(b);
			m[b].push_back(a);
		}
		while(cin >> a >> b) {
			if(a+b == 0)
				break;
			cout << "Case " << count;
			cout << ": ";
			cout << allNodes.size()-bfs(a,b);
			cout << " nodes not reachable from node " ;
			cout << a;
			cout << " with TTL = ";
			cout << b;
			cout << "." << endl;
			count++;
		}
	}
	return 0;
}