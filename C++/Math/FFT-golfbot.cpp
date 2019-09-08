#include <bits/stdc++.h>

using namespace std;

const int N = (1<<19);
const double two_pi = 4 * acos(0);

struct cpx
{
	cpx(){}
	cpx(double aa): a(aa){}
	cpx(double aa,double bb):a(aa),b(bb){}
	double a;
	double b;
	double modsq(void) const
	{
		return a*a+b*b;
	}
	cpx bar(void) const
	{
		return cpx(a,-b);
	}
};

cpx b[N+100];
cpx c[N+100];
cpx B[N+100];
cpx C[N+100];
int a[N+100];
int x[N+100];
double coss[N+100], sins[N+100];
int n,m,p;

cpx operator +(cpx a,cpx b)
{
	return cpx(a.a+b.a,a.b+b.b);
}

cpx operator *(cpx a,cpx b)
{
	return cpx(a.a*b.a-a.b*b.b,a.a*b.b+a.b*b.a);
}

cpx operator /(cpx a,cpx b)
{
	cpx r = a*b.bar();
	return cpx(r.a/b.modsq(),r.b/b.modsq());
}

cpx EXP(int i,int dir)
{
	return cpx(coss[i],sins[i]*dir);
}

void FFT(cpx *in,cpx *out,int step,int size,int dir)
{
	if(size<1) return;
	if(size==1)
	{
		out[0]=in[0];
		return;
	}
	FFT(in,out,step*2,size/2,dir);
	FFT(in+step,out+size/2,step*2,size/2,dir);
	for(int i=0;i<size/2;++i)
	{
		cpx even=out[i];
		cpx odd=out[i+size/2];
		out[i] = even+EXP(i*step,dir)*odd;
		out[i+size/2]=even+EXP((i+size/2)*step,dir)*odd;
	}
}

int main()
{
	for(int i=0;i<=N;++i)
	{
		coss[i]=cos(two_pi*i/N);
		sins[i]=sin(two_pi*i/N);
	}
	while(cin >> n) // Numero de tacadas possiveis
	{
		fill(x,x+N+100,0);
		fill(a,a+N+100,0);
		for(int i=0;i<n;++i)
		{
			cin >> p; // Distancia das tacadas
			x[p]=1;
		}
		for(int i=0;i<N+100;++i)
		{
			b[i]=cpx(x[i],0);
		}
		cin >> m; // Querys
		for(int i=0;i<m;++i)
		{
			cin >> a[i]; // Distancia da query
		}
		FFT(b,B,1,N,1);
		for(int i=0;i<N;++i)
			C[i]=B[i]*B[i];
		FFT(C,c,1,N,-1);
		for(int i=0;i<N;++i)
			c[i]=c[i]/N;
		int cnt=0; 
		for(int i=0;i<m;++i)
			if(c[a[i]].a>0.5 || x[a[i]])
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}