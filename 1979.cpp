//蟻本 初級練習問題 No.1 

// 14/5/11 Accepted


#include<iostream>
#include<map>
#include<queue>

using namespace std;

typedef pair<int,int> P;



char data[21][21];
int W,H;
int nowx,nowy;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};


int bfs(){
	queue<P> que;
	
	que.push(P(nowx,nowy));
	
	int count=1;
	
	while(que.size()){
		P p=que.front();que.pop();
	
		for(int i =0;i<4;i++){
			int nx=p.first+dx[i],ny=p.second+dy[i];
			
			if(0<=nx && nx<W && 0<=ny && ny<H && data[ny][nx]!='#'){
				que.push(P(nx,ny));
				count++;
				data[ny][nx]='#';
			}
			
			
		}
		

	}

return count;
}

int main(){
while(cin>>W>>H && W!=0 && H!=0){
for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
		cin>>data[i][j];
		if(data[i][j]=='@'){
			nowx=j;
			nowy=i;
			data[i][j]='#';
			}
		}
	}	
	cout<<bfs()<<endl;
}
}
