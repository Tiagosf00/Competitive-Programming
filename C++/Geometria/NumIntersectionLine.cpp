int main()
{
    int lim = 1e6;
    Segtree st(lim+100);
    int n, m, y, x, l, r;
    cin >> n >> m;

    int open=-1, close=INF; // open -> check -> close
    vector< pair<int, pii> > sweep;

    ll ans = 0;
    for(int i=0;i<n;i++){ // horizontal
        cin >> y >> l >> r;
        sweep.pb({l, {open, y}});
        sweep.pb({r, {close, y}});
    }
    for(int i=0;i<m;i++){ // vertical
        cin >> x >> l >> r;
        sweep.pb({x, {l, r}});
    }
    sort(sweep.begin(), sweep.end());

    // set<int> on;
    for(auto s: sweep){
        if(s.ss.ff==open){
            st.update(s.ss.ss, 1);
            // on.insert(s.ss.ss);
        }
        else if(s.ss.ff==close){
            st.update(s.ss.ss, -1);
            // on.erase(s.ss.ss);
        }
        else{
            ans += st.query(s.ss.ff, s.ss.ss);
            // auto it1 = on.lower_bound(s.ss.ff);
            // auto it2 = on.upper_bound(s.ss.ss);
            // for(auto it = it1; it!=it2; it++){
            //     intersection -> (s.ff, it);
            // }
        }
    }

    cout << ans << endl;

    
    return 0;
}