point center(vector<point> A){
    point centerA = point();
    for(int i=0;i<(int)A.size();i++)
        centerA=centerA+A[i];
    return centerA/(int)A.size();
}
