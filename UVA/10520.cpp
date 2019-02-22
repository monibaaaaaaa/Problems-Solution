/*
Author :: Moniba
Problem Id :: UVA 10520
Problem Name :: Determine it
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define MAX 20+5
ll dp[MAX][MAX];
int n;
ll call(int i , int j ){
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ans=0;
    if(i<j){
        for(int k=i ; k<j ; k++)
            ans=max(ans, call(i,k)+call(k+1,j) );
    }else{
        if(i!=n)
            for(int k=i+1; k<=n ; k++)
                ans=max(ans, call(k,1)+call(k,j) );
        ll ans2=0;
        if(j!=0)
            for(int k=1 ; k<j ; k++)
                ans2=max(ans2 , call(i,k)+call(n,k));

        ans+=ans2;
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main(){
    int s;
    while(cin>>n>>s){
        memset(dp , -1 , sizeof dp);
        dp[n][1]=s;
        cout<< call(1,n) <<endl;
    }
    return 0;
}
