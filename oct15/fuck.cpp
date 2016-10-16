#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int TSIZE = 100000;

unordered_map<string, int> m;
std::vector<bool> used(TSIZE, false);
int res, res_std;

void merge(vector<int> &tmpv, vector<int> &a, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	tmpv.clear();
	while (i != mid + 1 && j != right + 1) {
		if (a[i] < a[j]) {
			tmpv.push_back(a[i++]);
		} else {
			tmpv.push_back(a[j++]);
			res += (mid - i + 1);
		}
	}
	while (i != mid + 1) tmpv.push_back(a[i++]);
	while (j != right + 1) tmpv.push_back(a[j++]);
	for (int k = 0; k < tmpv.size(); k++) {
		a[left + k] = tmpv[k];
	}
}

void mergesort(vector<int> &tmpv, vector<int> &a, int left, int right) {
	if (left == right) return;
	int mid = left + (right - left) / 2;
	mergesort(tmpv, a, left, mid);
	mergesort(tmpv, a, mid + 1, right);
	merge(tmpv, a, left, mid, right);
}

int main() {
	int n;
	string tmps;
	vector<int> a, tmpv;
	for (int i = 0; i < 1; i++) {
		a.clear();
		tmpv.clear();
		res = 0;
		res_std = 0;
		for (int j = 0; j < TSIZE; j++) {
			used[j] = false;
		}
		for (int j = 0; j < TSIZE; j++) {
			a.push_back(TSIZE - j);
		}
		for (int j = TSIZE - 1; j > 0; j--) {
			res_std += j;
		}
		mergesort(tmpv, a, 0, a.size() - 1);
		cout << res << " " << res_std << endl;
		if (res != res_std) {
			cout << "!!!!!!!!!" << endl;
			break;
		}
	}
}