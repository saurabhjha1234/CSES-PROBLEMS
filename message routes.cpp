#include<vector>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

 void backt(int i,vector<int>& par){
 	stack<int> st;
 	while(i!=-1){
 		st.push(i);
 		i = par[i];
  	}
 	
 	cout<<st.size()<<endl;
 	while(!st.empty()){
 		cout<<st.top()<<" ";
 		st.pop();
 	}
 	cout<<endl;
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
	vector<int> vis(n+1,0);
	queue<vector<int>> q;
	q.push({1,0});
	vector<int> par(n+1,0);
	par[1]=-1;
	vis[1]=1;
	while(q.size()>0){
		auto it = q.front();
		q.pop();
		if(it[0]==n){
			backt(n,par);
			return 0;
		}
	
		for(auto& j:graph[it[0]]){
			if(vis[j]==0){
				vis[j]=1;
		    	par[j] = it[0];
		    	q.push({j,it[1]+1});
			}
		}
	}
	cout<<"IMPOSSIBLE\n";

	return 0;
}