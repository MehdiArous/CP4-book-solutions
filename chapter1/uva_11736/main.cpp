/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <math.h>
#include <cstring>
#define ull unsigned long long 

char variables[200][25];
int bytes[200];
ull values[200];

int main()
{
    //freopen("input.txt", "r", stdin);
    memset(bytes, 0, sizeof(bytes));
    memset(values, 0, sizeof(values));
    int b, v;
    while(scanf("%d %d", &b, &v) != EOF) {
        for (int i=0; i<v; i++) 
            scanf("%s %d", variables[i], &bytes[i]);
        for (int i=0; i<v; i++) {
            int exponent = b*bytes[i] - 1;
            ull value = 0;
            for (int j=0; j<bytes[i]; j++) {
                char byte[15];
                scanf("%s", byte);
                for (int k=0; byte[k]; k++) {
                    if (byte[k] == '1') value += (ull)pow(2, exponent);
                    --exponent;
                }
            }
            values[i] = value;
        }
        int q;
        bool found;
        scanf("%d", &q);
        char var[25];
        while(q--) {
            found = 0;
            scanf("%s", var);
            printf("%s=", var);
            for (int i=0; i<v; i++) {
                if (strcmp(var, variables[i]) == 0) {
                    found = 1;
                    printf("%llu\n", values[i]);
                    break;
                }
            }
            if (!found) puts("");
        }
    }
    return 0;
}