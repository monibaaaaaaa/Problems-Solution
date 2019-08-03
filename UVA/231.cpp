/*
Author :: Moniba
Problem id ::   UVA 231
Problem name :: Testing The CATCHER
*/
#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define ll long long
#define pii pair<int, int >
#define MAX 40000+5
#define mod 1
int h[MAX],t[MAX];
int cas=1,n;
int BS(int l, int r, int x){
    int mid=(l+r)/2;
    if(x<h[t[mid]])
        return BS(mid+1,r,x);
    if(mid==1 || x<h[t[mid-1]])
        return mid;
    return BS(l,mid-1,x);
}
int LIS(int n){
    int len=1;
    t[len]=0;
    repp(i,1,n-1){
        if(h[i]<h[t[len]]){
            len++;
            t[len]=i;
        }else{
            int idx=BS(1,len,h[i]);
            t[idx]=i;
        }
    }
    return len;

}
int main(){
    while(cin>>h[0]){
        if(h[0]==-1)
            break;
        n=1;
        repp(i,1,MAX){
            cin>>h[i];
            if(h[i]==-1)
                break;
            n++;
        }
        if(cas!=1)
            cout<<endl;
        cout<<"Test #"<<cas++<<":\n  maximum possible interceptions: "<<LIS(n)<<endl;
    }
    return 0;
}
