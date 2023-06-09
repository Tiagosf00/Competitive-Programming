// Comparator funcion for sorting points by angle

int ret[2][2] = {{3, 2},{4, 1}}; 
inline int quad(point p) { 
    return ret[p.x >= 0][p.y >= 0];  
}

bool comp(point a, point b) { // ccw
    int qa = quad(a), qb = quad(b);
    return (qa == qb ? (a ^ b) > 0 : qa < qb);
}

// only vectors in range [x+0, x+180)
bool comp(point a, point b){
    return (a ^ b) > 0; // ccw
    // return (a ^ b) < 0; // cw
}
