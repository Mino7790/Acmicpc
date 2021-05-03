#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int miro[101][101];
int visit[101][101];

queue<pair<int, int > > q;
int N, M;

void bfs(int n, int m, int mark) {
	if (n == N - 1 && m == M - 1) {
		return;
	}
	//cout<< q.size()<<"qsize"<<endl;
	q.pop();
	visit[n][m] = 1;
	pair<int, int> temp;

	if (n + 1 < N && visit[n + 1][m] != 1 && miro[n + 1][m] >= 1) {//
		temp.first = n + 1;
		temp.second = m;
		visit[n + 1][m] = 1;
		miro[n + 1][m] = mark + 1;
		q.push(temp);
	}

	if (m + 1 < M && visit[n][m + 1] != 1 && miro[n][m + 1] >= 1) {//
		temp.first = n;
		temp.second = m + 1;
		visit[n][m + 1] = 1;
		miro[n][m + 1] = mark + 1;
		q.push(temp);
	}

	if (n - 1 >= 0 && visit[n - 1][m] != 1 && miro[n - 1][m] >= 1) {//
		temp.first = n - 1;
		temp.second = m;
		visit[n - 1][m] = 1;
		miro[n - 1][m] = mark + 1;
		q.push(temp);
	}

	if (m - 1 >= 0 && visit[n][m - 1] != 1 && miro[n][m - 1] >= 1) {//
		temp.first = n;
		temp.second = m - 1;
		visit[n][m - 1] = 1;
		miro[n][m - 1] = mark + 1;
		q.push(temp);
	}
	bfs(q.front().first, q.front().second, miro[q.front().first][q.front().second]);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}
	pair<int, int> p;
	p.first = 0;
	p.second = 0;
	q.push(p);
	bfs(0, 0, 1);
	cout << miro[N - 1][M - 1];
	// cout<<endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		cout<<miro[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}

//	cout<<q.front().first<<q.front().second;
