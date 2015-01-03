
#include<iostream>
#include<algorithm>
using namespace std;

struct milk{
	int start;
	int end;
	int ef;
};

bool gre(const milk l,const milk r){
	return l.start<r.start;
}

milk data[2000];
int dp[2000][2000];
int main(){
	int n,m,r;
	cin>>n>>m>>r;
	
	for(int i=0;i<m;i++){
		cin>>data[i].start>>data[i].end>>data[i].ef;
	}
	sort(data,data+m,gre);
	for(int i=0;i<m;i++){
		dp[0][i]=data[i].ef;
	}
	
	
	
	int ans=0;
	for(int i=1;i<=m;i++){
		bool e=true;
		for(int j=i;j<m;j++){
			int ma=0;
			for(int k=i-1;k<m;k++){
				if(data[j].start>=data[k].end+r && dp[i-1][k]>ma)ma=dp[i-1][k];
			}
			if(ma>0){
				dp[i][j]=ma+data[j].ef;
				if(dp[i][j]>ans)ans=dp[i][j];
				e=false;
			}
			else dp[i][j]=-1;
		}
		if(e)break;
	}
	
	cout<<ans<<endl;
}
