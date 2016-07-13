/*
Link: https://www.codechef.com/JULY16/problems/CHEFARC/
Author : hasitpbhatt (hasit.p.bhatt@gmail.com)
*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define MAX 101
 
int n,m,K1,K2;
int arr[MAX][MAX], d11[MAX][MAX], d22[MAX][MAX];
bool visited[MAX*MAX],visited2[MAX*MAX];
 
bool isValid(int i,int j) {
	if(((i>=n) || (j>=m) || (i<0) || (j<0)))
		return false;
	return true;
}

int ar[MAX*MAX], ar1[MAX*MAX];
int dist[MAX*MAX], dist1[MAX*MAX];
 
int fun() {
	cin >> n >> m >> K1 >> K2;
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			cin >> arr[i][j];
			d11[i][j] = -1;
			if(!arr[i][j]) {
				visited2[i*MAX+j] = visited[i*MAX+j] = false;
			}
			else {
				visited2[i*MAX+j] = visited[i*MAX+j] = true;
			}
			d22[i][j] = -1;
		}
	}
	int r,cnt = 1;
	int index = 0;
	int startX, startY, endX, endY;
	ar[0] = dist[0] = 0;
	visited[0] = true;
	while(index < cnt) {
		i = ar[index]/MAX;
		j = ar[index]%MAX;
		startX = max(0,i-K1);
		startY = max(0,j-K1);
		endX = min(n-1,i+K1);
		endY = min(m-1,j+K1);
		d11[i][j] = dist[index];
		for(int ii=startX;ii<=endX;ii++) {
			for(int jj=startY;jj<=endY;jj++) {
				r = (ii)*MAX+jj;
				if(isValid(ii,jj) && !visited[r] && (abs(i-ii)+abs(j-jj) <= K1)) {
					ar[cnt] = r;
					dist[cnt] = dist[index]+1;
					visited[r] = true;
					cnt++;
				}
			}
		}
		index++;
	}
	index = 0;
	cnt = 1;
	dist[0] = 0;
	ar[0] = m-1;
	visited2[m-1] = true;
	while(index < cnt) {
		i = ar[index]/MAX;
		j = ar[index]%MAX;
		startX = max(0,i-K2);
		startY = max(0,j-K2);
		endX = min(n-1,i+K2);
		endY = min(m-1,j+K2);
		d22[i][j] = dist[index];
		for(int ii=startX;ii<=endX;ii++) {
			for(int jj=startY;jj<=endY;jj++) {
				r = (ii)*MAX+jj;
				if(isValid(ii,jj) && !visited2[r] && (abs(i-ii)+abs(j-jj) <= K2)) {
					ar[cnt] = r;
					dist[cnt] = dist[index]+1;
					visited2[r] = true;
					cnt++;
				}
			}
		}
		index++;
	}
	/*for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << d11[i][j] << " ";
		}
		cout << endl;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << d22[i][j] << " ";
		}
		cout << endl;
	}*/
	int ans = MAX*MAX;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(!arr[i][j] && (d11[i][j] != -1) && (d22[i][j] != -1)) {
					ans = min(ans,max(d11[i][j],d22[i][j]));
				}
			}
		}
		if(ans == MAX*MAX)
			cout << -1 << endl;
		else
			cout << ans << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		fun();
	}
	return 0;
}