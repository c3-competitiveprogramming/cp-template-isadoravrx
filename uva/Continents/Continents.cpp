#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

int visited[22][22];
int m, n;
int tamanho = 1;
int xking,yking;
int contking = 0;
char land, water;

void dfs(vector<vector<char> > &v, int x, int y, int cont){
    visited[x][y] = cont;

    if(x == xking && y == yking){
        contking = cont;
    }

    if(y == 0 && visited[x][n-1] == 0 && v[x][n-1] == land){
        dfs(v, x, n-1, cont);
        tamanho++;
    }

    if(y == n-1 && visited[x][0] == 0 && v[x][0] == land){
        dfs(v, x, 0, cont);
        tamanho++;
    }

    if(y != 0 && visited[x][y-1] == 0 && v[x][y-1] == land){
        dfs(v, x, y-1, cont);
        tamanho++;
    }

    if(y != n-1 && visited[x][y+1] == 0 && v[x][y+1] == land){
        dfs(v, x, y+1, cont);
        tamanho++;
    }

    if(x != 0 && visited[x-1][y] == 0 && v[x-1][y] == land){
        dfs(v, x-1, y, cont);
        tamanho++;
    }

    if(x != m-1 && visited[x+1][y] == 0 && v[x+1][y] == land){
        dfs(v, x+1, y, cont);
        tamanho++;
    }
}
int main(){
   
    while(cin >> m >> n){
        vector<vector<char> > v(m, vector<char>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char c; 
                cin >> c;
                v[i][j] = c;
                if(i == 0 && j == 0){
                    land = c;
                }            

                if(c != land){
                    water = c;
                }
            }
        }

        
        cin >> xking >> yking;
        if(v[xking][yking] == water){
            char temp = water;
            water = land;
            land = temp;
        }


        int cont = 1;
        map<int,int>mp;

        contking = 0;
        tamanho = 1;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && v[i][j] == land){
                    dfs(v, i, j, cont);
                    mp[cont] = tamanho;
                    tamanho = 1;
                    cont++;
                }
            }
        }

        int mx = 0;
        for(auto it : mp){
            if(it.first == contking){
                continue;
            }
            mx = max(mx, it.second);
        }

        cout << mx << endl;
    }
}