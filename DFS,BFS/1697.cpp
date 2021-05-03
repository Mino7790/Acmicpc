// ���ٲ���
// ���� N(0<= N <= 100000)
// ���� K(0<= K <= 100000)
// ���� �̵� +1 �Ǵ� -1
// �����̵� 2����ġ�� ���� 500�̸� 1000�� ����
// ���� ���� ���� �ð� ���ϱ�

// 
#include<iostream>
#include<queue>
using namespace std;


void BFS1697(int K, int* BfsMap, queue <pair<int, int>> q)
{
	//cout << "����ī��Ʈ : "<<q.front().first<<"  ī��Ʈ"<< q.front().second<<endl;

	while (!q.empty()) {

		int nowcount = q.front().second + 1;
		int num1, num2, num3;
		num1 = q.front().first + 1;
		num2 = q.front().first - 1;
		num3 = q.front().first * 2;

		q.pop();
		//cout << "durl" ;
		if (BfsMap[K] > -1)
		{
			return;
		}
		//cout << "durl2";
		if (num1 == K || num2 == K || num3 == K)
		{
			BfsMap[K] = nowcount;
			return;
		}
		//cout << "durl3";

		if (num1 <= 100000 && BfsMap[num1] < 0)
		{
			q.push(make_pair(num1, nowcount));
			BfsMap[num1] = nowcount;

		}
		if (num2 >= 0 && BfsMap[num2] < 0)
		{
			q.push(make_pair(num2, nowcount));
			BfsMap[num2] = nowcount;
		}
		if (0 <= num3 && num3 <= 100000 && BfsMap[num3] < 0)
		{
			q.push(make_pair(num3, nowcount));
			BfsMap[num3] = nowcount;

		}
	}
}



int main()
{
	int N, K, count;
	queue <pair<int, int>> q;




	cin >> N >> K;
	pair <int, int> first;
	first.first = N;
	first.second = 0;

	count = -1;
	q.push(first);

	int bfsmap[100001] = { -1 };
	for (int i = 0; i < 100001; i++)
		bfsmap[i] = -1;

	bfsmap[N] = 0;
	BFS1697(K, bfsmap, q);
	cout << bfsmap[K];


}
// while�� �̿��� bfs�� Ǭ��, ��� ȣ���� �޸� �ʰ�