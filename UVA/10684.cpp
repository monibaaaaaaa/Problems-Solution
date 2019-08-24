/*
Author :: Moniba
Problem id :: UVA 10684
Problem name :: The jackpot
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (100000+5)
#define pii pair< int , int >
#define ll long long
int n, res;
int val[ MAX ], dp[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while( cin >> n , n != 0 ){
        repp(i, 1, n )
            cin >> val[ i ];

        res = 0;
        memset( dp , 0, sizeof dp );

        repp(i, 1, n ){
            dp[ i ] = max( dp[ i - 1 ] + val[ i ] , val[ i ] );
            res = max( res, dp[ i ]);
        }
        if( res ){
            cout << "The maximum winning streak is "<< res <<"."<<endl;
        }else cout << "Losing streak." << endl;
    }



   return 0;
}
