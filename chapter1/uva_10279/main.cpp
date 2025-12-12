/*************************************
Created By Mehdi Arous 
**************************************/

#include <iostream>
#define repeat(nb) for (int k=0; k<nb; k++)
#define inRange(x, y, n) ((x >= 0 && x < n) && (y >= 0 && y < n))
using namespace std;

int n;
char mines[11][11]; 
char game[11][11];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void solve(){
    bool lostGame = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (game[i][j] == 'x' && mines[i][j] != '*'){
                int ans = 0;
                repeat(8){
                    if (inRange(j+dx[k], i+dy[k], n) && mines[i+dy[k]][j+dx[k]] == '*')
                        ++ans;
                }
                game[i][j] = ans + '0';
            }
            else if (game[i][j] == 'x' && mines[i][j] == '*')
                lostGame = 1;
        }
    }
    if (lostGame){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (mines[i][j] == '*')
                    game[i][j] = '*';
            }
        }
    }
    for (int i=0; i<n; i++)
        printf("%s\n", game[i]);
}

int main()
{
    int Tc;
    bool f = 0;
    scanf("%d", &Tc);
    while(Tc--){
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%s", mines[i]);
        for (int i=0; i<n; i++)
            scanf("%s", game[i]);
        if (f) puts("");
        solve();
        f = 1;
    }
    return 0;
}