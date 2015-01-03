//蟻本初級練習問題No.5

//  14/7/14 accepted
//  参考 : http://inazz.jp/pku/3009/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include<map>
#define INF 100000

using namespace std;

typedef pair<int,int> P;

int map_data[21][21];

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int Gx,Gy;
int W,H;
int dfs(int x,int y,int now){
	if(now==10)return 11;
	int ans=11;
	for(int i=0;i<4;i++){
		int cx=x,cy=y;
		int nx=cx+dx[i],ny=cy+dy[i];
		if(nx<0 || ny<0 || nx>=W || ny>=H)continue;
		if(map_data[ny][nx]==1)continue;
		bool fail=false;
		while(1){
			cx=nx;cy=ny;
			if(cx==Gx && cy==Gy)return now+1;
			nx=cx+dx[i];ny=cy+dy[i];
			if(nx<0 || ny<0 || nx>=W || ny>=H){
				fail=true;
				break;
			}
			if(map_data[ny][nx]==1){
				break;
			}
		}
		if(!fail){
			map_data[ny][nx]=0;
			ans=min(ans,dfs(cx,cy,now+1));
			map_data[ny][nx]=1;
		}
	}
	
	return ans;
}


int main(){
	int Sx,Sy;
		
	while(cin>>W>>H && W!=0 && H!=0){
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				cin>>map_data[i][j];
				switch(map_data[i][j]){
				case 2: Sx=j,Sy=i;break;
				case 3: Gx=j,Gy=i;break;
				}
			}
		}
		
		int ans=dfs(Sx,Sy,0);
		cout<<(ans==11?-1:ans)<<endl;
		
	}
}
