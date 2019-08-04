/*
Author :: Moniba
Problem id ::   UVA 497
Problem name :: Strategic Defense Initiative
*/
#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define ll long long
#define pii pair<int, int >
#define MAX 500000+5
#define mod 1
int h[MAX], t[MAX], p[MAX], ans[MAX];
int n,cas,x;
string line;
int BS(int l, int r, int x){
    int mid=(l+r)/2;
    if(x>h[t[mid]])
        return BS(mid+1,r,x);
    if(mid==1 || x>h[t[mid-1]])
        return mid;
    return BS(l,mid-1,x);
}
int LIS(int n){
    int len=1;
    //t[len]= the minimum value can be the last element of the sequence with the length of len
    t[len]=1;
    //p[i]= the last value before h[i]
    p[1]=p[0]=-1;
    repp(i,2,n){
        if(h[i]>h[t[len]]){
            p[i]=t[len];
            len++;
            t[len]=i;
        }else{
            int idx=BS(1,len,h[i]);
            p[i]=t[idx-1];
            t[idx]=i;
        }
    }
    int idx=t[len],i=len;
    while(i!=0){
        ans[i]=h[idx];
        idx=p[idx];
        i--;
    }
    return len;

}
int main(){
    cin>>cas;
    cin.ignore();
    //blank line
    getline(cin, line);
    while(cas--){
        n=0;
        //gets number until blank line
        while(getline(cin, line),line!=""){
            n++;
            stringstream ss(line);
            ss>>h[n];
        }
        int res=LIS(n);
        cout<<"Max hits: "<<res<<endl;
        repp(i,1,res){
            cout<<ans[i]<<endl;
        }
        if(cas!=0) cout<<endl;

    }
    return 0;
}
