#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll maxi=1000000000000000;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  //cout<<"input";
  vector<pair<int,int>> graph[n+1];
  for(int i=0;i<m;i++){
    	int x,y,z;
    	cin>>x>>y>>z;
    	graph[x].push_back({y,z});
 	}
    vector<vector<ll>> dis(n+1,vector<ll>(k,maxi));
    dis[1][0]=0;
    multiset<pair<ll,int>> st;
    st.insert({0LL,1});
    multiset<ll> ans;
    while(!st.empty()){
    	auto it= *st.begin();
    	ll d = it.first;
    	int node = it.second;
    	st.erase(st.begin());
    	if(dis[node][k-1]<d)
    		continue;
       	for(auto& j:graph[node]){
    		if(d+(1LL*j.second)<dis[j.first][k-1]){
    			dis[j.first][k-1] = d+(1LL*j.second);
    			st.insert({dis[j.first][k-1],j.first});
    			sort(dis[j.first].begin(),dis[j.first].end());
    		}
    	}

    }
 for(int i=0;i<k;i++)
 	cout<<dis[n][i]<<" ";
    
 
  return 0;
}