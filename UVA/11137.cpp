/*
Author :: Moniba
Problem id :: UVA 11137
Problem name :: Ingenuous Cubrency
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define REP(i,s,y) for(int i=s;i<y;i++)
#define rep(i,s,y) for(int i=s;i<=y;i++)
#define mod 1000000007
#define pdi pair<double , int >
ll memo [21+1][10000+1];
//memo :: the number of ways to pay a given amount
int n;
vector<int> coin;
void findcoin(int sz){
    rep(i,1,sz)
        coin.pb(i*i*i);
}
ll solve(int c, int total){
    //c :: the index of the coins
    // total :: the given amount
    if(total==0)
        return 1;
    if(c==-1)
        return 0;
    if(memo[c][total]!=-1)
        return memo[c][total];
    ll num=solve(c-1,total);;
    if(total>= coin[c])
        num+=solve(c,total-coin[c]);
    memo[c][total]=num;
    return num;
}
int main(){
    findcoin(21);
    memset(memo , -1, sizeof memo);
    while(cin>>n){
        cout<<solve(20,n)<<endl;
    }
    return 0;
}
