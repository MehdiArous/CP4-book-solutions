/*************************************
Created By Mehdi Arous 
**************************************/

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int nbPages;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &nbPages), nbPages){
        int nbSheets = ceil(nbPages / 4.0);
        if (nbPages == 1) {
            puts("Printing order for 1 pages:");
            puts("Sheet 1, front: Blank, 1");
        }
        else {
            printf("Printing order for %d pages:\n", nbPages);
            int maxPage = 4*nbSheets, firstPage = 1;
            for (int i=1; i<=nbSheets; i++){
                if (maxPage > nbPages) 
                    printf("Sheet %d, front: Blank, %d\n", i, firstPage);
                else
                    printf("Sheet %d, front: %d, %d\n", i, maxPage, firstPage);
                --maxPage, ++firstPage;
                
                if (maxPage > nbPages) 
                    printf("Sheet %d, back : %d, Blank\n", i, firstPage);
                else
                    printf("Sheet %d, back : %d, %d\n", i, firstPage, maxPage);
                --maxPage, ++firstPage;
            }
        }
    }
    return 0;
}