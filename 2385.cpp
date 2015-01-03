// 14/9/11 accepted

#include<iostream>

using namespace std;
int data[1100];
int dp[1100][40]={0};
int main(){
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++)cin>>data[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++){
			int x=0;
			if(j%2==0 && data[i-1]==1)x=1;
			if(j%2==1 && data[i-1]==2)x=1;
			if(j-1>=0)dp[i][j]=max(dp[i-1][j]+x,dp[i-1][j-1]+x);
			else dp[i][j]=dp[i-1][j]+x;
		}
	}
	int ans=0;
	for(int i=0;i<=w;i++)ans=max(ans,dp[n][i]);
	//for(int i=0;i<=n;i++){
	//	for(int j=0;j<=w;j++){
	//		cout<<dp[i][j];
	//	}
	//	cout<<endl;
	//}
	cout<<ans<<endl;
}
