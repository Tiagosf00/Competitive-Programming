typedef struct Point
{
    double x, y;
    Point(int _x=0, int _y=0)
    {
        x=_x;y=_y;
    }

    void show()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

} point;

typedef struct Line
{
    point fp, sp;
    Line(point _fp=0, point _sp=0)
    {
        fp=_fp;sp=_sp;
    }

} line;

point sum(point A, point B)
{
    return point(A.x+B.x, A.y+B.y);
}

point sub(point A, point B)
{
    return point(A.x-B.x, A.y-B.y);
}

point neg(point A)
{
    return point(-A.x, -A.y);
}

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
    point c = sub(a, b);
    return sqrt(c.x*c.x + c.y*c.y);
}

// Dist entre ponto e reta
double dist(point a, line b){
    double crs = cross(point(sub(a, b.fp)), point(sub(b.sp, b.fp)));
    return abs(crs/dist(b.fp, b.sp));
}

// Area de um poligono (pontos ordenados por adjacencia)
double area(vector <point> p){
  double ret = 0;
  for(int i=2;i<(int)p.size();i++)
    ret += cross(sub(p[i], p[0]), sub(p[i-1], p[0]))/2;
  return abs(ret);
}