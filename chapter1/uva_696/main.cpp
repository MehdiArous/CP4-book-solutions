/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
using namespace std;

int main()
{
    int m, n, ans;
    while (scanf("%d %d", &m, &n), m||n) {
        if (min(m,n) == 1) ans = max(m,n);
        else if (min(m,n) == 2) {
            int m1 = max(m,n);
            ans = ((m1 + 2) / 4) * 4;
            if ((m1-1)%4 == 0) ans += 2;
        }
        else ans = (m*n)/2 + (m*n) % 2;
        
        printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }
    return 0;
}
