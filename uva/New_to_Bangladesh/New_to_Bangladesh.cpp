#include <iostream>
#include <map>
#include <vector>
using namespace std;

void djk(){
    
}


int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;

        vector<vector<pair<int,pair<int,int> > > >adj(n+1);
        for(int i = 0; i < m ; i++){    
            int a,b,temp, dist;
            cin >> a >> b >> temp >> dist;
            adj[a].push_back(make_pair(b,make_pair(temp,dist)));
        }
        
        int q;
        cin >> q;
    

        map<int,vector<pair<int,int> > >mp;
        
        vector<int>dist;
        dist.assign(n,1000000000);
        for(int i = 0; i < q; i++){
            int ini,fim;
            cin >> ini >> fim;

            if(mp.find(ini) == mp.end()){
                djk(ini);
            }
            
            int dist = mp[ini][fim].first;
            int temp = mp[ini][fim].second;

            printf("Distance and time to reach destination is %d & %d.",dist,temp);
            
        }

    }
}
