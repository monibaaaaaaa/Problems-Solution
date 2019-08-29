/*
Author :: Moniba
Problem id :: UVA 108
Problem name :: Maximum Sum
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX ( 100 + 5 )
#define pii pair< int , int >
#define ll long long
int N;
int mat[ MAX ][ MAX ];
int res = -1270000 - 5;

bool can( int i , int j ){
    if( i>= 0 && j >= 0 && i < N && j <N )
        return true;
    return false;
}

void findsum(){
    repp( i, 0,N -1 ){
        repp( j, 1, N - 1){
            mat [ i ][ j ] += mat[ i ][ j - 1];
        }
    }
    repp( j, 0,N -1 ){
        repp( i, 1, N - 1){
            mat[ i ][ j ] += mat[ i - 1][ j ];
        }
    }
}

void findmax(){
    int ans ;
    // All the sub_rectangle
    repp( sx, 0,N -1 )
    repp( sy , 0, N - 1)
        repp( fx, sx ,N - 1 )
        repp( fy, sy, N - 1){

            ans = mat[ fx ][ fy ];
            if( can ( sx - 1, sy - 1 ))
                ans += mat[ sx - 1][ sy - 1];
            if( can ( sx - 1, fy ))
                ans -= mat[ sx - 1][ fy ];
            if( can ( fx, sy - 1 ))
                ans -= mat[ fx ][ sy - 1];
            res = max( res, ans);
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    repp( i, 0,N - 1 ){
        repp( j, 0, N - 1){
            cin >> mat[ i ][ j ];
        }
    }
    findsum();
    findmax();
    cout << res << endl;
    return 0;
}
