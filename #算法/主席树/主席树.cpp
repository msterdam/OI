#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
const int NN = 120000;
struct node {
	int l , r , s;
	node *ll , *rr;
} pool[NN*2+NN*20] , *t[NN];
int top;
int n , q;
int a[NN];
void buildtree ( node *id , int l , int r ) {
	id -> l = l; id -> r = r;
	if ( l == r ) {
		id -> s = a[l];
		return ;
	}
	int mid = (l+r)/2;
	id -> ll = &pool[++top]; id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid ); buildtree ( id -> rr , mid + 1 , r );
	id -> s = id -> ll -> s + id -> rr -> s;
}
void add ( node *id , node *idd , int l , int x ) {
	id -> l = idd -> l; id -> r = idd -> r;
	if ( id -> l == id -> r ) {
		id -> s = x;
		return ;
	}
	int mid = (id->l+id->r)/2;
	if ( l <= mid ) {
		id -> rr = idd -> rr;
		id -> ll = &pool[++top];
		add ( id -> ll , idd -> ll , l , x );
	}
	else {
		id -> ll = idd -> ll;
		id -> rr = &pool[++top];
		add ( id -> rr , idd -> rr , l , x );
	}
	id -> s = id -> ll -> s + id -> rr -> s;
}
int query ( node *id , int l , int r ) {
	if ( id -> l == l && id -> r == r ) return id -> s;
	int mid = (id->l+id->r)/2;
	if ( r <= mid ) return query ( id -> ll , l , r );
	else {
		if ( l > mid ) return query ( id -> rr , l , r );
		else {
			return query ( id -> ll , l , mid ) + query ( id -> rr , mid + 1 , r );
		}
	}
}
void work () {
	int i , tim , op , l , r;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] );
	}
	t[0] = &pool[++top];
	buildtree ( t[0] , 1 , n );
	scanf ( "%d" , &q );
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d%d%d" , &op , &tim , &l , &r );
		if ( op == 1 ) {
			t[i] = &pool[++top];
			add ( t[i] , t[tim] , l , r );
		}
		else {
			printf ( "%d\n" , query ( t[tim] , l , r ) );
			t[i] = t[tim];
		}
	}
}
int main () {
	work ();
	return 0;
}
