#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;

int dx[] = {1,0,-1,0,-1,1,-1,1};
int dy[] = {0,1,0,-1,-1,-1,1,1};

bool ok(int x, int y){
    if(x >=0 && x < n && y >=0 && y < n){
        return true;
    }

    return false;    
}

bool meupar(char a, char b){

    if((a == 'M' && b == 'P') || (a == 'P' && b == 'M') || a == 'O' && b == 'O'){
        return true;
    }else{
        return false;
    }
}

bool meupar2(char a, char b){
    if((a == 'm' && b == 'P') || (a == 'p' && b == 'M') || a == 'o' && b == 'O'){
        return true;
    }else{
        return false;
    }
}


int qpar(int x, int y, vector<pair<int,int> >&meuspares, map<pair<pair<int,int>,pair<int,int> >, int>&mp, vector<vector<char> >&v){
    int qpar = 0;
    for(int k = 0;  k < 8; k++){
        int xi = x + dx[k];
        int yi = y + dy[k];

        if(ok(xi,yi) && mp.find(make_pair(make_pair(x,y), make_pair(xi,yi))) == mp.end() && meupar2(v[x][y], v[xi][yi])){
            meuspares.push_back(make_pair(xi,yi));
            qpar++;
        }
    }

    return qpar;
}

int main(){
   

    cin >> n;
    vector<vector<char> >v(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    int iniscore = 0;

    map<pair<pair<int,int>,pair<int,int> >, int>mp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == 'P' || v[i][j] == 'M' || v[i][j] == 'O'){
                iniscore++;
                for(int k = 0;  k < 8; k++){
                    int xi = i + dx[k];
                    int yi = j + dy[k];

                    
                    if(ok(xi,yi) && mp.find(make_pair(make_pair(i,j), make_pair(xi,yi))) == mp.end() && meupar(v[i][j], v[xi][yi])){
                        mp[make_pair(make_pair(i,j), make_pair(xi,yi))] = 1;
                        mp[make_pair(make_pair(xi,yi), make_pair(i,j))] = 1;
                        iniscore++;
                    }
                }

            }
        }
    }

    int finalscore = iniscore;
    for(int l = 0; l < 100; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] != '.' && v[i][j] != 'P'  && v[i][j] != 'M'  && v[i][j] != 'O'){
                    vector<pair<int,int> >meuspares;
                    int qpares = qpar(i,j, meuspares, mp,v);
                    if( qpares > 0){
                        finalscore += qpares + 1;
                        if(v[i][j] == 'p'){
                            v[i][j] = 'P';
                        }

                        if(v[i][j] == 'o'){
                            v[i][j] = 'O';
                        }

                        if(v[i][j] == 'm'){
                            v[i][j] = 'M';
                        }
                        for(auto it : meuspares){
                            mp[make_pair(make_pair(i,j), make_pair(it.first,it.second))] = 1;
                            mp[make_pair(make_pair(it.first,it.second), make_pair(i,j))] = 1;
                        }
                    }

                }
            }
        }
    }
    
    cout << iniscore << " " << finalscore << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j];
        }
        cout << endl;
    }
}