#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    
    vector<int>adj[1002];
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    deque<int>v;
    bool visited[1002];
    int cont = 0; 
    
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            v.push_back(i);
            visited[i] = true;
            cont++;

            while(!v.empty()){
                int no = v[0];
                v.pop_front();

                visited[no] = true;

                for(int x : adj[no]){
                    if(visited[x]){
                        continue;
                    }
                    v.push_front(x);
                }
            }
        }
    }

    cout << cont << endl;
}

