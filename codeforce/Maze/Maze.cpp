#include <iostream>
#include <vector>
using namespace std;
vector<char>v[500];
int visited[500][500];
int n,m,k;
int cont = 0;
int qpontos = 0;

void dfs(int i,int j){
    if(cont == qpontos - k){
        return;
    }
    visited[i][j] = 1;
    cont++;

    if(i - 1 >= 0 && v[i-1][j] == '.' && visited[i-1][j] != 1){//c
        dfs(i-1,j);
    }if(i + 1 < n && v[i+1][j] == '.' && visited[i+1][j] !=      1){//b
        dfs(i+1,j);
    }if(j - 1 >= 0 && v[i][j-1] == '.' && visited[i][j-1] !=      1){//e
        dfs(i,j-1);
    }if(j + 1 < m && v[i][j+1] == '.' && visited[i][j+1] !=      1){//d
        dfs(i,j+1);
    }
}

int main(){
    cin >> n >> m >> k;
    
    int lpont,cpont;
    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '.'){
                if(cont == 0){    
                    lpont = i;
                    cpont = j;
                    cont = 1;
                }
                qpontos++;
            }

            v[i].push_back(c);
        }
    }
    
    dfs(lpont,cpont);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == '.' && visited[i][j] == 0){
                cout << 'X';
            }else{
                cout << v[i][j];
            }
        }

        cout << endl;
    }

}
