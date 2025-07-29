#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;


struct Coordenada {
    int nivel;
    int linha;
    int coluna;

    Coordenada(int a = 0, int b = 0 , int c = 0){
        nivel = a;
        linha = b;
        coluna = c;
    }


    bool operator<(const Coordenada& other) const {
        if (nivel != other.nivel) return nivel < other.nivel;
        if (linha != other.linha) return linha < other.linha;
        return coluna < other.coluna;
    }
};

int l,r,c;

Coordenada coord_s;
Coordenada coord_e;

int dist[32][32][32];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool ok(vector<vector<vector<char> > >&v, int nivel,int linha,int coluna){
    if(nivel >= 0  && nivel < l && linha >= 0  && linha < r && coluna >= 0 && coluna < c){
        if(v[nivel][linha][coluna] == '.' || v[nivel][linha][coluna] == 'E'){
            return true;
        }
    }

    return false;
}

void djk(vector<vector<vector<char> > >&v){
    set<pair<int,Coordenada> >st;
    st.insert(make_pair(0,coord_s));
    dist[coord_s.nivel][coord_s.linha][coord_s.coluna] = 0;

    while(!st.empty()){
        Coordenada no = (*st.begin()).second;
        int cost = (*st.begin()).first;

        st.erase(st.begin());


        for(int i = 0; i < 4; i++){
            int nivel = no.nivel;
            int linha = no.linha + dx[i];
            int coluna = no.coluna + dy[i];

            if(ok(v,nivel,linha,coluna)){
                if(cost+1 < dist[nivel][linha][coluna] || dist[nivel][linha][coluna] == -1){
                    dist[nivel][linha][coluna] = cost+1;
                    st.insert(make_pair(dist[nivel][linha][coluna],Coordenada(nivel,linha,coluna)));
                }
            }

        }

        int nivel = no.nivel + 1;
        int linha = no.linha;
        int coluna = no.coluna;

        if(ok(v,nivel,linha,coluna)){
                if(cost+1 < dist[nivel][linha][coluna] || dist[nivel][linha][coluna] == -1){
                    dist[nivel][linha][coluna] = cost+1;
                    st.insert(make_pair(dist[nivel][linha][coluna],Coordenada(nivel,linha,coluna)));
                }
        }

        nivel = no.nivel - 1;
        linha = no.linha;
        coluna = no.coluna;

        if(ok(v,nivel,linha,coluna)){
                if(cost+1 < dist[nivel][linha][coluna] || dist[nivel][linha][coluna] == -1){
                    dist[nivel][linha][coluna] = cost+1;
                    st.insert(make_pair(dist[nivel][linha][coluna],Coordenada(nivel,linha,coluna)));
                }
        }

    }
}


int main(){
   
    while(cin >> l >> r >> c){
        if(l == 0 && r == 0 && c == 0){
            break;
        }

        
        memset(dist,-1,sizeof(dist));
        
        vector<vector<vector<char> > > v(l, vector<vector<char> >(r, vector<char>(c)));


        for(int i = 0; i < l ; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    char c;
                    cin >> c;

                    if(c == 'S'){
                        coord_s = Coordenada(i,j,k);
                    }else if(c == 'E'){
                        coord_e = Coordenada(i,j,k);
                    }

                    v[i][j][k] = c;
                    
                }
            }
        }

        djk(v);

        if(dist[coord_e.nivel][coord_e.linha][coord_e.coluna] == -1){
            cout << "Trapped!" << endl;
        }else{
            printf("Escaped in %d minute(s).\n", dist[coord_e.nivel][coord_e.linha][coord_e.coluna]);
        }
    }
}
