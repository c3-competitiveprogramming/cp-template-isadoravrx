#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


//INCOMPLETO
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


        vector<vector<pair<int,pair<int,int>>>>dist(n);
        for(int i = 0; i < n ;i++){
            int x1 = points[i].first;
            int y1 = points[i].second;
            for(int j = 0; j < n; j++){
                int x2 = points[j].first;
                int y2 = points[j].second;

                int primeiro_quadrado = (x2-x1) * (x2-x1);
                int segundo_quadrado = (y2-y1) * (y2-y1);
                int distancia = sqrt(primeiro_quadrado + segundo_quadrado);
                dist[i].push_back(make_pair(distancia,make_pair(x2,y2)));
            }
        }

        sort(dist.begin(),dist.end());
        vector<vector<int>>adj(n+1);
        
        for(int i = 1; i <= n; i++){

            adj[i].push_back(mp[make_pair(dist[i-1][0].first, dist[i-1][0].second)]);
            adj[i].push_back(mp[make_pair(dist[i-1][1].first, dist[i-1][0].second)]);
        }



        //direcionado?
    }
}