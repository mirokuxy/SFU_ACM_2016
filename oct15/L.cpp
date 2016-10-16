#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<char> vol = {'a', 'i', 'y', 'e', 'o', 'u'};
vector<char> other = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};

int main() {
	string str;
	unordered_map<char, char> m;
	for (int i = 0; i < vol.size(); i++) {
		m[vol[i]] = vol[ (i + 6 - 3) % 6 ];
	}
	for (int i = 0; i < other.size(); i++) {
		m[other[i]] = other[ (i + 20 - 10) % 20 ];
	}
	while (getline(cin, str)) {
		for (int i = 0; i < str.length(); i++) {
			bool cap = false;
			if (str[i] >= 'A' && str[i] <= 'Z') {
				cap = true;
				str[i] -= ('A' - 'a');
			}
			if (m.find(str[i]) != m.end()) {
				str[i] = m[str[i]];
			}
			if (cap) {
				str[i] += ('A' - 'a');
			}
		}
		cout << str << endl;
	}
}