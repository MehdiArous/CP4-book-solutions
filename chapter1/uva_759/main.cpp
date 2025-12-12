/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int value(char& x) {
    if (x=='M') return 1000;
    if (x=='D') return 500;
    if (x=='C') return 100;
    if (x=='V') return 5;
    if (x=='I') return 1;
    if (x=='L') return 50;
    if (x=='X') return 10;
    return 0;
}

int level(char& x) {
    if (x == 'M') return 3;
    if (x == 'C' || x == 'D') return 2;
    if (x == 'X' || x == 'L') return 1;
    if (x == 'I' || x == 'V') return 0;
    return 0;
}

bool valid(int x) {
    if (-x == 40 || -x == 90 || -x == 400 || -x == 900 || -x == 4 || -x == 9) return 1;
    return 0;
}

void solve(char* x) {
    int idx = 0, ans = 0;
    vector<int> sums, levels;
    while (x[idx] && x[idx] != '\r' && x[idx] != '\n') {
        char c1 = x[idx], c2 = x[idx+1];
        char c3 = x[idx+2], c4 = x[idx+3];
        if (c1 == c2 && c2 == c3 && c3 == c4) {
            puts("This is not a valid number");
            return;
        }
        int diff = value(c1) - value(c2);
        if (diff  < 0 && valid(diff)) {
            sums.push_back(value(c2) - value(c1));
            idx += 2;
        }
        else sums.push_back(value(x[idx++]));
        levels.push_back(level(c1));
    }
    if (!levels.size()) {
        puts("0");
        return;
    }
    for (int i=0; i<levels.size()-1; i++) {
        if (levels[i] < levels[i+1] || sums[i] < sums[i+1]) {
            puts("This is not a valid number");
            return;
        }
        if (levels[i] == levels[i+1]) {
            if (sums[i] + sums[i+1] >= (int)pow(10, levels[i]+1)) {
                puts("This is not a valid number");
                return;
            }
            if ((abs(sums[i+1] - sums[i]) > (int)pow(10, levels[i]) && (valid(-sums[i+1]) || valid(-sums[i])))
            || sums[i+1] > (int) pow(10, levels[i])) {
                puts("This is not a valid number");
                return;
            }
            else ans += sums[i];
        }
        else ans += sums[i];
    }
    ans += sums[sums.size()-1];
    printf("%d\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char number[1000];
    while(fgets(number, sizeof(number), stdin))
        solve(number);            
    return 0;
}