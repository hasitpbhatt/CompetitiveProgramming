#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

void fun() {
	int n,m;
	int a,b,c;
	int src, dest;
	cin >> n >> m;
	vector < iii > edgeList;
	vector < vector<ii> > adjList(n, vector<ii> ());
	cin >> src >> dest;
	src--;
	dest--;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		adjList[a].push_back(make_pair(c,b));
		adjList[b].push_back(make_pair(c,a));
	}
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	vector<int> dist(n,INT_MAX);
	vector<bool> isVisited(n,false);
	pq.push(make_pair(0,src));
	dist[src] = 0;
	while(pq.size()) {
		ii t = pq.top();
		pq.pop();
		if(isVisited[t.second])
			continue;
		isVisited[t.second] = true;
		dist[t.second] = t.first;
		for(vector < ii >::iterator edge = adjList[t.second].begin() ; edge != adjList[t.second].end(); edge++) {
			if(!isVisited[(*edge).second] && dist[(*edge).second] > dist[t.second]+(*edge).first) {
				dist[edge->second] = dist[t.second]+edge->first;
				pq.push(make_pair(dist[t.second]+edge->first,edge->second));
				}
			}
		}
	if(dist[dest] == INT_MAX)
		dist[dest] = -1;
	cout << dist[dest] << endl;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		fun();
	}
	return 0;
}
