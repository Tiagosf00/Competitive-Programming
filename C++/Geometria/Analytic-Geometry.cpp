struct point
{
    double x, y;
    point(double _x=0, double _y=0){
        x=_x;y=_y;
    }

    void show(){
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    point operator+(const point &o) const{
        return {x + o.x, y + o.y};
    }
    point operator-(const point &o) const{
        return {x - o.x, y - o.y};
    }
    bool operator==(const point &o) const{
        return (x == o.x and y == o.y);
    }

};

struct line
{
    point fp, sp;
    line(point _fp=0, point _sp=0){
        fp=_fp;sp=_sp;
    }

};

// Produto Escalar
double dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}

// Produto Vetorial
double cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

// Dist entre dois pontos
double dist(point a, point b){
    point c = a - b;
    return sqrt(c.x*c.x + c.y*c.y);
}

// Colinearidade entre 3 pontos
bool collinear(point a, point b, point c){ 
    return ((c.y - b.y)*(b.x - a.x)==(b.y - a.y)*(c.x-b.x));
} 

// Dist entre ponto e reta
double distr(point a, line b){
    double crs = cross(point(a - b.fp), point(b.sp - b.fp));
    return abs(crs/dist(b.fp, b.sp));
}

// Area de um poligono (pontos ordenados por adjacencia)
double area(vector <point> p){
  double ret = 0;
  for(int i=2;i<(int)p.size();i++)
    ret += cross(p[i] - p[0], p[i-1] - p[0])/2;
  return abs(ret);
}
// Concavo ou Convexo
double ccw(point a, point b, point c){
  double ret = cross(b - a, c - b);
  return ret < 0;
}