vector<int> a = {1, 2, 3};
int n = a.size();
do{ 
    display(a, n);// 1,2,3; 1,3,2; 2,1,3; 2,3,1; 3,1,2; 3,2,1; 
}while(next_permutation(a.begin(), a.begin() + n)); 