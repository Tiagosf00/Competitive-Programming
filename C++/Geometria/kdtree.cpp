bool on_x(const point& a, const point& b) { return a.x < b.x; }
bool on_y(const point& a, const point& b) { return a.y < b.y; }
bool on_z(const point& a, const point& b) { return a.z < b.z; }

struct Node {
	point pt; // if this is a leaf, the single point in it
	cod x0 = LLINF, x1 = -LLINF, y0 = LLINF, y1 = -LLINF, z0 = LLINF, z1 = -LLINF; // bounds
	Node *first = 0, *second = 0;

	cod distance(const point &p) { // min squared distance to a point
		cod x = (p.x < x0 ? x0 : p.x > x1 ? x1 : p.x);
		cod y = (p.y < y0 ? y0 : p.y > y1 ? y1 : p.y);
		cod z = (p.z < z0 ? z0 : p.z > z1 ? z1 : p.z);
		return norm(point(x,y,z) - p);
	}

	Node(vp&& p) : pt(p[0]) {
		for (point pi : p) {
			x0 = min(x0, pi.x); x1 = max(x1, pi.x);
			y0 = min(y0, pi.y); y1 = max(y1, pi.y);
			z0 = min(z0, pi.z); z1 = max(z1, pi.z);
		}
		if (p.size() > 1) {
			auto cmp = (x1-x0 >= y1-y0 and x1-x0 >= z1-z0 ? on_x : (y1-y0 >= z1-z0 ? on_y:on_z));
			sort(p.begin(), p.end(), cmp);
			// divide by taking half the array for each child (not
			// best performance with many duplicates in the middle)
			int half = p.size() / 2;
			first = new Node({p.begin(), p.begin() + half});
			second = new Node({p.begin() + half, p.end()});
		}
	}
};

struct KDTree {
	Node* root;
	KDTree(const vp& p) : root(new Node({p.begin(), p.end()})) {}

	pair<cod, point> search(Node *node, const point& p) {
		if (!node->first) {
			// uncomment if we should not find the point itself:
			if (p == node->pt) return {LLINF, point()};
			return make_pair(norm(p - node->pt), node->pt);
		}

		Node *f = node->first, *s = node->second;
		cod bfirst = f->distance(p), bsec = s->distance(p);
		if (bfirst > bsec) swap(bsec, bfirst), swap(f, s);

		auto best = search(f, p);
		if (bsec < best.first)
			best = min(best, search(s, p));
		return best;
	}

	// find nearest point to a point, and its squared distance
	// (requires an arbitrary operator< for Point)
	pair<cod, point> nearest(const point& p) {
		return search(root, p);
	}
};
