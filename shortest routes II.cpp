#include<iostream>
typedef long long ll;
using namespace std;

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	ll dis[n+1][n+1] ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)
				dis[i][j]=0;
			else
				dis[i][j] =100000000000000000;
		}
	}

	for(int i=0;i<m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		dis[x][y]=min(z,dis[x][y]);
		dis[y][x]=min(z,dis[y][x]);
	}
	
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	while(q--){
		int x,y;
		cin>>x>>y;
		if(dis[x][y]==100000000000000000)
			cout<<-1<<endl;
		else
		 cout<<dis[x][y]<<endl;
	}

	return 0;
}