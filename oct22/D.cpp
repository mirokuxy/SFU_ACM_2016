#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long res = 100;
	vector<int> prices;
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		prices.push_back(tmp);
	}
	for (int i = 1; i < n; i++) {
		if (prices[i] < prices[i - 1]) continue;
		long long num = min((long long)100000, res/prices[i - 1]);
		res = res + num * (long long)(prices[i] - prices[i - 1]);
	}
	cout << res << endl;
}