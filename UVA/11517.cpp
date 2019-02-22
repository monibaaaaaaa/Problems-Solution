/*
Author :: Moniba
Problem id :: UVA 11517
Problem name :: Exact Change
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define REP(i,s,y) for(int i=s;i<y;i++)
#define rep(i,s,y) for(int i=s;i<=y;i++)
//#define mod 1000000007
//#define pdi pair<double , int >

int memo[100+5][20000+5],ways[100+5][20000+5],bill[100+5];
//memo :: the amount we will pay(minimum)
//ways :: minimum number of coin
int all,n;
int f(int c , int total){
    if(total>=all){
        ways[c][total]=0;
        return total;
    }
    if(c==0){
        ways[c][total]=0;
        return all*all;
    }
    if(memo[c][total]!=-1)
        return memo[c][total];
     //the minimum amount without c-th coin
    int res=f(c-1,total);
    ways[c][total]=ways[c-1][total];
    
    ////the minimum amount with c-th coin
    if(f(c-1,total+bill[c])<res){
        res=f(c-1,total+bill[c]);
        ways[c][total]=ways[c-1][total+bill[c]]+1;
    }else if( res==f(c-1,total+bill[c]) && ways[c][total]>ways[c-1][total+bill[c]]+1){
          // if the result are the same but the number of coins are different
          //we are looking for minimum number of the coins
             ways[c][total]=ways[c-1][total+bill[c]]+1;
    }
        memo[c][total]=res;
      return memo[c][total];
}
int main(){
    int q;
    cin>>q;
    while(q--){
        memset(memo , -1, sizeof memo);
        cin>>all>>n;
        rep(i,1,n){
            cin>>bill[i];
        }
        f(n,0);
        cout<<memo[n][0]<<' '<<ways[n][0]<<endl;

    }
    return 0;
}
