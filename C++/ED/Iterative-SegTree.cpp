// Segment Tree Iterativa - Range maximum query

#define N 100010

struct Segtree{
	int t[2*N]={0};

	void build(){
		for(int i=N-1; i>0; i--)
			t[i]=max(t[i<<1], t[i<<1|1]);
	}

	int query(int l, int r){
		int ans=0;
		for(i+=N, r+=N; l<r; l>>=1, r>>=1)
		{
			if(l&1)
				ans=max(ans, t[l++]);
			if(r&1)
				ans=max(ans, t[--r]);
		}

		return ans;
	}

	void update(int p, int value){
		for(t[p+=n]=value; p>1; p>>=1)
			t[p>>1]=max(t[p], t[p^1]);
	}

};

int main()
{
	Segtree st;

	for(int i=0;i<n;i++){
		cin >> aux;
		st.t[N+i]=aux; //Leaves are stored in continuous nodes with indices starting with N
	}

	st.build();
	x = st.query(inicio, fim);
	st.update(ind, value);

}