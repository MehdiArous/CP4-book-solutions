/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

int convert(char* x){
    int size = strlen(x), sum = 0, base = 10, i0 = 0;
    if (x[0] == '0'){
        if (x[1] == 'x') {
            base = 16, i0 = 2;
        }
        else {
            base = 8, i0 = 1;
        }
    }
    for (int i=size-1; i>=i0; --i) {
        if (x[i] >= 65)
            sum += ((x[i]-55) * pow(base, size-(1+i)));
        else 
            sum += ((x[i]-'0') * pow(base, size-(1+i)));    
    }
    return sum;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char num[20], instruct[5];
    int t, ivalue, ans, score;
    while(scanf("%s %d", num, &t), t) {
        ivalue = convert(num);
        score = 0;
        while(t--){
            scanf("%s %d", instruct, &ans);
            if (instruct[0] == '-') --ivalue;
            if (instruct[0] == '+') ++ivalue;
            if (ivalue == ans) ++score;
            else ivalue = ans;
            if (instruct[1] == '+' && instruct[0] == 'i') ++ivalue;
            if (instruct[1] == '-' && instruct[0] == 'i') --ivalue;
        }
        printf("%d\n", score);
    }
    return 0;
}