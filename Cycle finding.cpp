#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxi=1000000000000000;
int main(){
  int n,m;
  cin>>n>>m;
  //cout<<"input";
  vector<vector<ll>> v;
  for(int i=0;i<m;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    v.push_back({x,y,z});
  }
    ll dis[n+1],parent[n+1];
    for(int i=0;i<=n;i++){
      dis[i]=maxi;
      parent[i]=-1;
    }
    dis[1]=0;
    parent[1]=-1;
    ll start=-1;
   // cout<<"input cal";
    for(int j=1;j<=n;j++){
      start=-1;
      for(int i=0;i<m;i++){
        if(dis[v[i][1]]>dis[v[i][0]]+v[i][2]){
          dis[v[i][1]]=dis[v[i][0]]+v[i][2];
          parent[v[i][1]]=v[i][0];
          start=v[i][1];
        }
      }
    }
  
    if(start==-1)
      cout<<"NO\n";
    else{
      cout<<"YES\n";
     
      	for (int i = 1; i <= n ; i++){
            start = parent[start];
        }
 
        vector<ll> cycle;
        for (ll v = start; ;v = parent[v]) {
 
            cycle.push_back(v);
          
            if (v == start
                && cycle.size() > 1)
                break;
        }
 
        // Reverse cycle[]
        reverse(cycle.begin(), cycle.end());
 
        // Printing the negative cycle
        for (ll v : cycle)
            cout << v << ' ';
    }
 
  return 0;
}