#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


void dfs( vector<vector<int> >&adj, vector<int> &visited, int no){
    visited[no] = 1;

    for(auto x : adj[no]){
        if(visited[x] == 0){
            dfs(adj, visited, x);
        }
    }
}
int main(){
    int n;
    
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<pair<int,int> >points;
        map<pair<int,int>,int>mp;
        for(int i = 1; i <= n; i++){
            int x,y;
            cin >> x >> y;
            mp[make_pair(x,y)] = i;
            points.push_back(make_pair(x,y));
        }


        vector<vector<pair<double, int> > >dist(n);
        for(int i = 0; i < n ;i++){
            int x1 = points[i].first;
            int y1 = points[i].second;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                double x2 = points[j].first;
                double y2 = points[j].second;

                double primeiro_quadrado = (x2-x1) * (x2-x1);
                double segundo_quadrado = (y2-y1) * (y2-y1);
                double distancia = sqrt(primeiro_quadrado + segundo_quadrado);
                dist[i].push_back(make_pair(distancia,j));
            }
        }
        vector<vector<int> >adj(n);
        
        for(int i = 0; i < n; i++){
            sort(dist[i].begin(), dist[i].end());
            if(dist[i].size() >= 1){
                adj[i].push_back(dist[i][0].second);
            }

            if(dist[i].size() >=2){
                adj[i].push_back(dist[i][1].second);
            }
        }
        
        vector<int>visited(n);
        dfs(adj, visited, 0);

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