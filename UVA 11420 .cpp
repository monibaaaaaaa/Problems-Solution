
/*
Author :: Moniba
Problem Id :: UVA 11420
Problem Name :: Chest of Drawers
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define MAX 65+5
ll dp[MAX][MAX][MAX];
int n,s;
ll f(int idx , int lock , int last){
    //idx :: the current drawer.
    //lock :: the number of lock drawer we need.
    //last :: index of the last drawer was unlocked.
    if(idx==0 && lock==0)
        return 1;
    if(idx==0)
        return 0;
    if(dp[idx][lock][last]!=-1)
        return dp[idx][lock][last];
    ll res=0;
    if(idx==n || idx<last-1){
        //the current drawer is the topest drawer or the top drawer is locked.
        if(lock>0) res+= call(idx-1,lock-1,last);
    }else if(idx==last-1){
        //the top drawer is NOT locked.
        res+= call(idx-1,lock,last);
    }
    res+=call(idx-1,lock,idx);
    dp[idx][lock][last]=res;
    return dp[idx][lock][last];
}
int main(){
    memset(dp , -1 , sizeof dp);
    while(cin>>n>>s , !(n<0 && s<0)){
        memset(dp , -1 , sizeof dp);
        cout<< call(n,s,n+1) <<endl;
    }
    return 0;
}
