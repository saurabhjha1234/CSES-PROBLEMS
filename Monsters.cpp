#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int sx,sy;
void fun(int i,int j,vector<vector<int>>& par){
	string ans ="";
	while(!(i==sx && j==sy)){
		if(par[i][j]==1){
			ans +='D';
			i--;
		}
		else if(par[i][j]==2){
			ans +='R';
			j--;
		}
		else if(par[i][j]==3){
			ans +='U';
			i++;
		}
		else if(par[i][j]==4){
			ans+='L';
			j++;
		}
		
	}
	cout<<"YES\n"<<ans.size()<<endl;
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}
int main(){
	int n,m;
	cin>>n>>m;
	string mat[n];
	for(int i=0;i<n;i++){
		cin>>mat[i];
	}
	queue<vector<int>> q;
	vector<vector<int>> vis(n,vector<int>(m,0));
	//int vis[n][m];

	vector<vector<int>> par(n,vector<int>(m,-1));
	vector<pair<int,int>> tmp2;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]=='A'){
				//q.push({i,j,1});
				vis[i][j]=1;
				par[i][j]=-1;
				sx=i;
				sy=j;
			}
			else if(mat[i][j]=='M'){
				q.push({i,j,2});
				vis[i][j]=2;
				par[i][j]=-1;
			}
		}
	}
	q.push({sx,sy,1});

	while(q.size()>0){
		auto tmp=q.front();
		q.pop();
		int i = tmp[0],j=tmp[1];
		if((i==0 || i==n-1 || j==0 || j==m-1) && tmp[2]==1){
			fun(i,j,par);
			return 0;
		}
		if(i+1<n && vis[i+1][j]==0 && mat[i+1][j]=='.'){
			vis[i+1][j] = 1;
			par[i+1][j]=1;
			q.push({i+1,j,tmp[2]});
		}
		if(j+1<m && vis[i][j+1]==0 && mat[i][j+1]=='.'){
			vis[i][j+1]=1;
			par[i][j+1]=2;
			q.push({i,j+1,tmp[2]});
		}
		if(i-1>=0 && vis[i-1][j]==0 && mat[i-1][j]=='.'){
			vis[i-1][j]=1;
			par[i-1][j]=3;
			q.push({i-1,j,tmp[2]});

		}
		if(j-1>=0 && vis[i][j-1]==0 && mat[i][j-1]=='.'){
			vis[i][j-1]=1;
			par[i][j-1]=4;
			q.push({i,j-1,tmp[2]});

		}

	}
	cout<<"NO\n";
	return 0;
}