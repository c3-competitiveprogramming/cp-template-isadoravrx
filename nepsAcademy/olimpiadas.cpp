#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int paises,modalidades;
    cin >> paises >> modalidades;
    
    vector<vector<int>>medalhas(paises);
    for(int i = 0; i < paises; i++){  //assim, o país 0,1,2... terao suas q de medalhas
        medalhas[0] = i;
        medalhas[i].assign(3,0);//quantidade,depois o numero
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
