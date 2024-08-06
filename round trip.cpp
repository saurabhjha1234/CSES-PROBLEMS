#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int flag = 0;
void fun(int last,int start,vector<int>& par){
	stack<int> st;
	st.push(start);
	while(last!=start){
		st.push(last);
		last = par[last];
	}
	st.push(start);
	cout<<st.size()<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
void dfs(int i,vector<int>& vis,int pare,vector<int>& par,vector<int>& dis,vector<int>* graph){
	vis[i]=1;
	par[i]=pare;
	for(auto& j:graph[i]){
		if(vis[j]==0){
			dis[j] = 1+dis[i];
			dfs(j,vis,i,par,dis,graph);
		}
		else if(j!=pare && abs(dis[j]-dis[i])>=2){
			fun(i,j,par);
			flag=1;
			exit(0) ;
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
	vector<int> vis(n+1,0),dis(n+1,-1),par(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dis[i] = 0;
			//par[i]=-1;
			dfs(i,vis,-1,par,dis,graph);
			if(flag==1)
				break;
		}
	}
	if(flag==0)
		cout<<"IMPOSSIBLE\n";
	return 0;
}