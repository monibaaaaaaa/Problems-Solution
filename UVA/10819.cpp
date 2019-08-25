/*
Author :: Moniba
Problem id :: UVA 10819
Problem name :: Trouble of 13-Dots
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (100+5)
#define pii pair< int , int >
#define ll long long

int m, n;
struct Dress{int p,f;};
Dress dress[ MAX ];
int dp[ MAX ][ 10000 + 200 + 5 ];

int knapsack( int idx, int price){
    if( price > m && m <= 1800 )
        return -1000;
    if( price > m + 200 )
        return -1000;
    if( idx == n && price > m && price <= 2000)
        return -1000;

    if( idx == n )
        return 0;

    if( dp[ idx ][ price ] != -1)
        return dp[ idx ][ price ];

    dp[ idx ][ price ] = max( knapsack( idx + 1, price),
                             knapsack( idx + 1, price + dress[ idx ].p ) + dress[ idx ].f );

    return dp[ idx ][ price ];
}

int main(){

    while( cin >> m >> n ){
         memset( dp , -1, sizeof dp);

         repp( i, 0, n - 1 )
            cin >> dress[ i ].p >> dress[ i ].f;

         cout<< max( 0, knapsack( 0, 0) ) << endl;

    }

    return 0;
}
