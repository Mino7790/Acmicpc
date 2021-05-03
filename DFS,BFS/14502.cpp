#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int map[8][8];
int temp[8][8];
int n, m;
//2= 바이러스 1벽 0 공간 벽은 3개세워서 최소로 하자 바이러스공간
vector<pair<int, int> > zero_point;
vector<pair<int, int> > qhold;
queue<pair<int, int> > q;

void arr_copy(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = map[i][j];
		}
	}

}

void bfs() {
	//int count =0;
	//cout<< q.size();
	//cout<<q.empty()<<endl;
	while (q.empty() != 1) {
		//count +=1;

		if (q.front().second + 1 < m && temp[q.front().first][q.front().second + 1] == 0) {
			pair<int, int> temp_P;
			temp_P.first = q.front().first;
			temp_P.second = q.front().second + 1;
			q.push(temp_P);
			temp[q.front().first][q.front().second + 1] = 2;
		}
		if (q.front().second - 1 >= 0 && temp[q.front().first][q.front().second - 1] == 0) {
			pair<int, int> temp_P;
			temp_P.first = q.front().first;
			temp_P.second = q.front().second - 1;
			q.push(temp_P);
			temp[q.front().first][q.front().second - 1] = 2;
		}

		if (q.front().first + 1 < n && temp[q.front().first + 1][q.front().second] == 0) {
			pair<int, int> temp_P;
			temp_P.first = q.front().first + 1;
			temp_P.second = q.front().second;
			q.push(temp_P);
			temp[q.front().first + 1][q.front().second] = 2;
		}

		if (q.front().first - 1 >= 0 && temp[q.front().first - 1][q.front().second] == 0) {
			pair<int, int> temp_P;
			temp_P.first = q.front().first - 1;
			temp_P.second = q.front().second;
			q.push(temp_P);
			temp[q.front().first - 1][q.front().second] = 2;
		}
		q.pop();
	}
	// return count;
}

int find_C_A(int a, int b, int c) {
	arr_copy(n, m);
	for (int i = 0; i < qhold.size(); i++) {
		pair<int, int> temp_p;
		temp_p.first = qhold[i].first;
		temp_p.second = qhold[i].second;
		q.push(temp_p);
	}

	temp[zero_point[a].first][zero_point[a].second] = 1;
	temp[zero_point[b].first][zero_point[b].second] = 1;
	temp[zero_point[c].first][zero_point[c].second] = 1;
	bfs();
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout<<temp[i][j];
	// 	}
	// 	cout<<endl;
	// }
	// cout<< FCA<<endl;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
				count += 1;
		}
	}

	return count;

}


int main() {
	int count_0 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				count_0 += 1;
				pair<int, int>temp;
				temp.first = i;
				temp.second = j;
				zero_point.push_back(temp);
			}
			if (map[i][j] == 2) {
				pair<int, int>temp;
				temp.first = i;
				temp.second = j;
				qhold.push_back(temp);
			}
		}
	}
	int safe_area = 0;
	//cout<< count_0;
	for (int i = 0; i < count_0 - 2; i++) {
		for (int j = i + 1; j < count_0 - 1; j++) {
			for (int k = j + 1; k < count_0; k++) {
				int temp = find_C_A(i, j, k);
				if (temp > safe_area) {
					safe_area = temp;
					// cout<<zero_point[i].first<<", "<<zero_point[i].second<<"   ";
					// cout<<zero_point[j].first<<", "<<zero_point[j].second<<"   ";
					// cout<<zero_point[k].first<<", "<<zero_point[k].second<<"   ";

					// cout<<"i ="<<i<<" j="<<j<<" k="<<k<<"  C ="<<temp<<endl;

				}
			}
		}

	}
	cout << safe_area;


}
