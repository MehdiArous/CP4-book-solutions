#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; 
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        long long v[a][b][c];
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                for (int k=0; k<c; k++) {
                    cin >> v[i][j][k];
                    if (j > 0) v[i][j][k] += v[i][j-1][k];
                    if (k > 0) v[i][j][k] += v[i][j][k-1];
                    if (j > 0 && k > 0) v[i][j][k] -= v[i][j-1][k-1];
                }
            }
        }
        long long ans = -(1ll<<31)*20*20*20;
        for (int i0=0; i0<b; i0++) {
            for (int i1=i0; i1<b; i1++) {
                for (int j0=0; j0<c; j0++) {
                    for (int j1=j0; j1<c; j1++) {
                        long long subSum = 0;
                        for (int i=0; i<a; i++) {
                            long long val = v[i][i1][j1];
                            if (i0 > 0) val -= v[i][i0-1][j1];
                            if (j0 > 0) val -= v[i][i1][j0-1];
                            if (i0 > 0 && j0 > 0) val += v[i][i0-1][j0-1];
                            subSum += val;
                            ans = max(ans, subSum);
                            subSum = max(subSum, 0ll);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        if (tc) cout << '\n';
    }
}
