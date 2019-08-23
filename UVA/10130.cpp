/*
Author :: Moniba
Problem id :: UVA 10130
Problem name :: SuperSale
*/

#include <bits/stdc++.h>
using namespace std ;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX (30+5)
#define pii pair< int , int >
#define ll long long
int q, n,W , P, G, MX, sum;
int dp[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;
    while( q-- ){
        sum = 0;
        memset( dp , 0 , sizeof dp);

        cin >> n;
        repp(i ,0 , n - 1){
            cin >> P >> W;
            repn(j, 30, W){
                dp[ j ] =max( dp[ j ], P + dp [ j - W ]);
            }
        }
        
        cin >> G;
        while( G-- ){
            cin >> MX;
            sum += dp[ MX ];
        }
        cout << sum << endl;
    }
    
   return 0;
}
