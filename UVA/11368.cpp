/*
Author :: Moniba
Problem id ::   UVA 11368
Problem name :: Nested Dolls
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (20000+5)
#define pii pair< int , int >
#define ll long long
int q, n;
pii a[ MAX ];
bool comp( pii x , pii y){
    if( x.first == y.first )
        return x.second < y.second;
    return x.first > y.first ;
}

int main(){
   cin >> q;
   while( q-- ){
        cin >> n;
        repp(i , 0 , n - 1){
            cin >> a[ i ].first >> a[ i ].second;
        }
        sort( a , a + n , comp);
        multiset<int> height;
        multiset<int>::iterator it;
        height.insert(MAX);
        repp( i , 0 , n - 1){
            it = height.lower_bound( a[ i ].second + 1);
            if ( *it != MAX )
                height.erase( it );
            height.insert( a[ i ].second );
        }
        cout << height.size() - 1 << endl;
   }
   return 0;
}
