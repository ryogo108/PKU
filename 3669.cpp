//蟻本初級練習問題No.6

// 14/7/13 accepted


#include<iostream>
#include<queue>
#include<cstdio>

#define INF 10000000
#define N 320            ////map_data配列は大きめに!!  これにn時間も取られるなんてもったいない!!
using namespace std;

int data[N][N];
int ans_d[ N][ N];
typedef pair<int,int> P;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int bfs(){
	ans_d[0][0]=0;
	if(data[0][0]==0)return -1;
	queue<P> que;
	
	que.push(P(0,0));
	
	while(que.size()){
		P p=que.front();que.pop();
		int cx=p.first,cy=p.second;
		if(data[cy][cx]==INF)return ans_d[cy][cx];
		for(int i=0;i<4;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			if(0<=nx && 0<=ny && data[ny][nx]>ans_d[cy][cx]+1 && ans_d[cy][cx]+1<ans_d[ny][nx]){
				que.push(P(nx,ny));
				ans_d[ny][nx]=ans_d[cy][cx]+1;
			}
		}

	}
	return -1;
}


int main(){
	for(int i=0;i< N;i++){
		for(int j=0;j< N;j++){
			data[i][j]=INF;
			ans_d[i][j]=INF;
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		data[y][x]=min(t,data[y][x]);
		for(int j=0;j<4;j++){
			int nx=x+dx[j],ny=y+dy[j];
			if(nx>=0 && ny>=0){
				data[ny][nx]=min(data[ny][nx],t);
			}
		}
	}
	cout<<bfs()<<endl;
	return 0;
}
