/*
Author :: Moniba
Problem id :: UVA 336
Problem name :: A Node Too Far
*/

#include <bits/stdc++.h>

using namespace std ;

#define repp(i,a,b) for(int i=(a);i<=(b);i++)
#define repn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define MAX ( 1000 )
#define pii pair< int , int >
#define ll long long
#define mod (1)

int n, x, y;
int start, ttl;
int cas = 1;
map<int, vector<int> > adj;
map<int, int> dis;

int bfs(int s, int ttl){
    int reach = 1;
    queue< int > q;
    q.push(s);
    dis[ s ] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vector<int> v = adj[ node ];
        repp(i, 0, (int)v.size() - 1){
            if( dis[ node ] + 1 >= dis[ v[ i ] ])
                continue;
            dis[ v[ i ]] = dis[ node ] + 1;
            if( dis[ v[ i ] ] <= ttl)
                reach++;
            q.push(v[i]);
        }

    }
    return reach;

}

int main(){
    while(cin >> n, n!=0){
       adj.clear();
       dis.clear();
        vector<int> nodes;
        repp(i, 0, n - 1){
            cin >> x >> y;
            if(adj[ x ].empty())
                nodes.pb(x);
            if(adj[ y ].empty())
                nodes.pb(y);

            adj[ x ].pb(y);
            adj[ y ].pb(x);
        }

        while( cin>> start>> ttl,!(start == 0 && ttl == 0)){
            repp(i, 0, nodes.size() - 1)
                dis[ nodes[ i ] ] = MAX;

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas++, adj.size() - bfs(start, ttl), start, ttl);
        }
    }
    return 0;
}
