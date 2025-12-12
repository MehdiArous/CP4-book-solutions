/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <math.h>
#include <map>
#include <string>
#include <cstring>
using namespace std;

const char *units[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char *tens[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *thousands[] = {"M", "MM", "MMM"};
map <string, int> myMap = {
    {"I", 1}, {"V", 5}, {"X", 10},
    {"L", 50}, {"C", 100}, {"D", 500},
    {"M", 1000}, {"IV", 4}, {"IX", 9},
    {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
};

int convert_RtoA (char* x){
    int i = 0, ans = 0;
    char part[3];
    while(x[i]) {
        part[0] = x[i], part[1] = x[i+1];
        if (myMap[part] && part[1] != '\0') {
            ans += myMap[part], i+=2;
        }
        else{
            part[1] = '\0';
            ans += myMap[part], ++i;
        }
    }
    return ans;
}

string convert_AtoR(char* x) {
    int length = strlen(x);
    int num = 0;
    for (int i=0; i<length; ++i)
        num += (int)pow(10, length-(i+1))*(x[i]-'0');
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
    char num[20];
    while(scanf("%s", num) != EOF) {
        if (num[0] > 65) 
            printf("%d\n", convert_RtoA(num));
        else 
            printf("%s\n", convert_AtoR(num).c_str());
    }
    return 0;
}