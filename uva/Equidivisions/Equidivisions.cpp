#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cont = 0;
int n;
int ind = 0;

void dfs(vector<vector<int> >&v, vector<vector<int> >&visited, int i, int j){
    visited[i][j] = 1;
    cont++;
    if(i > 0 && v[i-1][j] == v[i][j] && visited[i-1][j] == 0){//cim
        dfs(v,visited,i-1,j);
    }if(i < n-1 && v[i+1][j] == v[i][j] && visited[i+1][j] == 0){//baix
        dfs(v,visited,i+1,j);
    }if(j > 0 && v[i][j-1] == v[i][j] && visited[i][j-1] == 0){//esq
        dfs(v,visited,i,j-1);
    }if(j < n-1 && v[i][j+1] == v[i][j] && visited[i][j+1] == 0){//dir
        dfs(v,visited,i,j+1);
    }
}

int pick_num(string s){
    string aux = "";

    while(ind < s.size()){
        if(s[ind] == ' '){
            ind++;
            break;
        }

        aux += s[ind];
        ind++;
    }
    return stoi(aux);
}
int main(){

    while(true){
        cin >> n;
        cont = 0;
        ind = 0;

        if(n == 0){
            break;
        }

        vector<int>group(n+1);
        vector<vector<int> >v(n,vector<int>(n,n));
        vector<vector<int> >visited(n,vector<int>(n));
        
        string s;
        getline(cin,s);
        for(int i = 0; i < (n-1); i++){
            getline(cin,s);
            ind = 0;
            
            while(ind < s.size()){
                if(s[ind] == ' '){
                    ind++;
                    continue;
                }
                int n1 = pick_num(s);
                int n2 = pick_num(s);
                v[n1-1][n2-1] = i;
            }
        }


        bool equi = true;
        cont = 0;

        for(int i = 0; i < n && equi; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0){
                    dfs(v,visited,i,j);
                    if(cont != n || group[v[i][j]] == 1){
                        equi = false;
                        break;
                    }
                    group[v[i][j]] = 1;
                    cont = 0;
                }
            }
        }

        if(equi){
            cout << "good" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }
}
