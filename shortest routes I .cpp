#include<iostream>
#include<vector>
#include<set>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,ll>> graph[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		graph[x].pb({y,z});
	}
	int vis[n+1];
	ll dis[n+1] ;
	for(int i=0;i<=n;i++){
		vis[i]=0;
		dis[i] =100000000000000000;
	}
	set<pair<ll,int>> que;
	que.insert({0,1});
	dis[1]=0LL;
	
	while(!que.empty()){
		auto it = que.begin();
		int node= (*it).second;
		que.erase(que.begin());
		
		if(vis[node]==1)
			continue;
		vis[node]=1;
		for(auto tmp:graph[node]){
			ll distance = tmp.second;
			int j = tmp.first;			
			if((distance+dis[node])<dis[j]){
				dis[j] =distance*1LL+dis[node];
				que.insert({dis[j],j});
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
	return 0;
}