/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const char *units[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char *tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
int results[101][5];
map<char, int> myMap = {
    {'I', 0}, {'V', 1}, {'X', 2},
    {'L', 3}, {'C', 4}
};

string convert(int x) {
    string res = "";
    if (x==100) return res;
    if (x / 10 != 0) res += tens[(x/10) - 1];
    if (x % 10 != 0) res += units[(x%10) - 1];
    return res;
} 

int main()
{
    memset(results, 0, sizeof(results));
    for (int i=1; i<=100; i++) {
        string romanNum = convert(i);
        for (int j=0; romanNum[j]; j++)
            ++results[i][myMap[romanNum[j]]];
        for (int j=0; j<5; j++)
            results[i][j] += results[i-1][j];
    }
    ++results[100][4];
    int n;
    while(scanf("%d", &n), n) 
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n,
        results[n][0], results[n][1], results[n][2], results[n][3], results[n][4]);
    return 0;
}