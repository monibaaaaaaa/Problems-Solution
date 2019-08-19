/*
Author :: Moniba
Problem id ::   UVA 10534
Problem name :: Wavio Sequence
*/

#include <bits/stdc++.h>

using namespace std ;

#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (10000+5)
#define pii pair< int , int >
#define ll long long
int n;
int gr[ MAX ], lt [ MAX ] , a [ MAX ], t[ MAX ];

int BS(int l , int r , int x ){
    int mid = (l + r)/2;
    if( x > t[ mid ])
        return BS( mid + 1 , r , x);
    if( mid == 1 || x > t[ mid - 1 ])
        return mid;
    return BS( l, mid - 1 , x);
}
void LIS(){
        int len = 1;
        t[ len ] = a[ 0 ] , gr[ 0 ] = len;
        repp( i, 1 , n-1){
            if( a[ i ] > t[ len ] ){
                len++;
                t[ len ] = a[ i ];
                gr[ i ] = len ;
            }else{
                int idx = BS(1, len , a[ i ] );
                t[ idx ]= a[ i ];
                gr[ i ] = idx ;
            }
        }
}

void LDS(){
        int len = 1;
        t[ len ] = a[ n - 1 ] , lt[ n - 1 ] = len;
        repn( i, n - 2 , 0){
            if( a[ i ] > t[ len ] ){
                len++;
                t[ len ] = a[ i ];
                lt[ i ] = len ;
            }else{
                int idx = BS(1, len , a[ i ] );
                t[ idx ]= a[ i ];
                lt[ i ] = idx ;
            }
        }
}
int main(){
    while(scanf("%d", &n ) == 1){
        repp( i , 0 , n-1 ){
          scanf("%d" , &a[i]);
        }
        // gr[ idx ] is the length of longest increasing sequence if a[ idx ] will be the last value
        // lt [ idx ] is the length of longest decreasing sequence if a[ idx ] will be the last value
        
        LIS();
        LDS();
        int mx = 1;
        repp(i , 0 , n - 1){
            mx = max( mx , 2*min( lt[ i ] , gr [ i ] ) -1 );
        }
        printf("%d\n", mx );
    }
    return 0;
}
