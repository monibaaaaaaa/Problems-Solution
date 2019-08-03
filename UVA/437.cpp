/*
Author :: Moniba
Problem id ::   UVA 437
Problem name :: The Tower Of Babylon
*/
#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define ll long long
#define pii pair<int, int >
#define MAX 30+5
#define mod 1
int rec[MAX][3],dp[MAX][3];
int n,cas=1;
bool can(int idx, int h, int i, int j){
    int area[2][2];
    int a=0,b=0;
    repp(ch,0,2){
        if(ch!=h)
            area[0][a++]=rec[idx][ch];
        if(ch!=j)
            area[1][b++]=rec[i][ch];
    }
    if(min(area[0][0],area[0][1])<min(area[1][0],area[1][1]) && max(area[0][0],area[0][1])<max(area[1][0],area[1][1]))
        return true;
    return false;
}
int f(int idx, int h){
    if(dp[idx][h]!=-1)
        return dp[idx][h];
    int ans=rec[idx][h];
    repp(i,0,n-1)
        repp(j,0,2)
            if(can(idx,h,i,j))
                ans=max(ans, f(i,j)+rec[idx][h]);
    dp[idx][h]=ans;
    return ans;
}
int main(){
    while(cin>>n,n){
        memset(dp, -1, sizeof dp);
        repp(i,0,n-1)
        repp(j,0,2)
            cin>>rec[i][j];

        int ans=0;
        repp(i,0,n-1)
        repp(j,0,2)
            ans=max(ans,f(i,j));


        cout<<"Case "<<cas++<<": maximum height = "<<ans<<endl;

    }

    return 0;
}
