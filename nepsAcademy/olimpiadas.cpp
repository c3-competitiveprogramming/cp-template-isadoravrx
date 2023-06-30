#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int paises,modalidades;
    cin >> paises >> modalidades;
    
    vector<vector<int>>medalhas(paises);
    for(int i = 0; i < paises; i++){  //assim, o país 0,1,2... terao suas q de medalhas
        medalhas[i].assign(3,0);//quantidade,depois o numero
        medalhas[0][3] = i;// identidade do pais, lembrando que comeca de 0
    }

    for(int i = 0; i < modalidades; i++){
        int ouro,prata,bronze;
        cin >> ouro >> prata >> bronze;
        ouro--; //pois os paises comecam de 0
        prata--;
        bronze--;
        medalhas[ouro][1]++;
        medalhas[prata][2]++;
        medalhas[bronze][3]++;
    }

    
    
}
