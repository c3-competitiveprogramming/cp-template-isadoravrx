#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<pair<int,int>, int>arestas;


int dfs(int pai,int no, vector<vector<int> >&adj,vector<int>&visited, map<int,int>freqcor, vector<int>&colors, int qpares){
    visited[no] = 1;
    freqcor[colors[no]]++;
    if(freqcor[colors[no]] % 2 == 0){
        qpares++;
    }   

    arestas[make_pair(pai,no)] = max(arestas[make_pair(pai,no)], qpares);

    int maxqpares = qpares;
    for(auto x : adj[no]){
        if(visited[x] == 0){
            maxqpares = max(maxqpares,dfs(no, x, adj, visited,freqcor, colors, qpares));
        }
    }   

    arestas[make_pair(pai,no)] = max(arestas[make_pair(pai,no)],maxqpares);
    return maxqpares;
}

int main(){
    int n;
    cin >> n;


    vector<int>colors(n+1);
    for(int i = 1; i <= n; i++){
        int c;
        cin >> c;   
        colors[i] = c;
    }

    vector<vector<int> >adj(n+1);
    vector<pair<int,int> >ordem_arestas;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        arestas[make_pair(a,b)] = 0;
        arestas[make_pair(b,a)] = 0;
        ordem_arestas.push_back(make_pair(a,b));
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            vector<int>visited(n+1);
            map<int,int>freqcor;
            dfs(0, i, adj, visited,freqcor,colors, 0);
        }
    }

    for(int i = 0; i < n-1; i++){
        int contordemdireta = arestas[ordem_arestas[i]];
        
        int a = ordem_arestas[i].second;
        int b = ordem_arestas[i].first;
        int contordeminversa = arestas[make_pair(a,b)];

        cout << max(contordemdireta,contordeminversa) << endl;
    }
}