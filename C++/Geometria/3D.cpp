// typedef int cod;
// bool eq(cod a, cod b){ return (a==b); }

typedef ld cod;
bool eq(cod a, cod b){ return fabs(a - b) <= EPS; }

struct point
{
	cod x, y, z;
	point(cod x=0, cod y=0, cod z=0): x(x), y(y), z(z){}

	point operator+(const point &o) const{
        return {x+o.x, y+o.y, z+o.z};
    }
    point operator-(const point &o) const{
        return {x-o.x, y-o.y, z-o.z};
    }
    point operator*(cod t) const{
        return {x*t, y*t, z*t};
    }
    point operator/(cod t) const{
        return {x/t, y/t, z/t};
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y) and eq(z, o.z);
    }
};

// Produto Escalar
cod dot(point a, point b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Produto Vetorial
point cross(point a, point b){
    return point(a.y*b.z - a.z*b.y,
                   a.z*b.x - a.x*b.z,
                   a.x*b.y - a.y*b.x);
}

ld dist(point a, point b){
    return sqrt(dot(a-b, a-b));
}

ld abs(point a){ // Modulo
    return sqrt(dot(a, a));
}
ld proj(point a, point b){ // a sobre b
    return dot(a, b)/abs(b);
}
ld angle(point a, point b){ // em radianos
    return acos(dot(a, b) / abs(a) / abs(b));
}

cod triple(point a, point b, point c){
    return dot(a, cross(b, c)); // Area do paralelepipedo
}


struct plane{
    point p1, p2, p3;
    plane(point p1=0, point p2=0, point p3=0): p1(p1), p2(p2), p3(p3){}

    point aux = cross(p1-p3, p2-p3);
    cod a = aux.x, b = aux.y, c = aux.z;
    cod d = -a*p1.x - b*p1.y - c*p1.z;
    // ax+by+cz+d = 0;
};

cod dist(plane pl, point p){
    return fabs(pl.a*p.x + pl.b*p.y + pl.c*p.z + pl.d) / sqrt(pl.a*pl.a + pl.b*pl.b + pl.c*pl.c);
}