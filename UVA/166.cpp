/*
Author :: Moniba
Problem id :: 166
Problem name :: Making Change
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long
#define pdi pair<double , int >

int change[200+1],memo[10000000],num[6+1];
int coin[]={0,5,10,20,50,100,200};
int f(int total){
    if(total==0)
        return 0;
    if(memo[total]!= -1)
        return memo[total];
    int res=(1<<30),ans;
    for(int i=1;i<=6;i++){
        if(total<coin[i]) break;
        if(num[i]==0) continue;
        num[i]--;
        ans=f(total-coin[i]);
        if(ans!=(1<<30)) res=min(res , ans+1);
        num[i]++;
    }
    memo[total]=res;
    return res;
}
int main(){
    memset(change , 0, sizeof change);
    //what we get change
    for(int i=5;i<=200;i+=5){
        int temp=i;
        for(int j =6;j>0;j--){
            if(!temp) break;
            change[i]+=temp/coin[j];
            temp%=coin[j];
        }
    }
    while(true){
        int a,b,money,sum=0;
        for(int i=1;i<=6;i++){
            cin>>num[i];
            sum+=num[i]*coin[i];
        }
        if(!sum) break;
        memset(memo , -1 , sizeof memo);
        scanf("%d.%d",&a,&b);
        money=a*100+b;
        int res=(1<<30), ans;
        for(int i=money;i<=min(sum,money+200);i+=5){
            ans=f(i);
            // i :: what we need to pay
            if(ans!=(1<<30))
                res=min(res,ans+change[i-money]);
        }
        //justifyng in a field 3 characters wide
        printf("%3d\n",res);
    }
    return 0;
}
