ll bestRectangle(vector<int> hist){
    int n = hist.size();
    stack<ll> s;
    s.push(-1);
    ll ans = hist[0];
    vector<ll> left_smaller(n, -1), right_smaller(n, n);
    for(int i=0;i<n;i++){
        while(!s.empty() and s.top()!=-1 and hist[s.top()]>hist[i]){
            right_smaller[s.top()] = i;
            s.pop();
        }
        if(i>0 and hist[i]==hist[i-1])
            left_smaller[i] = left_smaller[i-1];
        else
            left_smaller[i] = s.top();
        s.push(i);
    }

    for(int j=0;j<n;j++){
        ll area = hist[j]*(right_smaller[j]-left_smaller[j]-1);
        ans = max(ans, area);
    }
    return ans;
}