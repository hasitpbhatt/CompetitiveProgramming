#include<bits/stdc++.h>
using namespace std;

void fun() {
	int a,b,c;
	cin >> a >> b >> c;
	map< pair<int,int> , int> minStepsToNode;
	map< pair<int,int> , bool> visited;
	queue< pair<int,int> > q;
	pair<int,int> init = make_pair(0,0);
	q.push(init);
	minStepsToNode[init] = 0;
	while(!q.empty()) {
		pair<int,int> curr = q.front();
		q.pop();
		if((curr.first == c) || (curr.second == c)) {
			cout << minStepsToNode[curr] << endl;
			return;
		}
		if(visited[curr])
			continue;
		int currSteps = minStepsToNode[curr];
		visited[curr] = true;

		// empty first can
		pair<int,int> next = make_pair(0,curr.second);
		if(!visited[next]) {
			q.push(next);
			minStepsToNode[next] = currSteps+1;
		}

		// empty second can
		next = make_pair(curr.first,0);
		if(!visited[next]) {
			q.push(next);
			minStepsToNode[next] = currSteps+1;
		}

		// fill first can
		next = make_pair(a,curr.second);
		if(!visited[next]) {
			q.push(next);
			minStepsToNode[next] = currSteps+1;
		}

		// fill second can
		next = make_pair(curr.first,b);
		if(!visited[next]) {
			q.push(next);
			minStepsToNode[next] = currSteps+1;
		}


		// pour from second can to first
		if(curr.first != a) {
			int k = min(a,curr.first+curr.second);
			next = make_pair(k,curr.second+curr.first-k);
			if(!visited[next]) {
				q.push(next);
				minStepsToNode[next] = currSteps+1;
			}
		}

		// pour from first to second
		if(curr.second != b) {
			int k = min(b,curr.first+curr.second);
			next = make_pair(curr.second+curr.first-k,k);
			if(!visited[next]) {
				q.push(next);
				minStepsToNode[next] = currSteps+1;
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}