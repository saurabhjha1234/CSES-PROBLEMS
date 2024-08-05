#include<iostream>
#include<vector>
using namespace std;
int flag = 0;
void dfs(int i,vector<int>& vis,int color,vector<int>* graph){
	vis[i]=color;
	for(auto& j:graph[i]){
		if(vis[j]==-1){
			dfs(j,vis,1-color,graph);
		}
		else if(i!=j && vis[j]==color){
			flag=1;
			return ;
		}

	}
}
int main(){
	int n,m;
	cin>>n>>m;
	flag=0;
	vector<int> graph[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> vis(n+1,-1);
	for(int i=1;i<=n;i++){
		if(vis[i]==-1)
			dfs(i,vis,0,graph);
		if(flag==1){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
			cout<<"1 ";
		else
			cout<<"2 ";
	}
	cout<<endl;

	return 0;
}