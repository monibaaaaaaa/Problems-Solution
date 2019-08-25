/*
Author :: Moniba
Problem id :: UVA 11003
Problem name :: Boxes
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (1000+5)
#define pii pair< int , int >
#define ll long long

int N;
struct Box{ int w, l; };
Box box[ MAX ];
int dp[ MAX ][ 3000 + 5 ];

int knapsack( int idx, int load ){
    if( idx == 0)
        return 0;
    
    if( load > box[ idx ].l )
        return knapsack( idx - 1, load );

    if( dp[ idx ][ load ] != -1 )
        return dp[ idx ][ load ];

    dp[ idx ][ load ] = max( knapsack( idx - 1 , load ),
                             knapsack( idx - 1,  load + box[ idx ].w ) + 1 );

    return dp[ idx ][ load ];
}
int main(){
    
    while( cin >> N , N != 0){
        memset( dp, -1, sizeof dp);

        repp( i, 1, N )
            cin >> box[ i ].w >> box[ i ].l;

        cout << knapsack( N, 0) << endl;

    }

    return 0;
}
