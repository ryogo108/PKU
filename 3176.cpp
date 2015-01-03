// 14/9/11 accepted

#include<iostream>
#include<math.h>
using namespace std;

int dp[370][370]={0};

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin>>dp[i][j];
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j-1>=0)dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
			else dp[i][j]+=dp[i-1][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[n-1][i]);
	}
	
	cout<<ans<<endl;
}
