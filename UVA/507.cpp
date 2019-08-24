/*
Author :: Moniba
Problem id :: UVA 507
Problem name :: Jill Rides Again
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (20000+5)
#define pii pair< int , int >
#define ll long long

int q, n, res, idx;
int val[ MAX ], dp[ MAX ], start[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;
    repp(cas, 1, q){

        cin >> n ;
        repp(i, 1, n - 1 )
            cin >> val [ i ];

        res = 0, start[ 0 ] = 1;
        memset( dp , 0, sizeof dp );

        repp(i, 1, n - 1 ){
            if( dp[ i - 1 ] + val[ i ] >= val[ i ] ){
                start[ i ] = start[ i - 1 ];
            }else start[ i ] = i;

            dp[ i ] = max( dp[ i - 1 ] + val[ i ] , val[ i ] );

            if( res < dp [ i ] || ( res == dp[ i ] && i - start[ i ] > idx - start[ idx ])){
                res = dp[ i ];
                idx = i;
            }
        }
        if( res ){
            cout << "The nicest part of route " << cas <<" is between stops "<< start[ idx ]  <<" and "<<idx + 1 <<endl;
        }else cout << "Route " << cas << " has no nice parts" << endl;
    }



   return 0;
}
