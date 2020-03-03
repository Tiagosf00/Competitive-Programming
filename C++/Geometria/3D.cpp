typedef ld cod;

bool eq(cod a, cod b){ return abs(a - b) <= EPS; }

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
