/*
Link: https://www.codechef.com/JULY16/problems/CHEFELEC/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;

void fun() {
	int n;
	cin >> n;
	std::vector<bool> isVisited(n);
	vector<long long> dist(n);
	long long last, curr;
	string s;
	cin >> s;
	for(int i=0;s[i];i++) {
		if(s[i]=='1')
			isVisited[i] = true;
		else
			isVisited[i] = false;
	}
	for(int i=0;i<n;i++) {
		last = curr;
		cin >> curr;
		if(i) {
			dist[i-1] = curr - last;
		}
	}
	priority_queue< pair<long long, long long> , std::vector< pair<long long, long long> > , greater< pair<long long, long long> > > pq;
	for(int i=0;i<n-1;i++) {
		if(isVisited[i] ^ isVisited[i+1]) {
			pq.push(make_pair(dist[i],i));
		}
	}
	long long sum = 0;

	while(!pq.empty()) {
		pair<long long, long long> d = pq.top();
		int e = d.second;
		pq.pop();
		if(isVisited[e] ^ isVisited[e+1])
		{
			if(!isVisited[e]) {
				if(e > 0) {
					if(!isVisited[e-1]) {
						pq.push(make_pair(dist[e-1],e-1));
					}
				}
				isVisited[e] = true;
			}
			else {
				if(e < n-1) {
					//cout << "fff" << endl;
					if(!isVisited[e+1]) {
						pq.push(make_pair(dist[e+1],e+1));
					}
				}
				isVisited[e+1] = true;
			}
			sum += d.first;
		}
	}
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}