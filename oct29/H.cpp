#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

double r(int a, int m, int &s) {
  double val = (s % m) / double(m);
  s = (a * s + 1) % m;
  return val;
}

int main() {
  int a, m, s;
  cin >> a >> m >> s;
  string str;
  char w;
  scanf("%d%d%d%c", &a, &m, &s, &w);
  while (getline(cin, str)) {
    for (char c: str) {
      if (c < 0x20 || c > 0x7e) cout << c;
      else {
        int k = 0;
        int inner = (int)ceil(95 - r(a, m, s) * 95);
        char n_c;
        while (true) {
          n_c = (c - 32) + 95 * k - inner + 32;
          if (n_c >= 0x20 && n_c <= 0x7e) {
            break;
          }
          k++;
        }
        cout << n_c;
      }
    }
    cout << endl;
  }
}