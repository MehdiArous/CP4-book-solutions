/*************************************
Created By Mehdi Arous 
**************************************/

#include <stdio.h>
#include <cmath>
using namespace std;

int taxRange[4] = {180000, 300000, 400000, 300000};
double Percent[4] = {0, 0.1, 0.15, 0.2};

int main()
{
    int Tc, i, c = 0, k; 
    double tax;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &Tc);
    while (Tc--) {
        i = 0, tax = 0.0;
        scanf("%d", &k);
        while (k - taxRange[i] > 0){
            tax += (taxRange[i] * Percent[i]);
            k -= taxRange[i], ++i;
            if (i == 4) break;
        }
        if (i == 4 && k > 0)  
            tax += (k * 0.25);
        else tax += (k * Percent[i]);
        
        if (tax <= 2000 && tax > 0) printf("Case %d: 2000\n", ++c);
        else printf("Case %d: %d\n", ++c, (int)ceil(tax));
    }
    return 0;
}
