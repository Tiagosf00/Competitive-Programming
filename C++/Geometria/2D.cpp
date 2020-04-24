// typedef int cod;
// bool eq(cod a, cod b){ return (a==b); }

typedef ld cod;
bool eq(cod a, cod b){ return fabsl(a - b) <= EPS; }

struct point
{
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
    bool operator<(const point &o) const{
        if(!eq(x, o.x)) return x < o.x;
        return y < o.y;
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y);
    }

};

struct line
{
    point p1, p2;
    line(point p1=0, point p2=0): p1(p1), p2(p2){}

    cod a = p1.y-p2.y;
    cod b = p2.x-p1.x;
    cod c = p2.x*p1.y - p2.y*p1.x;
    // ax+by+c = 0;
    // a=y1-y2;
    // b=x2-x1;
    // c=x2*y1-y2*x1;

};


// Produto Escalar
cod dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}
// Produto Vetorial
cod cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

ld norm(point a){ // Modulo
    return sqrt(dot(a, a));
}
ld proj(point a, point b){ // a sobre b
    return dot(a, b)/norm(b);
}
ld max(ld a, ld b){ return (a>b ? a:b); }
ld min(ld a, ld b){ return (a<b ? a:b); }
ld angle(point a, point b){ // em radianos
    ld ang = dot(a, b) / norm(a) / norm(b);
    return acos(max(min(ang, 1), -1));
}
int ccw(point &a, point &b, point &e) //-1=dir; 0=collinear; 1=esq;
{
    cod tmp = cross(b-a, e-a); // from a to b
    return (tmp > EPS) - (tmp < -EPS);
}
ld order_angle(point a, point b) // from a to b ccw (a in front of b)
{
    ld aux = angle(a,b)*180/PI;
    return (cross(a,b)<=0 ? aux:360-aux);
}

bool collinear(point a, point b, point c){ 
    return eq(cross(a-c, b-c), 0);
}

point rotccw(point p, ld a) // em radianos
{
    //a = a*acos(0.0)/90; // graus
    return point((p.x*cos(a)-p.y*sin(a)), (p.y*cos(a)+p.x*sin(a)));
}

point rot90cw(point a) { return {a.y, -a.x} };
point rot90ccw(point a) { return {-a.y, a.x} };

// Area de um poligono (pontos ordenados por adjacencia)
ld area(vector <point> &p){
    ld ret = 0;
    for(int i=2;i<(int)p.size();i++)
        ret += cross(p[i] - p[0], p[i-1] - p[0]);
    return fabsl(ret/2);
}

// Dist entre ponto e segmento de reta
cod distr(point p, point a, point b){
    point u,v,w,z;
    u = b-a;
    v = p-a;
    w = p-b;
    z = a-x;
 
    if(dot(u,w) > 0)
        return norm(p-b);
    if(dot(z,v) > 0)
        return norm(p-a);
    return fabs(cross(u,v))/norm(a-b);
}
