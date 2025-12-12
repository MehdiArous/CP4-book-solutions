/*************************************
Created By Mehdi Arous 
**************************************/

#include <bits/stdc++.h>
using namespace std;

int Pg[3], Pb[2]; // Princess and prince 

int search(int idx){
    if (!idx){
        int y = 1;
        while (y <= 52){
            if (y != Pb[0] && y != Pb[1] && y != Pg[0] && y != Pg[1] && y != Pg[2]) 
                return y;
            ++y;
        }
    }
    else if (idx == 1){
        int y = Pg[2] + 1;
        while (y <= 52){
            if (y != Pb[1]) return y;
            ++y;
        }
        if (y >= 52) return -1;        
    }
    else {
        int y = Pg[1] + 1;
        while (y <= 52){
            if (y != Pb[0] && y != Pb[1] && y != Pg[2]) return y;
            ++y;
        }
        if (y >= 52) return -1;
    }
    return 0;
}

int solve(){
    
    sort(Pg, Pg+3), sort(Pb, Pb+2);
    if ((Pb[1] < Pg[1]) || (Pb[1] < Pg[2] && Pb[0] < Pg[1])) return -1;
    if (Pb[0] > Pg[2]) return search(0);
    if (Pb[1] > Pg[2] && Pb[0] < Pg[1]) return search(1);
    if ((Pb[1] < Pg[2] && Pb[0] > Pg[1]) || (Pb[1] > Pg[2] &&  Pb[0] > Pg[1] && Pb[0] < Pg[2]))
        return search(2);
    return 0;
}


int main()
{
    while(scanf("%d %d %d %d %d", &Pg[0], &Pg[1], &Pg[2], &Pb[0], &Pb[1])){
        if (!(Pg[0] || Pg[1] || Pg[2] || Pb[0] || Pb[1])) return 0;
        int ans = solve();
        printf("%d\n", ans);
    }

    return 0;
}