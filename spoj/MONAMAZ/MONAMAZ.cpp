#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n;
int visited[1002];

void dfs(vector<vector<int>>&adj, int no){
    visited[no] = 1;

    for(auto x : adj[no]){
        if(visited[x] != 0){
            dfs(adj, no);
        }
    }
}
double distancia(int x1, int y1, int x2, int y2){
    double sub1 = (x2- x1) * (x2-x1);
    double sub2 = (y2- y1) * (y2-y1);
    double soma = sub1 + sub2;
    return sqrt(soma); 
}
void make_arestas(vector<pair<int,int>>&coord, vector<vector<int>>&adj){
    for(int i = 0; i < n; i++){
        set<pair<double,int>>st;  
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }

            double dist = distancia(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
            st.insert(make_pair(dist, j));
        }   

        int cont = 0;
        //nao ta respeitando a regra mais ao oeste e mais ao sul
        for(auto x : st){
            adj[i].push_back(x.second);
            if(cont == 2){
                break;
            }
            cont++;
        }   
    }
}   


int main(){
   
    
    while(cin >> n){

        memset(visited, 0, sizeof(visited));
        if(n == 0){
            break;
        }

        vector<vector<int>>adj(n);
        vector<pair<int,int>>coord;
        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
        }

        make_arestas(coord,adj);
        dfs(adj,0);

        bool b = true;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                b = false;
                break;
            }
        }

        if(b){
            cout << "All stations are reachable." << endl;
        }else{
            cout << "There are stations that are unreachable." << endl;
        }
    }

}