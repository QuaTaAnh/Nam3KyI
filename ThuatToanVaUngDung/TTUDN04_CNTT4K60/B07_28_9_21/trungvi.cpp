#include<bits/stdc++.h>
using namespace std;
#ifndef __pq__cpp__
#define __pq__cpp__
template <class T>
struct node
{
	T elem;			//du lieu
	int n;			//so node
	node *L,*R;		//con trai va con phai
	node(T x) {elem=x;n=1;L=R=0;}
};
template <class K,class CMP>
class pq    //priority_queue
{
	node<K> *T;
	CMP ss;
		void add(node<K> *&H,K x)
		{
			if(ss(H->elem,x)) swap(x,H->elem);
			H->n++;	
			if(!H->L) {H->L=new node<K>(x);}
			else if(!H->R) {H->R=new node<K>(x);}
			else add(H->L->n<H->R->n?H->L:H->R,x);
		}
		void remove(node<K> *&H)
		{
			if(!H->L) H=H->R;
			else if(!H->R) H=H->L;
			else if(ss(H->R->elem,H->L->elem)) {H->n--;H->elem=H->L->elem; remove(H->L);}
			else {H->n--; H->elem=H->R->elem; remove(H->R);}
		}
	public:
		pq() {T=0;}
		bool empty() {return !T;}
		int size() 	 {return T?T->n:0;}
		K top() 	 {return T->elem;}
		void push(K x){	if(!T) T=new node<K>(x);else add(T,x);}
		void pop(){remove(T);}
};
#endif
int main()
{
	pq<int,less<int> > L;
	pq<int,greater<int> > R;
	int n,x,u,v;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x; 
		i%2?L.push(x):R.push(x);
		if(i>1 && L.top()>R.top())
		{
			int u=L.top(); L.pop();
			int v=R.top(); R.pop();
			L.push(v);
			R.push(u);
		}
		cout<<L.top()<<" ";
	}
}

