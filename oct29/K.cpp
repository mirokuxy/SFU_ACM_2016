#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<long long> VI;
typedef pair<long long, long long> PII;

vector<long long> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

long long mod(long long a, long long b) {
  return ((a % b) + b) % b;
}

long long ee(long long a, long long b, long long &x, long long &y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a/b;
    long long t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;  
  }
  return a;
}

PII crt(long long x, long long a, long long y, long long b) {
  long long s, t;
  long long d = ee(x, y, s, t);
  if (a % d != b % d) return make_pair(0, -1);
  return make_pair(mod(s * b * x + t * a * y, x * y) / d, x* y /d);
}

PII crt(const VI &x, const VI &a) {
  PII ret = make_pair(a[0], x[0]);
  for (long long i = 1; i < x.size(); i++) {
    ret = crt(ret.second, ret.first, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}

long long comb(long long n, long long k) {
  if (n < k) return 0;
  long long res = 1;
  if (k > n - k) 
    k = n - k;
  for (long long i = 1; i <= k; i++) {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}

long long Lucas(long long n, long long r, long long p) {
  long long res = 1;
  VI n_i, r_i;
  while (n) {
    n_i.push_back(n % p);
    n /= p;
  }
  while (r) {
    r_i.push_back(r % p);
    r /= p;
  }
  while (n_i.size() != r_i.size()) {
    if (n_i.size() > r_i.size()) {
      r_i.push_back(0);
    } else {
      n_i.push_back(0);
    }
  }
  for (long long i = 0 ; i < n_i.size(); i++) {
    res *= comb(n_i[i], r_i[i]);
    res %= p;
  }
  return res;
}

int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, r, m;
    cin >> n >> r >> m;
    VI used_primes, ans_i;
    for (long long prime: primes) {
      if (m % prime == 0) {
        used_primes.push_back(prime);
      }
    }
    for (long long prime: used_primes) {
      ans_i.push_back(Lucas(n, r, prime));
    }
    if (used_primes.size() == 0) {
      cout << 0 << endl;
    } else {
      PII res = crt(used_primes, ans_i);
      cout << res.first << endl;
    }
  }
}