/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#define repeat(nb) for (int i=0; i<nb; i++)
using namespace std;

int main() {
    int Tc, sum, add;
    char num[4][5];
    scanf("%d\n", &Tc);
    while(Tc--){
        sum = 0;
        repeat(4) scanf("%s", num[i]);
        repeat(4) {
            sum += (num[i][1]-'0' + num[i][3]-'0');
            add = 2*(num[i][0] - '0');
            if (add >= 10) add = add%10 + 1;
            sum += add;
            add = 2*(num[i][2] - '0');
            if (add >= 10) add = add%10 + 1;
            sum += add;
        }
        if (sum % 10 == 0) puts("Valid");
        else puts("Invalid");
    }
    return 0;
}
