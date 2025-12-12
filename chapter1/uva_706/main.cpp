/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <cstring>

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char n[10];
    int s;
    while(scanf("%d %s", &s, n), s){
        int nbL = 2*s+3, length = strlen(n), nbCol = (s+2)*(length)+length;
        char number[nbL][nbCol];
        memset(number, ' ', sizeof(number));
        for (int i=0; i<nbL; i++) {
            int colIdx = 0;
            for (int c=0; n[c]; c++) {
                int d = n[c] - '0';
                if (i%(s+1) == 0) {
                    for (int j=colIdx+1; j<colIdx+s+1; j++) {
                        if (i==0 && d!=1 && d!=4) number[i][j] = '-';
                        else if (i==s+1 && d!=1 && d!=7 && d!=0) number[i][j] = '-';
                        else if (i==2*(s+1) && d!=1 && d!=7 && d!=4) number[i][j] = '-';
                    }
                }
                else {
                    if (i < s+1) {
                        if (d!=1 && d!=2 && d!=3 && d!=7) number[i][colIdx] = '|';
                        if (d!=6 && d!=5) number[i][colIdx+s+1] = '|';
                    }
                    else {
                        if (d!=4 && d%2 == 0) number[i][colIdx] = '|';
                        if (d!=2) number[i][colIdx+s+1] = '|';    
                    }
                }
                colIdx += (s+3);
            }
        }
        for (int i=0; i<nbL; i++) {
            for (int j=0; j<nbCol-1; j++) 
                printf("%c", number[i][j]);
            puts("");
        }
        puts("");
    }
    return 0;
}