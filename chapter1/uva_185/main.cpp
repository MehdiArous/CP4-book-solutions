/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map <string, int> myMap1 = {
    {"I", 1}, {"V", 5}, {"X", 10},
    {"L", 50}, {"C", 100}, {"D", 500},
    {"M", 1000}, {"IV", 4}, {"IX", 9},
    {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
};

int convert_RtoA (string x){
    int i = 0, ans = 0;
    char part[3];
    while(x[i]) {
        part[0] = x[i], part[1] = x[i+1];
        if (myMap1[part] && part[1] != '\0') {
            ans += myMap1[part], i+=2;
        }
        else{
            part[1] = '\0';
            ans += myMap1[part], ++i;
        }
    }
    return ans;
}

string checkSum(string s1, string s2, string res) {
    if (convert_RtoA(s1) + convert_RtoA(s2) == convert_RtoA(res))
        return "Correct";
    else return "Incorrect";
}

bool check(vector<int> &A, string s1, string s2, string res, int k){
    map<char, int> myMap;
    string ss = s1+s2;
    int idx = 0;
    for (int i=0; ss[i]; i++) {
        if (myMap.find(ss[i]) == myMap.end()) myMap[ss[i]] = A[idx++];
    }
    set<char> s, digits;
    for (int i=0; res[i]; i++){
        if (myMap.find(res[i]) == myMap.end()) s.insert(res[i]);
    }
    for (int i=0; s1[i]; i++)
        s1[i] = myMap[s1[i]]+'0';
    if (s1[0] == '0') return 0;
    for (int i=0; s2[i]; i++)
        s2[i] = myMap[s2[i]]+'0';
    if (s2[0] == '0') return 0;
    string sum = to_string(stoi(s1) + stoi(s2));
    if ( sum.length() != res.length() ) return 0;
    int nbValid = 0;
    for (int i=0; sum[i]; i++) {
        if (myMap.find(res[i]) != myMap.end() && myMap[res[i]]+'0' == sum[i]) ++nbValid;
        else digits.insert(sum[i]);
    }
    if (nbValid == k && digits.size() == s.size()) return 1;
    return 0;
}

string encoding(string s1, string s2, string res) {
    int maxNbDigits = max(s1.size(), s2.size());
    int l1 = s1.size(), l2 = s2.size(), l3 = res.size();
    if (res.size() > maxNbDigits+1 || res.size() < maxNbDigits)
        return "impossible";
    set<char> s;
    for (int i=0; i<l1; i++) s.insert(s1[i]);
    for (int i=0; i<l2; i++) s.insert(s2[i]);
    int k = s.size(), nbSol = 0;
    int nbValid = 0;
    for (int i=0; res[i]; i++)
        if (s.find(res[i]) != s.end()) ++nbValid;
    string bitmask(k, 1);
    bitmask.resize(10, 0);
    do {
        vector<int> A;
        for (int i=0; i<10; i++){
            if (bitmask[i]) A.push_back(i);
        }
        do {
            if (check(A, s1, s2, res, nbValid)) ++nbSol;
            if (nbSol > 1) return "ambiguous";
        } while (next_permutation(A.begin(), A.end()));
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    if (nbSol == 1) return "valid";
    else return "impossible";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char input[50];
    while (scanf("%s", input), input[0] != '#') {
        string str(input);
        int p1 = str.rfind("+");
        int p2 = str.rfind("=");
        string num1 = str.substr(0, p1);
        string num2 = str.substr(p1+1, p2-(p1+1));
        string res = str.substr(p2+1, p2-str.size());
        printf("%s %s\n",checkSum(num1, num2, res).c_str(),
        encoding(num1, num2, res).c_str());
    }
    return 0;
}