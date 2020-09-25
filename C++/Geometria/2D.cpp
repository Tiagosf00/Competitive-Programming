// typedef int cod;
// bool eq(cod a, cod b){ return (a==b); }

#define vp vector<point>
typedef ld cod;
bool eq(cod a, cod b){ return fabsl(a - b) <= EPS; }

struct point{
    cod x, y;
    int id;
    point(cod x=0, cod y=0): x(x), y(y){}


    point operator+(const point &o) const{
        return {x+o.x, y+o.y};
    }
    point operator-(const point &o) const{
        return {x-o.x, y-o.y};
    }
    point operator*(cod t) const{
        return {x*t, y*t};
    }
    point operator/(cod t) const{
        return {x/t, y/t};
    }
    cod operator*(const point &o) const{ // dot
        return x * o.x + y * o.y;
    }
    cod operator^(const point &o) const{ // cross
        return x * o.y - y * o.x;
    }
    bool operator<(const point &o) const{
        if(!eq(x, o.x)) return x < o.x;
        return y < o.y;
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y);
    }

};

ld norm(point a){ // Modulo
    return sqrt(a*a);
}
bool nulo(point a){
    return (eq(a.x, 0) and eq(a.y, 0));
}
ld proj(point a, point b){ // a sobre b
    return a*b/norm(b);
}
ld angle(point a, point b){ // em radianos
    ld ang = a*b / norm(a) / norm(b);
    return acos(max(min(ang, (ld)1), (ld)-1));
}
ld angle_vec(point v){
    // return 180/PI*atan2(v.x, v.y);
    return atan2(v.x, v.y);
}
int ccw(point a, point b, point e){ //-1=dir; 0=collinear; 1=esq;
    cod tmp = (b-a)^(e-a); // from a to b
    return (tmp > EPS) - (tmp < -EPS);
}
point rotccw(point p, ld a){
    // a = PI*a/180; // graus
    return point((p.x*cos(a)-p.y*sin(a)), (p.y*cos(a)+p.x*sin(a)));
}
ld order_angle(point a, point b){ // from a to b ccw (a in front of b)
    ld aux = angle(a,b)*180/PI;
    return ((a^b)<=0 ? aux:360-aux);
}
bool collinear(point a, point b, point c){ 
    return eq((a-c)^(b-c), 0);
}

point rot90cw(point a) { return point(a.y, -a.x); };
point rot90ccw(point a) { return point(-a.y, a.x); };

ld area(vp &p){ // (points sorted)
    ld ret = 0;
    for(int i=2;i<(int)p.size();i++)
        ret += (p[i]-p[0])^(p[i-1]-p[0]);
    return fabsl(ret/2);
}

point center(vp A){
    point centerA = point();
    int len = A.size();
    for(int i=0;i<len;i++)
        centerA=centerA+A[i];
    return centerA/len;
}


point forca_mod(point p, ld m){
    ld cm = norm(p);
    if(cm<EPS) return point();
    return point(p.x*m/cm,p.y*m/cm);
}


////////////
//  Line  //
////////////

struct line{
    point p1, p2;
    cod a, b, c; // ax+by+c = 0;
    line(point p1=0, point p2=0): p1(p1), p2(p2){
        a = p1.y-p2.y;
        b = p2.x-p1.x;
        c = -(a*p1.x + b*p1.y);
    }
    line(cod a=0, cod b=0, cod c=0): a(a), b(b), c(c){}

    cod eval(point p){
        return a*p.x+b*p.y+c;
    }
    bool inside(point p){
        return eq(eval(p), 0);
    }
    point normal(){
        return point(a, b);
    }

    bool inside_seg(point p){
        return (inside(p) and
                min(p1.x, p2.x)<=p.x and p.x<=max(p1.x, p2.x) and
                min(p1.y, p2.y)<=p.y and p.y<=max(p1.y, p2.y));
    }

};

point inter(line l1, line l2){
    ld det = l1.a*l2.b - l1.b*l2.a;
    if(det==0) return point(INF, INF);
    ld x = (l1.b*l2.c - l1.c*l2.b)/det;
    ld y = (l1.c*l2.a - l1.a*l2.c)/det;
    return point(x, y);
}

cod dseg(point p, point a, point b){ // point - seg
    if(((p-a)*(b-a)) < EPS) return norm(p-a);
    if(((p-b)*(a-b)) < EPS) return norm(p-b);
    return fabs((p-a)^(b-a))/norm(b-a);
}

cod dline(point p, line l){ // point - line
    return fabs(l.eval(p))/sqrt(l.a*l.a + l.b*l.b);
}

line mediatrix(point a, point b){
    point d = (b-a)*2;
    return line(d.x, d.y, a*a - b*b);
}

line perpendicular(line l, point p){ // passes through p
    return line(l.b, -l.a, -l.b*p.x + l.a*p.y);
}


////////////
// Circle //
////////////

struct circle{
    point c; cod r;
    circle() : c(0, 0), r(0){}
    circle(const point o) : c(o), r(0){}
    circle(const point a, const point b){
        c = (a+b)/2;
        r = norm(a-c);
    }
    circle(const point a, const point b, const point cc){
        c = inter(mediatrix(a, b), mediatrix(b, cc));
        r = norm(a-c);
    }
    bool inside(const point &a) const{
        return norm(a - c) <= r;
    }
};

// minimum circle cover O(n) amortizado
circle min_circle_cover(vector<point> v){
    random_shuffle(v.begin(), v.end());
    circle ans;
    int n = v.size();
    for(int i=0;i<n;i++) if(!ans.inside(v[i])){
        ans = circle(v[i]);
        for(int j=0;j<i;j++) if(!ans.inside(v[j])){
            ans = circle(v[i], v[j]);
            for(int k=0;k<j;k++) if(!ans.inside(v[k])){
                ans = circle(v[i], v[j], v[k]);
            }
        }
    }
    return ans;
}