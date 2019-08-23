/*
Author :: Moniba
Problem id :: UVA 10664
Problem name :: Luggage
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (200+5)
#define pii pair< int , int >
#define ll long long
int q, n, wt , sum;
int scase[ MAX ];
int dp [ MAX ][ MAX ];
string line;
int knapsack( int idx, int we ){
    if( idx == n && we == 0 )
        return 1;
    if( idx == n)
        return 0;
    if( dp[ idx ][ we ] != -1)
        return dp[ idx ][ we ];

    dp[ idx ][ we ] = knapsack( idx + 1, we);
    if( we >= scase[ idx ])
        dp[ idx ][ we ]=max( dp[ idx ][ we ], knapsack(idx + 1, we - scase[ idx ] ) );
        
    return dp[ idx ][ we ];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;
    cin.ignore();
    while( q-- ){
        sum = 0;
        memset( dp , -1 , sizeof dp );
        
        getline(cin, line );
        stringstream ss(line);
        n = 0;
        while( ss >> wt ){
            scase[ n++ ] = wt ;
            sum += wt ;
        }
        
        if ( sum % 2 ){
            cout << "NO" << endl;
            continue;
        }
        
        int can = knapsack(0 , sum/2);
        
        if( can ) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
   return 0;
}
