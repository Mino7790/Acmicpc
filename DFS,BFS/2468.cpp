#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[101][101];
int tempmap[101][101];

vector<int> maxrain;
bool myfuction(int a, int b) {
	return a > b;
}

void bfs1(int x, int y) {
	if (tempmap[x][y] == 1) {

		tempmap[x][y] = 0;
		bfs1(x + 1, y);
		if (x - 1 >= 0)
			bfs1(x - 1, y);
		bfs1(x, y + 1);
		if (x - 1 >= 0)
			bfs1(x, y - 1);
	}
	else return;

}

int bfs(int maxrain, int mapsize) {
	int rain = maxrain;
	int safezone = 0;
	vector<int> SZ;

	// for(int i=0;i<=mapsize;i++){
	// 		for(int j=0;j<=mapsize;j++){
	// 			cout<< map[i][j];
	// 		}
	// 		cout<<"\n";
	// }



	while (rain >= 0) {
		safezone = 0;
		//cout<< rain<<"\n";

		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if (map[i][j] <= rain) {
					tempmap[i][j] = 0;// ������ 0;
				}
				else tempmap[i][j] = 1; // ������ ������ 1
			}
		}


		// for(int i=0;i<=mapsize;i++){
		// 	for(int j=0;j<=mapsize;j++){
		// 		cout<< tempmap[i][j];
		// 	}
		// 	cout<<"\n";
		// }// ���� �����°� Ȯ��



		for (int x = 0; x < mapsize; x++) {
			for (int y = 0; y < mapsize; y++) {
				if (tempmap[x][y] == 1) {
					safezone += 1;
					bfs1(x, y);
				}

			}
		}
		//cout<<"sazfezone"<<safezone<<"\n";
		SZ.push_back(safezone);
		rain--;
	}
	sort(SZ.begin(), SZ.end(), myfuction);
	return SZ[0];
}



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (tempmap)	for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxrain.push_back(map[i][j]);
		}
	}
	sort(maxrain.begin(), maxrain.end(), myfuction);// �������� ����
	cout << bfs(maxrain[0], n);
}

//���������� ������ ����϶�
//���������� 4���� �鿡 �� �ش�ȴ�
//���Ƿ��� 0 ���� �ִ� ���� ���� ������ �����´�
// ������ �ִ������� ���� �� ���ٰ� ����ȴ�