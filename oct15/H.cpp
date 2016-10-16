#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;
long long res;

void merge(vector<int> &tmpv, vector<int> &a, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	tmpv.clear();
	while (i != mid + 1 && j != right + 1) {
		if (a[i] < a[j]) {
			tmpv.push_back(a[i++]);
		} else {
			tmpv.push_back(a[j++]);
			res += (long long)(mid - i + 1);
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
	cin >> n;
	while (n) {
		a.clear();
		m.clear();
		res = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> tmps;
			m[tmps] = cnt++;
		}
		for (int i = 0; i < n; i++) {
			cin >> tmps;
			a.push_back(m[tmps]);
		}
		if (n > 1) {
			mergesort(tmpv, a, 0, n - 1);
		}
		cout << res << endl;
		cin >> n;
	}

}