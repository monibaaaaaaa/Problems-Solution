/*
Author :: Moniba
Problem id ::   UVA 1196
Problem name :: Tiling Up Blocks
*/
#include <bits/stdc++.h>

using namespace std ;

#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (10000+5)
#define pii pair< int , int >
#define ll long long

pii a[ MAX ];
int t [ MAX ], n;

int comp ( pii a , pii b ){
    if (a.first == b.first)
        return a.second < b.second ;
    return a.first < b.first;
}

int BS( int l , int r , int i ){
    int mid = ( l + r ) / 2 ;
    if( a[ i ].second >= a[ t[ mid ] ].second )
        return BS(mid + 1 , r , i);
    if( mid == 1 || a[ i ].second >= a[ t[ mid - 1 ] ].second )
        return mid;
    return BS( l , mid - 1 , i );

}

int LIS(){
    int len = 1;
    t[ 1 ] = 0;
    repp( i , 1 , n - 1 ){
        if( a[ i ].second >= a[ t[ len ] ].second ){
            len++;
            t[ len ] = i;
        }else{
            int idx = BS(1, len, i);
            t[ idx ] = i ;
        }
    }
    return len;
}

int main(){
    while( cin >> n , n!=0 ){
        repp(i , 0 , n - 1 ){
            cin >> a[ i ].first >> a[ i ].second;
        }
        sort( a , a + n , comp );
        cout << LIS() << endl;
    }
    cout << "*" <<endl;
   return 0;
}
