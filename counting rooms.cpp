#include<iostream>
#include<vector>
const int p = 79;
const int mod = 1e9+7;
using namespace std;
typedef long long int ll;

bool solve(int i,int j,vector<vector<char>>& graph,vector<vector<int>>& vis){
	vis[i][j]=1;
	bool ans = true;
	if(i+1<graph.size()){
		if(graph[i+1][j]!='#' && vis[i+1][j]==0)
			ans &= solve(i+1,j,graph,vis);
	}
	if(i-1>=0){
		if(graph[i-1][j]!='#' && vis[i-1][j]==0)
			ans &= solve(i-1,j,graph,vis);
	}
	if(j+1<graph[0].size()){
		if(graph[i][j+1]!='#' && vis[i][j+1]==0)
			ans &= solve(i,1+j,graph,vis);
	}
	if(j-1>=0){
		if(graph[i][j-1]!='#' && vis[i][j-1]==0)
			ans &= solve(i,j-1,graph,vis);
	}
	return ans;
	
}
void input(){
	int n,m,ans=0;
	cin>>n>>m;
	vector<vector<char>> graph(n,vector<char>(m,'-'));
	vector<pair<int,int>> floors;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;
			cin>>c;
			graph[i][j] = c;
			if(c=='.')
				floors.push_back({i,j});
		}
	}
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(auto& it:floors){
		if(vis[it.first][it.second]==0){
			if(solve(it.first,it.second,graph,vis))
				ans++;
		}
	}
	cout<<ans<<endl;

}
int main(){
	input();
	return 0;
}