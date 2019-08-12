/*
Author :: Moniba
Problem id :: UVA 10131
Problem name :: Is Bigger Smarter?
*/

#include <bits/stdc++.h>

using namespace std ;

#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (1000+5)
#define pii pair< int , int >

struct Elephant{
    int q,w,idx;
    iq(int _w = 0 , int _q = 0 , int _idx = 0 ){
        q = _q ;
        w = _w ;
        idx = _idx ;
    }
};

Elephant elephant[ MAX ] ;
int t[ MAX ] ;
int n = 0 ;
vector< int > ans;

bool comp ( iq a , iq b ){
    if( a.w < b.w )
        return true;
    if( a.w == b.w && a.q > b.q )
        return true;
    return false;
}

int LIS( int n ){
    int len = 0 , idx = 0;
    
    repp( i , 0 , n - 1 )
        t[ i ] = 1 ;
    
    repp(i , 1 , n -1 ){
        repp( j , 0 , i - 1){
            if( elephant[ i ].w > elephant [ j ].w && elephant[ i ].q < elephant [ j ].q )
                t[ i ] = max ( t [ i ] , t[ j ]+1 );
        }
        if( len < t [ i ]){
            len = t[ i ];
            idx = i;
        }
    }
    
    repp( i , 1 , len ){
        ans.pb( elephant[ idx ] .idx );
        repp( j , 0 , idx - 1 ){
            if( elephant[ idx ].w > elephant [ j ].w && elephant[ idx ].q < elephant [ j ].q && t [ idx ] == t [ j ] + 1 ){
                idx=j;
                break;
            }
        }
    }
    
    return len;


}
int main(){

    while( cin >> elephant[n].w >> elephant[ n ].q ){
        elephant[n].idx = n ;
        n++;
    }
    
    sort( elephant , elephant + n , comp );
    
    int len = LIS ( n ) ;
    cout << len << endl;
    
    repn( i , ans.size() - 1 , 0 ){
        cout << ans[ i ] + 1  << endl ;
    }

    return 0;
}
