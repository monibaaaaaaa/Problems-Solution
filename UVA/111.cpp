/*
Author :: Moniba
Problem id ::   UVA 111
Problem name :: History Grading
*/
#include <bits/stdc++.h>
using namespace std;
#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define ll long long
#define pii pair<int, int >
#define MAX 20+5
#define mod 1
string line;
int n,input;
int a[MAX],t[MAX],st[MAX];
bool keep=true;
int BS(int l, int r, int val){
    int mid=(l+r)/2;
    if(val>st[t[mid]])
        return BS(mid+1,r,val);
    if(mid==1 || val>st[t[mid-1]])
        return mid;
    return BS(l,mid-1,val);
}
int LIS(int n){
    int len=1;
    t[len]=0;
    repp(i,1,n-1){
        if(st[i]>st[t[len]]){
            len++;
            t[len]=i;
        }else{
            int idx=BS(1,len,st[i]);
            t[idx]=i;
        }
    }
    return len;
}
int main(){
    cin>>n;
    while(keep){
        repp(i,0,n-1){
            cin>>input;
            a[i]=input-1;
        }
        cin.ignore();
        while(true){
            if(!getline(cin,line)){
                //end of file
                keep=false;
                break;
            }
            if(line.size()>2){
                //a student’s chronological ordering of the n events.
                stringstream ss(line);
                int i=0;
                while(ss>>input){
                    st[input-1]=a[i];
                    i++;
                }
                cout<<LIS(n)<<endl;
            }else{
                //New testcase
                //means line consist of a integer n
                stringstream ss(line);
                ss>>n;
                break;
            }
        }
    }
    return 0;
}
