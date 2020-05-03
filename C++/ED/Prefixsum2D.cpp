ll find_sum(vector<vi> &mat, int a, int b, int c, int d){
	// superior-esq(c,d) (a,b)inferior-dir
    return mat[a][b]-mat[a][d-1]-mat[c-1][b]+mat[c-1][d-1];
}

int main(){

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];

}