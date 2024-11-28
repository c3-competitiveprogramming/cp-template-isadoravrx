#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int pos = 0;
int qvisitados = 1;
string nextword(string s){
    string temp;

    while(s[pos] == ' '){
        pos++;
    }
    int i = pos;
    while(i < s.size() && s[i] != ' '){
        temp += s[i];
        i++;
    }
    
    pos = i;
    return temp;
    
}

void dfs(vector<vector<int> >&adj, int visited[], int excluido, int no){
    visited[no] = 1;

    for(auto x : adj[no]){
        if(visited[x] == 0 && x != excluido){
            qvisitados++;
            dfs(adj, visited, excluido, x);
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        string s;

        vector<vector<int> >adj(n+2);
        getline(cin,s);
        while(getline(cin,s)){
            pos = 0;
            int firstnumber  = stoi(nextword(s));
            if(firstnumber == 0){
                break;
            }
            while(pos != s.size()){
                int nxtnumber = stoi(nextword(s));
                adj[firstnumber].push_back(nxtnumber);
                adj[nxtnumber].push_back(firstnumber);
            }
        }

        int ans = 0;
        int visited[102];
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++){
            if(adj[i].size() > 1){
                if(i == n){
                    dfs(adj,visited,i,i-1);
                }else{
                    dfs(adj,visited,i, i+1);
                }
                memset(visited,0, sizeof(visited));
                if(qvisitados != (n-1)){
                    ans++;
                }
                qvisitados = 1;
            }
        }

        cout << ans << endl;
    }
}