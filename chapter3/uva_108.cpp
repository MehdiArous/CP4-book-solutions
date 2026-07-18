#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin >> n;
    int a[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (j > 0) a[i][j] += a[i][j-1];
        }
    }
    /*
    O(n^3) solution using Kadane logic on one dimension + getting
    the values for the other dimension using 1D-prefix sum
    
    For n = 100, an O(n^4) solution also passes: 
    brute force all possible sub-matrices, then 
    getting its sum in O(1) (2D prefix sum)
    */
    int ans = -1270000;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int subSum = 0;
            for (int r=0; r<n; r++) {
                int val = a[r][j];
                if (i > 0) val -= a[r][i-1];
                subSum += val;
                ans = max(ans, subSum);
                subSum = max(subSum, 0); 
            }
        }
    }
    cout << ans << '\n';
}
