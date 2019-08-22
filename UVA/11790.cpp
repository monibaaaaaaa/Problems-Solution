/*
Author :: Moniba
Problem id ::   UVA 11790
Problem name :: Murcia's Skyline
*/

#include <bits/stdc++.h>

using namespace std ;

#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (50000+5)
#define pll pair< long long , long long >
#define ll long long
pll a[ MAX ];
ll w[ MAX ];
int n, q;

ll LIS(){
    ll wid = 0 ;
    repp( i , 0 , n - 1){
        w[ i ] = a[ i ].second;
        repp(j , 0 , i - 1){
            if ( a[ i ].first <= a[ j ] .first )
                continue;
            w[ i ] = max( w[ i ] , w[ j ] + a[ i ].second);
        }
        wid = max ( wid , w[ i ]);
    }
    return wid;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll inc , dec ;
    cin >> q ;
    repp ( cas , 1 , q ){
        cin >> n;
        //heights
        repp( i , 0 , n - 1)
            cin >> a[ i ].first;
        
        //widths
        repp( i , 0 , n - 1)
            cin >> a[ i ].second;
        
        //LIS
        inc = LIS();
        
        //LDS
        // LDS from the left = LIS from the right
        reverse( a , a + n );
        dec = LIS();
        
        if( inc >= dec ){
            cout << "Case " << cas <<". Increasing (" << inc <<"). Decreasing (" << dec << ")."<<endl;
        }else{
            cout << "Case " << cas <<". Decreasing (" << dec <<"). Increasing (" << inc << ")."<<endl;
        }
    }
   return 0;
}
