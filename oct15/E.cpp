#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int max_rings = 22;
const int max_runes = 100;
bool fuck = false;
int n, m;
int cntt = 0;

vector<tuple<int, int, int>> rules;

bool comp(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
	if (get<0>(a) < get<0>(b)) return true;
	if (get<0>(a) > get<0>(b)) return false;
	if (get<1>(a) < get<1>(b)) return true;
	if (get<1>(a) > get<1>(b)) return false;
	if (get<2>(a) < get<2>(b)) return true;
	return false;
}

bool comp2(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
	return get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b);
}

void dfs(int val, int depth) {
	if (fuck) return;
	cntt++;
	if (cntt >= (2 << 17 - 1)) return;
	if (depth >= n) {
		bool find = true;
		for (int i = 0; i < m; i++) {
			bool find_i = false;
			find_i |= ( ! ( (get<0>(rules[i]) > 0) ^ ((val >> (abs(get<0>(rules[i])) - 1)) & 1) ) );
			find_i |= ( ! ( (get<1>(rules[i]) > 0) ^ ((val >> (abs(get<1>(rules[i])) - 1)) & 1) ) );
			find_i |= ( ! ( (get<2>(rules[i]) > 0) ^ ((val >> (abs(get<2>(rules[i])) - 1)) & 1) ) );
			find &= find_i;
		}
		if (find) fuck = true; 
		return;
	}
	int fucku = rand() % 2;
	if (fucku) {
		dfs(val | (1 << depth), depth + 1);
		dfs(val, depth + 1);
	} else {
		dfs(val, depth + 1);
		dfs(val | (1 << depth), depth + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int flag = 0;
		cntt = 0;
		fuck = false;
		rules.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if (abs(a) == 0 || abs(b) == 0 || abs(c) == 0) {
				flag = max(flag, 3);
			} else if (abs(a) > n || abs(b) > n || abs(c) > n) {
				flag = max(flag, 2);
			} else if (abs(a) == abs(b) || abs(b) == abs(c) || abs(a) == abs(c)) {
				flag = max(flag, 1);
			} else {
				if (abs(a) > abs(b)) swap(a, b);
				if (abs(a) > abs(c)) swap(a, c);
				if (abs(b) > abs(c)) swap(b, c);
				rules.push_back(make_tuple(a, b, c));
			}
		}
		if (!flag) {
			sort(rules.begin(), rules.end(), comp);
			auto it = unique(rules.begin(), rules.end(), comp2);
			rules.erase(it, rules.end());
            m = rules.size();
			dfs(0, 0);
			if (fuck) {
				cout << "RUNES SATISFIED!" << endl;
			} else {
				cout << "RUNES UNSATISFIABLE! TRY ANOTHER GATE!" << endl;
			}
		} else {
			switch (flag) {
				case 3:
					cout << "INVALID: NULL RING" << endl;
					break;
				case 2:
					cout << "INVALID: RING MISSING" << endl;
					break;
				case 1:
					cout << "INVALID: RUNE CONTAINS A REPEATED RING" << endl;
					break;
				default:
					break;
			}
		}
	}
}