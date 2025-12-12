/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#define repeat(nb) for (int k=0; k<nb; k++)
using namespace std;

int freq, amp;

void solve(){
    repeat(freq){
        for (int i=1; i<=amp; i++){
            repeat(i)
                printf("%d", i);
            puts("");
        }
        for (int i=amp-1; i>0; i--){
            repeat(i)
                printf("%d", i);
            puts("");
        }
        if (k < freq-1) puts("");
    }    
}

int main()
{
    int Tc;
    scanf("%d", &Tc);
    bool f=0;
    while(Tc--){
        scanf("%d %d", &amp, &freq);
        if (f) puts("");
        solve();
        f = 1;
    }
    return 0;
}
