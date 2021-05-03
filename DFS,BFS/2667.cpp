#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[25][25];
struct point {
	int X;
	int Y;
	int num;
};
vector <point> v;
int n;

void dfs1(int x, int y, int num) {
	if (map[x][y] == 0) {
		return;
	}
	point A;
	A.X = x; A.Y = y; A.num = num;
	map[x][y] = 0; // 좌표를 0으로 바꾸고
	v.push_back(A);// 좌표와 단지를 넣어주고
	if (x + 1 < n)
		dfs1(x + 1, y, num);
	if (x - 1 >= 0)
		dfs1(x - 1, y, num);
	if (y + 1 < n)
		dfs1(x, y + 1, num);
	if (y - 1 >= 0)
		dfs1(x, y - 1, num);
}

void dfs(int num) {
	int count = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (map[i][j] != 0) {
				dfs1(i, j, count);
				count += 1;
			}
		}
	}
	vector<int> v2;
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0)
			temp = 1;
		else if (v[i].num != v[i - 1].num) {
			v2.push_back(temp);
			temp = 1;//새로운거 넣어주고
		}
		else temp += 1;
		if (i == v.size() - 1)
			v2.push_back(temp);
	}

	cout << v2.size() << "\n";
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << "\n";

	}

}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	dfs(n);
}


// for(int i=0;i<n;i++){
// 	for(int j=0;j<m;j++){
// 			cout<<map[i][j];
// 	}
// 		cout<<"\n";
// }