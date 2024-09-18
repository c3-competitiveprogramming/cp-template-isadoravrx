#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int visited[9][9];
int mn = 1000000000;
int col1,col2;
int lin1,lin2;


void bfs(){
    vector<pair<pair<int,int>,int> >fila;
    fila.push_back(make_pair(make_pair(lin1,col1),0));

    while(!fila.empty()){
        int x = fila[0].first.first;
        int y = fila[0].first.second;
        int cont = fila[0].second;
        visited[x][y] = 1;

        fila.erase(fila.begin());

        if(x == lin2 && y == col2){
            mn = min(mn, cont);
        }

        if(x-2 >= 0 && y-1 >= 0 && visited[x-2][y-1] == 0){
            fila.push_back(make_pair(make_pair(x-2,y-1), cont+1));
        }
        if(x-1 >= 0 && y-2 >= 0 && visited[x-1][y-2] == 0){
            fila.push_back(make_pair(make_pair(x-1,y-2), cont+1));
        }
        if(x+1 < 8  && y-2 >= 0 && visited[x+1][y-2] == 0){
            fila.push_back(make_pair(make_pair(x+1,y-2), cont+1));
        }
        if(x+2 < 8 && y-1 >= 0 && visited[x+2][y-1] == 0){
            fila.push_back(make_pair(make_pair(x+2,y-1), cont+1));
        }


        if(x+2 < 8 && y+1 < 8 && visited[x+2][y+1] == 0){
            fila.push_back(make_pair(make_pair(x+2,y+1), cont+1));
        }
        if(x+1 < 8 && y+2 < 8 && visited[x+1][y+2] == 0){
            fila.push_back(make_pair(make_pair(x+1,y+2), cont+1));
        }
        if(x-1 >= 0 && y+2 < 8 && visited[x-1][y+2] == 0){
            fila.push_back(make_pair(make_pair(x-1,y+2), cont+1));
        }
        if(x-2 >= 0 && y+1 < 8 && visited[x-2][y+1] == 0){
            fila.push_back(make_pair(make_pair(x-2,y+1), cont+1));
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        char a,b;
        
        
        cin >> a >> lin1;
        col1 = a - 'a';

        lin1--;

        cin >> b >> lin2;
        col2 = b - 'a';

        lin2--;

        memset(visited,0,sizeof(visited));
        bfs();

        cout << mn << endl;
        mn = 1000000000;
    }
}