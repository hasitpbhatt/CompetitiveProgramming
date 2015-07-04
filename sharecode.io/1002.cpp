// https://sharecode.io/section/problemset/problem/1002

#include<iostream>
#include<cmath>
using namespace std;

// distance
double dist(int x1,int x2,int y1,int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	int x,y,n, coordx[151],coordy[151], tmpx, tmpy, mx = 0;
	double r;
	while(cin >> x >> y >> r) {
		mx = 0;
		if(r < 0)
			break;
		int j = 0;
		cin >> n;
		for(int i=0;i<n;i++) {
			cin >> tmpx >> tmpy;
			if( dist(x,tmpx,y,tmpy) <= r ){
				coordx[j] = tmpx;
				coordy[j] = tmpy;
				j++;
			}
		}
		for(int i=0;i<j;i++) {
			double m = 0;
			int count1 = 1, count2 = 1;
			bool flag = false;
			if(x != coordx[i]){
			m = double(y - coordy[i])/(x - coordx[i]);
			flag = true;
			}
			if(flag){
				double c = coordy[i] - m * coordx[i];
				for(int k=0; k< j ; k++){
					if(k == i)
						continue;
					if(coordy[k]-m*coordx[k]-c <= 0)
						count1++;
					if(coordy[k]-m*coordx[k]-c >= 0)
						count2++;
				}
				mx = max(mx, max(count1, count2));
			}			
			else {
				for(int k=0; k< j ; k++){
					if(k == i)
						continue;
					if(coordx[k] <= x)
						count1++;
					if(coordx[k] >= x)
						count2++;
				}
				mx = max(mx, max(count1, count2));
			}
		}
		cout << mx << endl;
	}
	return 0;
}