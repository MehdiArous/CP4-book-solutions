/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#define repeat(nb) for (int k=0; k<nb; k++)
#define inRange(x, y, n, m) ((x >= 0 && x < m) && (y >= 0 && y < n))
using namespace std;


int n, m, Tc=0;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void solve (char**& field){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (field[i][j] == '.'){
                int ans = 0;
                repeat(8){
                    if (inRange(j+dx[k], i+dy[k], n, m) && field[i+dy[k]][j+dx[k]] == '*')
                        ++ans;
                }
                field[i][j] = ans + '0';
            }
        }
    }
    printf("Field #%d:\n", ++Tc);
    for (int i=0; i<n; i++){
        printf("%s\n", field[i]);
    }
}

int main()
{
    bool f = 0;
    while (scanf("%d %d", &n, &m), n||m){
        char** field = new char*[n];
        for (int i=0; i<n; i++){
            field[i] = new char[m+1]; // Allocate memory for strings, including null terminator
            scanf("%s", field[i]);
        }
        if (f == 1) puts("");
        f = 1;
        solve(field);
        // Deallocate
        for (int i = 0; i < n; ++i)
            delete[] field[i];
        delete[] field;
    }
    return 0;
}
