/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

void solve(int& x, double res) {
    string str = to_string(res);
    int idx = 0, finalIdx;
    while(str[idx] != '.')
        ++idx;
    ++idx;
    bool canChange = 1;
    while(str[idx]) {
        if (str[idx] == '0' && canChange) {
            canChange = 0, finalIdx = idx;
        }
        if (str[idx] != '0') canChange = 1;
        ++idx;
    }
    char ans[20];
    memset(ans, '\0', sizeof(ans));
    if (str[finalIdx-1] == '.') strncpy(ans, str.c_str(), finalIdx-1);
    else strncpy(ans, str.c_str(), finalIdx);
    printf("Case %d: %s\n", ++x, ans);
    
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int Tc, val1, val2, c=0;
    char line[20];
    scanf("%d\n", &Tc);
    while(Tc--) {
        val1 = 0, val2 = 0;
        fgets(line, sizeof(line), stdin);
        val1 = line[0] - '0';
        if (line[1] == '0') val1 = 10;
        int startIdx = 0;
        if (val1 == 10) startIdx = 2;
        else startIdx = 1;
        while (line[startIdx]) {
            if (line[startIdx] >= 48 && line[startIdx] <= 57) {
                val2 = line[startIdx] - '0';
                break;
            }
            ++startIdx;
        }
        solve(c, .5*val1 + .05*val2);
    }
    return 0;
}