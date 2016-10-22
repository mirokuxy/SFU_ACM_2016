#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct TrieNode {
	char val;
	string str;
	vector<TrieNode *> next;
	TrieNode(char c, string s) {
		val = c;
		str = s;
	}
};

TrieNode *root = new TrieNode('0', "");

pair<int, int> use_tab(string &aim, string &auto_c, int st, int num) {
	//cout << "Tab: " << aim << " " << auto_c << " " << num << endl;
	int ret = num + 1;
	int i = st;
	while (i + 1 < aim.length() && i + 1< auto_c.length() && aim[i + 1] == auto_c[i + 1]) {
		i++;
	}
	return make_pair(i, ret + auto_c.length() - 1 - i);
}

int main() {
	int n, m;
	string tmps;
	cin >> n >> m;
	for (int i = 0; i < n ; i++) {
		cin >> tmps;
		TrieNode *cur = root;
		for (char c: tmps) {
			bool flag = false;
			for (int j = 0; j < cur->next.size(); j++) {
				if (cur->next[j]->val == c) {
					flag = true;
					cur = cur->next[j];
					break;
				}
			}
			if (flag) continue;
			TrieNode *tmp_node = new TrieNode(c, tmps);
			cur->next.push_back(tmp_node);
			cur = cur->next.back();
		}
	}
	while (m--) {
		bool has_auto = true;
		string prev_auto = "";
		cin >> tmps;
		vector<int> res = vector<int>(tmps.length(), INT_MAX);
		pair<int, int> p;
		TrieNode *cur = root;
		res[0] = 1;
		if (has_auto) {
			has_auto = false;
			for (int i = 0; i < cur->next.size(); i++) {
				if (cur->next[i]->val == tmps[0]) {
					has_auto = true;
					cur = cur->next[i];
					break;
				}
			}
		}
		if (has_auto) {
			if (cur->str.compare(prev_auto) != 0) {
				p = use_tab(tmps, cur->str, 0, res[0]);
				prev_auto = cur->str;
				res[p.first] = min(res[p.first], p.second);
			}
		}
		for (int i = 1; i < tmps.length(); i++) {
			res[i] = min(res[i], res[i - 1] + 1);
			if (has_auto) {
				has_auto = false;
				for (int j = 0; j < cur->next.size(); j++) {
					if (cur->next[j]->val == tmps[i]) {
						has_auto = true;
						cur = cur->next[j];
						break;
					}
 				}
			}
			if (has_auto) {
				if (cur->str.compare(prev_auto) != 0) {
					p = use_tab(tmps, cur->str, i, res[i]);
					prev_auto = cur->str;
					res[p.first] = min(res[p.first], p.second);
				}
			}
		}
		// for (int i = 0; i < res.size(); i++) {
		// 	cout << res[i] << " ";
		// }
		// cout << endl;
		cout << res[res.size() - 1] << endl;
	}
}