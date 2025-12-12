/*************************************
Created By Mehdi Arous 
**************************************/

#include <cstdio>
#include <unordered_map> 
#include <cctype>
using namespace std;

unordered_map<char, double> molarMass = {
    {'C', 12.01}, {'O', 16}, {'H', 1.008}, {'N', 14.01}
};

int main()
{
    int Tc, i; 
    char molecule[80];
    //freopen("input.txt", "r", stdin);
    scanf("%d", &Tc);
    while (Tc--){
        double moleMass = 0.0;
        i = 0;
        scanf("%s", molecule);
        while(molecule[i]){
            char c = molecule[i], c1 = molecule[i+1], c2 = molecule[i+2];
            if (isdigit(c1) && isdigit(c2)){
                moleMass += ( ((c1-'0')*10 + (c2-'0')) * molarMass[c] ), i+=3;}
            else if (isdigit(c1)){
                moleMass +=  ( (c1-'0') * molarMass[c] ), i+=2;}
            else {
                moleMass += molarMass[c], ++i;}
        }
        printf("%.3lf\n", moleMass);
    }
    return 0;
}