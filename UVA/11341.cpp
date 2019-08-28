/*
Author :: Moniba
Problem id :: UVA 11341
Problem name :: Term Strategy
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX ( 500 + 5 )
#define pii pair< int , int >
#define ll long long

int n, m, q;
int L[ 10 + 5 ][ 100 + 5], dp[ 10 + 5 ][ 100 + 5];

int f( int idx, int left ){

    if( left < 0 )
        return -2000;
    if( idx == n + 1 )
        return 0;
    if( dp[ idx ][ left ] != -2001 )
        return dp[ idx ][ left ];

    int res = -2000;
    repp( i, 1, m ){
        if( L[ idx ][ i ] < 5)
            continue;
        res = max( res, f( idx + 1 , left - i ) + L[ idx ][ i ]);
    }

    dp[ idx ][ left ] = res;
    return res;

}
int main(){

    scanf("%d", &q);
    while( q-- ){
    
        scanf("%d %d", &n, &m);
        repp( i, 0, n ){
            repp( j, 0, m ){
                dp[ i ][ j ] = -2001;
                if( i == 0 || j == 0 )
                    continue;
                scanf("%d", &L[ i ][ j ]);

            }
        }

        double res = f( 1 , m);
        if( res > 0 ){
            printf("Maximal possible average mark - %.2f.\n", (res/(double)n) + 1e-9 );
        }else printf("Peter, you shouldn't have played billiard that much.\n");

    }
    return 0;
}
