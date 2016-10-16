#include <iostream>
#include <vector>

using namespace std;

vector<long long> goodv = {1, 2, 3, 3, 4, 10};
vector<long long> badv = {1, 2, 2, 2, 3, 5, 10};

int main() {
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		long long tmp;
		long long good = 0;
		long long bad = 0;
		for (int i = 0; i < 6; i++) {
			cin >> tmp;
			good += tmp * goodv[i];
		}
		for (int i = 0; i < 7; i++) {
			cin >> tmp;
			bad += tmp * badv[i];
		}
		if (good > bad)
			cout << "Battle " << k << ": Good triumphs over Evil" << endl;
		else if (good < bad)
			cout << "Battle " << k << ": Evil eradicates all trace of Good" << endl;
		else
			cout << "Battle " << k << ": No victor on this battle field" << endl;
	}
}
