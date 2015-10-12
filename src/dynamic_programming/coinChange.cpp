#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int N,M;
	cout<<"Enter the Amount and No. of distinct coins:(eg. 4 3) ";
	cin>>N>>M;

	cout<<"Enter list of distinct coins:(eg. 1 2 3) ";

	vector<int> coins;
	int temp;
	for (int i=0; i<M; i++){
		cin>>temp;
		coins.push_back(temp);
	}

	sort(coins.begin(), coins.end());
	vector< vector<long long int> > mat(M);
	for (int i=0; i<=M; i++){
		mat[i].resize(N+1);
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if(j == 0) {
				mat[i][j] = 1;
				continue;
			}
			if(i == 0) {
				if(j%coins[i]==0) {
					mat[i][j] = 1;
				}
				else
					mat[i][j] = 0;
				continue;
			}

			if (j-(coins[i]) < 0) mat[i][j] = mat[i-1][j];
			else {
				mat[i][j] = mat[i-1][j] + mat[i][j-coins[i]];
			}
		}
	}
	cout<<"No. of different ways: "<<mat[M-1][N]<<endl;
	return 0;
}
