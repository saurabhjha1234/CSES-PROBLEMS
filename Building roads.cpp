#include<vector>
#include<iostream>
 
using namespace std;
 
void dfs(int i,vector<int>& vis,vector<int>* graph){
	vis[i]=1;
	for(auto& j:graph[i]){
		if(vis[j]==0)
			dfs(j,vis,graph);
	}
}
 
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> vis(n+1,0),city;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i,vis,graph);
			city.push_back(i);
		}
	}
	cout<<city.size()-1<<endl;
	if(city.size()>1){
		int f1 = city[0];
		for(auto& j:city){
			if(j==f1)
				continue;
			cout<<f1<<" "<<j<<endl;
		}
	}
	return 0;
