#include <iostream>
#include <vector>
using namespace std;

/*
	ó�� DP(Dynamic Programming)�� ������ �� ����
	��� �����غ���.
*/
unsigned int BinomialCoefficient(unsigned int totalNum, unsigned int selectionNum)
{
	vector<vector<unsigned int>> memory(totalNum + 1, vector<unsigned int>(selectionNum + 1, 0));

	for (unsigned int n = 0; n <= totalNum; n++)
	{
		for (unsigned int r = 0; r <= min(n, selectionNum); r++)
		{
			// nC0�� n == r�� ���� 1�̹Ƿ�
			if (r == 0 or n == r)
			{
				memory[n][r] = 1;
				continue;
			}

			// nCr = n-1Cr-1 + n-1Cr
			memory[n][r] = memory[n - 1][r - 1] + memory[n - 1][r];
		}
	}
	return memory[totalNum][selectionNum];
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int n, m;
		cin >> n >> m;
		cout << BinomialCoefficient(m, n) << '\n';
	}

	return 0;
}