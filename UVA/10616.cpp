/*
Author :: Moniba
Problem id :: UVA 10616
Problem name :: Divisible Group Sums
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (200+5)
#define pii pair< int , int >
#define ll long long

int N, Q, cas = 1;
ll val[ MAX ], dp[ MAX ][ MAX ][ 20 + 5 ];
int M ,D;

ll knapsack( int idx, int num, int sum ){
    if( num == M && sum == 0)
        return 1;
    if( idx == N || num == M )
        return 0;
    if( dp[ idx ][ num ][ sum ] != -1)
        return dp[ idx ][ num ][ sum ];

    ll res = knapsack( idx + 1 , num + 1 , (D + sum + val[ idx ] % D ) %D ) + knapsack( idx + 1 , num, sum) ;
    dp[ idx ][ num ][ sum ] = res;
    return res;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    while( cin >> N >> Q,!(N == 0 && Q == 0)){

        repp(i, 0, N - 1){
            cin >> val[ i ];
        }

        cout << "SET " << cas++ <<":"<< endl;
        repp( i, 1, Q ){
            cin >> D >> M;
            memset( dp, -1, sizeof dp);
            cout << "QUERY " << i <<": "<<knapsack( 0, 0, 0)<<endl;
        }

    }

    return 0;
}


