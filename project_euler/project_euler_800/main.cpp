#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;

vi primes;
const int MAX_N = (int)2e7;
const int euler = 800800;
vector<bool> is_prime(MAX_N, true);

inline void generate_primes() {
    for (int p=2; p<MAX_N; p++) {
        if (!is_prime[p]) continue;
        primes.push_back(p);
        for (int q=2*p; q<MAX_N; q += p) is_prime[q] = false;
    }
}

inline bool ok(int p, int q) { 
    return q*log(p) + p*log(q) <= euler*log(euler);
} 

void solve() {
    ll res = 0;
    int i=0, p = primes[i];
    int x = euler * log(euler) / log(p), l=0;
    int r0 = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    while (true) {
        int r = r0;
        while (r > l+1) {
            int mid = (r+l) >> 1;
            if (ok(p, primes[mid])) l = mid; 
            else r = mid;
        }
        if (l==i) break;
        res += l-i;
        i++; l = i; p=primes[i];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    generate_primes();
    solve();   
}
