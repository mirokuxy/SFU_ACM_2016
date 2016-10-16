#include <iostream>

using namespace std;

int main() {
	long long dict[55][55];
	long long N;

	for (int i = 0; i < 55; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dict[i][j] = 1;
			else if (j == i)
				dict[i][j] = 1;
			else
				dict[i][j] = dict[i - 1][j - 1] + dict[i - 1][j];
		}
	}

	while (cin >> N) {
		int cnt[55];
		int i, j;
		long long ans = 0;

		if (N < 7) {
			cout << "Day " << N << ": Level = " << 0 << endl;
			continue;
		}

		for (i = 55; i >= 0; i--)
			if ((N & ((1 << i)) != 0) {
				cout << "N: " << N << ", " << i << ", " << (N & (1 << i)) << endl;
				break;
			}

		for (j = i - 1; j >= 0; j--) {
			cnt[j] = cnt[j + 1] + (N & (1 << j) != 0); 
		}

		for (j = 0; j <= i; j++) {
			if (N & (1 << j) != 0) {
				int k = (cnt[0] - cnt[j] + 2) % 3;
				while (k <= j) {
					ans += dict[j][k];
					k += 3;
				}
			}
		}

		cout << "Day " << N << ": Level = " << ans << endl;
	}
}