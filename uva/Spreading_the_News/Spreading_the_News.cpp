#include <iostream>
#include <vector>
using namespace std;
int maxnos = 0;
int profundidademaxnos = 0;
int n;

void bfs(vector<vector<int> >adj, int raiz){
    vector<int>q;
    vector<int>visited(n);
    visited[raiz] = 1;
    q.push_back(raiz);

    int nivel = 2;
    
    while(!q.empty()){
        int no = q[0];
        q.erase(q.begin());

        int qnosnivel = 0;
        for(int x : adj[no]){
            if(visited[x] == 0){
                visited[no] = 1;
                q.push_back(x);
                qnosnivel++;
            }
        }

        if(qnosnivel > maxnos){
            maxnos = qnosnivel;
            profundidademaxnos = nivel;
        }

        nivel++;
    }
}

int main(){
    cin >> n;

    vector<vector<int> >adj(n+1);
    for(int i = 0; i < n; i++){
        int q;
        cin >> q;

        for(int j = 0; j < q; j++){
            int vizinho;
            cin >> vizinho;

            adj[i].push_back(vizinho);
        }
    }

    int t;
    cin >> t;

    while(t--){
        int raiz;
        cin >> raiz;

        maxnos = 0;
        profundidademaxnos = 0;
        bfs(adj, raiz);  


        if(maxnos == 0){
            cout << 0 << endl;
        }else{
            cout << maxnos << " " << profundidademaxnos << endl;
        }
    }
}