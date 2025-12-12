/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <map>
#include <string>
using namespace std;

const char *units[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char *tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *thousands[] = {"M", "MM", "MMM"};
map <char, int> myMap = {
    {'I', 1}, {'V', 2}, {'X', 2},
    {'L', 2}, {'C', 2}, {'D', 3},
    {'M', 4}
};

string convert_AtoR(int& num) {

    string res = "";
    int t = num / 1000, h = (num % 1000) / 100;
    int d = ((num % 1000) % 100) / 10, u = ((num % 1000) % 100) % 10 ;
    if (t != 0) res += thousands[t - 1];
    if (h != 0) res += hundreds[h - 1];
    if (d != 0) res += tens[d - 1];
    if (u != 0) res += units[u - 1];
    return res;
}

int main()
{
    int N, ans;
    while(scanf("%d", &N) != EOF) {
        ans = 0;
        string romanNum = convert_AtoR(N);
        for (int i=0; romanNum[i]; i++) {
            ans += myMap[romanNum[i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}