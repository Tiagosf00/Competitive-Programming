// Partition Problem DP O(n2)
bool findPartition(vi &arr){
    int sum = 0;
    int n = arr.size();
      
    for(int i=0;i<n;i++)
        sum += arr[i];
      
    if(sum&1) return false;
      
    bool part[sum/2+1][n+1];
      
    for(int i=0;i<=n;i++)
        part[0][i] = true;

    for(int i=1;i<=sum/2;i++)  
        part[i][0] = false;  
      
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            part[i][j] = part[i][j-1];
            if(i >= arr[j-1])
                part[i][j] |= part[i - arr[j-1]][j-1];
        }
    }
    return part[sum / 2][n];
}