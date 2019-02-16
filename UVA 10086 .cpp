/*
Author :: Moniba
Problem id ::   UVA 10086
Problem name :: Test The Rods
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define MAX 300+5
#define REP(i,s,y) for(int i=s;i<y;i++)
#define rep(i,s,y) for(int i=s;i<=y;i++)

int dp[30+5][MAX][MAX] , path[30+5][MAX][MAX];
vector <int >cost[2][30+5];
int t1,t2,n,m;
int call(int idx , int ncpc , int bcew){
    //idx :: idx-th site
    //ncpc :: number of samples we need in ncpc
    //bcew :: number of samples we need in bcew
    if(idx==n+1 && ncpc==t1 && bcew==t2)
        return 0;
    if(idx>n || ncpc>t1 || bcew>t2)
        return -2;
    if(dp[idx][ncpc][bcew]!=-1)
        return dp[idx][ncpc][bcew];
    int res=(1<<30),ans;
    for(int i=0,j=cost[1][idx].size()-1;i<cost[0][idx].size();i++ , j--){
        ans=call(idx+1 ,ncpc+i , bcew +j);
        if(ans==-2) continue;
        if(res>ans+cost[0][idx][i]+cost[1][idx][j]){
            res=ans+cost[0][idx][i]+cost[1][idx][j];
            path[idx][ncpc][bcew]=i;
        }
    }
    if(res==(1<<30))
        res=-2;
    dp[idx][ncpc][bcew]=res;
    return res;
}
void printpath(int idx ,int nc , int bc){
    if(idx==n+1){
        cout<<endl<<endl;
        return;
    }
    if(idx!=1)
        cout<<" ";
    cout<<path[idx][nc][bc];
    printpath(idx+1 , nc+path[idx][nc][bc] , bc+cost[1][idx].size()-1-path[idx][nc][bc]);

}
int main(){
    while(cin>>t1>>t2 , !(t1==0 && t2==0)){
        memset(dp , -1 , sizeof dp);
        cin>>n;
        int x;
        rep(i,1,n){
            cost[0][i].clear();
            cost[1][i].clear();
            cin>>m;
            cost[0][i].pb(0),cost[1][i].pb(0);
            rep(j,1,m){
                cin>>x;
                cost[0][i].pb(x);
            }
            rep(j,1,m){
                cin>>x;
                cost[1][i].pb(x);
            }
        }
        cout<<call(1,0,0)<<endl;
        printpath(1,0,0);
    }

    return 0;
}
