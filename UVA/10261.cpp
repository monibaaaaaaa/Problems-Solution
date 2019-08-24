/*
Author :: Moniba
Problem id :: UVA 10261
Problem name :: Ferry Loading
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (10000+5)
#define pii pair< int , int >
#define ll long long

int q, n,ferry;
int val[ 200 + 5 ], sum[ 200 + 5], side[ 200 + 5];
int dp[ 200 + 5][ MAX ] ;

int knapsack( int idx, int len ){

    if ( idx == n + 1)
        return 0;
    if( dp[ idx ][ len ] != -1)
        return dp[ idx ][ len ];

    int res = 0;
    if( sum[ idx ] - len <= ferry )
        res = knapsack( idx + 1, len ) + 1;

    if( val[ idx ] + len <= ferry ){
        int ans = knapsack( idx + 1, len + val[ idx ]) + 1;
        res = max( res, ans);
    }
    dp[ idx ][ len ] = res;
    return res;
}

// car finds out the idx-th car is directed to port or starboard.
void car(int idx, int len ){
    if( idx == n + 1 || dp[ idx ][ len ] == 0)
        return;

    if( sum[ idx ] - len <= ferry && dp[ idx ][ len ] == dp[ idx + 1 ][ len ] + 1){
        side[ idx ] = 0;
        car( idx + 1, len);
    }else{
        side[ idx ] = 1;
        car( idx + 1, len + val[ idx ]);
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;
    while( q-- ){

        n = 1;
        memset(sum , 0 , sizeof sum);
        memset(side, -1 , sizeof side);
        memset(dp , -1, sizeof dp);

        cin >> ferry;

        //convert to cm
        ferry *= 100;

        while( cin >> val[ n ], val[ n ] > 0){
            sum[ n ] = sum[ n - 1] + val[ n ];
            n++;
            //no more than 200 cars (100 directed to port,100 directed to starboard ) can be loaded!!
            if(n == 202)
                n--;
        }
        n--;
        cout << knapsack(1, 0)<<endl;
        car(1, 0);
        repp(i , 1, n)
            if( side[ i ] == -1)
                break;
            else if ( side[ i ])
                cout<< "port" << endl;
            else cout<< "starboard" << endl;

        if( q )
            cout << endl ;

    }

   return 0;
}
