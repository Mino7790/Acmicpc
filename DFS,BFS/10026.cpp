#include<iostream>
using namespace std;

char RGB[101][101];
char tempRGB[101][101];


void disunion(char a, int x, int y) {
	if (tempRGB[x][y] == '0')
		return;
	tempRGB[x][y] = '0';
	if (tempRGB[x + 1][y] == a) {
		disunion(a, x + 1, y);
	}
	if (tempRGB[x - 1][y] == a) {
		disunion(a, x - 1, y);
	}
	if (tempRGB[x][y + 1] == a) {
		disunion(a, x, y + 1);
	}
	if (tempRGB[x][y - 1] == a) {
		disunion(a, x, y - 1);
	}

}


void disunionB(char a, int x, int y) {
	if (RGB[x][y] == '0')
		return;
	RGB[x][y] = '0';
	if (RGB[x + 1][y] == a) {
		disunionB(a, x + 1, y);
	}
	if (RGB[x - 1][y] == a) {
		disunionB(a, x - 1, y);
	}
	if (RGB[x][y + 1] == a) {
		disunionB(a, x, y + 1);
	}
	if (RGB[x][y - 1] == a) {
		disunionB(a, x, y - 1);
	}

}


int dfs(int n) {
	int CB = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (RGB[i][j] == 'B') {
				tempRGB[i][j] = 'B';
			}
			if (RGB[i][j] == 'R' || RGB[i][j] == 'G') {
				tempRGB[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tempRGB[i][j] != '0')
				CB += 1;
			disunion(tempRGB[i][j], i, j);
		}
	}
	return CB;
}


int dfsB(int n) {
	int N = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (RGB[i][j] != '0')
				N += 1;
			disunionB(RGB[i][j], i, j);
		}
	}
	return N;
}






int main() {
	int n;
	cin >> n;
	char temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> RGB[i][j];
		}
	}
	int a, b;
	a = dfs(n);
	b = dfsB(n);
	cout << b << " " << a;



}

// for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cout<< RGB[i][j];
// 		}
// 		cout<< "\n";
// 	}