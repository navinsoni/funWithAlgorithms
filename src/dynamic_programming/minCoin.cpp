#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int r, c;
	cout << "Enter no. of coins and value: ";
	cin >> r >> c;
	vector< vector<int> > mat(r, vector<int>(c+1, 888888));
	cout << "Enter denomination: ";

	vector<int> coin(r);

	for (int i=0; i<r; i++) {
		cin >> coin[i];
	}

	sort (coin.begin(), coin.end());

	for (int i=0; i<r; i++) mat[i][0] = 0;

	for (int i=0; i<r; i++) {
		for (int j=0; j<=c; j++) {
			if (i == 0) {
				if(j%coin[i] == 0) mat[i][j] = j/coin[i];
				continue;
			}
			if (j<coin[i]) mat[i][j] = mat[i-1][j];
			else mat[i][j] = min(1 + mat[i][j-coin[i]], mat[i-1][j]);
		}
	}
	cout<<"Min no of coins: "<< mat[r-1][c] << endl;
	return 0;
}
