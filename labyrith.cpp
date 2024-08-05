
#include<bits/stdc++.h>
using namespace std;
void fun(int i,int j,vector<vector<pair<int,int>>>& par){
	string s="";
	while(i!=-1 && j!=-1){
		auto it=par[i][j];
		if(it.first==i-1){
			s+='D';
			i=it.first;
		}
		else if(it.first==i+1){
			s+='U';
			i=it.first;
		}
		else if(it.second==j+1){
			s+='L';
			j=it.second;
		}
		else{
			s+='R';
			j=it.second;
		}
 
	}s.pop_back();
	reverse(s.begin(),s.end());
 
	cout<<s<<endl;
}
 
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s[n];
		vector<vector<int>> vis(n,vector<int>(m,0));
		vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
		for(int i=0;i<n;i++)
			cin>>s[i];
		int ans=0,flag1=0,flag2=0;
		int sx,sy,dx,dy;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='A' && flag1==0){
					sx=i;
					sy=j;
					flag1=1;
				}
				else if(s[i][j]=='B' && flag2==0){
					dx=i;
					dy=j;
					flag2=1;
				}
				else if(flag1==1 && flag2==1){
					break;
				}
			}
			if(flag1==1 && flag2==1)
					break;
 
		}
		int flag=0;
		queue<vector<int>> q;
		q.push({sx,sy,0});
		vis[sx][sy]=1;
		par[sx][sy]={-1,-1};
		while(q.size()>0){
			auto  it=q.front();
			q.pop();
			int i=it[0],j=it[1],d=it[2];
			
	if(i+1<n && vis[i+1][j]==0 && s[i+1][j]!='#')
	{	par[i+1][j]={i,j};
		vis[i+1][j]=1;
		
		q.push({i+1,j,d+1});
		if(i+1==dx && j==dy){
				cout<<"YES\n";
				cout<<d+1<<endl;
				fun(i+1,j,par);
				//cout<<st<<endl;
				flag=1;
				break;
			}
	}
	if(j+1<m && vis[i][j+1]==0 && s[i][j+1]!='#'){
		par[i][j+1]={i,j};
		vis[i][j+1]=1;
		
		q.push({i,j+1,d+1});
		if(i==dx && j+1==dy){
				cout<<"YES\n";
				cout<<d+1<<endl;
				//cout<<st<<endl;
				fun(i,j+1,par);
				flag=1;
				break;
			}
	}
		
	if(i-1>=0 && vis[i-1][j]==0 && s[i-1][j]!='#'){
		par[i-1][j]={i,j};
		vis[i-1][j]=1;
		
		q.push({i-1,j,d+1});
 
		if(i-1==dx && j==dy){
				cout<<"YES\n";
				cout<<d+1<<endl;
				fun(i-1,j,par);
				//cout<<st<<endl;
				flag=1;
				break;
			}
	}
		
	if(j-1>=0  && vis[i][j-1]==0 && s[i][j-1]!='#'){
		par[i][j-1]={i,j};
		vis[i][j-1]=1;
		
		q.push({i,j-1,d+1});
		if(i==dx && j-1==dy){
				cout<<"YES\n";
				cout<<d+1<<endl;
				fun(i,j-1,par);
				//cout<<st<<endl;
				flag=1;
				break;
			}
	}
		
	}
	if(flag==0)
		cout<<"NO\n";
 
		//cout<<ans<<endl;
		
 
	}
	return 0;
}