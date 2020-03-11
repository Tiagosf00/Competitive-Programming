typedef pair<double, double> dd;

bool compare(dd a, dd b){
	return a.st < b.st;
}

double closest(dd v[], int n){
	sort(v, v+n, compare);
	double best = FLT_MAX;
	set<dd> box;
	box.insert(v[0]);
	int left = 0;
	rep2(i, 1, n){
		while(left < i && v[i].st-v[left].st > best){
			box.erase(v[left++]);
		}
		for(set<dd>::iterator it = box.lower_bound(mp(v[i].nd-best, v[i].st-best));it!=box.end() && v[i].nd + best >= it->nd;it++){
			best = min(best, sqrt(pow(v[i].nd - it->nd, 2.0) + pow(v[i].st - it->st, 2.0)));
		}
		box.insert(v[i]);
	}
	return best;
}