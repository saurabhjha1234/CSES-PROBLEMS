#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define pb push_back
typedef long long int ll; 

void djikstra(int s,int n,ll* dis,vector<pair<int,int>>* g){
	set<pair<ll,int>> st;
	dis[s]=0;
	st.insert({0LL,s});
	vector<int> vis(n+1,0);
	while(!st.empty()){
		auto it = *st.begin();
		int node = it.second;
		ll d = it.first;
		st.erase(st.begin());
		if(vis[node]==1)
			continue;
		vis[node]=1;
		for(auto& child:g[node]){
			if(dis[child.first]>d+1LL*child.second){
				dis[child.first] =d+1LL*child.second;
				st.insert({dis[child.first],child.first});
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> graph[n+1],revg[n+1];
	vector<int> edge[m];
	for(int i=0;i<m;i++){
		int x,y;
		int z;
		cin>>x>>y>>z;
		graph[x].pb({y,z});
		revg[y].pb({x,z});
		edge[i].pb(x);
		edge[i].pb(y);
		edge[i].pb(z);
	}
	
	ll disf[n+1],disb[n+1] ;
	for(int i=0;i<=n;i++){
		disf[i] =100000000000000000;
		disb[i] =100000000000000000;
	}
	djikstra(1,n,disf,graph);
	djikstra(n,n,disb,revg);

	ll ans = 100000000000000000;

	for(int i=0;i<m;i++){
		if(disf[edge[i][0]]!= 100000000000000000 && disb[edge[i][1]]!=100000000000000000){
			ans = min(disf[edge[i][0]]+(1LL*edge[i][2])/2 +disb[edge[i][1]],ans);
		}
	}

	cout<<ans<<endl;
	return 0;
}