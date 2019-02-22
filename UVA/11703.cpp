/*
Author :: Moniba
Problem Id :: UVA 11703
Problem Name :: Sqrt Log Sin
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define mod 1000000
#define MAX 1000000

int dp[MAX+5];
int call(int x){
    if(x==0)
        return 1;
    if(dp[x]!=-1)
        return dp[x];
    dp[x]=call((int) x-sqrt(x) )+ call((int) log(x) / log(exp(1)) )+ call((int) x*sin(x)*sin(x) );
    dp[x]%=mod;
    return dp[x];
}
int main(){
    memset(dp , -1 , sizeof dp);
    int i;
    while(cin>>i , i!=-1)
        cout<<call(i)<<endl;
    return 0;
}
