#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool letrasadj(char a, char b){
    if(char(a + 1) == b || char(a - 1) == b){
        return true;
    }

    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> >adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    map<int,char>mp;
    //quem está conectado com todos, é b
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == n-1){
            mp[i] = 'b';
        }
    }

    for(int i = 1; i <= n; i++){
        if(mp.find(i) == mp.end()){
            mp[i] = 'a';
            for(int j = 0; j < adj[i].size(); j++){
                if(mp.find(adj[i][j]) == mp.end()){
                    mp[adj[i][j]] = 'a';
                }
            }
            break;
        }
    }
    //quem sobrou, é 'c'
    for(int i = 1; i <= n; i++){
        if(mp.find(i) == mp.end()){
            mp[i] = 'c';
        }
    }

    bool b = true;
    for(int i = 1; i <= n; i++){            
        vector<int>v(n+1);
        for(int j = 0; j < adj[i].size() && b; j++){
            v[adj[i][j]] = 1;
            if(mp[i] != mp[adj[i][j]] && !letrasadj(mp[i], mp[adj[i][j]])){
                b = false;
            }
        }

        for(int j = 1; j <= n && b; j++){
            if(i != j && v[j] == 0 && (mp[i] == mp[j] || letrasadj(mp[i], mp[j]))){
                b = false;
                break;
            }
        }
    }

    if(b){
        cout << "Yes" << endl;
        for(int i = 1; i <= n ; i++){
            cout << mp[i];
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }

}