// typedef int cod;
// bool eq(cod a, cod b){ return (a==b); }

#define vp vector<point>
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
    cod operator*(const point &o) const{ // dot
        return x*o.x + y*o.y + z*o.z;
    }
    point operator^(const point &o) const{ // cross
        return point(y*o.z - z*o.y,
                     z*o.x - x*o.z,
                     x*o.y - y*o.x);
    }
};

ld dist(point a, point b){
    return sqrt((a-b)*(a-b));
}
bool nulo(point a){
    return (eq(a.x, 0) and eq(a.y, 0) and eq(a.z, 0));
}

ld norm(point a){ // Modulo
    return sqrt(a*a);
}
ld proj(point a, point b){ // a sobre b
    return (a*b)/norm(b);
}
ld angle(point a, point b){ // em radianos
    return acos((a*b) / norm(a) / norm(b));
}

cod triple(point a, point b, point c){
    return dot(a, b^c); // Area do paralelepipedo
}


struct plane{
    point p1, p2, p3;
    plane(point p1=0, point p2=0, point p3=0): p1(p1), p2(p2), p3(p3){}

    point aux = (p1-p3)^(p2-p3);
    cod a = aux.x, b = aux.y, c = aux.z;
    cod d = -a*p1.x - b*p1.y - c*p1.z;
    // ax+by+cz+d = 0;
};

cod dist(plane pl, point p){
    return fabs(pl.a*p.x + pl.b*p.y + pl.c*p.z + pl.d) / sqrt(pl.a*pl.a + pl.b*pl.b + pl.c*pl.c);
}

point rotate(point v, point k, ld theta){
    // Rotaciona o vetor v theta graus em torno do eixo k
    // theta *= PI/180; // graus
    return rotated = (v*cos(theta)) +
                     ((k^v)*sin(theta)) +
                     (k*(k*v))*(1-cos(theta));
}