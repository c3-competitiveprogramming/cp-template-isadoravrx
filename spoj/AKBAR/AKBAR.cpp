#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,r,m;
        cin >> n >> r >> m;

        int visited[1000002];
        memset(visited, 0, sizeof(visited));
        bool b = true;

        vector<vector<int> >adj(n+1);
        for(int i = 0; i < r; i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        map<int,int>mp;
        for(int i = 0; i < m; i++){
            int no, strength;
            cin >> no >> strength;
            mp[no] = strength;
        }

        for(auto x : mp){
            int nobase = x.first;   

            deque<pair<int,int> >q;
            q.push_front(make_pair(nobase,x.second));
 
            while(!q.empty()){
                int no = (*q.begin()).first;
                int forca = (*q.begin()).second;
                
                q.pop_front();
                if(forca < 0){
                    continue;
                }

                if (visited[no] != 0){
                    b = false;
                    break;
                }

                visited[no] = nobase;

                for (auto x : adj[no]){
                    if (visited[x] != nobase){
                        q.push_front(make_pair(x, forca - 1));
                    }
                }
            }

            if(!b){
                break;
            }
        }

        for(int i = 1; i <= n ; i++){
            if(visited[i] == 0){
                b = false;
                break;
            }
        }
        if(b){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}