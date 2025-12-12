/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

char meal[5][20];

double solve() {
    char value[20];
    int val, x=0, per=0;
    for (int i=0; i<5; i++){
        int l = strlen(meal[i]);
        val = atoi(meal[i]);
        if (meal[i][l-1] == 'C') x += val;
        else if (meal[i][l-1] == '%') per += val;
        else {
            if (i == 0) x += val * 9;
            else if (i == 4) x += val * 7;
            else x += val * 4;
        }
    }
    return (x *100.0) / (100 - per);
}

double fat(double& total){
    double fatCal;
    int l = strlen(meal[0]);
    if (meal[0][l-1] == 'C') fatCal = atof(meal[0]);
    else if (meal[0][l-1] == 'g') fatCal = atoi(meal[0]) * 9.0;
    else fatCal = (atoi(meal[0]) / 100.0) * total;
    return fatCal;
}

int main()
{
    double calPerM, fatPerM, fatCal, totalCal;
    //freopen("input.txt", "r", stdin);
    while(scanf("%s", meal[0]), meal[0][0]!= '-') {
        fatCal = 0.0, totalCal = 0.0;
        scanf("%s %s %s %s", meal[1], meal[2], meal[3], meal[4]);  
        calPerM = solve();
        fatPerM = fat(calPerM);
        fatCal += fatPerM, totalCal += calPerM;
        while(scanf("%s", meal[0]), meal[0][0]!= '-') {
            scanf("%s %s %s %s", meal[1], meal[2], meal[3], meal[4]);  
            calPerM = solve();
            fatPerM = fat(calPerM);
            fatCal += fatPerM, totalCal += calPerM;
        }
        printf("%d", (int)round(fatCal * 100 / totalCal)), puts("%");
    }
    return 0;
}