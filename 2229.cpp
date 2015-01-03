#include<iostream>
#include<math.h>
#define N 1000000
using namespace std;


int dp[1000010];

int main(){
	int n;
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i%2==0)dp[i]=dp[i-1]+dp[i/2];
		else dp[i]=dp[i-1];
		dp%=1000000000
	}
	cout<<dp[n]<<endl;
}
