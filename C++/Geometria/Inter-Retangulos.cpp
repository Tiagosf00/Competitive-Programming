typedef struct
{
    int x, y;
} Point;

bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
    if (l1.x>r2.x or l2.x>r1.x or l1.y<r2.y or l2.y<r1.y)
        return false;
    return true;
}