#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll; 

void dfs(int i,int* vis,vector<int>* graph){
	vis[i]=1;
	for(auto& j:graph[i]){
		if(vis[j]==0)
			dfs(j,vis,graph);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>arr[m],graph[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		int z;
		cin>>x>>y>>z;
		arr[i].push_back(x);
		arr[i].push_back(y);
		arr[i].push_back(-1*z);
		graph[y].pb(x);
	}
	
	ll dis[n+1] ;
	for(int i=0;i<=n;i++){
		dis[i] =100000000000000000;
	}
	dis[1] = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(dis[arr[j][0]]!= 100000000000000000 && (dis[arr[j][1]]>dis[arr[j][0]]+arr[j][2]))
				dis[arr[j][1]]=dis[arr[j][0]]+1LL*arr[j][2];
		}
	}
	int vis[n+1]={0};
	dfs(n,vis,graph); // for checking cycle
	for(int i=0;i<1;i++){
		for(int j=0;j<m;j++){
			if(dis[arr[j][0]]!= 100000000000000000 && (dis[arr[j][1]]>dis[arr[j][0]]+arr[j][2])){
				if(vis[arr[j][1]]==1){
					cout<<-1<<endl;
					return 0;
				}
			}				
		}
	}
	cout<<-1LL*dis[n]<<endl;

	return 0;
}