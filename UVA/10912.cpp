
/*
Author :: Moniba
Problem Id :: UVA 10912
Problem Name :: Simple Minded Hashing

!!Dynamic Programming
    you can't find a string have only lowercase letters in strictly ascending order more than 26 length.
    and if the length is 26 the most summing values are 1+2+..+26=26*(26+1)/2 that is much less than 10000.
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define MAX 27*26/2
int cas=1,length,st;
int dp[MAX+5][26+1][26+1];
int f(int s,int l,int idx){
    if(s==0 && l==0)
        return 1;
    if(s==0 || l==0)
        return 0;
    if(dp[s][l][idx]!=-1)
        return dp[s][l][idx];
    int res=0;
    for(int i=idx ; i<=26 && i<=s; i++){
        res+=f(s-i,l-1,i+1);
    }
    dp[s][l][idx]=res;
    return dp[s][l][idx];
}
int main(){
    memset(dp , -1 , sizeof dp);
    while(cin>>length>>st,!(length==0 && st==0)){
        if(length>26 || st>MAX ) cout<<"Case "<<cas++<<": "<<0<<endl;
        else
            cout<<"Case "<<cas++<<": "<<f(st,length,1)<<endl;
    }
    return 0;
}
