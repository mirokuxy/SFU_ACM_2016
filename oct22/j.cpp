#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n == m) {
		cout << 0 << endl;
		return 0;
	}
	if (n < m) {
		int pos = m - n;
		int neg = n + 360 - m;
		if (abs(pos) <= abs(neg)) {
			cout << pos << endl;
		} else {
			cout << -neg << endl;
		}
		return 0;
	}
	int pos = 360 - n + m;
	int neg = n - m;
	if (abs(pos) <= abs(neg)) {
		cout << pos << endl;
	} else {
		cout << -neg << endl;
	}
	return 0;
}