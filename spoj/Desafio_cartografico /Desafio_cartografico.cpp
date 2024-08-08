#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
int visited[1000002] = {0};


int main(){
    int n;
    scanf("%d", &n);

    vector<vector<int> >adj(n+1);

    for(int i = 1; i <= n-1; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int bestcont = 0;
    int nodistante = 0;
    int start = 1;

    vector<pair<int,int> >v;
    v.push_back(make_pair(start,0));

    while(!v.empty()){
        int no = v.back().first;
        int cont = v.back().second;
        visited[no] = 1;
        v.pop_back();

        for(auto x : adj[no]){
            if(visited[x] == 0){
                 v.push_back(make_pair(x,cont+1));
            }
        }

        if(cont > bestcont){
            bestcont = cont;
            nodistante = no;
        }

    } 

    bestcont = 0;
    start = nodistante;
    v.push_back(make_pair(start,0));

    while(!v.empty()){
        int no = v.back().first;
        int cont = v.back().second;
        visited[no] = 2;
        v.pop_back();

        for(auto x : adj[no]){
            if(visited[x] == 1){
                 v.push_back(make_pair(x,cont+1));
            }
        }

        if(cont > bestcont){
            bestcont = cont;
            nodistante = no;
        }

    }       
    
    
    printf("%d\n", bestcont);

}