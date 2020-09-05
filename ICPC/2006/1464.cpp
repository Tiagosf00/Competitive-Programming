#include <bits/stdc++.h>
using namespace std;

bitset<2010> used;

struct Point{
	int x, y, idx;
};

bool finished(int n){
	for(int i=0;i<n;i++){
		if(!used[i]){
			return false;
		}
	}
	return true;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - 
			  (q.x - p.x) * (r.y - q.y);

	if(val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

bool convexHull(Point opoints[], int n){

	vector<Point> points;
	for(int i=0;i<n;i++){
		if(!used[i]){
			points.push_back(opoints[i]);
		}
	}
	vector<Point> hull;
	int l=0;
	n = points.size();
	if(n < 3){
		return false;
	}
	for(int i=0;i<n;i++){
		if(points[i].x < points[l].x){
			l = i;
		}
	}

	int p = l, q;
	do
	{
		used.set(points[p].idx);
		q = (p+1)%n;
		for(int i=0;i<n;i++){
			if(orientation(points[p], points[i], points[q]) == 2){
				q = i;
			}
		}
		p = q;
	}while(p != l);
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	while(cin >> N && N){
		Point points[N];
		for(int i=0;i<N;i++){
			cin >> points[i].x >> points[i].y;
			points[i].idx = i;
		}
		int hulls = 0;
		while(convexHull(points, N)){
			hulls++;
		}

		if(hulls%2 == 0){
			cout << "Do not take this onion to the lab!" << endl;
		}else{
			cout << "Take this onion to the lab!" << endl;
		}

		used.reset();
	}
	return 0;
}